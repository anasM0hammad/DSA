#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    vector<int> ropes = { 4,3,2,6 };
    int cost = 0;

    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());

    while(!pq.empty()){
        int min = pq.top();
        pq.pop();

        if(pq.empty()){
            cout<<cost<<endl;
            break;
        }

        int min2 = pq.top();
        pq.pop();

        cost += (min + min2);
        int newRope = min + min2;

        pq.push(newRope);
    }

    return 0;
}