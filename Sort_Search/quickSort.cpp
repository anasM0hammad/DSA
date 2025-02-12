#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int> &arr, int s, int e){
    if(s >= e) return;

    int i=s-1;
    int j=s;
    int pivot = arr[e];

    while(j < e){
       if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
       }
       j++;
    }
    i++;
    swap(arr[e], arr[i]);

    quickSort(arr, s, i-1);
    quickSort(arr, i+1, e);
    return;
}

int main()
{
    vector<int> arr = { 10, 5, 2, 0, 7, 6, 4 };
    quickSort(arr, 0, arr.size()-1);

    for(auto x: arr){
        cout<<x<<" ";
    }

    return 0;
}