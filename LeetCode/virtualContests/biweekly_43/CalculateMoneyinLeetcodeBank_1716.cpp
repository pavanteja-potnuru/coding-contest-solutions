#include <bits/stdc++.h>
using namespace std;

/**
 * 1716. Calculate Money in Leetcode Bank
 * Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
 * He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
 * Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.
 * 
 * 
 * Input: n = 4
 * Output: 10
 * Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
 */
class Solution {
public:
    int totalMoney(int n) {
        int x = n/7;
        int y = n%7;
        
        // following is the equation for totalMoney given x and y
        return (28*x)+((7*x*(x-1))/2)+(x*y)+((y*(y+1))/2);
    }
};
int main() {
    Solution sol;
    vector<int> input = {4, 10, 20};
    for(int a: input) {
        cout<<sol.totalMoney(a)<<endl;
    }
    return 0;
}
