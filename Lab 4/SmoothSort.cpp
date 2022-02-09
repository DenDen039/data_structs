#include <iostream>
using namespace std;
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
}
int main ()
{
    srand(time(0));
    system("clear");
    int size = 5;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % size + 1;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    SmoothSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
            