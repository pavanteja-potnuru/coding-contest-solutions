#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 1702. Maximum Binary String After Change
 * You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:
 * Operation 1: If the number contains the substring "00", you can replace it with "10".
 * For example, "00010" -> "10010"
 * Operation 2: If the number contains the substring "10", you can replace it with "01".
 * For example, "00010" -> "00001"
 * Return the maximum binary string you can obtain after any number of operations. Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.
 */

class Solution {
public:
    string maximumBinaryString(string binary) {
        int b_size = binary.length();
        int last0Index = -1;
        for(int i=0;i<b_size;i++) {
            if(binary[i] == '0') {
                if(last0Index >= 0) {
                    // Recursively convert from /01*0/ to /101*/ to maximise the value of binary string. and the conversion maintain string length same
                    binary[last0Index] = '1'; 
                    binary[i] = '1';
                    binary[last0Index+1] = '0';
                    last0Index++;
                }
                else last0Index = i;
            }
        }
        return binary;
    }
};

int main() {
    Solution sol;

    vector<string> input = {
        "000110",
        "10"
    };
    for(string &s: input) {
        cout<<sol.maximumBinaryString(s)<<endl;
    }
    return 0;
}
