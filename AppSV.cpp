/**
* Code by Phan Van Hoai | Vu Quang Minh | Pham Nhat Nam
* IT1 - K58 UTC
*/
#ifndef APSV_CPP
#define APPSV_CPP 1
#include "DblList.cpp"
#include "DblItr.cpp"
#include "SinhVien.cpp"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

class AppSV {
private:
	DblList<SinhVien> x;
public:
	int menu();
	void run();
	void ReadFile();
	void WriteFile();
	void InsertFirst();
	void InsertLast();
	void Remove();
	void Update();
	void Find();
	void DisplayList();	
	void About();
 };
 
 int AppSV::menu() {
 	int choice;
 	cout << "CHUONG TRINH QUAN LY SINH VIEN" << endl << endl;
 	cout << "1.Doc danh sach sinh vien tu file vao danh sach." << endl;
 	cout << "2.Ghi danh sach sinh vien vao file." << endl;
 	cout << "3.Them mot sinh vien vao cuoi danh sach." << endl;
 	cout << "4.Xoa bo mot sinh vien khoi danh sach." << endl;
 	cout << "5.Hien thi danh sach sinh vien hien co trong danh sach." << endl;
 	cout << "6.Chinh sua thong tin sinh vien trong danh sach." << endl;
 	cout << "7.Tim kiem sinh vien theo ho va ten." << endl;
 	cout << "8.Thong tin chuong trinh." << endl;
 	cout << "9.Thoat." << endl;
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
 			case 1:ReadFile();
 				break;
 			case 2:WriteFile();
 				break;
 			case 3:InsertLast();
 				break;
 			case 4:Remove();
 				break;
 			case 5:DisplayList();
 				break;
 			case 6:Update();
 				break;
 			case 7:Find();
 				break;
 			case 8:About();
 				break;
 			case 9:exit(0);
 			default:cout << "\nBan nhap khong dung!";
 				break;
		 }
		getch();
	 }
 }

void AppSV::ReadFile() {
	ifstream ifs("input.txt",ios::in);
	if (ifs.fail()) {
		cout << "\nFile khong ton tai !";
	}
	else {
		SinhVien sv;
		while (!ifs.eof()) {
			sv.readInfor(ifs);
			x.insertLast(sv);
		}
		cout << "Doc file thanh cong!";
	}
	ifs.close();
}

void AppSV::WriteFile() {
	ofstream ofs("output.txt",ios::out);
	ofs << "\t" << left << setw(15) << "Ma sv" << setw(22) << "Ho ten" << setw(10) << "Gioi" << setw(10) << "Lop"  << "Ngay sinh" << endl << endl;			
	DblItr<SinhVien> itr(x);
	while (itr.hasNext()) {
		itr.next().writeInfor(ofs);
	}
	cout << "Ghi file thanh cong!";
	ofs.close();
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
void AppSV::Update() {
	cout << "SUA DOI THONG TIN SINH VIEN TRONG DANH SACH" << endl;
	if (x.isEmpty()) cout << "Danh sach SV hien dang trong!" << endl;
	else {
		SinhVien sv;
		int sttUp;
		cout << "Nhap vi tri tri sinh vien can xoa: ";
		cin >> sttUp;
		Node<SinhVien> *p;
		p = x.getNode(sttUp);
		if (p != NULL) {
			SinhVien sv;
			cout << "\nThong tin sinh vien hien tai: " << endl;
			cout << "\t" << left << setw(6) << "Stt" << setw(15) << "Ma sv" << setw(22) << "Ho ten" << setw(10) << "Gioi" << setw(10) << "Lop"  << "Ngay sinh" << endl << endl;
			p->getElem().displayInfo(1);
			cout << "\nNhap thong tin chinh sua: " << endl;
			sv.setInfo();
			x.replace(p,sv);
			cout << "\nChinh sua thong tin sinh vien thanh cong!";
		}
	 	else {
	 		cout << "\nChinh sua thong tin sinh vien khong thanh cong!";
		 }
	}
}

void AppSV::Find() {
	if (x.isEmpty()) cout << "Danh sach SV hien dang trong!" << endl;
	else {
		string hoTen ="";
		int dem = 0;
		SinhVien sv;
		cout << "TIM KIEM SINH VIEN TRONG DANH SACH" << endl;
		cin.ignore();
	 	cout << "Nhap ho ten sinh vien can tim: ";
	 	getline(cin,hoTen);
	 	cout << "\t" << left << setw(6) << "Stt" << setw(15) << "Ma sv" << setw(22) << "Ho ten" << setw(10) << "Gioi" << setw(10) << "Lop"  << "Ngay sinh" << endl << endl;
	 	DblItr<SinhVien> itr(x);
	 	while (itr.hasNext()) {
			sv = itr.next();
			if (hoTen.compare(sv.getHoTen()) == 0) {
				dem++;
				sv.displayInfo(dem);
			}
		}
		cout << endl << setw(79) << "Tong cong:" << setfill('0') << setw(2) << x.size() << setfill(' ') << endl; 
	}
}

void AppSV::DisplayList() {
	if (x.isEmpty()) cout << "Danh sach SV hien dang trong!" << endl;
	else {
		cout << "DANH SACH SINH VIEN : " << endl << endl;
		cout << "\t" << left << setw(6) << "Stt" << setw(15) << "Ma sv" << setw(22) << "Ho ten" << setw(10) << "Gioi" << setw(10) << "Lop"  << "Ngay sinh" << endl << endl;
		DblItr<SinhVien> itr(x);
		int stt = 0;
		while (itr.hasNext()) {
			stt++;
			itr.next().displayInfo(stt);
		}
		cout << endl << setw(79) << "Tong cong:" << setfill('0') << setw(2) << x.size() << setfill(' ') << endl;
	}
}

void AppSV::About() {
	cout << " CHUONG TRINH QUAN LY SINH VIEN SU DUNG LIEN KET KEP" << endl << endl;
	cout << " Bai tap lon mon: Cau truc du lieu va giai thuat." << endl;
	cout << " Giao vien huong dan: TS.Hoang Van Thong" << endl;
	cout << " Nhom thuc hien: 10 - Lop CNTT K58" << endl;
	cout << " Thanh vien thuc hien: " << endl;
	cout << "                     Phan Van Hoai" << endl;
	cout << "                     Pham Nhat Nam" << endl;
	cout << "                     Vu Quang Minh" << endl;
	cout << "      --------------------------------------" << endl;
}
	
#endif
