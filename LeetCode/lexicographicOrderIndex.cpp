// Leetcode: 1830
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#define MOD_VALUE 1000000007
using namespace std;
class Solution {
public:
    int ncr[3001][3001];
    int calculatencr(int n, int r) {
        if(n==r || r==0) {
            ncr[n][r] = 1;
        } else if(ncr[n][r] == 0) {
            ncr[n][r] = calculatencr(n-1, r-1)+calculatencr(n-1, r);
        }

        return ncr[n][r]%MOD_VALUE;
    }
    int makeStringSorted(string s) {
        int n = s.length();
        string sortedS = s;
        sort(sortedS.begin(), sortedS.end());
        map<char, int> count;
        for(auto c: s) {
            count[c]++;
        }
        long long sol = 0;
        for(int i=0;i<n;i++) {
            auto it = lower_bound(sortedS.begin(),sortedS.end(),s[i]);
            if(it != sortedS.begin()) {
                
                auto it1 = count.find(s[i]);
                for(auto it2=count.begin();it2!=it1;it2++) {
                    int m = n-i-1;
                    long long current = 1;
                    for_each(count.begin(), count.end(), [&m, &current, &it2, this](const pair<char, int> &p) {
                        if(it2->first != p.first){
                            current*=this->calculatencr(m, p.second);
                            m-=p.second;
                        } else {
                            current*=this->calculatencr(m, p.second-1);
                            m-=p.second-1;
                        }
                        if(current>MOD_VALUE) current%=MOD_VALUE;
                        
                    });
                    sol += current;
                    if(sol>MOD_VALUE) sol%=MOD_VALUE;
                }
            }
            count[s[i]]--;
            if(count[s[i]]==0) count.erase(s[i]);
            sortedS.erase(it);
        }
        return sol;
    }
};

int main () {
    Solution sol;
    string s;
    cin>>s;
    cout<<sol.makeStringSorted(s);
    return 0;
}