/**
* Code by Phan Van Hoai IT1 - K58 UTC
*/
#ifndef APSV_CPP
#define APPSV_CPP 1
#include "DblList.cpp"
#include "DblItr.cpp"
#include "SinhVien.cpp"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class AppSV {
private:
	DblList<SinhVien> x;
public:
	int menu();
	void run();
	void InsertFirst();
	void InsertLast();
	void Remove();
	void Replace();
	void Find();
	void DisplayList();	
 };
 
 int AppSV::menu() {
 	int choice;
 	cout << "CHUONG TRINH QUAN LY SINH VIEN" << endl << endl;
 	cout << "2.Them mot sinh vien vao cuoi danh sach." << endl;
 	cout << "3.Xoa bo mot sinh vien khoi danh sach." << endl;
 	cout << "4.Thay the mot sinh vien moi trong danh sach." << endl;
 	cout << "5.Hien thi danh sach sinh vien." << endl;
 	cout << "7.Tim kiem sinh vien theo ten." << endl;
 	cout << "6.Thoat." << endl;
 	cout << "Ban chon ? ";
 	cin >> choice;
 	return choice;
 }
 
 void AppSV::run() {
 	while (1) {
 		system("cls");
 		system("COLOR 2F");
 		int choice = menu();
 		system("cls");
 		switch(choice) {
 			case 2:InsertLast();
 				break;
 			case 3:Remove();
 				break;
 			case 4:Replace();
 				break;
 			case 5:DisplayList();
 				break;
 			case 7:Find();
 				break;
 			case 6:exit(0);
 			default:cout << "\nBan nhap khong dung!";
 				break;
		 }
		getch();
	 }
 }

void AppSV::InsertLast() {
	SinhVien sv;
	cout << "THEM MOT SINH VIEN CUOI DANH SACH" << endl;
 	cout << "Nhap thong tin sinh vien: " << endl;
 	sv.setInfo();
 	if (x.insertLast(sv)) {
	 	cout << "Them sinh vien \"" << sv.getHoTen() << "\" thanh cong!" << endl;
	}
	else {
		cout << "Them sinh vien \"" << sv.getHoTen() << "\" khong thanh cong!" << endl; 
	}
}
void AppSV::Remove() {
	cout << "XOA BO SINH VIEN" << endl;
	if (x.isEmpty()) cout << "Danh sach sinh vien hien dang rong!" << endl;
	else {
		int sttDel;
		cout << "Nhap vi tri tri sinh vien can xoa: ";
		cin >> sttDel;
		Node<SinhVien> *p;
		p = x.getNode(sttDel);
		if (p != NULL) {
			string masvDel = p->getElem().getMaSv();
			string hoTenDel = p->getElem().getHoTen();	
			x.remove(p);
			cout << "\nDa xoa thanh cong sinh vien \"" << hoTenDel << " - " << masvDel << "\" !" << endl;
		}
		else {
			cout << "\nXoa khong thanh cong!";
		}
	}
}
void AppSV::Replace() {
	SinhVien sv;
	int i;
	cout << "THAY THE MOT SINH VIEN TRONG DANH SACH" << endl;
 	cout << "Nhap thong tin sinh vien: " << endl;
 	sv.setInfo();
 	cout << "Vi tri sinh vien can thay the ( > 0 va < "<< x.size()+1 << " ): ";
		cin >> i;
	if (i < 1 || i > x.size()) {
		cout << "Thay the sinh vien khong thanh con ! Loi vi tri !" << endl;
	}
 	else {
 		string hoTenBefore = x.getNode(i)->getElem().getHoTen();
 		x.replace(x.getNode(i),sv);
 		string hoTenAfter = x.getNode(i)->getElem().getHoTen();
 		cout << "Thay the sinh vien \"" << hoTenBefore << "\" bang sinh vien \"" << hoTenAfter << "\" thanh cong!" << endl;
	 }
}

void AppSV::Find() {
	string hoTen ="";
	int dem = 0;
	SinhVien sv;
	cout << "TIM KIEM SINH VIEN TRONG DANH SACH" << endl;
	cin.ignore();
 	cout << "Nhap ho ten sinh vien can tim: ";
 	getline(cin,hoTen);
 	cout << endl << setw(15) << "MA SINH VIEN" << setw(30) << "HO TEN" << "\t\t NGAY SINH" << setw(15) << "GIOI TINH" << setw(15) << "LOP" << endl << endl;
 	DblItr<SinhVien> itr(x);
	while (itr.hasNext()) {
		sv = itr.next();
		if (hoTen.compare(sv.getHoTen()) == 0) {
			sv.displayInfo();
			dem++;
		}
	}
	cout << "\nTong cong: " << dem; 
}

void AppSV::DisplayList() {
	if (x.isEmpty()) cout << "Danh sach SV hien dang trong!" << endl;
	else {
		cout << "DANH SACH SINH VIEN : " << endl << endl;
		cout << setw(15) << "MA SINH VIEN" << setw(30) << "HO TEN" << "\t\t NGAY SINH" << setw(15) << "GIOI TINH" << setw(15) << "LOP" << endl << endl;
		DblItr<SinhVien> itr(x);
		while (itr.hasNext()) {
			itr.next().displayInfo();
		}
		cout << endl << setw(95) << "Tong cong:" << x.size() << endl;
	}
}
	
#endif
