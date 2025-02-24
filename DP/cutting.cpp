#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

int helper(vector<int> logs, int i, int rod, unordered_map<int,int> &m){
    if(i >= logs.size() || rod < 0){
        return INT_MIN;
    }

    if(rod == 0){
        return 0;
    }

    if(m.find(rod) != m.end()) return m[rod];

    int a = helper(logs, i, rod - (i+1), m) + logs[i];
    int b = helper(logs, i+1, rod - (i+1), m) + logs[i];
    int c = helper(logs, i+1, rod, m);

    int ans = max(a, max(b,c));
    m[rod] = ans;

    return ans;
}

int findMaxAmount(vector<int> logs, int rod){
    int index = 0;
    unordered_map<int,int> m;

    return helper(logs, index, rod, m);
}

int main()
{
    vector<int> logs = {3,5,8,9,10,17,17,20};
    int rod = 8;

    int ans = findMaxAmount(logs, rod);
    cout<<ans<<endl;

    return 0;
}