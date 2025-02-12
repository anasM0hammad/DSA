#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

bool cmp(string a, string b){
    string x = a+b;
    string y = b+a;

    return x < y; 
}

void merge(vector<string> &str, int s, int mid, int e){
    int i=s;
    int j=mid+1;

    vector<string> temp;

    while(i<= mid && j<=e){
        if(cmp(str[i], str[j])){
            temp.push_back(str[i]);
            i++;
        }
        else{
            temp.push_back(str[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(str[i]);
        i++;
    }

    while(j <= e){
        temp.push_back(str[j]);
        j++;
    }

    int x=0;
    for(int i=s; i<=e; i++){
        str[i] = temp[x];
        x++;
    }
    return;
}

void mergeSort(vector<string> &str, int s, int e){
    if(s == e) return;

    int mid = (s+e) / 2;

    mergeSort(str, s, mid);
    mergeSort(str, mid+1, e);

    merge(str, s, mid, e);
    return;
}


int main()
{
    vector<string> str = { "c", "cb", "cba" };
    
    // mergeSort(str, 0, str.size()-1);

    sort(str.begin(), str.end(), cmp);

    for(auto x: str){
        cout<<x;
    }
    return 0;
}