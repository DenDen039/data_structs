#include <bits/stdc++.h>
using namespace std;
const int M = 200;
int R = 2;
void insertionSort(vector<int> &vec){
   for (auto it = vec.begin(); it != vec.end(); it++){
      auto const insertion_point =
      upper_bound(vec.begin(), it, *it);
      rotate(insertion_point, it, it+1);
   }
}
void radix_sort(vector<int> &arr,int r = 0,int max_r = 8)
{
    if (arr.size() <= M || r == max_r)
    {
        insertionSort(arr);
        return ;
    }
    int cut = int(pow(10,R)),slice = pow(10,max_r-r-R);
    vector<int> buckets[int(pow(10,R))];
    for(int i = 0; i < arr.size();i++)
    {
        int x = arr[i]/slice%cut;
        buckets[x].push_back(arr[i]);
    }
    arr.clear();
    for(auto i : buckets)
    {
        radix_sort(i,r+R,max_r);
        arr.insert(arr.end(),i.begin(),i.end());
    }
    return ;
}
void RadixSort(vector<int>& arr)
{
    radix_sort(arr);
}
void HeapSort(vector<int>& arr)
{
    make_heap(arr.begin(),arr.end());
    sort_heap(arr.begin(),arr.end());
}
void sort_check(vector<int> arr,void (*sort_func)(vector<int>&))
{
    double start_time;
    double end_time;
    vector<int> temp_arr = arr;
    vector<int> sorted_arr = arr;

    sort(sorted_arr.begin(),sorted_arr.end());

    start_time = clock();
    sort_func(temp_arr);
    end_time = clock();
    
    if(!(sorted_arr == temp_arr)){
        cout << "sorted uncorrectly!";
        throw string("sorted uncorrectly!");
    }
    cout << (end_time - start_time) / CLOCKS_PER_SEC << "\t";

}
void Fill1(vector<int>&arr, int size)
{
    for(int i = 0 ; i < size;i++){
        arr.push_back((rand()%9+1) * int(pow(10,7)) + rand()%int(pow(10,8)));
    }
}
void Fill2(vector<int>&arr, int size)
{
    for(int i = 0 ; i < size;i++){
        arr.push_back(size-i);
    }
}
void Fill3(vector<int>&arr, int size)
{
    for(int i = 0 ; i < size;i++){
        arr.push_back(i);
    }
}
void Fill4(vector<int>&arr, int size)
{
    for(int i = 0 ; i < size;i++){
        arr.push_back(30000000);
    }
}
int main()
{
    srand(time(NULL));
    vector<int> arr;
    cout << "==========Random==========\n";
    cout << "N"
         << "\t"
         << "Radix1"
         << "\t"
         << "Radix2"
         << "\t"
         << "Radix3"
         << "\t"
         << "Radix4"
         << "\t\n";
    for (int count = 100000; count <= 300000; count += 50000)
    {
        arr.clear();
        cout << count << "\t";
        Fill1(arr, count);
        R = 1;
        sort_check(arr, RadixSort);
        R = 2;
        sort_check(arr, RadixSort);
        R = 3;
        sort_check(arr, RadixSort);
        R = 4;
        sort_check(arr, RadixSort);
        cout << "\n";
    }
    cout << "==========Dec==========\n";
    cout << "N"
         << "\t"
         << "Radix1"
         << "\t"
         << "Radix2"
         << "\t"
         << "Radix3"
         << "\t"
         << "Radix4"
         << "\t\n";
    for (int count = 100000; count <= 300000; count += 50000)
    {
        arr.clear();
        cout << count << "\t";
        Fill1(arr, count);
        R = 1;
        sort_check(arr, RadixSort);
        R = 2;
        sort_check(arr, RadixSort);
        R = 3;
        sort_check(arr, RadixSort);
        R = 4;
        sort_check(arr, RadixSort);
        cout << "\n";
    }
    cout << "==========Inc==========\n";
    cout << "N"
         << "\t"
         << "Radix1"
         << "\t"
         << "Radix2"
         << "\t"
         << "Radix3"
         << "\t"
         << "Radix4"
         << "\t\n";
    for (int count = 100000; count <= 300000; count += 50000)
    {
        arr.clear();
        cout << count << "\t";
        Fill1(arr, count);
        R = 1;
        sort_check(arr, RadixSort);
        R = 2;
        sort_check(arr, RadixSort);
        R = 3;
        sort_check(arr, RadixSort);
        R = 4;
        sort_check(arr, RadixSort);
        cout << "\n";
    }
    cout << "==========Same==========\n";
    cout << "N"
         << "\t"
         << "Radix1"
         << "\t"
         << "Radix2"
         << "\t"
         << "Radix3"
         << "\t"
         << "Radix4"
         << "\t\n";
    for (int count = 100000; count <= 300000; count += 50000)
    {
        arr.clear();
        cout << count << "\t";
        Fill1(arr, count);
        R = 1;
        sort_check(arr, RadixSort);
        R = 2;
        sort_check(arr, RadixSort);
        R = 3;
        sort_check(arr, RadixSort);
        R = 4;
        sort_check(arr, RadixSort);
        cout << "\n";
    }
    return 0;
}