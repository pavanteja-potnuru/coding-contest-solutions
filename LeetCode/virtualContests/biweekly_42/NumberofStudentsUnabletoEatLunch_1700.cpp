#include <iostream>
#include <string>
#include <vector>
using namespace std;

// generic typedefs
template<class T>
using v = vector<T>;
template<class T>
using vv = vector<v<T>>;
template<class T>
using vvv = vector<vv<T>>;
/**
 * 1700. Number of Students Unable to Eat Lunch
 * The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.
 * The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:
 * If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
 * Otherwise, they will leave it and go to the queue's end.
 * This continues until none of the queue students want to take the top sandwich and are thus unable to eat.
 * 
 * You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.
 * 
 * Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
 * Output: 0
 * 
 * Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
 * Output: 3 
 */
class Solution {
public:
    int countStudents(v<int>& students, v<int>& sandwiches) {
        int oneCount=0, zeroCount=0;
        for(int a: students) {
            if(a == 0) zeroCount++;
            else oneCount++;
        } // count total no of ones and zeros
        for(int i=0;i<sandwiches.size();i++) {
            if( sandwiches[i] == 0) zeroCount--;
            else oneCount--;
            // stop when either no more students are intersted at sandwitch at top of stack.
            // i.e. either zero count or one count becomes lessthan 0
            if(zeroCount <0 || oneCount<0) return ((int)sandwiches.size())-i;
        }
        
        return 0;
    }
};

int main() {
    Solution sol;
    vvv<int> inputs = {
        {{1,1,0,0}, {0,1,0,1}},
        {{1,1,1,0,0,1}, {1,0,0,0,1,1}}
    };

    for(vv<int> input: inputs) {
        cout<<sol.countStudents(input[0], input[1])<<endl;
    }
    return 0;
}