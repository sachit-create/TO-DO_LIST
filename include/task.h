#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task {
private:
    int id;                // Unique ID for each task
    std::string title;     // Description of the task
    bool completed;        // Status of the task (true if completed)

public:
    // Constructor
    Task(int id, const std::string& title, bool completed = false);

    // Getter and Setter functions
    int getId() const;
    std::string getTitle() const;
    bool isCompleted() const;

    void setTitle(const std::string& newTitle);
    void markCompleted();

    // Display task details
    void display() const;
};

#endif // TASK_H
