#include<iostream>

using namespace std;

void quydoi(int &hapham,int &trungpham,int &thuongpham){
	int trungphamquydoi = hapham/100;
	trungpham += trungphamquydoi;
	hapham = hapham % 100;
	
	int thuongphamquydoi = trungpham/100;
	thuongpham +=thuongphamquydoi;
	trungpham = trungpham % 100;
}
int main(){
	int ha,trung,thuong;
	cout << "Nhap so linh thach ha pham :"		;	cin >> ha;
	cout << "Nhap so linh thach trung pham :"	;	cin >> trung;
	cout << "Nhap so linh thach thuong pham :"	;	cin >> thuong;
	
	quydoi(ha,trung,thuong);
	
	cout << "\nSo linh thach thuong pham la :" << thuong;
	cout << "\nSo linh thach trung pham la :"  << trung;
	cout << "\nSo linh thach ha pham la :"	 << ha;
	
	return 0;
}
