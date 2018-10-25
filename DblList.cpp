/**
* Code by Phan Van Hoai IT1 - K58 UTC
*/
#ifndef DBLLIST_CPP
#define DBLLIST_CPP 1
#include "Node.cpp"

template<class T>
class DblList {
private:
	Node<T> *header;
	Node<T> *trailer;
public:
	DblList();
	int size();
	int isEmpty();
	
	Node<T> *getFirst();
	Node<T> *getNode(int x);
//	Node<T> *insertFirst(SinhVien elem);
	Node<T> *insertLast(T elem);
	void remove(Node<T> *n);
	void replace(Node<T> *p, T elem);
};

template<class T>
DblList<T>::DblList() {
	header = trailer = NULL;
}

template<class T>
int DblList<T>::size() {
	if (header == NULL) return 0;
	int s = 1;
	Node<T> *n = header;
	while (n->getNext() != NULL) {
		s++;
		n = n->getNext();
	}
	return s;
}

template<class T>
int DblList<T>::isEmpty() {
	if (header == NULL) return 1;
	return 0;
}

template<class T>
Node<T> *DblList<T>::getFirst() {
	return header;
}

template<class T>
Node<T>* DblList<T>::getNode(int x) {
	if (x == 1) return header;
	if (x == size()) return trailer;
	Node<T> *p = new Node<T>();
	p = header;
	int j = 1;
	while (j < x) {
		p = p->getNext();
		j++;
	}
	return p;
}

//Node<T>* DblList<T>::insertFirst(T elem) {
//	Node<T> *n = new Node<T>();
//	n->setT(elem);
//	if (header == NULL) {
//		header = trailer = n;
//	}
//	else {
//		header->setPrev(n);
//		n->setNext(header);
//		header = n;
//	}
//	return n;
//}

template<class T>
Node<T>* DblList<T>::insertLast(T elem) {
	Node<T> *n = new Node<T>();
	n->setElem(elem);
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

template<class T>
void DblList<T>::remove(Node<T> *n) {
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

template<class T>
void DblList<T>::replace(Node<T> *p, T elem) {
	p->setElem(elem);
}

#endif
