#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

class ToDoListManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask{description, false};
        tasks.push_back(newTask);
        cout << "Task added successfully!\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
            return;
        }

        cout << "\nTo-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    }

    void removeTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!\n";
    }
};

int main() {
    ToDoListManager manager;
    int choice;

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(); // Clear the input buffer
            string description;
            cout << "Enter task description: ";
            getline(cin, description);
            manager.addTask(description);
            break;
        }
        case 2:
            manager.viewTasks();
            break;
        case 3: {
            size_t taskNumber;
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            manager.markTaskAsCompleted(taskNumber);
            break;
        }
        case 4: {
            size_t taskNumber;
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            manager.removeTask(taskNumber);
            break;
        }
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
