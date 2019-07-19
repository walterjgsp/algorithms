#include <bits/stdc++.h>

using namespace std;

template <typename T> class LinkedList{
private:
	struct Node{
		T value;
		Node *next;

		Node(){
			next = NULL;
		}

		Node(T val){
			value = val;
			next = NULL;
		}
	};
	Node *start;
	Node *end;
	int length;

	
public:
	LinkedList(){
		start = end = NULL;
		length = 0;
	}

	void push_back(T value){
		Node * temp = new Node(value);

		if(end==NULL){
			start = temp;
		}else{
			end->next = temp;
		}

		end = temp;
		length++;
	}

	void push_front(T value){
		Node *temp = new Node(value);

		if(start==NULL){
			end = temp;
		}else{
			temp->next = start;
		}

		start = temp;
		length++;
	}

	void printLinkedList(){
		Node *aux = start;
		while(aux!=NULL){
			cout<<aux->value<<" ";
			aux=aux->next;
		}
		cout<<endl;
	}

	int size(){
		return length;
	}

	bool empty(){
		if(length==0)
			return true;
		return false;
	}

	T back(){
		if(end!=NULL)
			return end->value;
		return NULL;
	}

	T front(){
		if(start!=NULL)
			return start->value;
		return NULL;
	}
	
	bool find(T value){
		Node *it = start;
		while(it){
			if(it->value == value){
				return true;
			}
			it = it->next;
		}
		return false;
	}

	void insert_at(T value, int position){
		Node *newNode = new Node(value);
		Node *dummy = new Node(-1), *it = dummy;
		dummy->next = start;
		while(it->next && position>0){
			it = it->next;
			position--;
		}
		newNode->next = it->next;
		it->next = newNode;

		start =  dummy->next;

		if(length == 0){
			end = start;
		}

		delete dummy;
		length++;
	}

	void pop_front(){
		if(length==0)
			return;
		
		Node *to_delete = start;
		start = start->next;
		delete to_delete;

		if(length == 0){
			end = nullptr;
		}
	}

	void remove(T value){
		if(length==0)
			return;
	
		Node *dummy = new Node(-1), *it = dummy;
		dummy->next = start;

		while(it->next && it->next->value != value){
			it = it->next;
		}

		if(it->next){
			Node *to_delete = it->next;
			it->next = to_delete->next;
			length--;

			if(to_delete == start){
				start = it->next;
			}

			delete to_delete;
		}

		delete dummy;

		if(length == 0){
			end = nullptr;
		}
	}
};

int main(){
	LinkedList<int> lista;

	lista.push_back(1);
	lista.push_back(3);
	lista.printLinkedList();
	lista.push_front(4);
	lista.printLinkedList();
	cout<<lista.find(3)<<endl;
	lista.insert_at(2,0);
	lista.printLinkedList();
	lista.insert_at(5,2);
	lista.printLinkedList();
	lista.pop_front();
	lista.printLinkedList();
	lista.remove(4);
	lista.printLinkedList();
	lista.remove(3);
	lista.printLinkedList();

	return 0;
}
