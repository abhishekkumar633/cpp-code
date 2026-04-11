#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(vector<int>& nums) {
    if (nums.empty()) return 0;

    vector<int> dp(nums.size(), 1); // dp[i] will hold the length of the LIS ending at index i
    int maxLength = 1;

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

// Function to find the longest common subsequence between two strings
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

// Function to find the longest palindromic subsequence
int longestPalindromicSubsequence(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Every single character is a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Fill the table for substrings of length 2 and more
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && length == 2) {
                dp[i][j] = 2;
            } else if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    // Test Longest Increasing Subsequence
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << longestIncreasingSubsequence(nums) << endl;
    
    // Test Longest Common Subsequence
    string text1 = "abcde";
    string text2 = "ace";
    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequence(text1, text2) << endl;
    
    // Test Longest Palindromic Subsequence
    string s = "bbbab";
    cout << "Length of Longest Palindromic Subsequence: " << longestPalindromicSubsequence(s) << endl;
    
    return 0;
}
