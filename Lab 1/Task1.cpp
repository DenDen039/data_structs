#include <bits/stdc++.h>
using namespace std;
template <typename T>
class StaticDeque
{
private:
	T *deque;
	int limit_size, left, right, cur_size = 0;

public:
	StaticDeque(int size = 10)
	{
		limit_size = size;
		cur_size = 0;
		deque = new T[size];
		right = size / 2;
		left = right;
	}
	void push_left(T value)
	{
		if (cur_size == limit_size)
			throw "Overflow error";
		left--;
		if (left < 0)
			left = limit_size - 1;
		deque[left] = value;
		cur_size++;
	}
	void push_right(T value)
	{
		if (cur_size == limit_size)
			throw "Overflow error";
		deque[right++] = value;
		if (right >= limit_size)
			right = 0;
		cur_size++;
	}
	T pop_right()
	{
		if (cur_size > 0)
		{
			right--;
			T ret = deque[right];
			if (right < 0)
				right = limit_size - 1;
			cur_size--;
			return ret;
		}else
			throw "Deque is empty";
	}
	T pop_left()
	{
		if (cur_size > 0)
		{
			T ret = deque[left];
			left++;
			if (left >= limit_size)
				left = 0;
			cur_size--;
			return ret;
		}else
			throw "Deque is empty";
	}
	void get_right()
	{
		if (cur_size == 0)
			throw "Out of range error";
		return deque[right - 1];
	}
	void get_left()
	{
		if (cur_size == 0)
			throw "Out of range error";
		return deque[left];
	}
	bool empty()
	{
		return cur_size == 0;
	}
	int size()
	{
		return cur_size;
	}
	void clear(){
		cur_size = 0;
		right = limit_size / 2;
		left = right;
	}
	void Print()
	{
		int temp_left = left;
		for (int i = 0; i < cur_size; i++)
		{
			if (temp_left >= limit_size)
				temp_left = 0;
			cout << deque[temp_left++] << " ";
		}
		cout << endl;
	}
	~StaticDeque()
	{
		delete deque;
	}
};
template <typename T>
class DynamicDeque
{
private:
	struct Node
	{
		T _value;
		Node *right, *left;
		Node(T value)
		{
			_value = value;
			right = nullptr;
			left = nullptr;
		}
		void connect_right(Node *node)
		{
			right = node;
			node->left = this;
		}
		void connect_left(Node *node)
		{
			left = node;
			node->right = this;
		}
	};
	int cur_size;
	Node *left, *right;

public:
	DynamicDeque()
	{
		left = nullptr;
		right = nullptr;
		cur_size = 0;
	}
	void CreateRootNode(T value)
	{
		left = new Node(value);
		right = left;
	}
	void push_right(T value)
	{
		if (right == nullptr)
			CreateRootNode(value);
		else
		{
			Node *temp = new Node(value);
			right->connect_right(temp);
			right = right->right;
		}
		cur_size++;
	}
	void push_left(T value)
	{
		if (left == nullptr)
			CreateRootNode(value);
		else
		{
			Node *temp = new Node(value);
			left->connect_left(temp);
			left = left->left;
		}
		cur_size++;
	}
	T pop_right()
	{
		if (right == nullptr)
			throw "deque is empty";
		T ret = right->_value;
		Node *temp = right;
		right = right->left;
		if (right != nullptr)
			right->right = nullptr;
		else
			left = nullptr;
		delete temp;
		cur_size--;
		return ret;
	}
	T pop_left()
	{
		if (left == nullptr)
			throw "deque is empty";
		Node *temp = left;
		T ret = left->_value;
		left = left->right;
		if (left != nullptr)
			left->left = nullptr;
		else
			right = nullptr;
		delete temp;
		cur_size--;
		return ret;
	}
	void get_right()
	{
		if (right == nullptr)
			throw "deque is empty";
		return right->_value;
	}
	void get_left()
	{
		if (left == nullptr)
			throw "deque is empty";
		return right->_value;
	}
	bool empty()
	{
		return cur_size == 0;
	}
	int size()
	{
		return cur_size;
	}
	void Print()
	{
		Node *temp = left;
		while (temp != nullptr)
		{
			cout << temp->_value << " ";
			temp = temp->right;
		}
		cout << endl;
	}
	~DynamicDeque()
	{
		Node *temp;
		while (left != nullptr)
		{
			temp = left;
			left = left->right;
			delete temp;
		}
	}
};
int main()
{
	StaticDeque<int> s_d(3);
	DynamicDeque<int> d_d;
	system("cls");
	s_d.push_right(3);
	s_d.push_left(2);
	s_d.push_left(1);
	s_d.Print();
	cout << "Element popped " << s_d.pop_right() << endl;
	s_d.push_left(0);
	s_d.Print();
	cout << "Element popped " <<s_d.pop_left()<< endl;
	s_d.push_right(3);
	s_d.Print();
	system("pause");
	system("cls");
	d_d.push_right(3);
	d_d.push_left(2);
	d_d.push_left(1);
	d_d.Print();
	cout << "Element popped " <<d_d.pop_right()<< endl;
	d_d.push_left(0);
	d_d.Print();
	cout << "Element popped " <<d_d.pop_left()<< endl;
	d_d.push_right(3);
	d_d.Print();
	return 0;
}
