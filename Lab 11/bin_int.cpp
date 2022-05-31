#include <bits/stdc++.h>
using namespace std;

double f1(double x)
{
    return 14 * x;
}
double f2(double x)
{
    return 100 * log(x);
}
double f3(double x)
{
    return 0.03 * x * x * x;
}
int bin_search(vector<int> arr, int x)
{
    int low = 0, high = arr.size() - 1, mid;
    while (low < high)
    {

        mid = (high + low) / 2;

        if (x > arr[mid])
            low = mid + 1;
        else if (x < arr[mid])
            high = mid - 1;
        else
            return mid;
    }
    if (arr[low] == x)
        return low;
    if (arr[high] == x)
        return high;

    return -1;
}
int int_search(vector<int> arr, int x)
{
    int low = 0, high = arr.size() - 1, mid;
    while (arr[low] < x && arr[high] > x)
    {
        if (low == high)
            break;
        mid = low + ((high - low) * (x - arr[low])) / (arr[high] - x);

        if (x > arr[mid])
            low = mid + 1;
        else if (x < arr[mid])
            high = mid - 1;
        else
            return mid;
    }
    if (arr[low] == x)
        return low;
    if (arr[high] == x)
        return high;

    return -1;
}

vector<double> FormArr(double (*func)(double),
                       double start = 0, double end = 20,
                       double step = 0.1)
{
    vector<double> arr;
    for (double x = start; x <= end; x += step)
    {
        arr.push_back(func(x));
    }
    return arr;
}

int main()
{
    vector<double> arr_f1 = FormArr(f1),
                   arr_f2 = FormArr(f2),
                   arr_f3 = FormArr(f3);
    
    return 0;
}