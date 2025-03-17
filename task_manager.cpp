#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>  // Needed for remove_if
#include <limits>     // Needed for numeric_limits

using namespace std;

// Task structure
struct Task {
    int id;
    string description;
    string deadline;
};

// Function to load tasks from file
vector<Task> loadTasks(const string& filename) {
    vector<Task> tasks;
    ifstream file(filename);

    if (!file) {
        cerr << "Warning: No task file found. A new one will be created.\n";
        return tasks;
    }

    Task task;
    while (file >> task.id) {
        file.ignore();  // Ignore newline after ID
        getline(file, task.description);
        getline(file, task.deadline);
        tasks.push_back(task);
    }

    file.close();
    return tasks;
}

// Function to save tasks to file
void saveTasks(const string& filename, const vector<Task>& tasks) {
    ofstream file(filename);
    
    if (!file) {
        cerr << "Error: Unable to save tasks!\n";
        return;
    }

    for (const auto& task : tasks) {
        file << task.id << endl;
        file << task.description << endl;
        file << task.deadline << endl;
    }

    file.close();
}

// Function to display tasks
void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found!\n";
        return;
    }

    cout << "\nTask List:\n";
    for (const auto& task : tasks) {
        cout << "ID: " << task.id << "\nDescription: " << task.description
             << "\nDeadline: " << task.deadline << "\n------------------\n";
    }
}

// Function to add a new task
void addTask(vector<Task>& tasks, const string& filename) {
    Task newTask;
    newTask.id = tasks.empty() ? 1 : tasks.back().id + 1;

    cin.ignore();  // Clear input buffer
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    cout << "Enter task deadline (YYYY-MM-DD): ";
    getline(cin, newTask.deadline);

    tasks.push_back(newTask);
    saveTasks(filename, tasks);

    cout << "Task added successfully!\n";
}

// Function to delete a task
void deleteTask(vector<Task>& tasks, const string& filename) {
    int id;
    cout << "Enter Task ID to delete: ";
    
    if (!(cin >> id)) {  // Handle invalid input
        cout << "Invalid input! Please enter a valid ID.\n";
        cin.clear();  // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore incorrect input
        return;
    }

    auto it = remove_if(tasks.begin(), tasks.end(), [&](const Task& t) { return t.id == id; });

    if (it == tasks.end()) {
        cout << "Task ID not found!\n";
    } else {
        tasks.erase(it, tasks.end());
        saveTasks(filename, tasks);
        cout << "Task deleted successfully!\n";
    }
}

// Function to edit a task
void editTask(vector<Task>& tasks, const string& filename) {
    int id;
    cout << "Enter Task ID to edit: ";
    
    if (!(cin >> id)) {  // Handle invalid input
        cout << "Invalid input! Please enter a valid ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore();  // Clear input buffer before taking new lines

    for (auto& task : tasks) {
        if (task.id == id) {
            cout << "Enter new description: ";
            getline(cin, task.description);
            cout << "Enter new deadline: ";
            getline(cin, task.deadline);
            saveTasks(filename, tasks);
            cout << "Task updated successfully!\n";
            return;
        }
    }

    cout << "Task ID not found!\n";
}

// Main menu function
void menu() {
    string filename = "tasks.txt";
    vector<Task> tasks = loadTasks(filename);
    int choice;

    while (true) {
        cout << "\nTask Manager\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Edit Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {  // Handle invalid menu input
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: displayTasks(tasks); break;
            case 2: addTask(tasks, filename); break;
            case 3: editTask(tasks, filename); break;
            case 4: deleteTask(tasks, filename); break;
            case 5: cout << "Goodbye! See you next time!\n"; return;
            default: cout << "Invalid choice! Please enter 1-5.\n";
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}
