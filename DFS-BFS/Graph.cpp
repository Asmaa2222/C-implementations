#include "Graph.h"

graph::graph(int n)
{
    numofnodes = n;
    mygraph.resize(n);
}
void graph::addedge(int source, int destination)

{
    if ((source >= 0 && source < numofnodes) && (destination >= 0 && destination < numofnodes))
        mygraph[source].push_back(destination);
    else
        cout << "Oh no !\n";
}

void graph::BFS()
{
    if (numofnodes == 0)
        return;
    vector<bool> visited(numofnodes, false);
    queue<int> q;
    q.push(0);
    int j = 0;

    do
    {
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            visited[temp] = true;
            for (int i = 0; i < mygraph[temp].size(); ++i)
            {
                if (!visited[mygraph[temp][i]])
                    q.push(mygraph[temp][i]);
                visited[mygraph[temp][i]] = true;
            }
            if (j < numofnodes && visited[j] == false)
                q.push(j);
            ++j;
        }

    } while (j <= numofnodes);
}

void graph::DFS()
{
    if (numofnodes == 0)
        return;
    vector<bool> visited(numofnodes, false);
    for (int i = 0; i < numofnodes; ++i)
    {
        if (visited[i] == false)
            DFSRec(i, visited);
    }
}
void graph::DFSRec(int vertex, vector<bool> &visited)
{
    if (visited[vertex])
        return;
    else
        cout << vertex;
    visited[vertex] = true;
    for (int i = 0; i < mygraph[vertex].size(); ++i)
    {
        if (!visited[mygraph[vertex][i]])
        {
            int dest = mygraph[vertex][i];
            DFSRec(dest, visited);
        }
    }
}
