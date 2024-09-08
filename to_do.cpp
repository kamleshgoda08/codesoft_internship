#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    string description;
    cout << "Enter the task description: ";
    cin.ignore();  
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
        }
    }
}

void markTaskCompleted() {
    int taskNumber;
    viewTasks();
    if (!tasks.empty()) {
        cout << "Enter the task number to mark as completed: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

void removeTask() {
    int taskNumber;
    viewTasks();
    if (!tasks.empty()) {
        cout << "Enter the task number to remove: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

void showMenu() {
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;  
    }

    return 0;
}
