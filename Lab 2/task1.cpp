#include <bits/stdc++.h>
using namespace std;

void Copy(int *dist, int *arr, int size)
{
    memcpy(dist, arr, size * sizeof(int));
}
void Heapify(int *arr, int parent,int size){
    int max_el = parent;
    int left = parent*2+1,right = parent*2+2;
    if(left < size && arr[left] > arr[max_el])
        max_el = left;
    if(right < size && arr[right] > arr[max_el])
        max_el = right;
    if(max_el != parent){
        swap(arr[max_el],arr[parent]);
        Heapify(arr,max_el,size);
    }
}
void BuildHeap(int *arr, int size){
    for(int i  = size/2-1;i >= 0;i--){
        Heapify(arr,i,size);
    }
}
void HeapSort(int *arr, int size){
    BuildHeap(arr,size);
    for(int i = size-1; i >0;i--){
        swap(arr[0],arr[i]);
        Heapify(arr,0,i);
    }
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
void Fill2(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
}
void Fill3(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
}
void Fill4(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 1;
    }
}
bool is_equal(int *sorted_arr, int *to_check, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (sorted_arr[i] != to_check[i])
        {
            return 0;
        }
        
    }
    return 1;
}
void sort_check(int *arr, int size,void (*sort_func)(int *, int), ofstream &file)
{
    double start_time;
    double end_time;
    int *temp_arr = new int[size];
    int *sorted_arr = new int[size];

    Copy(sorted_arr,arr,size);
    Copy(temp_arr, arr, size);

    sort(sorted_arr,sorted_arr+size);

    start_time = clock();
    sort_func(temp_arr, size);
    end_time = clock();
    
    if(!is_equal(sorted_arr,temp_arr,size)){
        throw string("sorted uncorrectly!");
    }
        

    file << (end_time - start_time) / CLK_TCK << ";";

    delete temp_arr;
    delete sorted_arr;
}

int main()
{
    ofstream f("random_values.csv"), f2("increasing_values.csv"), f3("decreasing_values.csv"), f4("same_values.csv");
    srand(time(0));
    
    f << "N;"
      << "BubbleSort;"
      << "InsertionSort;"
      << "SelectionSort;"
      << "CountingSort;"
      << "HeapSort;" << endl;
    for (int i = 1000; i < 36000; i += 1000)
    {
        f << i << ";";
        int *arr = new int[i];
        Fill(arr,i);

        sort_check(arr,i,BubbleSort,f);
        sort_check(arr,i,InsertionSort,f);
        sort_check(arr,i,SelectionSort,f);
        sort_check(arr,i,CountingSort,f);
        sort_check(arr,i,HeapSort,f);

        f<<endl;
        delete arr;
    }

    f2 << "N;"
       << "BubbleSort;"
       << "InsertionSort;"
       << "SelectionSort;"
       << "CountingSort;"
       << "HeapSort;" << endl;
     for (int i = 1000; i < 36000; i += 1000)
    {
        f2 << i << ";";
        int *arr = new int[i];
        Fill2(arr,i);

        sort_check(arr,i,BubbleSort,f2);
        sort_check(arr,i,InsertionSort,f2);
        sort_check(arr,i,SelectionSort,f2);
        sort_check(arr,i,CountingSort,f2);
        sort_check(arr,i,HeapSort,f2);

        f2<<endl;
        delete arr;
    }

    f3 << "N;"
       << "BubbleSort;"
       << "InsertionSort;"
       << "SelectionSort;"
       << "CountingSort;"
       << "HeapSort;" << endl;
    for (int i = 1000; i < 36000; i += 1000)
    {
        f3 << i << ";";
        int *arr = new int[i];
        Fill3(arr,i);

        sort_check(arr,i,BubbleSort,f3);
        sort_check(arr,i,InsertionSort,f3);
        sort_check(arr,i,SelectionSort,f3);
        sort_check(arr,i,CountingSort,f3);
        sort_check(arr,i,HeapSort,f3);

        f3<<endl;
        delete arr;
    }

    f4 << "N;"
       << "BubbleSort;"
       << "InsertionSort;"
       << "SelectionSort;"
       << "CountingSort;" 
       << "HeapSort;" << endl;
    for (int i = 1000; i < 36000; i += 1000)
    {
        f4 << i << ";";
        int *arr = new int[i];
        Fill4(arr,i);

        sort_check(arr,i,BubbleSort,f4);
        sort_check(arr,i,InsertionSort,f4);
        sort_check(arr,i,SelectionSort,f4);
        sort_check(arr,i,CountingSort,f4);
        sort_check(arr,i,HeapSort,f4);

        f4<<endl;
        delete arr;
    }
    return 0;
}