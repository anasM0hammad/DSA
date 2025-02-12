#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,4,5,8,6,7,9,10};

    int small = INT_MAX;
    int large = INT_MIN;

    for(int i=0; i<arr.size(); i++){
        if(i == 0){
            if(arr[i] > arr[i+1]){
                small = min(small, arr[i]);
                large = max(large, arr[i]);
            }
        }
        else if(i == arr.size()-1){
            if(arr[i] < arr[i-1]){
                small = min(small, arr[i]);
                large = max(large, arr[i]);
            }
        }
        else{
            if((arr[i] < arr[i-1] && arr[i] < arr[i+1]) || (arr[i] > arr[i-1] && arr[i] > arr[i+1])){
                small = min(small, arr[i]);
                large = max(large, arr[i]);
            }
        }
    }

    // Find the correct place for large and small
    int x=-1;
    int y=-1;
   
    for(int i=0; i<arr.size(); i++){
        if(i == 0){
            if(small < arr[i]){
                x = i;
            }
        }
        else if(i == arr.size()-1){
            if(small > arr[i-1]){
                x = i;
            }
        }
        else{
            if(small < arr[i+1] && small > arr[i-1]){
                x = i;
            }
        }
    }    

    for(int i=arr.size()-1; i>=0; i--){
        if(i == 0){
            if(large < arr[i]){
                y = i;
            }
        }
        else if(i == arr.size()-1){
            if(large > arr[i-1]){
                y = i;
            }
        }
        else{
            if(large < arr[i+1] && large > arr[i-1]){
                y = i;
            }
        }
    }
    cout<<x+1<<" "<<y<<endl;
    return 0;
}