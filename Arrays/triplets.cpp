#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int,int> twoSum(vector<int> arr, int s, int e, int sum){
    while(s < e){
        if(arr[s] + arr[e] == sum){
            return {arr[s], arr[e]};
        }
        else if(arr[s] + arr[e] > sum){
            e--;
        }
        else{
            s++;
        }
    }
    return { -1,-1 };
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    int n = arr.size();
    int sum = 18;

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        pair<int,int> ans = twoSum(arr, i+1, n-1, sum-arr[i]);
        if(ans.first != -1){
            cout<<arr[i]<<" "<<ans.first<<" "<<ans.second<<endl;
        }
    }
     
    return 0;
}