#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int s, int mid, int e){
    int i=s;
    int j=mid+1;
    vector<int> temp;
    while(i <= mid && j <= e){
        if(arr[i] > arr[j]){
            temp.push_back(arr[j]);
            j++;
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }
    
    int x=0;
    for(int i=s; i<=e; i++){
        arr[i] = temp[x];
        x++;
    }
    return;
}

void mergeSort(vector<int> &arr, int s, int e){
    if(s == e) return;
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, mid, e);
}

int main()
{
    vector<int> arr = {10,5,2,0,7,6,4};
    mergeSort(arr, 0, arr.size()-1);

    for(auto x: arr){
        cout<<x<<" ";
    }
    return 0;
}