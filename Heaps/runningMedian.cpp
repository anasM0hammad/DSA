#include <iostream>
#include <vector>
#include <queue>
#include<cmath>

using namespace std;


int main()
{
    vector<int> arr = { 10,5,2,3,0,12,18,20,22 };
    int cost = 0;

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    left.push(arr[0]);
    int median = arr[0];
    cout<<median<<" ";

    for(int i=1; i<arr.size(); i++){
        if(arr[i] < median){
            left.push(arr[i]);
        }
        else{
            right.push(arr[i]);
        }

        //Rebalancing
        if(abs((int)left.size() - (int)right.size()) > 1){
            if(left.size() > right.size()){
                int x = left.top();
                left.pop();
                right.push(x);
            }
            else{
                int x = right.top();
                right.pop();
                left.push(x);
            }
        }

        int n = i+1;

        if(n&1){
            // odd
            median = left.size() > right.size() ? left.top() : right.top();
        }
        else{
            int x = left.top();
            int y = right.top();
            median = (x+y)/2;
        }
        cout<<median<<" ";
    }

    return 0;
}