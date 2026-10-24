#include "../include/todo.h"

#include <cstdlib>
#include <iostream>
#include <limits>

namespace {
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void printHeader() {
    std::cout << "\n\033[1;36m========================================\033[0m\n";
    std::cout << "\033[1;35m     MODERN TO-DO LIST\033[0m\n";
    std::cout << "\033[1;36m========================================\033[0m\n";
}

void printMenu() {
    std::cout << "\n\033[1;33mChoose an option:\033[0m\n";
    std::cout << "\033[32m1.\033[0m Add Task\n";
    std::cout << "\033[32m2.\033[0m Remove Task\n";
    std::cout << "\033[32m3.\033[0m Mark Task as Completed\n";
    std::cout << "\033[32m4.\033[0m View Tasks\n";
    std::cout << "\033[32m5.\033[0m Save and Exit\n";
    std::cout << "\033[1;34mEnter your choice: \033[0m";
}

void waitForKey() {
    std::cout << "\n\033[1;37mPress Enter to continue...\033[0m";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
} // namespace

int main() {
    Todo todo;
    todo.loadFromFile("data/tasks.txt");

    int choice = 0;
    while (true) {
        clearScreen();
        printHeader();
        printMenu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\033[1;31mInvalid input. Please enter a valid number.\033[0m\n";
            waitForKey();
            continue;
        }

        switch (choice) {
            case 1: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string title;
                std::cout << "\n\033[1;34mEnter task title: \033[0m";
                std::getline(std::cin, title);

                if (title.empty()) {
                    std::cout << "\n\033[1;31mTask title cannot be empty.\033[0m\n";
                    waitForKey();
                    break;
                }

                todo.addTask(title);
                std::cout << "\n\033[1;32mTask added successfully.\033[0m\n";
                waitForKey();
                break;
            }
            case 2: {
                int id = 0;
                std::cout << "\n\033[1;34mEnter task ID to remove: \033[0m";
                std::cin >> id;
                todo.removeTask(id);
                std::cout << "\n\033[1;32mTask removal processed.\033[0m\n";
                waitForKey();
                break;
            }
            case 3: {
                int id = 0;
                std::cout << "\n\033[1;34mEnter task ID to mark as completed: \033[0m";
                std::cin >> id;
                todo.markTaskCompleted(id);
                std::cout << "\n\033[1;32mTask status updated.\033[0m\n";
                waitForKey();
                break;
            }
            case 4:
                std::cout << "\n\033[1;33mYour Tasks:\033[0m\n";
                todo.displayTasks();
                waitForKey();
                break;
            case 5:
                todo.saveToFile("data/tasks.txt");
                std::cout << "\n\033[1;32mTasks saved successfully. Exiting...\033[0m\n";
                return 0;
            default:
                std::cout << "\n\033[1;31mInvalid choice. Please try again.\033[0m\n";
                waitForKey();
                break;
        }
    }
}
