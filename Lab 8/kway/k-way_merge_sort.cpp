#include <bits\stdc++.h>
#include <stdio.h>
#include <filesystem>
using namespace std;
using std::filesystem::exists;
int M = 50000;
int K = 10;
const int N = 1234567;

void Create_start_file()
{
    ofstream out;
    out.open("input.dat", ios::out | ios::binary);
    if (!out)
    {
        throw string("cannot open the file");
    }
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        out << rand() % 100001;
        if (i != N - 1)
            out << endl;
    }
    out.close();
}
vector<int> Read_from_file(ifstream &fin)
{
    vector<int> arr;
    int temp;
    for (int i = 0; i < M; i++)
    {
        if (fin.eof())
            break;
        fin >> temp;
        arr.push_back(temp);
    }
    return arr;
}
void Serialize(vector<int> arr, int f_num)
{
    ofstream wf;
    wf.open(to_string(f_num) + ".dat", ios::out | ios::binary);
    for (int i = 0; i < arr.size(); i++)
    {

        wf << arr[i];
        if (i != arr.size() - 1)
            wf << endl;
    }
    wf.close();
}
void Clear_temp_files()
{
    for (int i = 1; i <= K; i++)
    {
        remove((to_string(i) + ".dat").c_str());
    }
}
struct num_index
{
    int index_, num_;
    friend bool operator<(const num_index &lhs, const num_index &rhs);
    friend bool operator>(const num_index &lhs, const num_index &rhs);
    num_index(int num, int index)
    {
        index_ = index;
        num_ = num;
    }
    num_index()
    {
        index_ = -1;
        num_ = -1;
    }
};
bool operator<(const num_index &lhs, const num_index &rhs)
{
    return lhs.num_ < rhs.num_;
}
bool operator>(const num_index &lhs, const num_index &rhs)
{
    return lhs.num_ > rhs.num_;
}
void Merge(vector<ifstream *> &file_list)
{

    priority_queue<num_index, vector<num_index>, greater<vector<num_index>::value_type>> q;
    ofstream file;
    file.open("temp_out.dat", ios::out | ios::binary);
    num_index temp;
    for (int i = 0; i < file_list.size(); i++)
    {
        if (!(*file_list[i]).eof())
        {
            (*file_list[i]) >> temp.num_;
            temp.index_ = i;
            q.push(temp);
        }
    }
    while (!q.empty())
    {
        temp = q.top();
        file << temp.num_;
        q.pop();
        if ((*file_list[temp.index_]))
        {
            if ((*file_list[temp.index_]).eof())
                (*file_list[temp.index_]).close();
            else
            {
                (*file_list[temp.index_]) >> temp.num_;
                q.push(temp);
            }
        }
        if (!q.empty())
            file << endl;
    }
    for (int i = 0; i < file_list.size(); i++)
    {
        delete file_list[i];
    }
    file.close();
    remove("output.dat");
    rename("temp_out.dat", "output.dat");
}
int main()
{
    double start_time;
    double end_time;
    Create_start_file();
    ifstream main_file_stream;
    for (; K <= 20; K += 10)
    {
        main_file_stream.open("input.dat", ios::in | ios::binary);
        if (!main_file_stream)
        {
            cout << "Cannot open file!" << endl;
            return 1;
        }
        start_time = clock();
        vector<int> buffer;
        vector<ifstream *> file_list;
        ifstream *temp;
        int i = 0;
        while (!main_file_stream.eof())
        {
            file_list.clear();

            if (exists("output.dat"))
            {
                temp = new ifstream();
                (*temp).open("output.dat", ios::in | ios::binary);
                file_list.push_back(temp);
            }
            i = 1;
            while (i <= K && !main_file_stream.eof())
            {
                buffer = Read_from_file(main_file_stream);
                if (buffer.size() == 0)
                    break;
                sort(buffer.begin(), buffer.end());
                Serialize(buffer, i);
                temp = new ifstream();
                (*temp).open(to_string(i) + ".dat", ios::in | ios::binary);
                file_list.push_back(temp);
                i++;
                if (main_file_stream.eof())
                    break;
            }
            Merge(file_list);
        }
        Clear_temp_files();
        end_time = clock();
        cout << "Time: " << (end_time - start_time) / CLOCKS_PER_SEC << " Files: " << K << " Buffer: " << M << endl;
        main_file_stream.close();
        remove("output.dat");
    }
    return 0;
}