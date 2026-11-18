#include <iostream>
using namespace std;

int main()
{
    const int n = 6;
    int graph[6][6] = {};
    int indegree[6] = {};

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;
    graph[2][5] = 1;
    graph[3][5] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }

    int q[6], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q[rear++] = i;
    }

    char course[6] = {'A','B','C','D','E','F'};
    int count = 0;

    cout << "Course completion order: ";

    while (front < rear)
    {
        int u = q[front++];
        cout << course[u] << " ";
        count++;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] == 1)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q[rear++] = v;
            }
        }
    }

    if (count != n)
        cout << "\nCycle detected. No valid ordering exists.\n";
    else
        cout << "\nNo cycle detected.\n";

    return 0;
}
