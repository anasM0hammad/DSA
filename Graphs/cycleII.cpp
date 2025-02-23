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

        void addEdge(int i, int j, bool unDir=false){
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
           if(visited[source]) return true;

           visited[source] = true;
           bool ans = false;
           for(auto nbr: this->l[source]){
                if(nbr != parent){
                    ans = isCyclic(nbr, visited, source);
                    if(ans) return true;
                }
           }
           visited[source] = false;
           return false;
        }

        bool DFS(int source){
            vector<bool> visited(this->v, false);
            return this->isCyclic(source, visited, source);
        }

};

int main()
{
    Graph *g = new Graph(6);
    g->addEdge(0,1);
    g->addEdge(1,2);
    g->addEdge(2,3);
    g->addEdge(0,5);
    g->addEdge(5,4);
    // g->addEdge(0,4);
    g->addEdge(4,0);

    cout<<boolalpha<<g->DFS(0)<<endl;

    return 0;
}