#include <iostream>
#include <vector>
using namespace std;

void getElement(vector<int> &arr)
{
    int n;
    cout << "enter size of the heap" << endl;
    cin >> n;
    cout << "enter elements into the heap" << endl;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int> &arr, int rootIndex)
{
    int leftIndex = 2 * rootIndex;
    int rightIndex = 2 * rootIndex + 1;
    int greatestIndex = rootIndex;
    if ((leftIndex <= arr.size()) and (arr[leftIndex - 1] > arr[rootIndex - 1]))
    {
        greatestIndex = leftIndex;
    }
    if ((rightIndex <= arr.size()) and (arr[rightIndex - 1] > arr[greatestIndex - 1]))
    {
        greatestIndex = rightIndex;
    }
    if (greatestIndex != rootIndex)
    {
        swap(arr[greatestIndex - 1], arr[rootIndex - 1]);
        heapify(arr, greatestIndex);
    }
}

void buildHeap(vector<int> &arr)
{
    // start from the last non leaf element and go up till the root node
    if (arr.size() == 0)
        return;
    int nonleaf = arr.size() / 2;
    while (nonleaf > 0)
    {
        heapify(arr, nonleaf);
        nonleaf--;
    }
}

void deleteMax(vector<int> &arr)
{
    arr[0] = arr[arr.size() - 1]; // replace the array's first element with the last element
    arr.pop_back();
    heapify(arr, 1);
}

void increaseKey(vector<int> &arr, int key, int keyValue)
{
    if (key <= arr.size())
    {
        arr[key - 1] = keyValue; // changing the value of key to increased value
        int parentIndex = key / 2;
        while (parentIndex > 0)
        {
            if (arr[parentIndex - 1] < arr[key - 1])
                swap(arr[parentIndex - 1], arr[key - 1]);
            key = parentIndex;
            parentIndex = key / 2;
        }
    }
    else
        cout << "key does not exists" << endl;
}

void insertElement(vector<int> &arr, int element)
{
    arr.push_back(element);
    int key = arr.size();
    int parentIndex = key / 2;
    while (parentIndex > 0 and (arr[parentIndex - 1] < arr[key - 1]))
    {
        swap(arr[parentIndex - 1], arr[key - 1]);
        key = parentIndex;
        parentIndex = key / 2;
    }
}

void printHeap(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> heapArr;
    getElement(heapArr);
    buildHeap(heapArr);
    printHeap(heapArr);
    increaseKey(heapArr, 5, 100);
    printHeap(heapArr);
    insertElement(heapArr, 300);
    printHeap(heapArr);
    deleteMax(heapArr);
    printHeap(heapArr);
    return 0;
}