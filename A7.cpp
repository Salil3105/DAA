#include <iostream>
#include <cstring>
#include <chrono>
#define INF 9999999
#define V 5
using namespace std::chrono;
using namespace std;
void Prims(int G[V][V])
{
    int no_edge;
    int selected[V];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x;
    int y;
    cout << "Edge"
         << " : "
         << "Weight";
    cout << endl;
    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " : " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
}
int main()
{
    auto start = high_resolution_clock::now();
    int G[V][V] = {
        {0, 4, 30, 10, 0},
        {9, 1, 5, 19, 42},
        {75, 95, 0, 1, 6},
        {0, 9, 51, 0, 41},
        {0, 92, 36, 11, 0}};
    cout << "Prim's Algorithm :" << endl;
    Prims(G);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count() << "\tMicrosecond" << endl;
    return 0;
}
