#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> graph;

    int dist[v];

    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cout << "Enter the source, destination and weight of edge " << i + 1 << ": ";
        cin >> u >> v >> w;

        graph.push_back({u, v, w});
    }

    for (int i = 0; i < v - 1; i++)
    {
        for (auto edge : graph)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {

                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : graph)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative cycle detected" << endl;
            return 0;
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << "Distance of vertex " << i << " from source is " << dist[i] << endl;
    }
}
