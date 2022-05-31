#include <bits/stdc++.h>
using namespace std;
const int N = 50;
void print(vector<int> arr)
{
    for(auto i: arr)
    {
        cout << i << " ";
    }
    cout << "\n";
}
int linear1(vector<int> arr, int x)
{
    arr.push_back(x);
    int i = 0;
    while (arr[i] != x)
    {
        if(arr[i+1] != x)
        {
            i+=2;
            continue;
        }
        i++;
    }
    if(i == arr.size()-1)
        return -1;
    else
        return i;
}
int linear2(vector<int> &arr, int x)
{
    int pos = linear1(arr,x);
    while(pos > 0)
    {
        swap(arr[pos],arr[pos-1]);
        pos--;
    }
    return 0;
}
int linear3(vector<int> &arr, int x)
{
    int pos = linear1(arr,x);
    if(pos == -1)
        return -1;
    swap(arr[pos],arr[pos-1]);
    return pos-1;
}

int main ()
{
    vector<int> arr{1,2,3,4,5};
    cout << linear1(arr,3) << endl;
    cout << linear2(arr,3) << endl;
    cout << linear3(arr,2) << endl;

    return 0;
}