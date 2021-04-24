#include <bits/stdc++.h>
using namespace std;
/**
 * You are given a string s and two integers x and y. You can perform two types of operations any number of times.
 * Remove substring "ab" and gain x points.
 * For example, when removing "ab" from "cabxbae" it becomes "cxbae".
 * Remove substring "ba" and gain y points.
 * For example, when removing "ba" from "cabxbae" it becomes "cabxe".
 * Return the maximum points you can gain after applying the above operations on s.
 * 
 * Input: s = "cdbcbbaaabab", x = 4, y = 5
 * Output: 19
 * 
 * Input: s = "aabbaaxybbaabb", x = 5, y = 4
 * Output: 20
 */
class Solution {
public:
    int countOnRemove(string &s, string a, int x) {
        int count=0;
        int i=0;
        // Instead of removing elements from string (which increases time complexity)
        // using two pointer technique where `i` maintains last index of string after remove operation on s,
        // and j just iterates from left to right on string s 
        for(int j=0;j<s.length();j++) {
            s[i++] = s[j];
            if (i > 1 && s[i - 2] == a[0] && s[i - 1] == a[1]) i -= 2, count += x;
        }
        s.resize(i);
        return count;
    }
    /**
     * Clear all substrings "ab" or "ba, which has max value
     * Observation: if you remove one of the type(eg: "ab"), you will never see them when you are removing the other substring(in this case "ba", since "ab" is selected first)
     * 
     * Proof by contradiction:
     * step1: lets say you removed all "ab" one by one
     * step2: you start removing "ba" and you see "ab" combination formed.
     *        So the string before doing step2 is "a`ba`b"(contains 2 "ab").
     *        Which contradicts our first step where all "ab" are beings removed.
     */
    int maximumGain(string s, int x, int y) {
        string a= "ab", b = "ba";
        if(x<y) swap(a, b), swap(x, y);
        
        return countOnRemove(s, a, x)+countOnRemove(s, b, y);
    }
};
int main() {
    Solution sol;
    cout<<sol.maximumGain("cdbcbbaaabab", 4, 5)<<endl;
    cout<<sol.maximumGain("aabbaaxybbaabb", 5, 4)<<endl;
    return 0;
}
