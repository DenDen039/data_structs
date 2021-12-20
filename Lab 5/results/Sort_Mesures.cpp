#include <bits/stdc++.h>
using namespace std;

void Copy(int *dist, int *arr, int size)
{
    memcpy(dist, arr, size * sizeof(int));
}
int partition1(int *arr, int l, int r){
    int m = l;
    for(int i  = l+1; i <= r;i++)
    {
        if(arr[i] < arr[l])
        {
            m++;
            swap(arr[i],arr[m]);
        }
    }
    swap(arr[l],arr[m]);
    return m;
}
void quick_sort1(int *arr,int l, int r)
{
    if (l < r) 
    { 
        int m = partition1(arr,l,r); 
        quick_sort1(arr,l,m - 1); 
        quick_sort1(arr,m+1,r); 
    } 
}
void quick_sort2(int *arr, int l, int r)
{

    int temp = arr[(l + r) / 2], i = l, j = r;
    do
    {
        while (arr[i] < temp)
            i++;
        while (arr[j] > temp)
            j--;

        if (i <= j)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < r)
        quick_sort2(arr, i, r);
    if (l < j)
        quick_sort2(arr, l, j);
}
void quick_sort3(int *arr, int l, int r)
{

    int temp = arr[(l + r) / 2], i = l, j = r;
    do
    {
        while (arr[i] < temp)
            i++;
        while (arr[j] > temp)
            j--;

        if (i <= j)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < r)
        quick_sort3(arr, i, r);
    if (l < j)
        quick_sort3(arr, l, j);
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
void sort_check(int *arr, int size,void (*sort_func)(int *, int, int), ofstream &file)
{
    double start_time;
    double end_time;
    int *temp_arr = new int[size];
    int *sorted_arr = new int[size];

    Copy(sorted_arr,arr,size);
    Copy(temp_arr, arr, size);

    sort(sorted_arr,sorted_arr+size);

    start_time = clock();
    sort_func(temp_arr,0,size-1);
    end_time = clock();
    
    if(!is_equal(sorted_arr,temp_arr,size)){
        throw string("sorted uncorrectly!");
    }
        

    file << (end_time - start_time) / CLOCKS_PER_SEC << ";";

    delete temp_arr;
    delete sorted_arr;
}

int main()
{
    ofstream f("random_values.csv"), f2("increasing_values.csv"), f3("decreasing_values.csv"), f4("same_values.csv");
    srand(time(0));
    system("clear");
    #pragma region 
    f << "N;"
        << "quick_sort1;" 
        << "quick_sort2;" 
        << "quick_sort3;"
        << endl;
    f2 << "N;"
        << "quick_sort1;" 
        << "quick_sort2;" 
        << "quick_sort3;"
        << endl;
    f3 << "N;"
        << "quick_sort1;" 
        << "quick_sort2;" 
        << "quick_sort3;"
        << endl;
    f4 << "N;"
        << "quick_sort1;" 
        << "quick_sort2;" 
        << "quick_sort3;"
        << endl;
    #pragma endregion
    
    try
    {
        int from = 1000,to = 50000,step = 1000;
    
        for (int i = from; i <= to; i += step)
        {
            f << i << ";";
            int *arr = new int[i];
            Fill(arr,i);

            sort_check(arr,i,quick_sort1,f);
            sort_check(arr,i,quick_sort2,f);
            sort_check(arr,i,quick_sort3,f);

            f<<endl;
            delete arr;
        }
        cout << "Fill 1 done" << endl;

        for (int i = from; i <= to; i += step)
        {
            f2 << i << ";";
            int *arr = new int[i];
            Fill2(arr,i);

            sort_check(arr,i,quick_sort1,f2);
            sort_check(arr,i,quick_sort2,f2);
            sort_check(arr,i,quick_sort3,f2);

            f2<<endl;
            delete arr;
        }
        cout << "Fill 2 done" << endl;
        
        for (int i = from; i <= to; i += step)
        {
            f3 << i << ";";
            int *arr = new int[i];
            Fill3(arr,i);

            sort_check(arr,i,quick_sort1,f3);
            sort_check(arr,i,quick_sort2,f3);
            sort_check(arr,i,quick_sort3,f3);

            f3<<endl;
            delete arr;
        }
        cout << "Fill 3 done" << endl;

        for (int i = from; i <= to; i += step)
        {
            f4 << i << ";";
            int *arr = new int[i];
            Fill4(arr,i);

            sort_check(arr,i,quick_sort1,f4);
            sort_check(arr,i,quick_sort2,f4);
            sort_check(arr,i,quick_sort3,f4);

            f4<<endl;
            delete arr;
        }
        cout << "Fill 4 done" << endl;

    }
    catch(string s){
        cout << s;
    }
    return 0;
}