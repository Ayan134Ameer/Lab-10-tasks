#include <iostream>
using namespace std;

void prim(int graph[7][7], char names[], int n, int start)
{
    int selected[7] = {};
    selected[start] = 1;
    int total = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int min = 9999, x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (selected[j] == 0 && graph[i][j] != 0 && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1)
            break;

        cout << names[x] << " - " << names[y] << " : " << min << endl;
        total += min;
        selected[y] = 1;
    }

    cout << "Total cost = " << total << "\n\n";
}

int main()
{
    int a[7][7] = {};
    char first[] = {'0','1','2','3','4'};

    a[0][1] = a[1][0] = 3;
    a[1][2] = a[2][1] = 1;
    a[1][3] = a[3][1] = 4;
    a[0][3] = a[3][0] = 7;
    a[0][4] = a[4][0] = 8;
    a[4][3] = a[3][4] = 3;
    a[3][2] = a[2][3] = 2;

    cout << "Graph a\n";
    prim(a,first,5,0);

    int b[7][7] = {};
    char second[] = {'A','B','C','D','E','F','G'};

    b[0][1] = b[1][0] = 1;
    b[0][3] = b[3][0] = 5;
    b[1][3] = b[3][1] = 3;
    b[1][2] = b[2][1] = 4;
    b[2][4] = b[4][2] = 7;
    b[3][4] = b[4][3] = 1;
    b[3][6] = b[6][3] = 4;
    b[4][6] = b[6][4] = 2;
    b[4][5] = b[5][4] = 1;
    b[6][5] = b[5][6] = 10;

    cout << "Graph b\n";
    prim(b,second,7,0);

    return 0;
}
