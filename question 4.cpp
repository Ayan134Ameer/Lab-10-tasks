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

    int choice;

    do
    {
        cout << "\n1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Display Matrix\n";
        cout << "4. Incoming and Outgoing Edges\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            char from, to;
            int cost, x = -1, y = -1;

            cout << "Enter starting department: ";
            cin >> from;
            cout << "Enter ending department: ";
            cin >> to;
            cout << "Enter cost: ";
            cin >> cost;

            for (int i = 0; i < n; i++)
            {
                if (names[i] == from) x = i;
                if (names[i] == to) y = i;
            }

            if (x != -1 && y != -1 && cost > 0)
            {
                graph[x][y] = cost;
                cout << "Edge inserted\n";
            }
            else
                cout << "Invalid input\n";
        }
        else if (choice == 2)
        {
            char from, to;
            int x = -1, y = -1;

            cout << "Enter starting department: ";
            cin >> from;
            cout << "Enter ending department: ";
            cin >> to;

            for (int i = 0; i < n; i++)
            {
                if (names[i] == from) x = i;
                if (names[i] == to) y = i;
            }

            if (x != -1 && y != -1 && graph[x][y] != 0)
            {
                graph[x][y] = 0;
                cout << "Edge deleted\n";
            }
            else
                cout << "Edge not found\n";
        }
        else if (choice == 3)
        {
            cout << "\n  ";
            for (int i = 0; i < n; i++)
                cout << names[i] << " ";
            cout << endl;

            for (int i = 0; i < n; i++)
            {
                cout << names[i] << " ";
                for (int j = 0; j < n; j++)
                    cout << graph[i][j] << " ";
                cout << endl;
            }
        }
        else if (choice == 4)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "\n" << names[i] << " outgoing: ";
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][j] != 0)
                        cout << names[i] << "->" << names[j] << "(" << graph[i][j] << ") ";
                }

                cout << "\n" << names[i] << " incoming: ";
                for (int j = 0; j < n; j++)
                {
                    if (graph[j][i] != 0)
                        cout << names[j] << "->" << names[i] << "(" << graph[j][i] << ") ";
                }
                cout << endl;
            }
        }
    }
    while (choice != 0);

    return 0;
}
