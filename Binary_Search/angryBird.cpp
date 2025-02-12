#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPossible(vector<int> arr, int birds, int distance){
    int count = birds - 1;
    int cur = 0;
    for(int i=1; i<arr.size(); i++){
        if(arr[i] - arr[cur] >= distance){
            count--;
            cur = i;
        }
    }

    if(count <= 0) return true;

    return false;
}

int main()
{
    vector<int> arr = { 1, 2, 4, 8, 9 };
    int birds = 3;

    int maxLength = -1;
    int minLength = 100;

    for(auto x: arr){
        maxLength = max(x, maxLength);
        minLength = min(x, minLength);
    }
    
    int s = 0;
    int e = (maxLength - minLength);
    int ans = s;

    while(s <= e){
        int mid = (s+e) / 2;
        bool x = isPossible(arr, birds, mid);

        if(x){
            ans = max(ans, mid);
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    cout<<ans<<endl;
   
    return 0;
}