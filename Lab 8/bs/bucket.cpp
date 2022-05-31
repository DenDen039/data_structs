#include <bits/stdc++.h>
using namespace std;
void BucketSort(vector<float> &arr, int bucket_nums)
{
    float min_el = *min_element(arr.begin(), arr.end()),
          max_el = *max_element(arr.begin(), arr.end());
    float range = (max_el - min_el) / bucket_nums;
    vector<float> buckets[bucket_nums];
    for (int i = 0; i < arr.size(); i++)
    {
        int bucket_index = int((arr[i] - min_el) / range);
        if (bucket_index == (arr[i] - min_el) / range && arr[i] != min_el)
            buckets[bucket_index - 1].push_back(arr[i]);
        else
            buckets[bucket_index].push_back(arr[i]);
    }
    for (int i = 0; i < bucket_nums; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
    for (int i = 0, bucket_index = 0, el_index = 0; i < arr.size(); i++)
    {
        arr[i] = buckets[bucket_index][el_index++];
        if (el_index >= buckets[bucket_index].size())
        {
            do{
                bucket_index++;
            }while(buckets[bucket_index].size() == 0);
            el_index = 0;
        }
    }
}
int main()
{
    const int ElementsAmount = 1000000;
    const int StartRange = 1;
    const int EndRange = 100;
    vector<float> unsorted_arr, temp_arr, check_arr;
    double start_time, end_time;
    srand(time(0));

    for(int i = 0; i < ElementsAmount;i++){
        unsorted_arr.push_back(rand()%(EndRange-StartRange)+StartRange + rand()%1000/1000.0);
    }
    try
    {
        for (int num_of_buckets = 100; num_of_buckets <= 10000; num_of_buckets+=100)
        {
            temp_arr = unsorted_arr;
            check_arr = unsorted_arr;
            sort(check_arr.begin(), check_arr.end());

            start_time = clock();
            BucketSort(temp_arr, num_of_buckets);
            end_time = clock();

            if (check_arr != temp_arr)
                throw string("UncorrectSort");

            cout << "Time: " << (end_time - start_time) / CLOCKS_PER_SEC
                 << " Buckets " << num_of_buckets << endl;
        }
    }
    catch (string &e)
    {
        cout << e;
    }
    return 0;
}