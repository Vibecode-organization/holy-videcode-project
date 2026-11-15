<img width="317" height="559" alt="Screenshot from 2026-08-09 12-11-47" src="https://github.com/user-attachments/assets/046c339f-afda-4f6c-8f42-8ed08ad78062" />

## Warning

Stable releases / Pre-releases and beta versions are published only on GitHub. 

# kyuuriqstats

A simple system information fetcher written in Rust.

## Features

- OS
- Window Manager
- Shell
- Uptime

## Modules

- Weather

## Start

Add config.fish kyuuriqstats to the end

## Usage

- `kyuuriqstats` — system info and weather
- `kyuuriqstats --stats` — system info only
- `kyuuriqstats --weather` — weather only
- `kyuuriqstats --weather <city>` — weather for a specific city
- `kyuuriqstats --set-location <city>` — save a default city
- `kyuuriqstats --all` — system info and weather

## Requirements

- Linux
- Rust
- Internet connection (for the weather module)

## Build

cargo build --release

## Run

cargo run --release
