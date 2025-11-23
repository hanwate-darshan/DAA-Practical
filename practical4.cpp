//Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch andbound strategy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0-1 Knapsack problem
int knapsack_01(int W, vector<int> wt, vector<int> val, int n) {
    // Create a DP table (n+1) x (W+1)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Print result
    cout << "Maximum Value in Knapsack = " << dp[n][W] << endl;

    return dp[n][W];
}

// Main function
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();

    knapsack_01(W, wt, val, n);

    return 0;
}


// cd Desktop

// touch hello.cpp  or gedit hello.cpp
// g++ hello.cpp
// ./a.out
