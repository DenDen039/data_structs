#include <bits/stdc++.h>
using namespace std;
void SmoothSort(int *arr, int size){ 
    
}
int main()
{
    srand(time(0));
    system("clear");
    int size = 100;
    int *arr = new int[size];
    for(int i = 0; i < size;i++)
        arr[i] = rand()%size+1;
    SmoothSort(arr,size);
    for(int i = 0; i < size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}