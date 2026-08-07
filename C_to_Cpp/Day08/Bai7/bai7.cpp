#include<iostream>

using namespace std;

float diemielts(float reading,float listening,float speaking,float writing){
	float diemtrungbinh = (reading + listening + speaking + writing)/4;
	int phannguyen=(int)diemtrungbinh;
	float phanthapphan = diemtrungbinh - phannguyen;
	if(phanthapphan<0.25)					return phannguyen + 0;
	else if(0.25 <= phanthapphan && phanthapphan <0.75)	return phannguyen + 0.5;
	else									return phannguyen + 1;
}
int main(){
	float reading,listening,speaking,writing;
	cout << "Nhap diem Reading :"   ; 	cin >> reading;
	cout << "Nhap diem Listening :"	;	cin >> listening;
	cout << "Nhap diem Speaking :"	;	cin >> speaking;
	cout << "Nhap diem Writing :"	;	cin >> writing;
	
	float overall =	diemielts(reading,listening,speaking,writing);
	if(overall >= 6.5)	cout << "\nChuc mung thi sinh da dat target voi tong diem :" << overall;
	else				cout << "\nCan co gang them ,diem hien tai :" << overall;
	
	return 0;
}
