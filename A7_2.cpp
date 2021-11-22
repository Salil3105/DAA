#include <algorithm>
#include <iostream>
#include <vector>
#define edge pair<int, int>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Graph
{
private:
    vector<pair<int, edge>> G;
    vector<pair<int, edge>> T;
    int *parent;
    int V;

public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int V)
{
    parent = new int[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;
    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i)
{
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}
void Graph::union_set(int u, int v)
{
    parent[u] = parent[v];
}
void Graph::kruskal()
{
    int i, uRep, vRep;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++)
    {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep)
        {
            T.push_back(G[i]);
            union_set(uRep, vRep);
        }
    }
}
void Graph::print()
{
    cout << "Edge :"
         << " Weight" << endl;
    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i].second.first << " - " << T[i].second.second << " : "
             << T[i].first;
        cout << endl;
    }
}
int main()
{
    auto start = high_resolution_clock::now();
    Graph g(6);
    g.AddWeightedEdge(0, 1, 9);
    g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(1, 0, 3);
    g.AddWeightedEdge(2, 0, 4);
    g.AddWeightedEdge(2, 1, 2);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 2, 3);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(4, 2, 2);
    g.AddWeightedEdge(4, 3, 3);
    g.AddWeightedEdge(5, 2, 1);
    g.AddWeightedEdge(5, 4, 3);
    g.kruskal();
    g.print();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count() << "\tMicrosecond" << endl;
    return 0;
}