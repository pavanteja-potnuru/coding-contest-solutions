/**
 * Problem statement
 * https://leetcode.com/contest/biweekly-contest-41/problems/delivering-boxes-from-storage-to-ports/
 */


#include <bits/stdc++.h>
using namespace std;

template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ldiff(n, 0);
        vector<int> rdiff(n, 0);
        for(int i=1;i<n;i++) {
            ldiff[i] = (i*(nums[i]-nums[i-1]))+ ldiff[i-1];
        }
        for(int i=n-2;i>=0;i--) {
            rdiff[i] = ((n-1-i)*(nums[i+1]-nums[i]))+ rdiff[i+1];
        }
        vector<int> sol;
        for(int i=0;i<n;i++) {
            sol.push_back(ldiff[i]+rdiff[i]);
        }
        return sol;
    }
};
int main() {
    Solution sol;
    vv<int> input = {
        {2,3,5}, // [4,3,5]
        {1,4,6,8,10}, // [24,15,13,15,21]
    };
    for(auto arr: input) {
        auto outputArr = sol.getSumAbsoluteDifferences(arr);
        for(auto output: outputArr)
            cout<<output<<" ";
        cout<<endl;
    }
    
    return 0;
}

