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
#include<algorithm>
#include<cctype>
using namespace std;

time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);
int currentYear = aTime->tm_year + 1900;

void capitalizeFirstLetter(string &str)
{
	bool check;
	check=false;		
	for(int i=0;i<str.length();i++)
	{
		if(check==false && (str.at(i)>='a' && str.at(i)<='z')  )
			str.at(i)=str.at(i)+'A'-'a';  // -32 trong bang ma ascii
			check = true;                
		if(str.at(i) != ' ')           // neu khong phai khoang cach thi check = true
			check=true;									
		else							//khong thi false
			check = false;
	}
}


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
	void setBirthDay(int day){
		this->birthDay = birthDay;	
	}
	int getBirthDay() {
		return birthDay;
	}
	void setBirthMonth(int birthMonth){
		this->birthMonth = birthMonth;
	}
	int getBirthMonth() {
		return birthMonth;
	}
	void setBirthYear(int birthYear){
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
		this->sex = sex;
	}
	string getSex() {
		return sex;
	}
	
	void setStudentClass(string studentClass) {
		this->studentClass = studentClass;
	}
	string getStudentClass() {
		return studentClass;
	}
	
	void setInfo() {
		int day, month, year;
		cin.ignore();
		cout << "\tMa sinh vien: ";
		getline(cin,identificationNumber);
		cout << "\tHo ten: ";
		getline(cin, name);
		cout << "\tGioi tinh: ";
		getline(cin, sex);
		cout << "\tLop: ";
		getline(cin, studentClass);
		cout<<"Nhap ngay sinh:"<<endl;
		cout<<"\tNgay:";
		cin>>day;
		birthDay.setBirthDay(day);
		cout<<"\tThang: ";
		cin>>month;
		birthDay.setBirthMonth(month);
		cout<<"\tNam:";
		cin>>year;
		birthDay.setBirthYear(year);
	}
	
	void displayInfo(int stt) {
		cout << "\t" << left << setw(6) << stt << setw(15) << getIdentificationNumber() << setw(22) << getName() << setw(10) << getSex() << setw(10) << getStudentClass() 
	    << right << setfill('0') << setw(2) << birthDay.getBirthDay() << "/" << setw(2) << birthDay.getBirthMonth() << "/" << setw(4) << birthDay.getBirthYear()  << setfill(' ') << endl;
		
	}
	
	void readInfor(ifstream &ifs) {
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

