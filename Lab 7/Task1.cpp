#include <bits/stdc++.h>
using namespace std;
vector<int> Merge(vector<int> arr1, vector<int> arr2)
{
    vector<int> temp;
    int n = arr1.size() + arr2.size();
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    for (int i = 0; i < n; i++)
    {
        if (arr1.empty())
        {
            temp.push_back(arr2.back());
            arr2.pop_back();
        }
        else if (arr2.empty())
        {
            temp.push_back(arr1.back());
            arr1.pop_back();
        }
        else if (arr2.back() == arr1.back())
            arr2.pop_back();
        else if (arr2.back() < arr1.back()){
            temp.push_back(arr2.back());
            arr2.pop_back();
        }else{
            temp.push_back(arr1.back());
            arr1.pop_back();
        }
    }
    return temp;
}
void AutoFill(vector<int> &arr, int size, int step)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        arr.push_back(counter);
        counter += step;
    }
}
void Fill(vector<int> &arr, int size)
{
    int element;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        arr.push_back(element);
    }
}
void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size1, size2, step, limit_size = 100;
    vector<int> arr1, arr2;
    system("clear");
    cout << "Enter first array size: ";
    cin >> size1;
    cout << "Enter fill step: ";
    cin >> step;
    AutoFill(arr1, size1, step);
    cout << "First array: ";
    Print(arr1);
    cout << endl;

    while (limit_size > arr1.size())
    {
        cout << "Enter second array size: ";
        cin >> size2;

        cout << "Enter second array: ";
        Fill(arr2, size2);
        sort(arr2.begin(), arr2.end());

        cout << "First array: ";
        Print(arr1);
        cout << "Second array: ";
        Print(arr2);

        arr1 = Merge(arr1, arr2);

        cout << "Merged array: ";
        Print(arr1);
        cout << endl;
    }
    return 0;
}
// Enter first array size: 10
// Enter fill step: 2
// First array: 0 2 4 6 8 10 12 14 16 18

// Enter second array size: 4
// 4 4 1 3
// First array: 0 2 4 6 8 10 12 14 16 18
// Second array: 1 3 4 4