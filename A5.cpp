#include <iostream>
#define nV 4
#define INF 999
#include <chrono>
using namespace std::chrono;
using namespace std;

void printM(int matrix[][nV]);
void FW(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;
    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            matrix[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    printM(matrix);
}
void printM(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    auto start = high_resolution_clock::now();
    int graph[nV][nV] = {{0, 2, INF, 8},
                         {INF, 0, 5, INF},
                         {INF, INF, 0, 3},
                         {INF, INF, INF, 0}};
    FW(graph);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count() << "\tMicrosecond" << endl;
    return 0;
}
