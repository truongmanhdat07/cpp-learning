#include<iostream>
#include<string>
using namespace std;

const int current_year = 2026;

int main(){
	string lastname;
	string firstname;
	int birth_year;
	
	cout << "Nhap ho cua ban :";
	cin  >>lastname;
	cout << "Nhap ten cua ban :";
	cin  >>firstname;
	cout << "Nhap nam sinh :";
	cin  >>birth_year;
	string fullname = lastname + " " + firstname;
	
	cout << "Ten cua ban :" << fullname;
	cout << "\nTuoi cua ban :" << current_year-birth_year;
	
	return 0;
}
