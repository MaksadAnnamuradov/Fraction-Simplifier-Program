#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/**
 * Task structure
 */
struct Task {
	bool done = false;
	string description;
	int priority;
};

/**
 * function to print all tasks
 * @param const Task tasks array
 * @param int n size of tasks
 */
void printList(const Task tasks[], int n) {
	cout << "ROW       " << "TASK" << endl;
	for (int i = 0; i < n; ++i)
	{
		if (tasks[i].description != "" && !tasks[i].done)
		{
			cout << i;
			cout << "         ";
			cout << "[" << tasks[i].priority << "]";
			cout << tasks[i].description << endl;
		}
	}
}

/**
 * compares two different tasks
 * @param const Task a
 * @param const Task b
 * 
 * @return boolean
 */
bool isLessThan(const Task& a, const Task& b) {
   // first try to arrange based on difference in "done" field
   // if only one of the two tasks is done, then a should come first if it has not been done yet
   // if a.done != b.done, then return !a.done
	if (a.done != b.done)
	{
		return !a.done;
	}

   // next, try to arrange based on priority
   // if a.priority != b.priority, then return a.priority > b.priority
   if (a.priority != b.priority)
   {
   		return a.priority > b.priority;
   }

   // if they have the same done status and the same priority, then just arrange by description
   return a.description < b.description;
}

/**
 * swaps two tasks
 * @param Task a
 * @param Task b
 */
void swap(Task& a, Task& b) {
	Task temp = a;
	a = b;
	b = temp;
}

/**
 * sorts the tasks
 * @param Task array
 * @param int n size of tasks
 */
void sort(Task a[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isLessThan(a[j], a[i])) {
                swap(a[i], a[j]);
            }
        }
    }
}

/**
 * Creates Task
 * @param string description Description for Task
 * @param int priority Priority for Task
 * 
 * @return Task
 */
Task createTask(string description, int priority) {
	Task task;
	task.description = description;
	task.priority = priority;

	return task;
}

/**
 * Task Application
 */
int main() {
	Task tasks[10];
	char c;

	while(true) {
		sort(tasks, 10);
		printList(tasks, 10);
		cout << "Please enter -<row>, +<description>, or x (to exit): ";
		cin >> c;
		if (c == '-')
		{
			int row;
			cin >> row;
			tasks[row].done = true;
		} else if (c == '+') {
			string description;
			getline(cin, description);
			int priority;
			cout << "Priority: ";
			cin >> priority;
			tasks[9] = createTask(description, priority);
		} else if (c == 'x') {
			exit(0);
		}
	}
}