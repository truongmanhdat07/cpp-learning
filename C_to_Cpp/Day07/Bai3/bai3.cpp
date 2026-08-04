#include<iostream>
#include<string>
using namespace std;

void xethocbong(double gpa,int drl,string &loaihb,bool &duocnhan){
	if(gpa >= 3.6 && drl >= 90){
		loaihb = "Xuat sac";
		duocnhan = true;
	}
	else if(gpa >= 3.2 && drl >= 80){
		loaihb = "Gioi";
		duocnhan = true;
	}
	else {
		loaihb = "Khong";
		duocnhan = false;
	}

}

int main(){
	double gpa;
	int drl;
	string loaihocbong;
	bool duocnhan;
	
	cout << "Nhap gpa :";	cin >> gpa;
	cout << "Nhap diem ren luyen :";	cin >> drl;
	
	xethocbong(gpa,drl,loaihocbong,duocnhan);
	if(duocnhan)	cout << "\nChuc mung sinh vien vua nhan duoc hoc bong loai :" << loaihocbong;
	else			cout << "\nKhong du dieu kien xet hoc bong";
	
	return 0;
}
