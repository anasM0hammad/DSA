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

        bool isCyclic(int source, vector<bool> &visited, int parent){
            //base case
            if(visited[source]) return true;
            
            visited[source] = true;
            for(auto nbr: this->l[source]){
                if(nbr != parent){
                    return isCyclic(nbr, visited, source);
                }
            }
            return false;
        }

        bool DFS(int source){
            vector<bool> visited(this->v, false);
            return this->isCyclic(source, visited, source);
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
    // g->addEdge(4,5);
    g->addEdge(5,6);

    cout<<boolalpha<<g->DFS(1)<<endl;

    return 0;
}