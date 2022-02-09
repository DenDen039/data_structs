#include <bits/stdc++.h>
using namespace std;

void Copy(int *dist, int *arr, int size)
{
    memcpy(dist, arr, size * sizeof(int));
}
/*
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
int *LeonardoNums(int size)
{
    int limit_size = size;
    int *nums = new int[limit_size];
    nums[0] = 1;
    if (size > 1)
        nums[1] = 1;
    int i = 1;
    while (nums[i++] < size)
    {
        if (limit_size <= i)
        {
            limit_size += 10;
            int *temp = new int[limit_size];
            for (int i = 0; i < limit_size - 10; i++)
            {
                temp[i] = nums[i];
            }
            delete nums;
            nums = temp;
        }
        nums[i] = nums[i - 1] + nums[i - 2] + 1;
    }
    return nums;
}
void RestoreHeap(int *arr, int arr_size, int *heap,int heap_size, int * leonardo_nums, int i )
{
    int current_heap = heap_size-1;
    
    while(current_heap > 0)
    {
        if (i < leonardo_nums[heap[current_heap]]) {
            break;
        }
        int j = i-leonardo_nums[heap[current_heap]];
        if(arr[j] > arr[i])
        {
            if(i-j > 1)
            {
                int right = i-1;
                int left = i-1-leonardo_nums[heap[current_heap]-2];
                if (arr[j] > arr[left] && arr[j] > arr[right])
                    swap(arr[i],arr[j]);
                else 
                    break;
            }
            else 
                swap(arr[i],arr[j]);
                    
        }
        else 
            break;
        current_heap--;
        i = j;
    }

    int cur_heap_size = heap[current_heap];
    while  (cur_heap_size>= 2){
        int right_child = i - 1, right_size_index  = cur_heap_size - 2;
        int left_child = i-1-leonardo_nums[cur_heap_size-2], left_size_index = cur_heap_size - 1;
        if (arr[i] < arr[right_child] || arr[i] < arr[left_child]){
            if (arr[right_child] > arr[left_child])
            {
                swap(arr[i], arr[right_child]);
                i = right_child;
                cur_heap_size = right_size_index;
            }  
            else
            {
                swap(arr[i], arr[left_child]);
                i = left_child;
                cur_heap_size = left_size_index;
            } 
        }
        else
            break;
    }
}
void SmoothSort(int *arr, int size)
{
    int *leonadro_nums =LeonardoNums(size);
    int *heap = new int [size],cur_heap_size = 0;

    for(int i = 0; i < size; i++){
        if(cur_heap_size >= 2 && heap[cur_heap_size-1]+1== heap[cur_heap_size-2])
        {
            cur_heap_size--;
            heap[cur_heap_size-1]++;
        }
        else{
            if(cur_heap_size >= 1 && heap[cur_heap_size-1] == 1)
                heap[cur_heap_size++] = 0;
            else
                heap[cur_heap_size++] = 1;
        }
        RestoreHeap(arr,size,heap,cur_heap_size,leonadro_nums,i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        if (heap[cur_heap_size - 1] < 2)
            cur_heap_size--;
        else
        {
            int cur_size = heap[cur_heap_size-1];
            cur_heap_size--;
            int right_child = i - 1, right_size_index  = cur_size - 2;
            int left_child = i-1-leonadro_nums[cur_size-2], left_size_index = cur_size - 1;

            heap[cur_heap_size++] = left_size_index;
            RestoreHeap(arr,size,heap,cur_heap_size,leonadro_nums,left_child);

            heap[cur_heap_size++] = right_size_index;
            RestoreHeap(arr,size,heap,cur_heap_size,leonadro_nums,right_child);
        }
    }

    delete leonadro_nums;
    delete heap;
}*/
void Merge(int *arr, int l, int m ,int r){
    int *temp = new int[r-l+1]{};
    int p1 = l,p2 = m+1;
    for(int i  = 0; i < r-l+1;i++){
        if(p1 > m)
            temp[i] = arr[p2++];
        else if(p2 > r)
            temp[i] = arr[p1++];
        else if(arr[p1] <= arr[p2])
            temp[i] = arr[p1++];
        else
            temp[i] = arr[p2++];
    }
    for(int i = 0; i < r-l+1;i++)
        arr[l+i] = temp[i];
    delete temp;
}
void mergesort1(int *arr,int l,int r){
    int m = (r+l)/2;
    if(r-l > 0)
    {
        mergesort1(arr,l,m);
        mergesort1(arr,m+1,r);
    }
    else
        return;
    Merge(arr,l,m,r);
}
void MergeSort1(int *arr, int size){
    mergesort1(arr,0,size-1);
}
void mergesort2(int *arr,int l,int r){
    int m = 1;
    while(m <= r)
    {
        int i = l;
        while (i <= r-m)
        {
            Merge(arr,i,i+m-1,min(i+m+m-1,r));
            i+=2*m;
        }
        m+=m;
    }
}
void MergeSort2(int *arr, int size){
    mergesort2(arr,0,size-1);
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
void quick_sort(int *arr, int l, int r)
{

    if (r-l <= 40){
        InsertionSort(arr+l,r-l+1);
        return;
    }
        

    swap(arr[l],arr[rand()%(r-l)+l]);
    int i = l, j = r+1,pivot = arr[l];

    while (i < j)
    {
        do
        {
            i++;
        }while (i <= r && arr[i] < pivot);

        do
        {
            j--;
        }while (arr[j] > pivot);

        if (i > j)
            break;

        swap(arr[i], arr[j]);
    }

    swap(arr[l], arr[j]);

    quick_sort(arr, l, j-1);
    quick_sort(arr, j+1, r);
}
void QuickSort(int *arr, int size){
    quick_sort(arr,0,size-1);
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
        

    file << (end_time - start_time) / CLOCKS_PER_SEC << ";";

    delete temp_arr;
    delete sorted_arr;
}
void create_table_data(void fill_func(int *,int),ofstream &f,int from = 100000,int to = 1000000,int step = 50000){
    f << "N;"
      << "MergeSort1;"
      << "MergeSort2;"
      << "HeapSort;"
      << "QuickSort;"
      << endl;
    for (int i = from; i < to; i += step)
    {
        f << i << ";";
        int *arr = new int[i];
        Fill(arr,i);
            
        sort_check(arr,i,MergeSort1,f);
        sort_check(arr,i,MergeSort2,f);
        sort_check(arr,i,HeapSort,f);
        sort_check(arr,i,QuickSort,f);

        f<<endl;
        delete arr;
    }
}

int main()
{
    ofstream f("random_values.csv"), f2("increasing_values.csv"), f3("decreasing_values.csv"), f4("same_values.csv");
    srand(time(0));
    try
    {
        create_table_data(Fill,f);
        create_table_data(Fill2,f2);
        create_table_data(Fill3,f3);
        create_table_data(Fill4,f4);
    }
    catch(string s){
        cout << s;
    }
    return 0;
}