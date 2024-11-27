#include "../include/task.h"

// Constructor
Task::Task(int id, const std::string& title, bool completed)
    : id(id), title(title), completed(completed) {}

// Getter for ID
int Task::getId() const {
    return id;
}

// Getter for Title
std::string Task::getTitle() const {
    return title;
}

// Getter for Completed status
bool Task::isCompleted() const {
    return completed;
}

// Setter for Title
void Task::setTitle(const std::string& newTitle) {
    title = newTitle;
}

// Mark task as completed
void Task::markCompleted() {
    completed = true;
}

// Display the task details
void Task::display() const {
    std::cout << "ID: " << id << " | Title: " << title
              << " | Status: " << (completed ? "Completed" : "Not Completed") << std::endl;
}
