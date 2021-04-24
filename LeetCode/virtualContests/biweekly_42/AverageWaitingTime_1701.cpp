#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
using vv = vector<vector<T>>;
template <class T>
using v = vector<T>;

/**
 * 1701. Average Waiting Time
 * There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:
 * 
 * arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
 * timei is the time needed to prepare the order of the ith customer.
 * When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.
 * 
 * Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.
 * 
 * Input: customers = [[1,2],[2,5],[4,3]]
 * Output: 5.00000
 * 
 * Input: customers = [[5,2],[5,4],[10,3],[20,1]]
 * Output: 3.25000
 * 
 * Constraints:
 * 1 <= customers.length <= 105
 * 1 <= arrivali, timei <= 104
 * arrivali <= arrivali+1
 */

class Solution {
public:
    double averageWaitingTime(vv<int>& customers) {
        long totalWaitTime = 0; // total wait time
        long prevOrderEndTime = 0; // time at which order by last customer ended
        for(v<int> &customer: customers) {
            totalWaitTime += max(prevOrderEndTime-customer[0], (long)0)+customer[1];
            prevOrderEndTime = max(prevOrderEndTime, (long)customer[0]) + customer[1];
        }
        
        return ((double)totalWaitTime)/customers.size();
    }
};

int main() {
    Solution sol;
    v<vv<int>> input = {
        {{1,2},{2,5},{4,3}},
        {{5,2},{5,4},{10,3},{20,1}}
    };

    for(vv<int> a: input) {
        cout<<sol.averageWaitingTime(a)<<endl;
    }
    return 0;
}