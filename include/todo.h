#ifndef TODO_H
#define TODO_H

#include <vector>
#include "task.h"

class Todo {
private:
    std::vector<Task> tasks;  // List of tasks

public:
    void addTask(const std::string& title);
    void removeTask(int id);
    void displayTasks() const;
    void markTaskCompleted(int id);

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // TODO_H
