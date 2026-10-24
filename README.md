# TO-DO LIST

A modern C++ command-line to-do list application designed for simple task management with persistent storage. It lets users add, remove, complete, and review tasks while saving progress to a local file.

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B&logoColor=white" alt="C++ 17" />
  <img src="https://img.shields.io/badge/Build-CMake-064F8C?logo=cmake&logoColor=white" alt="CMake" />
  <img src="https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-4A4A4A?logo=windows&logoColor=white" alt="Cross-platform" />
</p>

## Overview

This project is a lightweight CLI-based task manager built using C++ and the Standard Library. It is ideal for beginners learning object-oriented programming, file I/O, and clean console application design.

## Features

- Add new tasks with a title
- Remove tasks by ID
- Mark tasks as completed
- View all current tasks
- Save and reload task data from `data/tasks.txt`
- Simple, colored console interface
- Cross-platform build support

## Project Structure

```text
TO-DO_LIST/
├── CMakeLists.txt
├── LICENSE
├── README.md
├── data/
│   └── tasks.txt
├── include/
│   ├── task.h
│   └── todo.h
├── src/
│   ├── main.cpp
│   ├── task.cpp
│   └── todo.cpp
└── todo_list.exe
```

## Tech Stack

- C++17
- CMake
- Standard Library
- File-based persistence

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/sachit-create/TO-DO_LIST.git
cd TO-DO_LIST
```

### 2. Build with CMake

```bash
cmake -S . -B build
cmake --build build
```

### 3. Run the app

```bash
./build/todo_list
```

## Data Storage

Tasks are stored in a text file at:

```text
data/tasks.txt
```

Each line follows this format:

```text
id,title,completed
```

Example:

```text
1,Buy groceries,0
2,Prepare for exam,1
```

## How It Works

The app uses:

- a `Task` class to represent each task
- a `Todo` class to manage the task list
- file read/write logic for persistence
- a terminal menu for user interaction

## Build Notes

- Works with modern GCC/Clang toolchains
- Compatible with Windows and Linux terminals
- No external library dependencies required

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Pull requests and improvements are welcome. If you want to add features such as sorting, filtering, or task editing, feel free to contribute.

---

Built as a practical C++ project for learning task management, persistence, and CLI design.
