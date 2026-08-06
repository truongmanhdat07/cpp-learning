#include<iostream>

using namespace std;

float tinhchiphi(float khoiluong,float khoangcach){
	return 15000 * khoiluong + 5000 * khoangcach ;
}

int main(){
	float khoiluong,khoangcach;
	bool hoatoc;
	
	cout << "Nhap khoi luong hang hoa :" 	; cin >> khoiluong;
	cout << "Nhap khoang cach giao hang :"	; cin >> khoangcach;
	cout << "Co su dung giao hang hoa toc khong :" ; cin >> hoatoc;
	
	float chiphicoban= tinhchiphi(khoiluong,khoangcach);
	float tongchiphi;
	if(hoatoc==1)				tongchiphi = chiphicoban * 1.5 ;
	else if(hoatoc==0)   	 	tongchiphi = chiphicoban ;
	
	cout << "\nTong chi phi phai tra la :" << tongchiphi;
	return 0;
}
