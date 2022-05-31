

#include <bits\stdc++.h>
using namespace std;
#define INF 9999
typedef pair<int, int> iPair;
class Graph
{
private:
    int V;
    list<pair<int, int>> *adj; // representing the adjecency list
public:
    Graph(int nodes)
    {
        V = nodes;
        adj = new list<iPair>[V]; // alocate memory
    }
    void addEdge(int u, int v, int w)
    {
        // undirected graph
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // connect the edges and illustrating their weights
    }
    void shortestPath(int s)
    {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<int> dist(V, INF);
        pq.push(make_pair(0, s));
        dist[s] = 0;
        while (!pq.empty())
        {
            // length in first to get the smallest
            int u = pq.top().second; // vertex
            pq.pop();
            list<pair<int, int>>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)

            {
                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    
        
            cout<<"Vertex Distance from Source: \n";
            for(int i=0; i<V; ++i)
            cout<<i<<"\t"<<dist[i]<<endl;
            
            
    }                 
    
};

int main()
{
int V=9; 
Graph g(9);
g.addEdge(0,1,4);
 g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    g.shortestPath(0);
    return 0;
}