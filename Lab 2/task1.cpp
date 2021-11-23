#include <bits/stdc++.h>
using namespace std;
void BubbleSort(int *arr, int size){
    for(int i = 0; i < size;i++){
        for(int j = 0; j < size;j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }   
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void Copy(int *dist,int *arr,int size){
    for(int j = 0; j < size;j++){
        dist[j] = arr[j];
    }
}
void Fill(int *arr,int size){
    for(int i = 0; i < size;i++){
        arr[i] = rand()%10000;
    }
}
int main (){
    ofstream f("random_values.txt");
    srand(time(0));
    double start_time;
    double end_time; 
    f << "N;" << "BubbleSort;" << "insertionSort;"<<"vibor;"<<"Perechisl;"<<endl;
    for(int i = 100; i < 1000;i+=100){
        f<<i << ";";

        int *arr = new int[i];
        int *temp_arr = new int[i];
        Fill(arr,i);

        Copy(temp_arr,arr,i);
        start_time =  clock();
        BubbleSort(temp_arr,i);
        end_time=  clock();
        f<<(end_time - start_time)/CLK_TCK << ";";

        Copy(temp_arr,arr,i);
        start_time =  clock();
        insertionSort(temp_arr,i);
        end_time=  clock();
        f<<(end_time - start_time)/CLK_TCK << ";" << endl;

        Copy(temp_arr,arr,i);
        start_time =  clock();
        //vibor(temp_arr,i);
        end_time=  clock();
        f<<(end_time - start_time)/CLK_TCK << ";" << endl;

        Copy(temp_arr,arr,i);
        start_time =  clock();
        //Perechisl(temp_arr,i);
        end_time=  clock();
        f<<(end_time - start_time)/CLK_TCK << ";" << endl;

        delete arr;
        delete temp_arr;
    }
    return 0;
}