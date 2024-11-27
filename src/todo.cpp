#include "../include/todo.h"
#include <fstream>
#include <iostream>
#include <algorithm>

// Add a task
void Todo::addTask(const std::string& title) {
    int id = tasks.empty() ? 1 : tasks.back().getId() + 1;
    tasks.emplace_back(id, title);
}

// Remove a task by ID
void Todo::removeTask(int id) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
               [id](const Task& task) { return task.getId() == id; }),
               tasks.end());
}

// Display all tasks
void Todo::displayTasks() const {
    for (const auto& task : tasks) {
        task.display();
    }
}

// Mark a task as completed
void Todo::markTaskCompleted(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markCompleted();
            break;
        }
    }
}

// Save tasks to file
void Todo::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.getId() << "," << task.getTitle() << "," << task.isCompleted() << "\n";
    }
    file.close();
}

// Load tasks from file
void Todo::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    tasks.clear();

    int id;
    std::string title;
    bool completed;
    char delimiter;

    while (file >> id >> delimiter && std::getline(file, title, ',') && file >> completed) {
        tasks.emplace_back(id, title, completed);
    }
    file.close();
}
