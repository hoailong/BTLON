/**
* Code by Phan Van Hoai IT1 - K58 UTC
*/
#ifndef SINHVIEN_CPP
#define SINHVIEN_CPP 0

#include<string>
#include<iostream>
#include<iomanip>

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
	string queQuan;
public:
	SinhVien():ngaySinh() {
		this->maSv = "000000000";
		this->hoTen = "NULL";
		this->gioiTinh = "XXX";
		this->queQuan = "NULL";
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
	
	void setQueQuan(string queQuan) {
		this->queQuan = queQuan;
	}
	string getQueQuan() {
		return queQuan;
	}
	
	void setInfo() {
		string s;
		int x;
		cin.ignore();
		cout << "Ma sinh vien: ";
		getline(cin,s);
		setMaSv(s);
		cout << "Ho ten: ";
		getline(cin,s);
		setHoTen(s);
		cout << "Ngay sinh:" << endl;
		cout << "\tNgay: ";
		cin >> x;
		ngaySinh.setNgay(x);
		cout << "\tThang: ";
		cin >> x;
		ngaySinh.setThang(x);
		cout << "\tNam: ";
		cin >> x;
		ngaySinh.setNam(x);
		cin.ignore();
		cout << "Gioi tinh: ";
		getline(cin,s);
		setGioiTinh(s);
		cout << "Que quan: ";
		getline(cin,s);
		setQueQuan(s);	
	}
	
	void displayInfo() {
		cout << setw(15) << getMaSv() << setw(30) << getHoTen() << "\t\t" << setw(2) << ngaySinh.getNgay() << "/" << setw(2) << ngaySinh.getThang() << "/" << setw(4) << ngaySinh.getNam() << setw(15) << getGioiTinh() << setw(15) << getQueQuan() << endl;
		
	}
};

#endif

