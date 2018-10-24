/**
* Code by Phan Van Hoai IT1 - K58 UTC
*/
#ifndef DBLLIST_CPP
#define DBLLIST_CPP 1
#include "Node.cpp"

class DblList {
private:
	Node *header;
	Node *trailer;
public:
	DblList();
	int size();
	int isEmpty();
	
	Node *getFirst();
	Node *getNode(int x);
	Node *insertFirst(SinhVien sv);
	Node *insertLast(SinhVien sv);
	void remove(Node *n);
	void replace(Node *p, SinhVien sv);
};

DblList::DblList() {
	header = trailer = NULL;
}

int DblList::size() {
	if (header == NULL) return 0;
	int s = 1;
	Node *n = header;
	while (n->getNext() != NULL) {
		s++;
		n = n->getNext();
	}
	return s;
}

int DblList::isEmpty() {
	if (header == NULL) return 1;
	return 0;
}
Node *DblList::getFirst() {
	return header;
}

Node* DblList::getNode(int x) {
	if (x == 1) return header;
	if (x == size()) return trailer;
	Node *p = new Node();
	p = header;
	int j = 1;
	while (j < x) {
		p = p->getNext();
		j++;
	}
	return p;
}

Node* DblList::insertFirst(SinhVien sv) {
	Node *n = new Node();
	n->setSinhVien(sv);
	if (header == NULL) {
		header = trailer = n;
	}
	else {
		header->setPrev(n);
		n->setNext(header);
		header = n;
	}
	return n;
}

Node* DblList::insertLast(SinhVien sv) {
	Node *n = new Node();
	n->setSinhVien(sv);
	if (trailer == NULL) {
		header = trailer = n;
	}
	else {
		trailer->setNext(n);
		n->setPrev(trailer);
		trailer = n;
	}
	return n;
}

void DblList::remove(Node *n) {
	if (n == header) {
		header = header->getNext();
		header->setPrev(NULL);
	}
	else {
		if (n == trailer) {
			trailer = trailer->getPrev();
			trailer->setNext(NULL);
		}
		else {
			n->getPrev()->setNext(n->getNext());
			n->getNext()->setPrev(n->getPrev());
		}
	}
	delete n;
}

void DblList::replace(Node *p, SinhVien sv) {
	p->setSinhVien(sv);
}

#endif
