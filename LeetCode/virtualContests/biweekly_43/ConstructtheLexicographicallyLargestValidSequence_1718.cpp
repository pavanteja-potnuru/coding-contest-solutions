/**
 * 1718. Construct the Lexicographically Largest Valid Sequence
 * Given an integer n, find a sequence that satisfies all of the following:
 * The integer 1 occurs once in the sequence.
 * Each integer between 2 and n occurs twice in the sequence.
 * For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
 * The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
 * 
 * Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
 * 
 * A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.
 * 
 * 
 * Input: n = 3
 * Output: [3,1,2,3,2]
 * 
 * Input: n = 5
 * Output: [5,3,1,4,3,5,2,4,2]
 */


#include <bits/stdc++.h>
using namespace std;

template <class T>
using v = vector<T>;

class Solution
{
public:
    v<int> constructDistancedSequence(int n)
    {
        v<int> sol((2 * n) - 1, 0);
        v<bool> visited(n, false);
        backTrackCDS(sol, visited, 0);
        return sol;
    }

    bool backTrackCDS(v<int> &sol, v<bool> &visited, int index)
    {
        while(index < sol.size() && sol[index] != 0) index++;
        if (index == sol.size())
        {
            return true;
        }
        int m = visited.size();
        for (int i = m; i>=1; i--)
        {
            if (!visited[i-1] && sol[index] == 0 && (i==1 || (index+i<sol.size() && sol[index + i] == 0)))
            {
                if(i == 1) sol[index] = 1;
                else sol[index] = sol[index + i] = i;
                visited[i-1] = true;
                if (backTrackCDS(sol, visited, index+1))
                {
                    return true;
                }
                visited[i-1] = false;
                if(i == 1) sol[index] = 0;
                else sol[index] = sol[index + i] = 0;
            }
        }

        return false;
    }
};
int main()
{
    Solution sol;
    v<int> input = {3, 4, 5};
    for (int item : input)
    {
        v<int> solArr = sol.constructDistancedSequence(item);
        for (int a : solArr)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
