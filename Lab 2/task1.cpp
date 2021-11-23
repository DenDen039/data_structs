#include <bits/stdc++.h>
using namespace std;

void Copy(int *dist, int *arr, int size)
{
    // for(int i = 0; i < size;i++){
    //     dist[i] = arr[i];
    // }
    memcpy(dist, arr, size * sizeof(int));
}
void BubbleSort(int *arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
void InsertionSort(int arr[], int n)
{
    int j, temp;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void CountingSort(int *arr, int n)
{
    int *count = new int[n];
    int *temp = new int[n];
    Copy(temp, arr, n);
    memset(count, 0, n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= arr[i])
            {
                if (arr[i] == arr[j])
                {
                    if (i > j)
                        count[i]++;
                }
                else
                    count[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[count[i]] = temp[i];
    }
    delete temp;
    delete count;
}
void SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (min != i)
            swap(arr[min], arr[i]);
    }
}
void Fill(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000;
    }
}
void Fill2(int *arr, int size){
    for(int i = 0; i < size;i++){
        arr[i] = i;
    }
}
void Fill3(int *arr, int size){
    for(int i = 0; i < size;i++){
        arr[i] = size-i;
    }
}
void Fill4(int *arr, int size){
    for(int i = 0; i < size;i++){
        arr[i] = 1;
    }
}
int main()
{
    ofstream f("random_values.txt"),f2("increasing_values.txt"),f3("decreasing_values.txt"),f4("same_values.txt");
    srand(time(0));
    double start_time;
    double end_time;
    // int arr[5] = {5,5,3,1,1};
    // CountingSort(arr,5);
    // for(int i = 0; i < 5;i++){
    //     cout << arr[i] << " ";
    // }
    f << "N;"
      << "BubbleSort;"
      << "InsertionSort;"
      << "SelectionSort;"
      << "CountingSort;" << endl;
    for (int i = 1000; i < 35000; i += 1000)
    {
        f << i << ";";

        int *arr = new int[i];
        int *temp_arr = new int[i];
        Fill(arr, i);

        Copy(temp_arr, arr, i);
        start_time = clock();
        BubbleSort(temp_arr, i);
        end_time = clock();
        f << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        InsertionSort(temp_arr, i);
        end_time = clock();
        f << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        SelectionSort(temp_arr, i);
        end_time = clock();
        f << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        CountingSort(temp_arr, i);
        end_time = clock();
        f << (end_time - start_time) / CLK_TCK << ";" << endl;

        delete arr;
        delete temp_arr;
    }
    f2 << "N;"
      << "BubbleSort;"
      << "InsertionSort;"
      << "SelectionSort;"
      << "CountingSort;" << endl;
    for (int i = 1000; i < 35000; i += 1000)
    {
        f2 << i << ";";

        int *arr = new int[i];
        int *temp_arr = new int[i];
        Fill2(arr, i);

        Copy(temp_arr, arr, i);
        start_time = clock();
        BubbleSort(temp_arr, i);
        end_time = clock();
        f2 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        InsertionSort(temp_arr, i);
        end_time = clock();
        f2 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        SelectionSort(temp_arr, i);
        end_time = clock();
        f2 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        CountingSort(temp_arr, i);
        end_time = clock();
        f2 << (end_time - start_time) / CLK_TCK << ";" << endl;

        delete arr;
        delete temp_arr;
    }
    f3 << "N;"
      << "BubbleSort;"
      << "InsertionSort;"
      << "SelectionSort;"
      << "CountingSort;" << endl;
    for (int i = 1000; i < 35000; i += 1000)
    {
        f3 << i << ";";

        int *arr = new int[i];
        int *temp_arr = new int[i];
        Fill3(arr, i);

        Copy(temp_arr, arr, i);
        start_time = clock();
        BubbleSort(temp_arr, i);
        end_time = clock();
        f3 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        InsertionSort(temp_arr, i);
        end_time = clock();
        f3 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        SelectionSort(temp_arr, i);
        end_time = clock();
        f3 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        CountingSort(temp_arr, i);
        end_time = clock();
        f3 << (end_time - start_time) / CLK_TCK << ";" << endl;

        delete arr;
        delete temp_arr;
    }
    f4 << "N;"
      << "BubbleSort;"
      << "InsertionSort;"
      << "SelectionSort;"
      << "CountingSort;" << endl;
    for (int i = 1000; i < 35000; i += 1000)
    {
        f4 << i << ";";

        int *arr = new int[i];
        int *temp_arr = new int[i];
        Fill4(arr, i);

        Copy(temp_arr, arr, i);
        start_time = clock();
        BubbleSort(temp_arr, i);
        end_time = clock();
        f4 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        InsertionSort(temp_arr, i);
        end_time = clock();
        f4 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        SelectionSort(temp_arr, i);
        end_time = clock();
        f4 << (end_time - start_time) / CLK_TCK << ";";

        Copy(temp_arr, arr, i);
        start_time = clock();
        CountingSort(temp_arr, i);
        end_time = clock();
        f4 << (end_time - start_time) / CLK_TCK << ";" << endl;

        delete arr;
        delete temp_arr;
    }
    return 0;
}