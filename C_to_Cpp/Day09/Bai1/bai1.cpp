#include<iostream>
#include<string>
using namespace std;

void chuanbi(int soluong,int *&vatlieu){
	vatlieu= new int[soluong];
	for(int i=0;i<soluong;i++){
		cout << "Nhap do tinh khiet cua vat lieu thu " << i+1 << " :";
		cin >> vatlieu[i];
	}
}
void luyenhoa(int *vatlieudon){
	*vatlieudon = (*vatlieudon) *2;
	cout << "\nLuyen hoa thanh cong , vat lieu co do tinh khiet gap doi :" << *vatlieudon;
}
int luyenhoa(int *mangvatlieu,int soluong){
	int tongtinhkhiet=0;
	for(int i=0;i<soluong;i++){
		tongtinhkhiet += mangvatlieu[i];
	}
	return tongtinhkhiet;
}
void dondep(int *mangvatlieu){
	delete [] mangvatlieu;
}
int main(){
	int soluong;
	cout << "Nhap so luong vat lieu :";	cin >> soluong;
	int *tuitruvat = nullptr;
	chuanbi(soluong,tuitruvat);
	
	int k;
	cout << "\nNhap vat lieu muon luyen hoa :" ; cin >> k;
	luyenhoa(&tuitruvat[k-1]);
	int tong = luyenhoa(tuitruvat,soluong);
	cout << "\nTong do tinh khiet cua cac vat lieu la :" << tong;
	dondep(tuitruvat);
	
	return 0;
}
