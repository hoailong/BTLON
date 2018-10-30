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
#include <time.h>

time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int year = aTime->tm_year + 1900;

using namespace std;

class Date {
private:
	int birthDay;
	int birthMonth;
	int birthYear;
public:
	Date() {
		this->birthDay = 1;
		this->birthMonth = 1;
		this->birthYear = 1900;
	}
	int setBirthDay(int birthDay){
		if ((birthDay < 1) || (birthDay > 31))			
			return 0;
		else 	
			this->birthDay = birthDay;
	}
	int getBirthDay() {
		return birthDay;
	}
	int setBirthMonth(int birthMonth){
		if ((birthMonth <1 ) || (birthMonth > 12))			
			return 0;
		else 	
			this->birthMonth = birthMonth;
	}
	int getBirthMonth() {
		return birthMonth;
	}
	int setBirthYear(int birthYear){
		if (birthYear > year)			
			return 0;
		else 	
			this->birthYear = birthYear;	
	}
	int getBirthYear() {
		return birthYear;
	}
};


class Student {
private:
	string identificationNumber;  //masinhvien
	string name;
	Date birthDay;
	string sex;
	string studentClass;
public:
	Student():birthDay() {
		this->identificationNumber = "000000000";
		this->name = "NULL";
		this->sex = "XXX";
		this->studentClass = "NULL";
	}
	void capitalizeFirstLetter(string &str)  /// Chuan hoa ho ten 
	{
		bool check;
		check=false;		
		for(int i=0;i<str.length();i++)
		{
			if(!check) {
				if (str.at(i)>='a' && str.at(i)<='z') {
					str.at(i)=str.at(i)-32;  // -32 trong bang ma ascii
				} 
			}
			else {
				if (str.at(i)>='A' && str.at(i)<='Z') {
					str.at(i)=str.at(i)+32;  // +32 trong bang ma ascii
				} 
			}
			check = true;                
			if(str.at(i) != ' ')           // neu khong phai khoang cach thi check = true
				check=true;									
			else							//khong thi false
				check = false;
		}
	}
	
	void capitalizeLetter(string &str) {	//Chuyen thanh chuoi viet hoa
		for(int i=0;i<str.length();i++) {			
			if (str.at(i)>='a' && str.at(i)<='z') {
				str.at(i)=str.at(i)-32;
			} 
		}
	}
	void setIdentificationNumber(string number) {
		this->identificationNumber = number;
	}
	string getIdentificationNumber() {
		return identificationNumber;
	}
	
	void setName(string name) {
		capitalizeFirstLetter(name);
		this->name = name;
	}
	string getName() {
		capitalizeFirstLetter(name);
		return name;
	}
	
	void setSex(string sex) {
		capitalizeFirstLetter(sex);
		this->sex = sex;
	}
	string getSex() {
		capitalizeFirstLetter(sex);
		return sex;
	}
	
	void setStudentClass(string studentClass) {
		capitalizeLetter(studentClass);
		this->studentClass = studentClass;
	}
	string getStudentClass() {
		capitalizeLetter(studentClass);
		return studentClass;
	}
	
	void setInfo() {
		int day, month, year;
		char ch;
		cin.ignore();
		cout << "\tMa sinh vien: ";
		getline(cin,identificationNumber);
		cout << "\tHo ten: ";
		getline(cin, name);
		cout << "\tGioi tinh: ";
		getline(cin, sex);
		cout << "\tLop: ";
		getline(cin, studentClass);
		cout<<"\tNgay sinh (dd/mm/yyyy): ";
		cin >> day >> ch >> month >> ch >> year;
		while(birthDay.setBirthDay(day) == 0 || birthDay.setBirthMonth(month) == 0 || birthDay.setBirthYear(year) == 0){
			if(birthDay.setBirthDay(day) == 0 || birthDay.setBirthMonth(month) == 0 || birthDay.setBirthYear(year) == 0){
				cout<<"\tNhap ngay thang nam khong hop le xin moi nhap lai."<<endl;
			}
			cout<<"\tNgay sinh (dd/mm/yyyy): ";
			cin >> day >> ch >> month >> ch >> year;
		}
	}
	
	void displayInfo(int stt) {
		cout << "\t" << left << setw(6) << stt << setw(15) << getIdentificationNumber() << setw(22) << getName() << setw(10) << getSex() << setw(10) << getStudentClass() 
	    << right << setfill('0') << setw(2) << birthDay.getBirthDay() << "/" << setw(2) << birthDay.getBirthMonth() << "/" << setw(4) << birthDay.getBirthYear()  << setfill(' ') << endl;
		
	}
	
	int readInfor(ifstream &ifs) {
		int day , month , year;
		char ch;
		string s = "";
		getline(ifs,identificationNumber);
		getline(ifs, name);
		ifs >> day >> ch >> month >> ch >> year;
		birthDay.setBirthDay(day);
		birthDay.setBirthMonth(month);
		birthDay.setBirthYear(year);
		getline(ifs,s);
		getline(ifs, sex);
		getline(ifs, studentClass);
	}
	
	void writeInfor(ofstream &ofs) {
		ofs << "\t" << left << setw(15) << getIdentificationNumber() << setw(22) << getName() << setw(10) << getSex() << setw(10) << getStudentClass() 
	    << right << setfill('0') << setw(2) << birthDay.getBirthDay() << "/" << setw(2) << birthDay.getBirthMonth() << "/" << setw(4) << birthDay.getBirthYear()  << setfill(' ') << endl;
	}
};

#endif

