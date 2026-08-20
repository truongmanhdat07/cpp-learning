#include<iostream>
#include<string>
using namespace std;

struct Hang{
	string maHang;
	string tenHang;
	int tgbh;
};

void nhapDanhSachHang(Hang *danhSachHang, int soLuongHang);
void inDanhSachHang(Hang *danhSachHang, int soLuongHang);
int thongKeHang(Hang *danhSachHang, int soLuongHang, int thoiGianBaoHanh);
bool timKiemHang(Hang *danhSachHang, int soLuongHang, string tenHangCanTim, int &viTriHangCanTim);

int main(){
	int soLuongHang;
	cout << "Nhap so luong hang :";	cin >> soLuongHang;	cin.ignore();
	Hang *danhSachHang = new Hang[soLuongHang];
	
	nhapDanhSachHang(danhSachHang, soLuongHang);
	cout << "\nDanh sach hang vua nhap la :\n";
	inDanhSachHang(danhSachHang, soLuongHang);
	
	int thoiGianBaoHanh;
	cout << "\nNhap thoi gian bao hanh can thong ke :";	cin >> thoiGianBaoHanh;
	int soLuongHangThoaMan = thongKeHang(danhSachHang, soLuongHang, thoiGianBaoHanh);
	cout << "\nSo luong hang co thoi gian bao hanh tu " << thoiGianBaoHanh << " tro len la :" << soLuongHangThoaMan;
	
	string tenHangCanTim;
	cin.ignore();
	cout << "\nNhap ten hang can tim kiem :";	getline(cin, tenHangCanTim);
	
	int viTriHangCanTim = 0;
	if(timKiemHang(danhSachHang, soLuongHang, tenHangCanTim, viTriHangCanTim)){
		cout << "\nTim thay hang " << tenHangCanTim << " tai vi tri " << viTriHangCanTim+1;
		cout << "\nThong tin hang " << tenHangCanTim << " la :\n";
		inDanhSachHang(&danhSachHang[viTriHangCanTim],1);
	}
	else	cout << "\nKhong tim thay hang " << tenHangCanTim << "!";
	
	delete[] danhSachHang;
	return 0;
}
void nhapDanhSachHang(Hang *danhSachHang, int soLuongHang){
	for(int i=0; i<soLuongHang; i++){
		cout << "Nhap thong tin hang thu " << i+1 << " :";
		cout << "\nNhap ma hang :" ;	getline(cin, danhSachHang[i].maHang);
		cout << "Ten hang :";			getline(cin, danhSachHang[i].tenHang);
		cout << "Thoi gian bao hanh :";	cin >> danhSachHang[i].tgbh;	cin.ignore();
	}
}
void inDanhSachHang(Hang *danhSachHang, int soLuongHang){
	for(int i=0; i<soLuongHang; i++){
		cout << danhSachHang[i].maHang << " " << danhSachHang[i].tenHang << " " << danhSachHang[i].tgbh << "\n";
	}
}
int thongKeHang(Hang *danhSachHang, int soLuongHang, int thoiGianBaoHanh){
	int soLuongHangThoaMan = 0;
	for(int i=0; i<soLuongHang; i++){
		if(danhSachHang[i].tgbh >= thoiGianBaoHanh)	soLuongHangThoaMan++;
	}
	return soLuongHangThoaMan;
}
bool timKiemHang(Hang *danhSachHang, int soLuongHang, string tenHangCanTim, int &viTriHangCanTim){
	viTriHangCanTim = 0;
	for(int i=0; i<soLuongHang; i++){
		if(danhSachHang[i].tenHang == tenHangCanTim){
			viTriHangCanTim = i;
			return true;
		}
	}
	viTriHangCanTim = -1;
	return false;
}
