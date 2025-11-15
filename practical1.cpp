//Practical 1: Write a program to calculate Fibonacci numbers and find its step count.

#include <iostream>
using namespace std;

void fibonacci(int n) {
    int a = 0, b = 1, c;
    int steps = 0;

    cout << a << " " << b << " ";

    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        cout << c << " ";
        steps++;
    }

    cout << "\nStep Count: " << steps << endl;
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    fibonacci(n);

    return 0;
}
// cd Desktop
// touch hello.cpp or gedit hello.cpp
// g++ hello.cpp
// ./a.out
