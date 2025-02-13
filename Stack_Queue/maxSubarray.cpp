#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void maxSubarray(vector<int> arr, int k){
    deque<int> q;

    // Adding initial k elements
    for(int i=0; i<k; i++){
        while(!q.empty() && arr[i] > q.back()){
            q.pop_back();
        }
        q.push_back(arr[i]);
    }
    cout<<q.front()<<" ";

    // Adding rest of the element
    for(int i=k; i<arr.size(); i++){
        // outgoing element
        if(arr[i] == q.front()){
            q.pop_front();
        }

        // incoming element
        while(!q.empty() && arr[i] > q.back()){
            q.pop_back();
        }
        q.push_back(arr[i]);
        cout<<q.front()<<" ";
    }
}

int main(){
    vector<int> arr = { 1,2,3,1,4,5,2,3,6 };
    int k=3;

    maxSubarray(arr, k);
   
    return 0;
}