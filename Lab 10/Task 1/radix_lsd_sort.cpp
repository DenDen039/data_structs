#include <bits/stdc++.h>
using namespace std;
const int M = 200;
int R = 2;
void RadixSort(vector<int> &arr)
{
    vector<int> bucket(arr.size(), 0);

    int max_value = *max_element(arr.begin(), arr.end()), digit_pos = 1, cut = pow(10, R);

    while (max_value / digit_pos > 0)
    {
        vector<int> digits(cut, 0);

        for (auto i : arr)
            digits[i / digit_pos % cut] += 1;
        for (int i = 1; i < digits.size(); i++)
            digits[i] += digits[i - 1];
        for (int i = arr.size() - 1; i >= 0; i--)
            bucket[--digits[arr[i] / digit_pos % cut]] = arr[i];
        for (int i = 0; i < arr.size(); i++)
            arr[i] = bucket[i];
        digit_pos *= cut;
    }
}
void HeapSort(vector<int> &arr)
{
    make_heap(arr.begin(), arr.end());
    sort_heap(arr.begin(), arr.end());
}
void sort_check(vector<int> arr, void (*sort_func)(vector<int> &))
{
    double start_time;
    double end_time;
    vector<int> temp_arr = arr;
    vector<int> sorted_arr = arr;

    sort(sorted_arr.begin(), sorted_arr.end());

    start_time = clock();
    sort_func(temp_arr);
    end_time = clock();

    if (!(sorted_arr == temp_arr))
    {
        throw string("sorted uncorrectly!");
    }
    cout << (end_time - start_time) / CLOCKS_PER_SEC << "\t";
}
void Fill1(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr.push_back((rand() % 9 + 1) * int(pow(10, 7)) + rand() % int(pow(10, 8)));
    }
}
void Fill2(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr.push_back(size - i);
    }
}
void Fill3(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr.push_back(i);
    }
}
void Fill4(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr.push_back(10000000);
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
         << "\t"
         << "Radix5\t"
         << "Radix6"
         << "\t\n";
    for (int count = 100000; count <= 1000000; count += 50000)
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
        R = 5;
        sort_check(arr, RadixSort);
        R = 6;
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
         << "\t"
         << "Radix5\t"
         << "Radix6"
         << "\t\n";
    for (int count = 100000; count <= 1000000; count += 50000)
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
        R = 5;
        sort_check(arr, RadixSort);
        R = 6;
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
         << "\t"
         << "Radix5\t"
         << "Radix6"
         << "\t\n";
    for (int count = 100000; count <= 1000000; count += 50000)
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
        R = 5;
        sort_check(arr, RadixSort);
        R = 6;
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
         << "\t"
         << "Radix5\t"
         << "Radix6"
         << "\t\n";
    for (int count = 100000; count <= 1000000; count += 50000)
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
        R = 5;
        sort_check(arr, RadixSort);
        R = 6;
        sort_check(arr, RadixSort);
        cout << "\n";
    }
    return 0;
}