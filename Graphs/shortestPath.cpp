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

        void shortestPathAll(int source){
            vector<bool> visited(this->v, false);
            queue<int> q;
            q.push(source);

            vector<pair<int,int>> distance(this->v);
            distance[source] = { 0, source };
            visited[source] = true;

            while(!q.empty()){
                int current = q.front();
                q.pop();

                int curDistance = distance[current].first;
                for(auto nbr: this->l[current]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        distance[nbr] = {curDistance+1, current};
                        visited[nbr] = true;
                    }
                }
            }

            for(auto i=0; i<this->v; i++){
                cout<<i<<"-->"<<distance[i].first<<" "<<distance[i].second<<endl;
            }
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

    g->shortestPathAll(1);

    return 0;
}