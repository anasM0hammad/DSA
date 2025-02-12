#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSelect(vector<int>& arr, int s, int e, int &value, int k){
    if(s == e && s == k-1){
        value = arr[s];
    }
    if(s >= e) return;

    int i=s-1;
    int j=s;
    int pivot = arr[e];


    while(j < e){
        if(arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
        j++;
    }

    i++;
    swap(arr[e], arr[i]);

    if(i == k-1) {
        value = arr[i];
        return;
    }

    quickSelect(arr, s, i-1, value, k);
    quickSelect(arr, i+1, e, value, k);

    return;
}


int main()
{
    vector<int> arr = { 10, 5, 2, 0, 7, 6, 4 };
    int k=4;
    int value = -1;

    quickSelect(arr, 0, arr.size()-1, value, k);

    cout<<value<<" ";
    return 0;
}