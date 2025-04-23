#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <vector>  

using namespace std;

template <typename T>
class Queue {
public:
    void addNumbers(queue<T>& q);
    void display_queue(queue<T> q);
    void move_to_rear(queue<T>& q);
    int linear_search_last(const vector<T>& items, const T& target, size_t pos_first);
    void insertion_sort(queue<T>& q);
};
