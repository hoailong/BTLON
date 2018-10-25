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
	DblList<T> dbl;
	int index;
public:
	DblItr(DblList<T> &d);
	int hasNext();
	T next();
};

template<class T>
DblItr<T>::DblItr(DblList<T> &d) {
	this->dbl = d;
	this->index = 1;
}

template<class T>
int DblItr<T>::hasNext() {
	if (index <= dbl.size()) return 1;
	return 0;
}

template<class T>
T DblItr<T>::next() {
	Node<T> *n = dbl.getNode(index);
	index++;
	return n->getElem();
}

#endif
