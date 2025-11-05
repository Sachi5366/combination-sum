#include <iostream>
#include <vector>
using namespace std;

// Function to perform backtracking
void combinationSumHelper(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(current); // Found a valid combination
        return;
    }
    if (target < 0) return; // Exceeded the target

    for (int i = start; i < candidates.size(); i++) {
        current.push_back(candidates[i]); // Include current number
        // Recur with the same index i because we can reuse the same element
        combinationSumHelper(candidates, target - candidates[i], current, result, i);
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    combinationSumHelper(candidates, target, current, result, 0);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations summing to " << target << " are:" << endl;
    for (auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
