#include <bits/stdc++.h>
#include <windows.h>
#define VK_SHIFT 0x10
#define VK_CONTROL 0x11
using namespace std;
vector<int> Merge(vector<int> arr1, vector<int> arr2)
{
    vector<int> temp;
    int n = arr1.size() + arr2.size();
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());

    for (int i = 0; i < n; i++)
    {
        if(!temp.empty()){
            if(temp.back() == arr2.back()){
                arr2.pop_back();
                continue;
            } 
        }
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
void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int conver_to_int(string s){
    stringstream num_stream(s);
  int num = 0;
  num_stream >> num;
    return num;
}
int main()
{
    int size1, size2, step, limit_size = 100;
    vector<int> arr1, arr2;
    system("cls");
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

        string str;
        for (int i = 0; i < size2; i++)
        {
            getline(cin, str, '\n');
            if((GetKeyState(VK_SHIFT) & 0x8000) != 0 && (GetKeyState(VK_CONTROL) & 0x8000) != 0)
                return 0;
            if(str != "")
                arr2.push_back(conver_to_int(str));
            else
                i--;
        }
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