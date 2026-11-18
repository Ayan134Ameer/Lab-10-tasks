#include <iostream>
using namespace std;

void addEdge(int a[8][8], int x, int y, int directed)
{
    a[x][y] = 1;
    if (directed == 0)
        a[y][x] = 1;
}

void bfs(int a[8][8], char names[], int n, int start)
{
    int visited[8] = {};
    int q[8], front = 0, rear = 0;

    visited[start] = 1;
    q[rear++] = start;

    while (front < rear)
    {
        int v = q[front++];
        cout << names[v] << " ";

        for (int i = 0; i < n; i++)
        {
            if (a[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

void dfs(int a[8][8], char names[], int n, int v, int visited[])
{
    visited[v] = 1;
    cout << names[v] << " ";

    for (int i = 0; i < n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
            dfs(a, names, n, i, visited);
    }
}

void display(int a[8][8], char names[], int n, int start)
{
    int visited[8] = {};

    cout << "BFS: ";
    bfs(a, names, n, start);

    cout << "\nDFS: ";
    dfs(a, names, n, start, visited);
    cout << "\n\n";
}

int main()
{
    int a[8][8] = {};
    char l1[] = {'a','b','c','d','e'};
    addEdge(a,0,1,1);
    addEdge(a,0,2,1);
    addEdge(a,0,3,1);
    addEdge(a,0,4,1);
    addEdge(a,1,3,1);
    addEdge(a,2,3,1);
    addEdge(a,2,4,1);
    addEdge(a,3,4,1);
    cout << "Graph a\n";
    display(a,l1,5,0);

    int b[8][8] = {};
    char l2[] = {'1','2','3','4','5','6','7'};
    addEdge(b,0,1,1);
    addEdge(b,0,3,1);
    addEdge(b,1,2,1);
    addEdge(b,1,4,1);
    addEdge(b,2,6,1);
    addEdge(b,3,5,1);
    addEdge(b,5,4,1);
    addEdge(b,5,6,1);
    addEdge(b,4,6,1);
    cout << "Graph b\n";
    display(b,l2,7,0);

    int c[8][8] = {};
    char l3[] = {'A','B','C','D','E','F'};
    addEdge(c,0,2,1);
    addEdge(c,0,1,1);
    addEdge(c,2,3,1);
    addEdge(c,2,1,1);
    addEdge(c,2,4,1);
    addEdge(c,3,4,1);
    addEdge(c,1,5,1);
    addEdge(c,4,5,1);
    cout << "Graph c\n";
    display(c,l3,6,0);

    int d[8][8] = {};
    addEdge(d,0,2,1);
    addEdge(d,0,1,1);
    addEdge(d,2,3,1);
    addEdge(d,2,1,1);
    addEdge(d,2,4,1);
    addEdge(d,3,4,1);
    addEdge(d,1,5,1);
    addEdge(d,4,5,1);
    cout << "Graph d\n";
    display(d,l3,6,0);

    int e[8][8] = {};
    char l5[] = {'A','B','C','D','E','F','G','H'};
    addEdge(e,0,1,1);
    addEdge(e,1,2,1);
    addEdge(e,2,6,1);
    addEdge(e,6,7,1);
    addEdge(e,7,0,1);
    addEdge(e,0,3,1);
    addEdge(e,3,5,1);
    addEdge(e,5,0,1);
    addEdge(e,1,5,1);
    addEdge(e,4,1,1);
    addEdge(e,2,4,1);
    addEdge(e,6,4,1);
    addEdge(e,4,5,1);
    cout << "Graph e\n";
    display(e,l5,8,0);

    int f[8][8] = {};
    char l6[] = {'0','1','2','3','4','5','6','7'};
    addEdge(f,0,1,1);
    addEdge(f,0,2,1);
    addEdge(f,0,3,1);
    addEdge(f,1,3,1);
    addEdge(f,2,4,1);
    addEdge(f,2,5,1);
    addEdge(f,3,5,1);
    addEdge(f,3,6,1);
    addEdge(f,4,5,1);
    addEdge(f,4,7,1);
    addEdge(f,5,2,1);
    cout << "Graph f\n";
    display(f,l6,8,0);

    int g[8][8] = {};
    addEdge(g,0,1,0);
    addEdge(g,0,7,1);
    addEdge(g,0,3,0);
    addEdge(g,7,4,1);
    addEdge(g,7,5,1);
    addEdge(g,3,5,1);
    addEdge(g,4,6,1);
    addEdge(g,5,6,1);
    cout << "Graph g\n";
    display(g,l6,8,0);

    int h[8][8] = {};
    addEdge(h,0,1,0);
    addEdge(h,1,2,0);
    addEdge(h,2,6,0);
    addEdge(h,0,3,0);
    addEdge(h,0,5,0);
    addEdge(h,1,5,0);
    addEdge(h,1,4,0);
    addEdge(h,2,4,0);
    addEdge(h,4,5,0);
    addEdge(h,5,3,0);
    addEdge(h,2,7,0);
    addEdge(h,6,7,0);
    addEdge(h,4,6,0);
    cout << "Graph h\n";
    display(h,l5,8,0);

    return 0;
}
