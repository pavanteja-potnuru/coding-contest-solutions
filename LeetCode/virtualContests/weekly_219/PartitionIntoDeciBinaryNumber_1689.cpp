#include <iostream>
#include <string>
using namespace std;

/**
 * A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
 * Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.
 * 
 * Input: n = "32"
 * Output: 3
 * Explanation: 10 + 11 + 11 = 32
 * 
 * Input: n = "27346209830709182346"
 * Output: 9
 */

class Solution {
public:
    /**
     * Solution is to find the maximum digit in given number in string format
     */
    int minPartitions(string n) {
        char maxDigit = '0';
        for(char c: n) {
            if(c>='1'&& c<='9') {
                maxDigit = max(c, maxDigit);
            }
        }
        return maxDigit-'0';
    }
};

int main() {
    Solution sol;
    string input[] = {
        "32",
        "82734",
        "27346209830709182346"
    };

    for(string s: input) {
        cout<<sol.minPartitions(s)<<endl;
    }

}