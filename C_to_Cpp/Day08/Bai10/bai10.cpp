#include<iostream>
#include<string>

using namespace std;

float chiphidatve(int soluong,string loaive,bool sinhvien){
	float tongchiphi=0;
	if(loaive == "NgoiMem"){
		tongchiphi=soluong * 300000;
	}
	else if(loaive == "GiuongNam"){
		tongchiphi=soluong * 500000;
	}
	else 	cout << "\nLoai ve khong phu hop";
	
	cout << "\nThanh toan thanh cong";
	if(sinhvien)	return tongchiphi * 0.8;
	else			return tongchiphi;
}
int main(){
	string loaive,sv;
	int soluongve;
	bool sinhvien;
	
	cout << "Nhap ten loai ve can dat :";	cin >> loaive;
	cout << "Nhap so luong ve can dat :";	cin >> soluongve;
	cout << "Co phai sinh vien khong :" ;	cin >> sv;
	if(sv=="co")	sinhvien=1;
	else			sinhvien=0;
	float tongchiphi = chiphidatve(soluongve,loaive,sinhvien);
	cout << "\nChi phi dat ve la :" << tongchiphi;
	
	return 0;
}
