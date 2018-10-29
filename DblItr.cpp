/**
* Code by Phan Van Hoai | Vu Quang Minh | Pham Nhat Nam
* IT1 - K58 UTC
*/
#ifndef DBLITR_CPP
#define DBLITR_CPP 1
#include "DblList.cpp" 

template<class T>
class DblItr {
private:
	DblList<T> doubleLinkedList; 
	int currentIndex;
public:
	DblItr(DblList<T> &d);
	int hasNext();
	T getNext();
};

template<class T>
DblItr<T>::DblItr(DblList<T> &d) {
	this->doubleLinkedList = d;
	this->currentIndex = 1;
}

template<class T>
int DblItr<T>::hasNext() {
	if (currentIndex <= doubleLinkedList.size())
	return 1;
	return 0;
}

template<class T>
T DblItr<T>::getNext() {
	Node<T> *n = doubleLinkedList.getNode(currentIndex);
	currentIndex++;
	return n->getElem();
}

#endif
