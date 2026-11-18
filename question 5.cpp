#include <iostream>
using namespace std;

int main()
{
    const int n = 6;
    char names[6] = {'A','B','C','D','E','F'};
    int graph[6][6] = {};

    graph[0][1] = 4;
    graph[0][2] = 2;
    graph[1][2] = 5;
    graph[1][3] = 10;
    graph[2][4] = 3;
    graph[4][3] = 4;
    graph[3][5] = 11;

    int dist[6], visited[6] = {}, parent[6];

    for (int i = 0; i < n; i++)
    {
        dist[i] = 9999;
        parent[i] = -1;
    }

    dist[0] = 0;

    for (int count = 0; count < n; count++)
    {
        int min = 9999, u = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 && visited[v] == 0 && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest paths from A\n";

    for (int i = 0; i < n; i++)
    {
        cout << "A to " << names[i] << ": ";

        if (dist[i] == 9999)
        {
            cout << "Unreachable\n";
        }
        else
        {
            int path[6], count = 0, x = i;

            while (x != -1)
            {
                path[count++] = x;
                x = parent[x];
            }

            for (int j = count - 1; j >= 0; j--)
            {
                cout << names[path[j]];
                if (j > 0)
                    cout << " -> ";
            }

            cout << " | Cost = " << dist[i] << endl;
        }
    }

    return 0;
}
