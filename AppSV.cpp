/**
* Code by Phan Van Hoai | Vu Quang Minh | Pham Nhat Nam
* IT1 - K58 UTC
*/
#ifndef APSV_CPP
#define APPSV_CPP 1
#include "DblList.cpp"
#include "DblItr.cpp"
#include "SinhVien.cpp"
#include "DoHoa.cpp"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

class AppSV {
private:
	DblList<Student> x;
	DoHoa graph;
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
 	cout << "\tCHUONG TRINH QUAN LY SINH VIEN" << endl << endl;
 	cout << "\t1.Doc danh sach sinh vien tu file vao danh sach." << endl;
 	cout << "\t2.Ghi danh sach sinh vien vao file." << endl;
 	cout << "\t3.Them mot sinh vien vao cuoi danh sach." << endl;
 	cout << "\t4.Xoa bo mot sinh vien khoi danh sach." << endl;
 	cout << "\t5.Hien thi danh sach sinh vien hien co trong danh sach." << endl;
 	cout << "\t6.Chinh sua thong tin sinh vien trong danh sach." << endl;
 	cout << "\t7.Tim kiem sinh vien theo ho va ten." << endl;
 	cout << "\t8.Thong tin chuong trinh." << endl;
 	cout << "\t9.Thoat." << endl;
 	cout << "\tBan chon ? ";
 	cin >> choice;
 	return choice;
 }
 
 void AppSV::run() {
 	graph.resizeConsole(710,350);  // Set mac dinh chieu dai va chieu ngang cho man hinh console
 	while (1) {
 		system("cls");
 		system("COLOR 0B");     // Set mau nen va mau chu man hinh console
 		graph.veKhung(); 		// Ve khung vien
 		int choice = menu();
 		system("cls");
 		graph.veKhung(); 	
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
 			default:cout << "\n\n\tBan nhap khong dung!";
 				break;
		 }
		getch();
	 }
 }

void AppSV::ReadFile() {
	cout << "\tDOC DANH SACH SINH VIEN TU FILE VAO DANH SACH" << endl << endl;
	char file[20];
	cout<<"\tNhap ten file can doc: ";
	cin>>file;
	ifstream ifs(file ,ios::in);
	if (ifs.fail()) {
		cout << "\tFile khong ton tai !";
	}else {
		Student student;
		while (!ifs.eof()) {
			student.readInfor(ifs);
			x.insertLast(student);
		}
		cout << "\tDoc file thanh cong!";
	}
	ifs.close();
}

void AppSV::WriteFile() {
	cout << "\tGHI DANH SACH SINH VIEN VAO FILE" << endl << endl;
	ofstream ofs("output.txt",ios::out);
	ofs << "\t" << left << setw(15) << "Ma sv" << setw(22) << "Ho ten" << setw(10) << "Gioi" << setw(10) << "Lop"  << "Ngay sinh" << endl << endl;			
	DblItr<Student> itr(x);
	while (itr.hasNext()) {
		itr.getNext().writeInfor(ofs);
	}
	cout << "\tGhi file thanh cong!";
	ofs.close();
}

void AppSV::InsertLast() {
	Student sv;
	cout << "\tTHEM MOT SINH VIEN CUOI DANH SACH" << endl << endl;
 	cout << "\tNhap thong tin sinh vien: " << endl;
 	sv.setInfo();
 	if (x.insertLast(sv)) {
	 	cout << "\tThem sinh vien \"" << sv.getName() << "\" thanh cong!" ;
	}
	else {
		cout << "\tThem sinh vien \"" << sv.getName() << "\" khong thanh cong!" ; 
	}
}
void AppSV::Remove() {
	cout << "\tXOA BO SINH VIEN" << endl << endl;
	if (x.isEmpty()) cout << "\tDanh sach sinh vien hien dang rong!";
	else {
		int delIndex;
		cout << "\tNhap vi tri tri sinh vien can xoa: ";
		cin >> delIndex;
		Node<Student> *p;
		p = x.getNode(delIndex);
		if (p != NULL) {
			string masvDel = p->getElem().getIdentificationNumber();
			string hoTenDel = p->getElem().getName()	;
			x.remove(p);
			cout << "\n\tDa xoa thanh cong sinh vien \"" << hoTenDel << " - " << masvDel << "\" !" << endl;
		}
		else {
			cout << "\n\tXoa khong thanh cong!";
		}
	}
}
void AppSV::Update() {
	cout << "\tSUA DOI THONG TIN SINH VIEN TRONG DANH SACH" << endl << endl;
	if (x.isEmpty()) cout << "\tDanh sach SV hien dang trong!";
	else {
		Student sv;
		int updateIndex;
		cout << "\tNhap vi tri tri sinh vien can sua thong tin: ";
		cin >> updateIndex;
		Node<Student> *p;
		p = x.getNode(updateIndex);
		if (p != NULL) {
			Student sv;
			cout << "\n\tThong tin sinh vien hien tai: " << endl;
			cout << "\t" << left << setw(6) << "Stt" << setw(15) << "Ma sv" << setw(22) << "Ho ten" << setw(10) << "Gioi" << setw(10) << "Lop"  << "Ngay sinh" << endl << endl;
			p->getElem().displayInfo(1);
			cout << "\n\tNhap thong tin chinh sua: " << endl;
			sv.setInfo();
			x.replace(p,sv);
			cout << "\n\tChinh sua thong tin sinh vien thanh cong!";
		}
	 	else {
	 		cout << "\n\tChinh sua thong tin sinh vien khong thanh cong!";
		 }
	}
}

void AppSV::Find() {
	cout << "\tTIM KIEM SINH VIEN TRONG DANH SACH" << endl << endl;
	if (x.isEmpty()) cout << "\tDanh sach SV hien dang trong!" ;
	else {
		string nameFind ="";
		int count = 0;
		Student student;
		cin.ignore();
	 	cout << "\tNhap ho ten sinh vien can tim: ";
	 	getline(cin, nameFind);
	 	cout << "\t" << left << setw(6) << "Stt" << setw(15) << "Ma sv" << setw(22) << "Ho ten" << setw(10) << "Gioi" << setw(10) << "Lop"  << "Ngay sinh" << endl << endl;
	 	DblItr<Student> itr(x);
	 	while (itr.hasNext()) {
			student = itr.getNext();
			if (nameFind.compare(student.getName()) == 0) {
				count++;
				student.displayInfo(count);
			}
		}
		cout << right << "\n\t" << setw(71) << "Tong cong:" << setfill('0') << setw(2) << count << setfill(' ') ; 
	}
}

void AppSV::DisplayList() {
	cout << "\tDANH SACH SINH VIEN" << endl << endl;		
	if (x.isEmpty()) cout << "\tDanh sach SV hien dang trong!";
	else {
		cout << "\t" << left << setw(6) << "Stt" << setw(15) << "Ma sv" << setw(22) << "Ho ten" << setw(10) << "Gioi" << setw(10) << "Lop"  << "Ngay sinh" << endl << endl;
		DblItr<Student> itr(x);
		int stt = 0;
		while (itr.hasNext()) {
			stt++;
			itr.getNext().displayInfo(stt);
		}
		cout << right << "\n\t" << setw(71) << "Tong cong:" << setfill('0') << setw(2) << x.size() << setfill(' ') ; 
	}
}

void AppSV::About() {
	cout << "\tTHONG TIN CHUONG TRINH" << endl << endl;		
	cout << "\n\n\tCHUONG TRINH QUAN LY SINH VIEN SU DUNG LIEN KET KEP" << endl << endl;
	cout << "\tBai tap lon mon: Cau truc du lieu va giai thuat." << endl;
	cout << "\tGiao vien huong dan: TS.Hoang Van Thong" << endl;
	cout << "\tNhom thuc hien: 10 - Lop CNTT K58" << endl;
	cout << "\tThanh vien thuc hien: " << endl;
	cout << "\t                    Phan Van Hoai" << endl;
	cout << "\t                    Pham Nhat Nam" << endl;
	cout << "\t                    Vu Quang Minh" << endl;
	cout << "\t     --------------------------------------" ;
}
	
#endif
