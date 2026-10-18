# TO-DO LIST

A small, cross-platform console To‑Do list application written in C++ — now with a modern, user-friendly console UI.

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE) [![Language](https://img.shields.io/badge/language-C++-00599C.svg)](https://isocpp.org/)

## Demo

> Replace `assets/demo.gif` with a short screen recording or screenshot for the demo.

![Demo placeholder](assets/demo.gif)

## Why this project?

- Lightweight and easy to build with a single g++ command.
- Simple file-based persistence (`data/tasks.txt`).
- Good for learning C++ classes, file I/O, and basic CLI UX polish.

## Features

- Add, remove, view and mark tasks as completed
- Tasks persisted to `data/tasks.txt`
- Clean, colored console UI for improved usability
- Minimal dependencies — plain C++ standard library

## Quick start

1. Clone:
   ```bash
   git clone https://github.com/sachit-create/TO-DO_LIST.git
   ```
2. Build (example with g++):
   ```bash
   g++ -std=c++17 -I include src/*.cpp -o todo_list
   ```
3. Run:
   ```bash
   ./todo_list
   ```
4. Tasks are saved to `data/tasks.txt` when you choose Save and Exit.

## Build notes

- Tested with g++ (GCC) on Linux and MinGW/Cygwin on Windows.
- No external libraries required.
- If you see color codes in Windows terminals, use a modern terminal emulator (Windows Terminal) or remove color escape codes.

## Repository layout

- `include/` — header files (Task and Todo declarations)
- `src/` — implementation and CLI entrypoint (`main.cpp`)
- `data/` — tasks storage (`tasks.txt`)
- `LICENSE` — project license

## Data format

Each line in `data/tasks.txt` is a comma-separated record:

```
id,title,completed
```

Example:

```
1,Buy groceries,0
```

## Contributing

Contributions are welcome. To help:
- Open an issue for bugs or feature requests
- Fork the repo, make changes, then open a PR with a clear description

## Ideas to improve

- Add sorting and filtering (by status)
- Add colored, columnar task output (status, id, title)
- Add unit tests and CI (GitHub Actions)
- Add a small GUI (Qt or ImGui) or a web frontend

## License

MIT — see LICENSE file.

## Contact

Maintained by sachit-create — thanks for checking the project out!
