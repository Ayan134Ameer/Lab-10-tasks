#include <iostream>
using namespace std;

int findParent(int parent[], int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

int main()
{
    const int n = 6;
    const int m = 12;
    int edges[12][3] = {
        {0,1,3},
        {0,2,5},
        {0,3,9},
        {1,2,3},
        {1,3,4},
        {1,4,7},
        {2,3,2},
        {2,4,6},
        {2,5,8},
        {3,4,2},
        {3,5,2},
        {4,5,5}
    };

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                for (int k = 0; k < 3; k++)
                {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }

    char names[] = {'A','B','C','D','E','F'};
    int parent[6];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0, count = 0;

    cout << "Minimum Spanning Tree using Kruskal's Algorithm\n";

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int p1 = findParent(parent,u);
        int p2 = findParent(parent,v);

        if (p1 != p2)
        {
            parent[p1] = p2;
            cout << names[u] << " - " << names[v] << " : " << w << endl;
            total += w;
            count++;
        }

        if (count == n - 1)
            break;
    }

    cout << "Total cost = " << total << endl;
    return 0;
}
