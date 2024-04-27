#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the maximum score using recursion with memoization
int dfs(vector<int>& dice, int index, int flipsLeft, vector<vector<int>>& memo) {
    // If we've processed all dice or used all flips, return 0
    if (index >= dice.size() || flipsLeft == 0)
        return 0;

    // If the result for this state is already calculated, return it from memo
    if (memo[index][flipsLeft] != -1)
        return memo[index][flipsLeft];

    // Calculate the score without flipping the current die
    int scoreWithoutFlip = dice[index] + dfs(dice, index + 1, flipsLeft, memo);

    // Calculate the score by flipping the current die
    int flip = (7-dice[index]) + dfs(dice,index+1,flipsLeft-1,memo);

    // Choose the maximum score between flipping and not flipping the current die
    int maxScore = max(scoreWithoutFlip, flip);

    // Memoize the result for this state
    return memo[index][flipsLeft] = maxScore;
}

// Function to solve the problem
int maxScore(vector<int>& dice, int flipsLeft) {
    // Initialize memoization table with -1
    vector<vector<int>> memo(dice.size() + 1, vector<int>(flipsLeft + 1, -1));
    return dfs(dice, 0, flipsLeft, memo);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int numDice, flips;
        cin >> numDice >> flips;
        vector<int> dice(numDice);
        for (int j = 0; j < numDice; j++) {
            cin >> dice[j];
        }
        cout << maxScore(dice, flips) << endl;
    }
    return 0;
}