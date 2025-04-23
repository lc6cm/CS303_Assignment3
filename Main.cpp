#include "Queue.h"


int main() {
    queue<int> q;
    Queue<int> myQueue;

    myQueue.addNumbers(q);

    bool running = true;
    while (running) {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Display Queue" << endl;
        cout << "2. Move Front to Rear" << endl;
        cout << "3. Search for Last Occurrence of a Number" << endl;
        cout << "4. Sort queue" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Input validation
        while (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            myQueue.display_queue(q);
            break;
        case 2:
            myQueue.move_to_rear(q);
            break;
        case 3: {
            queue<int> copy = q;
            vector<int> vec;
            while (!copy.empty()) {
                vec.push_back(copy.front());
                copy.pop();
            }

            int target;
            cout << "What is your target number?" << endl;
            cin >> target;

            int index = myQueue.linear_search_last(vec, target, 0);

            if (index != -1)
                cout << "Last occurrence found at index: " << index << endl;
            else
                cout << "Target not found." << endl;
            break;
        }
        case 4:
            myQueue.insertion_sort(q);  // Ensure the queue is sorted correctly
            cout << "Queue has been sorted" << endl;
            break;
        case 5:
            cout << "Exiting program." << endl;
            running = false;
            break;
        }
    }

    return 0;
}
