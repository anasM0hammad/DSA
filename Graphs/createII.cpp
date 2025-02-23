#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

class Node {
    string name;
    public:
        list<string> nbrs;
        Node(string name){
            this->name = name;
        }

        string getName(){
            return this->name;
        }
};

class Graph{
    public:
    unordered_map<string, Node*> m;

    Graph(vector<string> cities){
        for(auto city: cities){
            m[city] = new Node(city);
        }
    }

    void addEdge(string i, string j, bool undir=false){
        m[i]->nbrs.push_back(j);
        if(undir){
            m[j]->nbrs.push_back(i);
        }
    }

    void printGraph(){
        for(auto node: m){
            cout<<node.second->getName()<<"-->";
            for(auto nbr: node.second->nbrs){
                cout<<nbr<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    vector<string> cities = { "Delhi", "London", "Paris", "New York" };
    Graph *g = new Graph(cities);

    g->addEdge("Delhi", "London");
    g->addEdge("London", "Delhi");
    g->addEdge("London", "Paris");
    g->addEdge("New York", "Delhi");
    g->addEdge("Paris", "New York");

    g->printGraph();

    return 0;
}