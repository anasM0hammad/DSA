#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void heapify(vector<double> &distance, int index, int end){
    if(index >= end) return;

    int left = 2*index+1;
    int right = 2*right+2;

    if(left >= end) return;

    if(distance[index] <= distance[left] && right >= end) return;
    if(distance[index] <= distance[left] && distance[index] <= distance[right]){
        return;
    }
    int smallest;
    if(right >= end){
        smallest = left;
    }
    else{
         smallest = distance[left] < distance[right] ? left : right;
    }

    swap(distance[index], distance[smallest]);
    heapify(distance, smallest, end);

}

int main()
{
    vector<pair<int,int>> cabs = {{1,1},{2,1},{3,2},{1,0},{2,3}};
    vector<double> distance;
    int k=3;
    for(auto i: cabs){
        double x = i.first*i.first + i.second*i.second;
        distance.push_back(x);
    }

    for(int i=(distance.size()/2)-1; i>=0; i--){
        heapify(distance, i, distance.size());
    }

    for(int i=0; i<k; i++){
        int smallest = distance[0];
        cout<<smallest<<" ";

        swap(distance[0], distance[distance.size()-i-1]);
        heapify(distance, 0, distance.size()-i-1);
    }
    return 0;
}