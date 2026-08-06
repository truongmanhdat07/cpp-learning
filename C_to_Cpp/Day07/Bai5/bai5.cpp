#include<iostream>

using namespace std;

float tinhkcal(int thoigian,float quangduong,float &nhipdo){
	nhipdo = thoigian / quangduong;
	if(nhipdo<5) return quangduong * 60 + 50;
	else return quangduong*60 ;
}

int main(){
	int thoigian;
	float quangduong,nhipdo;
	cout << "Nhap quang duong :";	cin >> quangduong;
	cout << "Nhap thoi gian :"  ;	cin >> thoigian;
	
	float tongcalo = tinhkcal(thoigian,quangduong,nhipdo);
	cout << "Nhip do trung binh la :" << nhipdo;
	cout << "\nTong calo tieu thu sau khi chay la :" << tongcalo;
	
	return 0;
}
