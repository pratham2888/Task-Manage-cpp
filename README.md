# 📌 C++ Task Manager  

A simple **task management system** built using **C++**, allowing users to **add, edit, delete, and view tasks**. The program stores tasks in a file (`tasks.txt`) for persistence.

---

## 🔹 Features
✔ **Add Tasks** - Store task descriptions and deadlines.  
✔ **Edit Tasks** - Modify existing tasks.  
✔ **Delete Tasks** - Remove tasks by ID.  
✔ **View Tasks** - Display all saved tasks.  
✔ **File-Based Storage** - Tasks persist even after closing the program.  

---

## ⚠️ Character Encoding Issue  
🔹 In some terminals, **special characters may appear as symbols (e.g., `Üá∩╕Å` instead of normal text).**  
🔹 This issue occurs due to **terminal encoding differences**.  
🔹 To fix this:  
   - Use **plain text mode** (no Unicode symbols).  
   - Change the encoding to **UTF-8** before execution.  

### **✅ How to Fix Encoding (Command Prompt)**
1️⃣ Open **Command Prompt (cmd)**  
2️⃣ Run the following command before executing:  
   ```sh
   chcp 65001
✔ This sets the encoding to UTF-8, fixing symbol issues.

🚀 How to Compile and Run the Project (Using cmd)
📌 Step 1: Open Command Prompt
1️⃣ Press Win + R, type cmd, and hit Enter.
2️⃣ Navigate to your project folder:


Copy
Edit
cd C:\Users\YourName\Desktop\Task-Manager
📌 Step 2: Compile the C++ Code
Run the following command:


Copy
Edit
g++ task_manager.cpp -o task_manager -std=c++11
✔ This compiles your C++ Task Manager and creates an executable file.

📌 Step 3: Run the Task Manager
Run the compiled program:


Copy
Edit
task_manager.exe
✔ Now, you can start managing tasks! 🎉

📝 Example Usage
markdown
Copy
Edit
Task Manager
1. View Tasks
2. Add Task
3. Edit Task
4. Delete Task
5. Exit
Enter your choice: 2
Enter task description: Complete my C++ project
Enter task deadline (YYYY-MM-DD): 2025-03-20
Task added successfully!

Task Manager
1. View Tasks
2. Add Task
3. Edit Task
4. Delete Task
5. Exit
Enter your choice: 1

Task List:
ID: 1
Description: Complete my C++ project
Deadline: 2025-03-20
------------------
🔧 Possible Issues & Fixes
Issue	Solution
Special characters (e.g., Üá∩╕Å) appear instead of normal text	Run chcp 65001 before executing the program.
g++ is not recognized error	Install MinGW-w64 and add it to the system PATH.
fatal: 'origin' does not appear to be a git repository	Re-add the correct GitHub remote using git remote add origin <repo_url>.
🛠 Technologies Used
C++ (Standard Library)
File Handling (fstream)
Data Storage (vector)
Command Line Execution (cmd)
💖 Contributing
Contributions are welcome! Feel free to fork this repository, submit a pull request, or suggest new features.

🔗 GitHub Repository: https://github.com/pratham2888/Task-Manager-Cpp

📜 License
This project is open-source and available under the MIT License.