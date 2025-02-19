#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main()
{
    vector<pair<int,int>> points = {{1,2},{2,3},{2,2},{4,2},{2,0}};
    unordered_map<int,int> y;

    for(auto p: points){
        if(y.find(p.second) != y.end()){
            y[p.second]++;
        }
        else{
            y[p.second] = 1;
        }
    }

    int count = 0;

    for(auto i=0; i<points.size(); i++){
        for(auto j=i+1; j<points.size(); j++){
            if(points[i].first == points[j].first){
                int y1 = y[points[i].second] - 1;
                int y2 = y[points[j].second] - 1;

                count += (y1+y2);
            }
        }
    }

    cout<<count<<endl;
    return 0;
}