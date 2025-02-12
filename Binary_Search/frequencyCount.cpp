#include <iostream>
#include <vector>
#include <string>
using namespace std;

int binarySearchLeft(vector<int> arr, int s, int e, int key){
    if(s > e) return -1;

    int mid = (s+e)/2;
    if(arr[mid] == key){
        int x = binarySearchLeft(arr, s, mid-1, key);
        if(x == -1) return mid;
        return x;
    }
    else if(arr[mid] < key){
        s = mid+1;
        return binarySearchLeft(arr, s, e, key);
    }
    else{
        e = mid-1;
        return binarySearchLeft(arr, s, e, key);
    }
}

int binarySearchRight(vector<int> arr, int s, int e, int key){
    if(s > e) return -1;

    int mid = (s+e)/2;
    if(arr[mid] == key){
        int x = binarySearchRight(arr, mid+1, e, key);
        if(x == -1) return mid;
        return x;
    }
    else if(arr[mid] < key){
        s = mid+1;
        return binarySearchRight(arr, s, e, key);
    }
    else{
        e = mid-1;
        return binarySearchRight(arr, s, e, key);
    }
}


int main()
{
    vector<int> arr = { 0,0,1,1,1,2,2,2,2,2,3,3,3 };
    int key = 2;

    int l = binarySearchLeft(arr, 0, arr.size()-1, key);
    int r = binarySearchRight(arr, 0, arr.size()-1, key);
    
    cout<<(r-l+1)<<endl;
   
    return 0;
}