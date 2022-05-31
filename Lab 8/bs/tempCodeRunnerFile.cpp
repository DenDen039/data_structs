
    // try
    // {
    //     for (int num_of_buckets = 5; num_of_buckets <= 20; num_of_buckets++)
    //     {
    //         temp_arr = unsorted_arr;
    //         check_arr = unsorted_arr;
    //         sort(check_arr.begin(), check_arr.end());

    //         start_time = clock();
    //         BucketSort(temp_arr, num_of_buckets);
    //         end_time = clock();

    //         if (check_arr != temp_arr)
    //             throw string("UncorrectSort");

    //         cout << "Time: " << (end_time - start_time) / CLOCKS_PER_SEC
    //              << " Buckets " << num_of_buckets << endl;
    //     }
    // }
    // catch (string &e)
    // {
    //     cout << e;
    // }