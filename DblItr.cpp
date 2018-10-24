/**
* Code by Phan Van Hoai IT1 - K58 UTC
*/
#ifndef DBLITR_CPP
#define DBLITR_CPP 1
#include "DblList.cpp" 

class DblItr {
private:
	DblList dbl;
	int index;
public:
	DblItr(DblList &d);
	int hasNext();
	SinhVien next();
};

DblItr::DblItr(DblList &d) {
	this->dbl = d;
	this->index = 1;
}

int DblItr::hasNext() {
	if (index <= dbl.size()) return 1;
	return 0;
}

SinhVien DblItr::next() {
	Node *n = dbl.getNode(index);
	index++;
	return n->getSinhVien();
}

#endif
