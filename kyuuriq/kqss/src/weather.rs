use crate::pad_center;
use colored::Colorize;
use serde::Deserialize;
use std::error::Error;
use std::fs;
use std::path::PathBuf;

#[derive(Deserialize)]
struct GeocodingResponse {
    results: Option<Vec<Location>>,
}

#[derive(Deserialize)]
struct Location {
    latitude: f64,
    longitude: f64,
    name: String,
    country: Option<String>,
}

#[derive(Deserialize)]
struct IpLocation {
    city: Option<String>,
}

#[derive(Deserialize)]
struct WeatherResponse {
    current: CurrentWeather,
}

#[derive(Deserialize)]
struct CurrentWeather {
    temperature_2m: f64,
    weather_code: u8,
}

struct Weather {
    location: String,
    country: Option<String>,
    temperature: f64,
    condition: &'static str,
}

fn location_file() -> Result<PathBuf, Box<dyn Error>> {
    let home = std::env::var("HOME")?;

    let config_dir = PathBuf::from(home)
        .join(".config")
        .join("kyuuriqstats");

    fs::create_dir_all(&config_dir)?;

    Ok(config_dir.join("location"))
}

fn detect_language(text: &str) -> &'static str {
    if text.chars().any(|c| matches!(c, '\u{0400}'..='\u{04FF}')) {
        "ru"
    } else {
        "en"
    }
}

fn geocode(
    client: &reqwest::blocking::Client,
    city: &str,
) -> Result<Location, Box<dyn Error>> {
    let languages = if detect_language(city) == "ru" {
        ["ru", "en"]
    } else {
        ["en", "ru"]
    };

    for language in languages {
        let response = client
            .get("https://geocoding-api.open-meteo.com/v1/search")
            .query(&[
                ("name", city),
                ("count", "1"),
                ("language", language),
                ("format", "json"),
            ])
            .send()?
            .error_for_status()?
            .json::<GeocodingResponse>()?;

        if let Some(location) = response.results.and_then(|results| results.into_iter().next()) {
            return Ok(location);
        }
    }

    Err(format!("City '{}' not found", city).into())
}

pub fn set_location(city: &str) -> Result<(), Box<dyn Error>> {
    let client = reqwest::blocking::Client::new();

    let location = geocode(&client, city)?;

    let file = location_file()?;

    fs::write(&file, &location.name)?;

    Ok(())
}

pub fn print_weather(city: &str) {
    match get_weather(city) {
        Ok(weather) => {
            let country = weather.country.as_deref().unwrap_or("Unknown");
            let temperature = format!("{:.1}°C", weather.temperature);

            let lines = [
                weather.location.as_str(),
                country,
                temperature.as_str(),
                weather.condition,
            ];

            let width = lines
                .iter()
                .map(|line| crate::display_width(line))
                .max()
                .unwrap_or(0)
                .max(12);

            let bar = "─".repeat(width);

            println!("{}", format!("  ╭{}╮", bar).blue());
            println!(
                "{}",
                format!("  │{}│", pad_center("Weather", width))
                    .blue()
                    .bold()
            );

            for line in lines {
                println!(
                    "{}{}{}",
                    "  │".blue(),
                    pad_center(line, width).white().bold(),
                    "│".blue()
                );
            }

            println!("{}", format!("  ╰{}╯", bar).blue());
        }

        Err(error) => {
            println!("{}", "   ╭─────────╮".blue());
            println!("{}", "   │ Weather │".blue().bold());
            println!("{}", "   │  Error  │".red().bold());
            println!("{}", "   ╰─────────╯".blue());

            eprintln!("Weather error: {}", error);
        }
    }
}

pub fn print_weather_auto() {
    match get_saved_location() {
        Ok(Some(city)) => {
            print_weather(&city);
        }

        Ok(None) => {
            match get_ip_location() {
                Ok(city) => print_weather(&city),

                Err(error) => {
                    println!("{}", "   ╭──────────────╮".blue());
                    println!("{}", "   │   Location   │".blue().bold());
                    println!("{}", "   │    Error     │".red().bold());
                    println!("{}", "   ╰──────────────╯".blue());

                    eprintln!("Location error: {}", error);
                }
            }
        }

        Err(error) => {
            eprintln!("Location file error: {}", error);
        }
    }
}

fn get_saved_location() -> Result<Option<String>, Box<dyn Error>> {
    let file = location_file()?;

    if !file.exists() {
        return Ok(None);
    }

    let city = fs::read_to_string(file)?;
    let city = city.trim();

    if city.is_empty() {
        return Ok(None);
    }

    Ok(Some(city.to_string()))
}

fn get_ip_location() -> Result<String, Box<dyn Error>> {
    let client = reqwest::blocking::Client::new();

    let location = client
        .get("https://ipapi.co/json/")
        .send()?
        .error_for_status()?
        .json::<IpLocation>()?;

    location
        .city
        .ok_or_else(|| "Could not determine city from IP".into())
}

fn get_weather(city: &str) -> Result<Weather, Box<dyn Error>> {
    let client = reqwest::blocking::Client::new();

    let location = geocode(&client, city)?;

    let weather = client
        .get("https://api.open-meteo.com/v1/forecast")
        .query(&[
            ("latitude", location.latitude.to_string()),
            ("longitude", location.longitude.to_string()),
            (
                "current",
                "temperature_2m,weather_code".to_string(),
            ),
            ("timezone", "auto".to_string()),
        ])
        .send()?
        .error_for_status()?
        .json::<WeatherResponse>()?;

    Ok(Weather {
        location: location.name,
        country: location.country,
        temperature: weather.current.temperature_2m,
        condition: weather_condition(weather.current.weather_code),
    })
}

fn weather_condition(code: u8) -> &'static str {
    match code {
        0 => "Sunny",
        1..=3 => "Cloudy",
        45 | 48 => "Foggy",
        51..=57 => "Drizzle",
        61..=67 => "Rain",
        71..=77 => "Snow",
        80..=82 => "Rain",
        85 | 86 => "Snow",
        95 | 96 | 99 => "Storm",
        _ => "Unknown",
    }
}
