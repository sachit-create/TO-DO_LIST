#include "../include/todo.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

void Todo::addTask(const std::string& title) {
    int id = tasks.empty() ? 1 : tasks.back().getId() + 1;
    tasks.emplace_back(id, title);
}

void Todo::removeTask(int id) {
    tasks.erase(
        std::remove_if(tasks.begin(), tasks.end(),
                       [id](const Task& task) { return task.getId() == id; }),
        tasks.end());
}

void Todo::displayTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (const auto& task : tasks) {
        task.display();
    }
}

void Todo::markTaskCompleted(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markCompleted();
            return;
        }
    }
}

void Todo::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for writing: " << filename << "\n";
        return;
    }

    for (const auto& task : tasks) {
        file << task.getId() << ',' << task.getTitle() << ',' << (task.isCompleted() ? 1 : 0) << '\n';
    }

    file.close();
}

void Todo::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    tasks.clear();
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string idStr, titleStr, completedStr;

        if (!std::getline(ss, idStr, ',') || !std::getline(ss, titleStr, ',') || !std::getline(ss, completedStr)) {
            continue;
        }

        try {
            int id = std::stoi(idStr);
            bool completed = std::stoi(completedStr) != 0;
            tasks.emplace_back(id, titleStr, completed);
        } catch (const std::exception&) {
            continue;
        }
    }

    file.close();
}
