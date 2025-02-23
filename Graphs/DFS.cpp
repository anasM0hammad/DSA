#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_set>
#include <queue>

using namespace std;

class Graph{
    list<int> *l;  // unweighted graph. For weighted use pair of int
    public:
        int v;

        Graph(int V){
            this->v = V;
            l = new list<int>[v];
        }

        void addEdge(int i, int j, bool unDir=true){
            l[i].push_back(j);

            if(unDir){
                l[j].push_back(i);
            }
        }

        void printGraph(){
            for(int i=0; i<v; i++){
                list<int> node = l[i];
                cout<<i<<"-->";
                for(auto val: node){
                    cout<<val<<",";
                }
                cout<<endl;
            }
        }

        void DFSHelper(int source, vector<bool> &visited){
            if(visited[source]) return;

            cout<<source<<"-->";
            visited[source] = true;

            for(auto nbr: this->l[source]){
                DFSHelper(nbr, visited);
            }
        }

        void DFS(int source){
            vector<bool> visited(this->v, false);
            this->DFSHelper(source, visited);
        }

};

int main()
{
    Graph *g = new Graph(7);
    g->addEdge(0,1);
    g->addEdge(0,4);
    g->addEdge(1,2);
    g->addEdge(2,3);
    g->addEdge(3,4);
    g->addEdge(3,5);
    g->addEdge(4,5);
    g->addEdge(5,6);

    g->DFS(1);

    return 0;
}