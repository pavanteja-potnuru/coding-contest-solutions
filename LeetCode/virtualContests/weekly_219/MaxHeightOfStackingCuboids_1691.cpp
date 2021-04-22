#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> vvi;
/**
 * Step1: First sort each cuboid array to make width<=length<=height
 * Step2: Sort all cuboids based on width -> length -> height order. (i.e If width is same, sort based on length. If length is also same sort based on height)
 * Step3: Create array `sol` which stores solution by maximising height with cuboids[i] included.
 * Step3: Iterate from left to right and on each step find already visited index which maximises the sum of heights with give condition
 * i.e for index i, find j such that cuboid[i].height + sol[j] is maximum when cuboid[j] fits in cuboid[i].
 */

class Solution {
public:
    int maxHeight(vvi& cuboids) {
        for( vector<int> &cuboid: cuboids ) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int> lastCuboid= cuboids[0];
        int n = cuboids.size();
        // max stack height with base cuboid as index i
        vector<int> msh_wt_base(n, 0); // for index i, sol stores maxHeight of cuboid stack possible considering cuboids[i] is the bottom most of cuboid stack.  
        msh_wt_base[0] = cuboids[0][2];
        int maxStackHeight = msh_wt_base[0];
        for(int i=1;i<n;i++) {
            msh_wt_base[i] = cuboids[i][2];
            int j = i-1;
            // find index j such that cuboids[j] is the second bottom most cuboid in the stack which maximises height of stack with cuboid[i] as bottom most cuboid.
            while (j>=0) {
                if(cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]){
                    if(msh_wt_base[i] < cuboids[i][2] + msh_wt_base[j]) {
                        msh_wt_base[i] = cuboids[i][2] + msh_wt_base[j];
                    }
                }
                j--;
            }
            maxStackHeight = max(msh_wt_base[i], maxStackHeight);
        }
        
        return maxStackHeight;
    }
};


int main() {
    Solution sol;
    vector<vvi> input = {
        {{50,45,20},{95,37,53},{45,23,12}},
        {{38,25,45},{76,35,3}},
        {{7,11,17}, {7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}}
    };
    for(vvi &item: input) {
        cout<<sol.maxHeight(item)<<endl;
    }
/*
Output:
    190
    76
    102
*/
    return 0;
}