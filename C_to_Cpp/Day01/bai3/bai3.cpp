#include<iostream>
#include<string>

using namespace std;

bool isPassed(string &name,float score){
	cout << "Sinh vien " << name << " co so diem la :" << score ;
	return(score >=5);
}

int main(){
	string ten;	float diem;
	cout << "Nhap ten sinh vien :";
	cin >> ten;
	cout << "Nhap diem :";
	cin >> diem;
	if(isPassed(ten,diem))	cout << "\nDo";
	else							cout << "\nTruot";
	
	return 0;
}
