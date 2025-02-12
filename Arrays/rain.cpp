#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    vector<int> right;

    int r = 0;
    for(int i=arr.size()-1; i >= 0; i--){
        right.push_back(r);
        if(arr[i] > r) r = arr[i];
    }

    int l = 0;
    int area = 0;

    for(int i=0; i<arr.size(); i++){
        int x = min(l, right[arr.size() - i - 1]) - arr[i];
        if(x >= 0) area += x;

        if(arr[i] > l) l = arr[i];
    }

    cout<<area;
    
    return 0;
}