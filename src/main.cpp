#include "../include/todo.h"
#include <iostream>

int main() {
    Todo todo;
    todo.loadFromFile("data/tasks.txt");

    int choice;
    do {
        std::cout << "\n1. Add Task\n2. Remove Task\n3. Mark Task as Completed\n4. Display Tasks\n5. Save and Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cin.ignore();
            std::string title;
            std::cout << "Enter task title: ";
            std::getline(std::cin, title);
            todo.addTask(title);
            break;
        }
        case 2: {
            int id;
            std::cout << "Enter task ID to remove: ";
            std::cin >> id;
            todo.removeTask(id);
            break;
        }
        case 3: {
            int id;
            std::cout << "Enter task ID to mark as completed: ";
            std::cin >> id;
            todo.markTaskCompleted(id);
            break;
        }
        case 4:
            todo.displayTasks();
            break;
        case 5:
            todo.saveToFile("data/tasks.txt");
            std::cout << "Tasks saved. Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
