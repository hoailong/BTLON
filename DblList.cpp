/**
* Code by Phan Van Hoai | Vu Quang Minh | Pham Nhat Nam
* IT1 - K58 UTC
*/
#ifndef DBLLIST_CPP
#define DBLLIST_CPP 1
#include "Node.cpp"

template<class T>
class DblList {
private:
	Node<T> *header;
	Node<T> *tailer;
	int n;
public:
	DblList();
	int size();
	int isEmpty();
	
	Node<T> *getFirst();
	Node<T> *getNode(int x);
	Node<T> *insertLast(T elem);
	void remove(Node<T> *n);
	void replace(Node<T> *p, T elem);
};

template<class T>
DblList<T>::DblList() {
	header = NULL;
	tailer = NULL;
	n = 0;
}

template<class T>
int DblList<T>::size() {
	return n;
}

template<class T>
int DblList<T>::isEmpty() {
	return n==0;
}

template<class T>
Node<T> *DblList<T>::getFirst() {
	return header;
}

template<class T>
Node<T>* DblList<T>::getNode(int x) {
	if (x < 1 || x > size() || isEmpty()) return NULL;
	if (x == 1) return header;
	if (x == size()) return tailer;
	Node<T> *p = new Node<T>();
	p = header;
	int index = 1;
	while (index < x) {
		p = p->getNext();
		index++;
	}
	return p;
}

template<class T>
Node<T>* DblList<T>::insertLast(T elem) {
	Node<T> *p = new Node<T>();
	p->setElem(elem);
	if (isEmpty()) {
		header = p;
		tailer = p;
	}
	else {
		tailer->setNext(p);
		p->setPrev(tailer);
		tailer = p;
	}
	n++;
	return p;
}

template<class T>
void DblList<T>::remove(Node<T> *p) {
	if (size() == 1) {
		header = NULL;
		tailer = NULL;
	}
	else {
		if (p == header) {
			header = header->getNext();
			header->setPrev(NULL);
		}
		else {
			if (p == tailer) {
				tailer = tailer->getPrev();
				tailer->setNext(NULL);
			}
			else {
				p->getPrev()->setNext(p->getNext());
				p->getNext()->setPrev(p->getPrev());
			}
		}
	}
	n--;
	delete p;
}

template<class T>
void DblList<T>::replace(Node<T> *p, T elem) {
	p->setElem(elem);
}

#endif
