#include <iostream>
#include <vector>
using namespace std;

void getArray(vector<vector<int> > &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        for (int j = 0; j < m; j++)
        {
            int e;
            cin >> e;
            t.push_back(e);
        }
        arr.push_back(t);
    }
}

void setMatrix(vector<vector<int> > &arr, int n, int m)
{
    // better approach includes making a row and a coloumn matrix to store the corresponding row and column
    // 1 1 1   row[]={1, 0, 0}
    // 0 1 1   col[]={0, 1, 1}
    // 0 1 1
    // making the row and coloumn inside the matrix itself
    // treating row0 as coloumn array
    // treating coloumn0 as row array
    // arr[0][0] is colliding with row[0] and coloumn[0] therefore, col0 separate variable

    int col0 = 1; // initially 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                if (j != 0)
                    arr[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[0][j] == 0 or arr[i][0] == 0)
                arr[i][j] = 0;
        }
    }

    for (int j = m - 1; j > 0; j--)
    {
        if (arr[0][0] == 0)
            arr[0][j] = 0;
    }
    for (int i = n -1; i > 0; i--)
    {
        if (col0==0) arr[i][0]=0;
    }
}

void printArray(vector<vector<int> > &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m; // n X m matrix
    vector<vector<int> > arr;
    getArray(arr, n, m);
    setMatrix(arr, n, m);
    printArray(arr, n, m);
    return 0;
}
