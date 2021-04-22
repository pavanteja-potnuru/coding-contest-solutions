#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

/*
You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.

tasks.length == n
1 <= n <= 105
1 <= enqueueTimei, processingTimei <= 109

Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]

Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
*/
class Solution {
    typedef pair<int, int> T;
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<T, vector<T>, greater<>> pq;
        for(int i=0;i<tasks.size();i++) {
            tasks[i].push_back(i); // insert index to each element
        }
        sort(begin(tasks), end(tasks)); // sort based on enqueueTime and then with processTime and then with index
        vector<int> sol;
        long i = 0, time = 0;
        while(i<tasks.size() || pq.size()) {
            if(pq.empty()) {
                time = max(time, (long)tasks[i][0]);
            }
            while (i < tasks.size() && time >= tasks[i][0]) {
                pq.emplace(tasks[i][1], tasks[i][2]); // pq will give priority to shortest processing time and the index
                ++i;
            }
            auto [pro, index] = pq.top();
            pq.pop();
            time += pro;
            sol.push_back(index);
        }
        return sol;
    }
};

