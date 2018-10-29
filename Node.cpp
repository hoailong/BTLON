/**
* Code by Phan Van Hoai | Vu Quang Minh | Pham Nhat Nam
* IT1 - K58 UTC
*/
#ifndef NODE_CPP
#define NODE_CPP 0
#include<iostream>

using namespace std;

template<class T>
class Node {
	private:
		T elem;
		Node *next;
		Node *prev;
	public:
		Node() {
			this->next = NULL;
			this->prev = NULL;
		}
		void setElem(T elem) {
			this->elem = elem;
		}
		T getElem() {
			return elem;
		}
		void setNext(Node *n) {
			this->next = n;
		}
		Node *getNext() {
			return next;
		}	
		void setPrev(Node *p) {
			this->prev = p;
		}
		Node *getPrev() {
			return prev;
		}
	};
#endif

