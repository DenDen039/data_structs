#include <bits/stdc++.h>
using namespace std;
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

int main ()
{
    int arr[5] = {5,4,3,2,1};
    quick_sort1(arr,0,4);
    for(int i = 0; i < 5;i++){
        cout << arr[i] << " ";
    }
    return 0;
}