#include <bits/stdc++.h>

using namespace std;

template <typename T> struct Node{
	T value;
	Node<T> *next;

	Node(){
		next = NULL;
	}

	Node(T val){
		value = val;
		next = NULL;
	}
};

template <typename T> struct List{
	Node<T> *start;
	Node<T> *end;
	int size;

	List(){
		start = end = NULL;
		size = 0;
	}

	void push_back(T value){
		Node<T> * temp = new Node<T>(value);

		if(end==NULL){
			start = temp;
		}else{
			end->next = temp;
		}

		end = temp;
		size++;
	}

	void push_front(T value){
		Node<T> *temp = new Node<T>(value);

		if(start==NULL){
			end = temp;
		}else{
			temp->next = start;
		}

		start = temp;
		size++;
	}

	void printList(){
		Node<T> *aux = start;
		while(aux!=NULL){
			cout<<aux->value<<" ";
			aux=aux->next;
		}
		cout<<endl;
	}

	int size(){
		return size;
	}

	bool empty(){
		if(size==0)
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
		return NULL
	}
};

int main(){
	List<int> lista;

	lista.push_back(1);
	lista.push_back(3);
	lista.printList();
	lista.push_front(4);
	lista.printList();

	return 0;
}
