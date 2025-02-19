#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main()
{
    vector<pair<int,int>> points = {{0,0},{0,1},{1,1},{3,1},{1,0},{2,1},{2,0},{3,0}};
    set<pair<int,int>> s;

    for(auto p: points){
        s.insert(p);
    }

    int count = 0;

    for(int i=0; i<points.size(); i++){
        for(int j=i+1; j<points.size(); j++){

            if(points[i].first != points[j].first && points[i].second != points[j].second){
                pair<int,int> d1 = { points[i].first, points[j].second };
                pair<int,int> d2 = { points[j].first, points[i].second };

                if(s.find(d1) != s.end() && s.find(d2) != s.end()){
                    count++;
                }
            }
        }
    }

    cout<< count/2<<endl;

    return 0;
}