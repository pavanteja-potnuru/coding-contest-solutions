/**
 * Problem statement
 * https://leetcode.com/problems/stone-game-vi
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<int> indices(aliceValues.size(), 0);
        for(int j=0;j<aliceValues.size();j++) {
            indices[j] = j;
        }
        sort(indices.begin(), indices.end(), [&](int i, int j) {
                return aliceValues[i]+bobValues[i]>aliceValues[j]+bobValues[j];
        });

        int aliceScore = 0, bobScore = 0;
        for(int i=0;i<indices.size();i+=2) {
            aliceScore += aliceValues[indices[i]];
            if(i+1<indices.size()) bobScore += bobValues[indices[i+1]];
        }

        return aliceScore == bobScore? 0 : (aliceScore>bobScore? 1: -1);
    }
};
int main() {
    Solution sol;
    vector<int> a = {5,6,1,9,4,7,1,7,3,7,9,7,1,2,3,9,4,7,6}; //
    vector<int> b = {1,2,3,5,2,8,5,9,1,6,4,2,10,4,8,1,10,5,6}; //
    cout<<sol.stoneGameVI(a, b)<<endl;
    return 0;
}
