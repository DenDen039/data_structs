#include <bits/stdc++.h>
using namespace std;
void sort_strings()
{
    ifstream file("input.txt");
    ofstream outs[256];
    string s;
    for(int i = 0;i < 256;i++)
    {
        outs[i].open(to_string(i)+".txt");
    }
    while(!file.eof()){
        file >> s;
        outs[s.size()] << s << endl;
    }
    ifstream ins[256];
    for(int i = 0;i < 256;i++)
    {
        outs[i].close();
        ins[i].open(to_string(i)+".txt");
    }
    ofstream out("output.txt");
    for(int i =0;i < 256;i++)
    {
        s = "";
        while(!ins[i].eof())
        {
            ins[i] >> s;
            if (s != "")
                out << s << endl;
            s = "";
        }
        ins[i].close();
        remove((to_string(i)+".txt").c_str());
    }
}
string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}
int main ()
{
    ofstream in("input.txt");
    srand(time(0));
    for(int i =0; i < 1000;i++)
    {
        in << gen_random(rand()%255+1);
        if(i != 999)
            in << endl;
    }
    in.close();
    sort_strings();
    return 0;
}