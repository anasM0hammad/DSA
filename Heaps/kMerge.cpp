#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
//     return a.first < b.first;
// }

class cmp{
    public:
        bool operator()(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
            return a.first > b.first;
        }
};

int main()
{
    vector<vector<int>> arr = {{1,3,15},{2,4,6},{0,9,10,11}};
    priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> pq;

    for(int i=0; i<arr.size(); i++){
        pq.push({arr[i][0], {i,0}});
    }

    vector<int> ans;

    while(!pq.empty()){
        int min = pq.top().first;
        int arrIndex = pq.top().second.first;
        int index = pq.top().second.second;

        ans.push_back(min);
        pq.pop();   

        if(index < arr[arrIndex].size()-1){
            pq.push({arr[arrIndex][index+1], {arrIndex, index+1}});
        }
    }

    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}