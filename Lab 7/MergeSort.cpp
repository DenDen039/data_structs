#include <iostream>
using namespace std;
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

int main (){
    int arr[5] = {5,4,3,2,1};
    MergeSort(arr,0,4);
    for(int i = 0; i < 5;i++)
        cout << arr[i] << " ";
    //cout << "KEK";
    return 0;
}