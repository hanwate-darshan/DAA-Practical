//Practical 3: Write a program to solve a fractional Knapsack problem using a greedy method.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 4; // Number of items
    int weight[] = {10, 40, 20, 30};
    int value[] = {60, 40, 100, 120};
    int capacity = 50;

    double ratio[n];
    for (int i = 0; i < n; i++)
        ratio[i] = (double)value[i] / weight[i];

    // Sort items based on ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(value[i], value[j]);
            }
        }
    }

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (weight[i] <= capacity) {
            capacity -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += ratio[i] * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum value in Knapsack = " << totalValue << endl;

    return 0;
}

// cd Desktop
// touch hello.cpp or gedit hello.cpp
// g++ hello.cpp
// ./a.out
