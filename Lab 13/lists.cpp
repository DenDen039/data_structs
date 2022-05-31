#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class SkipList
{
private:
    class Node
    {
    public:
        unique_ptr<shared_ptr<Node>[]> arr;
        int key;
        int levels;
        Node(int key, int levels)
        {
            this->key = key;
            this->arr = make_unique<shared_ptr<Node>[]>(levels + 1);
            for(int i = 0; i < levels;i++)
            {
                this->arr[i] = NULL;
            }
            this->levels = levels;
        }
    };
    shared_ptr<Node> root;
    int max_level, cur_level;
    int size;

public:
    SkipList(int max_level)
    {
        this->max_level = max_level;
        this->cur_level = 0;
        this->root = shared_ptr<Node>(new Node(-1, max_level));
        this->size = 0;
    }
    int random_level()
    {
        // int lvl = 0, count;
        // int P = 75;
        // for (int i = 0; i < max_level; i++)
        // {
        //     count = rand() % 101;
        //     if (count > P)
        //         break;
        //     lvl += 1;
        // }
        //return lvl;
        return rand()%max_level;
    };
    int get_levels()
    {
        return cur_level;
    }
    void insert(int key)
    {

        unique_ptr<shared_ptr<Node>[]> nodes_to_update = make_unique<shared_ptr<Node>[]>(max_level+1);
        for(int i = 0; i < max_level;i++)
            nodes_to_update[i] = NULL;
        shared_ptr<Node> cur = this->root;
        for (int i = cur_level; i >= 0; i--)
        {
            while (cur->arr[i] != NULL && cur->arr[i]->key < key)
                cur = cur->arr[i];
            nodes_to_update[i] = cur;
        }
        cur = cur->arr[0];
        if (cur == NULL || cur->key != key)
        {
            int rlevel = random_level();
            if (rlevel > cur_level)
            {
                for (int i = cur_level + 1; i < rlevel + 1; i++)
                    nodes_to_update[i] = root;
                cur_level = rlevel;
            }
            shared_ptr<Node> node(new Node(key, rlevel));
            for (int i = 0; i <= rlevel; i++)
            {
                node->arr[i] = nodes_to_update[i]->arr[i];
                nodes_to_update[i]->arr[i] = node;
            }
            size++;
        }
    }
    tuple<int,int> find(int key)
    {
        shared_ptr<Node> cur = root;
        int moves = 0;
        int overall_moves = 0;
        for (int i = cur_level; i >= 0; i--)
        {
            if (cur->key == key)
                break;
            while (cur->arr[i] != NULL && cur->arr[i]->key <= key)
            {
                moves++;
                cur = cur->arr[i];
            }
            if (cur->key == key)
                break;
            overall_moves +=moves;
            moves=0;
        }
        return make_tuple(moves,overall_moves);
    }
    void delete_el(int key)
    {
        unique_ptr<shared_ptr<Node>[]> nodes_to_update = make_unique<shared_ptr<Node>[]>(max_level+1);
        for(int i = 0; i < max_level;i++)
            nodes_to_update[i] = NULL;
        shared_ptr<Node> cur = this->root;
        for (int i = cur_level; i >= 0; i--)
        {
            while (cur->arr[i] != NULL && cur->arr[i]->key < key)
                cur = cur->arr[i];
            nodes_to_update[i] = cur;
        }
        cur = cur->arr[0];
        if (cur != NULL && cur->key == key)
        {
            for (int i = 0; i < cur_level; i++)
            {
                if (nodes_to_update[i]->arr[i] != cur)
                    break;
                nodes_to_update[i]->arr[i] = cur->arr[i];
            }
        }
    }
    void display_list()
    {
        cout << "\nSkip List\n";
        for (int i = 0; i <= cur_level; i++)
        {
            shared_ptr<Node> node = root->arr[i];
            cout << "Level " << i << ": ";
            while (node != NULL)
            {
                cout << node->key << " ";
                node = node->arr[i];
            }
            cout << "\n";
        }
    };
};

int main()
{
    srand(time(0));
    vector<int> seq;
    ofstream out;
    
    int N = 4000;
    int M = 50000;
    for(int i = 0; i < N;i++)
        seq.push_back(rand()%(M+1));
    for(int i = 0; i <= 7;i++)
    {
        int levels = pow(2,i);
        out.open (to_string(levels)+".csv");
        out << "index,moves,overall_moves\n";
        SkipList l(levels);
        for(auto num : seq)
            l.insert(num);
        //l.display_list();
        int el = 0;
        for(auto num : seq)
        {
            tuple<int,int> moves = l.find(num);
            out <<to_string(el++)+"," + to_string(get<0>(moves)) + "," + to_string(get<1>(moves)) + "\n";
        }
        cout << l.get_levels() << endl;
        out.close();
    }
    return 0;
}