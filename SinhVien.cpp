/**
* Code by Phan Van Hoai | Vu Quang Minh | Pham Nhat Nam
* IT1 - K58 UTC
*/
#ifndef SINHVIEN_CPP
#define SINHVIEN_CPP 0

#include<string>
#include<iostream>
#include<iomanip>
#include <fstream>

using namespace std;

class Date {
private:
	int ngay;
	int thang;
	int nam;
public:
	Date() {
		this->ngay = 1;
		this->thang = 1;
		this->nam = 1900;
	}
	void setNgay(int ngay){
		if ((ngay >=1) && (ngay <= 31))
			this->ngay = ngay;	
		else 
			this->ngay = 1;
	}
	int getNgay() {
		return ngay;
	}
	void setThang(int thang){
		if ((thang >=1 ) && (thang <= 12))
			this->thang = thang;	
		else 
			this->thang = 1;
	}
	int getThang() {
		return thang;
	}
	void setNam(int nam){
		if (nam <= 2018)
			this->nam = nam;	
		else 
			this->nam = 1900;
	}
	int getNam() {
		return nam;
	}
	
	
};


class SinhVien {
private:
	string maSv;
	string hoTen;
	Date ngaySinh;
	string gioiTinh;
	string lop;
public:
	SinhVien():ngaySinh() {
		this->maSv = "000000000";
		this->hoTen = "NULL";
		this->gioiTinh = "XXX";
		this->lop = "NULL";
	}
	void setMaSv(string maSv) {
		this->maSv = maSv;
	}
	string getMaSv() {
		return maSv;
	}
	
	void setHoTen(string hoTen) {
		this->hoTen = hoTen;
	}
	string getHoTen() {
		return hoTen;
	}
	
	void setGioiTinh(string gioiTinh) {
		this->gioiTinh = gioiTinh;
	}
	string getGioiTinh() {
		return gioiTinh;
	}
	
	void setLop(string lop) {
		this->lop = lop;
	}
	string getLop() {
		return lop;
	}
	
	void setInfo() {
		int d,m,y;
		char ch;
		cin.ignore();
		cout << "Ma sinh vien: ";
		getline(cin,maSv);
		cout << "Ho ten: ";
		getline(cin,hoTen);
		cout << "Gioi tinh: ";
		getline(cin,gioiTinh);
		cout << "Lop: ";
		getline(cin,lop);cout << "Ngay sinh (dd/mm/yyyy):";
		cin >> d >> ch >> m >> ch >> y;
		ngaySinh.setNgay(d);
		ngaySinh.setThang(m);
		ngaySinh.setNam(y);
		
	}
	
	void displayInfo(int stt) {
		cout << "\t" << left << setw(6) << stt << setw(15) << getMaSv() << setw(22) << getHoTen() << setw(10) << getGioiTinh() << setw(10) << getLop() 
	    << right << setfill('0') << setw(2) << ngaySinh.getNgay() << "/" << setw(2) << ngaySinh.getThang() << "/" << setw(4) << ngaySinh.getNam()  << setfill(' ') << endl;
		
	}
	
	void readInfor(ifstream &ifs) {
		int d,m,y;
		char ch;
		string s = "";
		getline(ifs,maSv);
		getline(ifs,hoTen);
		ifs >> d >> ch >> m >> ch >> y;
		ngaySinh.setNgay(d);
		ngaySinh.setThang(m);
		ngaySinh.setNam(y);
		getline(ifs,s);
		getline(ifs,gioiTinh);
		getline(ifs,lop);
	}
	
	void writeInfor(ofstream &ofs) {
		ofs << "\t" << left << setw(15) << getMaSv() << setw(22) << getHoTen() << setw(10) << getGioiTinh() << setw(10) << getLop() 
	    << right << setfill('0') << setw(2) << ngaySinh.getNgay() << "/" << setw(2) << ngaySinh.getThang() << "/" << setw(4) << ngaySinh.getNam()  << setfill(' ') << endl;
	}
};

#endif

