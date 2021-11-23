#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Stack{
	private:
		T *arr = nullptr;
		int size_limit,cur_size;
	public:
		Stack(int size_limit = 10){
			cur_size = 0;
			this->size_limit = size_limit;
			arr = new T[size_limit];
		}
		Stack(const Stack<T> &stack){
			arr = new T[stack.size_limit];
			for(int i = 0; i < stack.cur_size;i++){
				arr[i] = stack.arr[i];
			}
			size_limit = stack.size_limit;
			cur_size = stack.cur_size;
		}
		Stack(Stack<T> &&stack){
			swap(arr,stack.arr);
			size_limit = stack.size_limit;
			cur_size = stack.cur_size;
		}
		Stack& operator =(const Stack<T> &stack){
			delete arr;
			arr = new T[stack.size_limit];
			for(int i = 0; i < stack.cur_size;i++){
				arr[i] = stack.arr[i];
			}
			size_limit = stack.size_limit;
			cur_size = stack.cur_size;
			return *this;
		}
		Stack& operator =(Stack<T> &&stack){
			delete arr;
			arr = nullptr;
			swap(arr,stack.arr);
			size_limit = stack.size_limit;
			cur_size = stack.cur_size;
			return *this;
		}
		void push(int value){
			if(size_limit <= cur_size){
				throw "stack_full";
			}
			arr[cur_size++] = value;
		}
		T pop(){
			if(cur_size == 0){
				throw "stack_empty";
			}
			return arr[--cur_size];
		}
		void print(){
			for(int i = cur_size-1; i >=0 ;i--)
				cout << arr[i] << " ";
		}
		int size(){
			return cur_size;
		}
		bool empty(){
			return cur_size == 0;
		}
		bool  full(){
			return cur_size == size_limit;
		}
		~Stack(){
			delete arr;
		}
};
template <typename T>
class MultiStack{
	
	struct Node{
		Stack<T> stack;
		Node *prev;
		Node (Node *parent, int size_limit){
			stack = Stack<T>(size_limit);
			prev = parent;
		}
		Node(int size_limit){
			stack = Stack<T>(size_limit);
			prev = nullptr;
		}
	};
	Node *root,*last;
	int stacks_num;
	int size_limit;
	void CreateNewStack(){
		stacks_num++;
		Node *temp = new Node(last,size_limit);
		last = temp;
	}
	public:
		MultiStack(int size_limit = 10){
			this->size_limit = size_limit;
			stacks_num = 1;
			root = new Node(size_limit);
			last = root;
		}
		T pop(){
			if(last->stack.empty() && last == root)
				throw "MultiStack is empty";
			else if(last->stack.empty()){
				Node *temp = last;
				last = last->prev;
				stacks_num--;
				delete temp;
			}
			return last->stack.pop();
		}
		void push(T value){
			if(last->stack.full())
				CreateNewStack();
			last->stack.push(value);
		}
		bool empty(){
			return root == last && root->stack.empty();
		}
		int size(){
			return (stacks_num-1)*size_limit+last->stack.size();
		}
		int num_stacks(){
			return stacks_num;
		}
		void print(){
			Node *temp = last;
			while(temp != nullptr){
				temp->stack.print();
				temp = temp->prev;
			}
			cout << endl;
		}
		~MultiStack(){
			Node *temp;
			while(last != nullptr){
				temp = last;
				last = last->prev;
				delete temp;
			}
		}
};
int main (){
	MultiStack<int> st(2);
	system("cls");
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	
	cout << "MultiStack: ";st.print();
	cout << "Number of elements  " << st.size() << "; Number of stacks " << st.num_stacks() << endl <<endl;

	cout <<"Popped element: " << st.pop() << endl;
	cout <<"Popped element: "<<  st.pop() << endl<<endl;

	cout << "MultiStack: ";st.print();
	cout << "Number of elements  " << st.size() << "; Number of stacks " << st.num_stacks()<< endl;
	return 0;
}