/* Problem statement
    https://leetcode.com/contest/biweekly-contest-41/problems/count-the-number-of-consistent-strings/
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
template <class T>
using vvv = v<vv<T>>;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> a(allowed.begin(), allowed.end());
        int count = 0;
        for(int i=0;i<words.size();i++) {
            set<char> b(words[i].begin(), words[i].end());
            if(includes(a.begin(),a.end(), b.begin(), b.end())) count++;
        }
        
        return count;
    }
};
int main() {
    Solution sol;
    vvv<string> input = {
        {{"ab"},{"ad","bd","aaab","baa","badab"}}, // 2
        {{"abc"}, {"a","b","c","ab","ac","bc","abc"}}, // 7
        {{"cad"}, {"cc","acd","b","ba","bac","bad","ac","d"}} // 4
    };
    for(auto arr: input) {
        cout<<sol.countConsistentStrings(arr[0][0], arr[1])<<endl;
    }
    
    return 0;
}
