#include <iostream>
using namespace std;

// 希尔
void shellSort(int arr[], int n) 
{
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 快排
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        //分区
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) 
        {
            if (arr[j] < pivot) 
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() 
{

    int n;
    cout<<"请输入需要排序的元素个数n：";
    cin>>n;
    int data[n];

    cout << "请输入 " << n << " 个元素: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> data[i];
    }

    // 希尔
    int shellSortedData[n];
    for (int i = 0; i < n; i++) 
    {
        shellSortedData[i] = data[i];
    }
    shellSort(shellSortedData, n);
    cout << "希尔排序后的数据: ";
    for (int i = 0; i < n; i++) 
    {
        cout << shellSortedData[i] << " ";
    }
    cout << endl;

    // 快排
    int quickSortedData[n];
    for (int i = 0; i < n; i++) 
    {
        quickSortedData[i] = data[i];
    }
    quickSort(quickSortedData, 0, n - 1);
    cout << "快速排序后的数据: ";
    for (int i = 0; i < n; i++) 
    {
        cout << quickSortedData[i] << " ";
    }
    cout << endl;
    return 0;
}