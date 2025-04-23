#include "Queue.h"
#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

template <typename T>
void Queue<T>::addNumbers(queue<T>& q) {
    cout << "Please Enter 10 numbers:" << endl;
    for (int i = 0; i < 10; i++) {
        T value;
        bool valid = false;

        while (!valid) {
            cout << "Enter number " << (i + 1) << ": ";
            cin >> value;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number: ";
            }
            else {
                q.push(value);
                valid = true;
            }
        }
    }
}

template <typename T>
void Queue<T>::display_queue(queue<T> q) {
    cout << "Queue contents: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

template <typename T>
void Queue<T>::move_to_rear(queue<T>& q) {
    if (!q.empty()) {
        T front_value = q.front();
        q.pop();
        q.push(front_value);
        cout << "Front value " << front_value << " has been moved to rear" << endl;
    }
    else {
        cout << "Queue is empty" << endl;
    }
}

template <typename T>
int Queue<T>::linear_search_last(const vector<T>& items, const T& target, size_t pos_first) {
    if (pos_first == items.size())
        return -1;

    int result = linear_search_last(items, target, pos_first + 1);

    if (result != -1)
        return result;

    if (items[pos_first] == target)
        return pos_first;

    return -1;
}

template <typename T>
void Queue<T>::insertion_sort(queue<T>& q) {
    vector<T> vec;

    // Move all elements from queue to vector
    while (!q.empty()) {
        vec.push_back(q.front());
        q.pop();
    }

    // Insertion sort on the vector
    int i, j;
    T key;
    bool insertionNeeded = false;
    for (j = 1; j < vec.size(); j++) {
        key = vec[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--) {
            if (key < vec[i]) {
                vec[i + 1] = vec[i]; // shift right
                insertionNeeded = true;
            }
            else {
                break;
            }
        }
        if (insertionNeeded)
            vec[i + 1] = key;
    }

    // Push sorted elements back to queue
    for (T val : vec) {
        q.push(val);
    }
}

// Explicit instantiation
template class Queue<int>;
