//#include <iostream>
//#include <vector>
//#include<string>
//#include <fstream>
//#include <algorithm>
//
//using namespace std;
//
//struct Task
//{
//    string desc;
//    string priority; // High, Medium, Low
//    bool done;
//};
//
//vector<Task> loadTasks()
//{
//    vector<Task> tasks;
//    ifstream file("todo.txt");
//    string desc, priority;
//    bool done;
//
//    while (getline(file, desc))
//    {
//        getline(file, priority);
//        file >> done;
//        file.ignore();
//        tasks.push_back({ desc, priority, done });
//    }
//
//    file.close();
//    return tasks;
//}
//
//void saveTasks(const vector<Task>& tasks)
//{
//    ofstream file("todo.txt");
//    for (auto& task : tasks)
//    {
//        file << task.desc << '\n';
//        file << task.priority << '\n';
//        file << task.done << '\n';
//    }
//    file.close();
//}
//
//bool prioritySort(const Task& a, const Task& b)
//{
//    auto val = [](string p)
//        {
//            if (p == "High") return 3;
//            if (p == "Medium") return 2;
//            return 1;
//        };
//    return val(a.priority) > val(b.priority);
//}
//
//void viewTasks(vector<Task> tasks)
//{
//    sort(tasks.begin(), tasks.end(), prioritySort);
//    cout << "\n----- TO-DO LIST -----\n";
//    int idx = 1;
//    for (auto& t : tasks)
//    {
//        cout << idx++ << ". [" << (t.done ? 'X' : ' ') << "] "
//            << t.desc << " (" << t.priority << ")\n";
//    }
//    cout << endl;
//}
//
//void addTask(vector<Task>& tasks)
//{
//    string desc, priority;
//    cin.ignore();
//    cout << "Task: ";
//    getline(cin, desc);
//    cout << "Priority (High/Medium/Low): ";
//    getline(cin, priority);
//    tasks.push_back({ desc, priority, false });
//    cout << "Added.\n";
//}
//
//void markDone(vector<Task>& tasks)
//{
//    viewTasks(tasks);
//    int n;
//    cout << "Task # to mark done: ";
//    cin >> n;
//    if (n >= 1 && n <= tasks.size())
//    {
//        tasks[n - 1].done = true;
//        cout << "Marked as done.\n";
//    }
//    else
//    {
//        cout << "Invalid task number.\n";
//    }
//}
//
//void deleteTask(vector<Task>& tasks)
//{
//    viewTasks(tasks);
//    int n;
//    cout << "Task # to delete: ";
//    cin >> n;
//    if (n >= 1 && n <= tasks.size())
//    {
//        tasks.erase(tasks.begin() + (n - 1));
//        cout << "Deleted.\n";
//    }
//    else
//    {
//        cout << "Invalid task number.\n";
//    }
//}
//
//int main()
//{
//    vector<Task> tasks = loadTasks();
//    int choice;
//
//    while (true)
//    {
//        cout << endl << "=== MENU ===" << endl;
//        cout << "1. View Tasks" << endl;
//        cout << "2. Add Task" << endl;
//        cout << "3. Mark as Done" << endl;
//        cout << "4. Delete Task" << endl;
//        cout << "5. Exit" << endl;
//        cout << "Choose: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//            case 1:
//                viewTasks(tasks);
//                break;
//            case 2:
//                addTask(tasks);
//                saveTasks(tasks);
//                break;
//            case 3:
//                markDone(tasks);
//                saveTasks(tasks);
//                break;
//            case 4:
//                deleteTask(tasks);
//                saveTasks(tasks);
//                break;
//            case 5:
//                cout << "Exiting..." << endl;
//                return 0;
//            default:
//                cout << "Invalid choice." << endl;
//        }
//    }
//}
