#include <iostream>
#include <string>
using namespace std;

/**
 * You are given a phone number as a string number. number consists of digits, spaces ' ', and/or dashes '-'.
 * You would like to reformat the phone number in a certain manner. Firstly, remove all spaces and dashes. Then, group the digits from left to right into blocks of length 3 until there are 4 or fewer digits. The final digits are then grouped as follows:
 * 2 digits: A single block of length 2.
 * 3 digits: A single block of length 3.
 * 4 digits: Two blocks of length 2 each.
 * 
 * Input: number = "1-23-45 6"
 * Output: "123-456"
 * 
 * Input: number = "123 4-5678"
 * Output: "123-456-78"
 */

class Solution {
public:
    string reformatNumber(string number) {
        string sol;
        int count = 0;
        for(char c: number) {
            if(c!= ' ' && c!= '-') {
                sol.push_back(c);
                count++;
            }
            if(count == 3) {
                sol.push_back('-');
                count = 0;
            }
        }
        if(sol.back() == '-') sol.pop_back();
        if(count == 1)
        {
            int n = sol.size();
            swap(sol[n-2], sol[n-3]);
        }
            
        return sol;
    }
};

int main() {
    Solution s;
    string input[] = {
        "1-23-45 6",
        "--17-5 229 35-39475 ",
        "12",
        "123 4-5678",
        "123 4-567"
    };

    for(int i=0;i<sizeof(input);i++) {
        cout<<s.reformatNumber(input[i])<<endl;
    }

}