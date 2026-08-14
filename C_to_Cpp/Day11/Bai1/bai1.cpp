#include<iostream>
#include<cmath>
using namespace std;

void nhapMangSoThuc(float *mangSoThuc, int soLuongPhanTu);
void xuatMangSoThuc(float *mangSoThuc, int soLuongPhanTu);
float trungBinhCongCacSoLonHonGiaTri(float *mangSoThuc,int soLuongPhanTu,float giaTri,int &soLuongThoaMan);
bool dayTangDan(float *mangSoThuc,int soLuongPhanTu);

int main(){
	int soLuongPhanTu;
	cout << "Nhap so luong phan tu cua mang :";	cin >> soLuongPhanTu;
	float *mangSoThuc = new float[soLuongPhanTu];
	
	nhapMangSoThuc(mangSoThuc, soLuongPhanTu);
	cout << "\nMang vua nhap la :";
	xuatMangSoThuc(mangSoThuc, soLuongPhanTu);
	
	float giaTri;
	cout << "\nNhap gia tri x :";	cin >> giaTri;
	int soLuongThoaMan = 0;
	float trungBinh = trungBinhCongCacSoLonHonGiaTri(mangSoThuc, soLuongPhanTu, giaTri, soLuongThoaMan);
	if(soLuongThoaMan != 0){
		cout << "\nSo phan tu co gia tri tuyet doi lon hon x la :" << soLuongThoaMan;
		cout << "\nTrung binh cong cac phan tu thoa man la :" << trungBinh;	
	}
	else{
		cout << "\nKhong co phan tu nao co gia tri tuyet doi lon hon x ";
	}
	
	if(dayTangDan(mangSoThuc,soLuongPhanTu))	cout << "\nDay la day tang dan";
	else			cout << "\nDay khong phai day tang dan";
	
	delete[] mangSoThuc;
	return 0;
}
void nhapMangSoThuc(float *mangSoThuc, int soLuongPhanTu){
	for(int i=0; i<soLuongPhanTu; i++){
		cout << "Nhap phan tu thu " << i+1 << " cua mang :";
		cin >> mangSoThuc[i];
	}
}
void xuatMangSoThuc(float *mangSoThuc,int soLuongPhanTu){
	for(int i=0; i<soLuongPhanTu; i++){
		cout << mangSoThuc[i] << " " ;
	}
}
float trungBinhCongCacSoLonHonGiaTri(float *mangSoThuc, int soLuongPhanTu, float giaTri, int &soLuongThoaMan){
	float tong = 0;
	for(int i=0; i<soLuongPhanTu; i++){
		if(abs(mangSoThuc[i]) > giaTri){
			tong += mangSoThuc[i];
			soLuongThoaMan++;
		}
	}
	if(soLuongThoaMan != 0)	return tong/soLuongThoaMan;
	else return 0;
}
bool dayTangDan(float *mangSoThuc,int soLuongPhanTu){
	for(int i=0; i<soLuongPhanTu-1; i++){
		if(mangSoThuc[i] >= mangSoThuc[i+1])	return false;
	}
	return true;
}
