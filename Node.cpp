/**
* Code by Phan Van Hoai IT1 - K58 UTC
*/
#ifndef NODE_CPP
#define NODE_CPP 0
#include "SinhVien.cpp"

class Node {
private:
	SinhVien sv;
	Node *next;
	Node *prev;
public:
	Node() {
		this->next = NULL;
		this->prev = NULL;
	}
	void setSinhVien(SinhVien sv) {
		this->sv = sv;
	}
	SinhVien getSinhVien() {
		return sv;
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

