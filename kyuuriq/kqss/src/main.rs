mod weather;

use colored::*;
use std::env;
use std::path::Path;
use sysinfo::System;
use unicode_width::UnicodeWidthStr;

pub(crate) fn display_width(text: &str) -> usize {
    UnicodeWidthStr::width(text)
}

pub(crate) fn pad_right(text: &str, width: usize) -> String {
    let current = display_width(text);

    if current >= width {
        text.to_string()
    } else {
        format!("{}{}", text, " ".repeat(width - current))
    }
}

pub(crate) fn pad_center(text: &str, width: usize) -> String {
    let current = display_width(text);

    if current >= width {
        return text.to_string();
    }

    let padding = width - current;
    let left = padding / 2;
    let right = padding - left;

    format!("{}{}{}", " ".repeat(left), text, " ".repeat(right))
}

fn get_desktop_environment() -> String {
    let vars = [
        "XDG_CURRENT_DESKTOP",
        "XDG_SESSION_DESKTOP",
        "DESKTOP_SESSION",
    ];

    for var in vars {
        if let Ok(value) = env::var(var)
            && !value.is_empty()
        {
            return value;
        }
    }

    "Unknown".to_string()
}

fn get_shell() -> String {
    let shell = env::var("SHELL").unwrap_or_default();

    Path::new(&shell)
        .file_name()
        .unwrap_or_default()
        .to_string_lossy()
        .to_string()
}

fn get_uptime() -> String {
    let uptime = System::uptime();

    let days = uptime / 86_400;
    let hours = (uptime % 86_400) / 3_600;
    let minutes = (uptime % 3_600) / 60;

    if days > 0 {
        format!("{}d {}h {}m", days, hours, minutes)
    } else {
        format!("{}h {}m", hours, minutes)
    }
}

fn print_stats() {
    let os = System::name()
        .unwrap_or("Unknown".into())
        .replace("Linux", "");
    let os = os.trim();

    let rows = [
        ("OS", os.to_string()),
        ("Shell", get_shell()),
        ("WM", get_desktop_environment()),
        ("Uptime", get_uptime()),
    ];

    let label_width = rows
        .iter()
        .map(|(label, _)| display_width(label))
        .max()
        .unwrap_or(0);

    let value_width = rows
        .iter()
        .map(|(_, value)| display_width(value))
        .max()
        .unwrap_or(0);

    let bar = "─".repeat(label_width + value_width + 4);

    println!("{}", "     ╭──────╮".blue());

    println!(
        "{}{}{}{}",
        "     │ ".blue(),
        "KQ".white().bold(),
        "SS".blue().bold(),
        " │".blue()
    );

    println!("{}", "     ╰──────╯".blue());

    println!("{}", format!("╭{}╮", bar).blue());

    for (label, value) in &rows {
        println!(
            "{}{}{}{}{}",
            "│ ".blue(),
            pad_right(label, label_width).white().bold(),
            "  ".blue(),
            pad_right(value, value_width).blue().bold(),
            " │".blue()
        );
    }

    println!("{}", format!("╰{}╯", bar).blue());
}

fn print_usage() {
    println!();
    println!("{}", "Usage:".white().bold());
    println!("  kyuuriqstats");
    println!("  kyuuriqstats --stats");
    println!("  kyuuriqstats --weather");
    println!("  kyuuriqstats --weather <city>");
    println!("  kyuuriqstats --set-location <city>");
    println!("  kyuuriqstats --all");
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let mut show_stats = true;
    let mut show_weather = true;
    let mut weather_city: Option<String> = None;

    if args.len() > 1 {
        match args[1].as_str() {
            "--stats" => {
                show_stats = true;
                show_weather = false;
            }

            "--weather" => {
                show_stats = false;
                show_weather = true;

                if args.len() > 2 {
                    weather_city = Some(args[2..].join(" "));
                }
            }

            "--set-location" => {
                if args.len() < 3 {
                    eprintln!("{}", "Error: city is required.".red().bold());
                    println!();
                    println!("Example:");
                    println!("  kyuuriqstats --set-location Люберцы");
                    return;
                }

                let city = args[2..].join(" ");

                match weather::set_location(&city) {
                    Ok(()) => {
                        println!(
                            "{} {}",
                            "Location saved:".green().bold(),
                            city.white().bold()
                        );
                    }

                    Err(error) => {
                        eprintln!(
                            "{} {}",
                            "Location error:".red().bold(),
                            error
                        );
                    }
                }

                return;
            }

            "--all" => {
                show_stats = true;
                show_weather = true;
            }

            "--help" | "-h" => {
                print_usage();
                return;
            }

            _ => {
                println!("{}", "Unknown argument.".red().bold());
                print_usage();
                return;
            }
        }
    }

    if show_stats {
        print_stats();
    }

    if show_stats && show_weather {
        println!();
    }

    if show_weather {
        match weather_city {
            Some(city) => weather::print_weather(&city),
            None => weather::print_weather_auto(),
        }
    }
}
