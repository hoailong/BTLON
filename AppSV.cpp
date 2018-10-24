/**
* Code by Phan Van Hoai IT1 - K58 UTC
*/
#ifndef APSV_CPP
#define APPSV_CPP 1
#include "DblList.cpp"
#include "DblItr.cpp"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class AppSV {
private:
	DblList x;
public:
	int menu();
	void run();
	void InsertFirst();
	void InsertLast();
	void Remove();
	void Replace();
	void DisplayList();	
 };
 
 int AppSV::menu() {
 	int choice;
 	cout << "CHUONG TRINH QUAN LY SINH VIEN" << endl << endl;
 	cout << "1.Them mot sinh vien vao dau danh sach." << endl;
 	cout << "2.Them mot sinh vien vao cuoi danh sach." << endl;
 	//cout << "3.Them mot sinh vien vao vi tri bat ky trong danh sach." << endl;
 	cout << "3.Xoa bo mot sinh vien khoi danh sach." << endl;
 	cout << "4.Thay the mot sinh vien moi trong danh sach." << endl;
 	cout << "5.Hien thi danh sach sinh vien." << endl;
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
 			case 1:InsertFirst();
 				break;
 			case 2:InsertLast();
 				break;
 			case 3:Remove();
 				break;
 			case 4:Replace();
 				break;
 			case 5:DisplayList();
 				break;
 			case 6:exit(0);
 			default:cout << "\nBan nhap khong dung!";
 				break;
		 }
		getch();
	 }
 }
 
void AppSV::InsertFirst() {
 	SinhVien sv;
	cout << "THEM MOT SINH VIEN DAU DANH SACH" << endl;
 	cout << "Nhap thong tin sinh vien: " << endl;
 	sv.setInfo();
 	x.insertFirst(sv);
 	cout << "Them sinh vien \"" << sv.getHoTen() << "\" thanh cong!" << endl;
 }
void AppSV::InsertLast() {
	SinhVien sv;
	cout << "THEM MOT SINH VIEN CUOI DANH SACH" << endl;
 	cout << "Nhap thong tin sinh vien: " << endl;
 	sv.setInfo();
 	x.insertLast(sv);
 	cout << "Them sinh vien \"" << sv.getHoTen() << "\" thanh cong!" << endl;
}
void AppSV::Remove() {
	cout << "XOA BO SINH VIEN" << endl;
	if (x.isEmpty()) cout << "Danh sach sinh vien hien dang rong!" << endl;
	else {
		string masvDel;
		string hoTenDel;
		bool deleted = false;
		cout << "Nhap ma sinh vien can xoa: ";
		cin.ignore();
		getline(cin,masvDel);
		int i = 1;
		while (i <= x.size()) {
			string masv = x.getNode(i)->getSinhVien().getMaSv();
			if (masv.compare(masvDel) == 0) {
				hoTenDel = x.getNode(i)->getSinhVien().getHoTen();
				x.remove(x.getNode(i));
				deleted = true;
			}
			else i++;
		}
		if (deleted) cout << "Xoa sinh vien ma sinh vien \"" << masvDel << " - " << hoTenDel << "\" thanh cong!" << endl;
		else cout << "Khong thanh cong ! Ma sinh vien \"" << masvDel << "\" khong ton tai!" << endl;
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
 		string hoTenBefore = x.getNode(i)->getSinhVien().getHoTen();
 		x.replace(x.getNode(i),sv);
 		string hoTenAfter = x.getNode(i)->getSinhVien().getHoTen();
 		cout << "Thay the sinh vien \"" << hoTenBefore << "\" bang sinh vien \"" << hoTenAfter << "\" thanh cong!" << endl;
	 }
}
void AppSV::DisplayList() {
	if (x.isEmpty()) cout << "Danh sach SV hien dang trong!" << endl;
	else {
		cout << "DANH SACH SINH VIEN : " << endl << endl;
		cout << setw(15) << "MA SINH VIEN" << setw(30) << "HO TEN" << "\t\t NGAY SINH" << setw(15) << "GIOI TINH" << setw(15) << "QUE QUAN" << endl << endl;
		DblItr itr(x);
		while (itr.hasNext()) {
			itr.next().displayInfo();
		}
		cout << endl << setw(95) << "Tong cong:" << x.size() << endl;
	}
}
	
#endif
