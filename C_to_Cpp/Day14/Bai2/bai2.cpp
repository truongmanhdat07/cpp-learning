#include<iostream>
#include<iomanip>
using namespace std;

class MatHang{
	private:
		string maHang;
		int soLuong;
		int donGia;
	public:
		MatHang(){};
		~MatHang(){};
		void nhapMatHang();
		void inMatHang();
		int getSoLuong();
		int getDonGia();
};

void MatHang::nhapMatHang(){
	cout << "\nNhap ma hang :";	getline(cin, maHang);
	cout << "Nhap don gia :";	cin >> donGia;
	cout << "Nhap so luong :";	cin >> soLuong;
	cin.ignore();
}
void nhapDanhSachMatHang(MatHang *danhSachMatHang, int soLuongMatHang){
	for(int i=0; i<soLuongMatHang; i++){
		cout << "Nhap thong tin mat hang thu " << i+1 << " :";
		danhSachMatHang[i].nhapMatHang();
	}
}

void MatHang::inMatHang(){
	cout << maHang << " - " << donGia << " - " << soLuong << "\n";
}
void inDanhSachMatHang(MatHang *danhSachMatHang, int soLuongMatHang){
	for(int i=0; i<soLuongMatHang; i++){
		danhSachMatHang[i].inMatHang();
	}
}

int MatHang::getSoLuong(){
	return soLuong;
}
int demSoLuongMatHangTheoSoLuong(MatHang *danhSachMatHang, int soLuongMatHang, int nguongSoLuong){
	int demSoLuong = 0;
	for(int i=0; i<soLuongMatHang; i++){
		if(danhSachMatHang[i].getSoLuong() > nguongSoLuong)	demSoLuong++;
	}
	return demSoLuong;
}

int MatHang::getDonGia(){
	return donGia;
}
int demSoLuongMatHangTheoDonGia(MatHang *danhSachMatHang, int soLuongMatHang, int nguongDonGia){
	int demDonGia = 0;
	for(int i=0; i<soLuongMatHang; i++){
		if(danhSachMatHang[i].getDonGia() > nguongDonGia)	demDonGia++;
	}
	return demDonGia;
}
int main(){
	int soLuongMatHang;
	cout << "Nhap so luong mat hang :";	cin >> soLuongMatHang;	cin.ignore();
	MatHang *danhSachMatHang = new MatHang[soLuongMatHang];
	
	nhapDanhSachMatHang(danhSachMatHang, soLuongMatHang);
	cout << "\nDanh sach mat hang vua nhap la :\n";
	inDanhSachMatHang(danhSachMatHang, soLuongMatHang);
	
	int nguongSoLuong;
	cout << "\nNhap nguong so luong mat hang can kiem tra :";	cin >> nguongSoLuong;
	int soMatHangThoaManTheoSoLuong = demSoLuongMatHangTheoSoLuong(danhSachMatHang, soLuongMatHang, nguongSoLuong);
	cout << "\nSo mat hang co so luong lon hon " << nguongSoLuong << " la :" << soMatHangThoaManTheoSoLuong;
	
	int nguongDonGia;
	cout << "\nNhap nguong don gia can kiem tra :";	cin >> nguongDonGia;
	int soMatHangThoaManTheoDonGia = demSoLuongMatHangTheoDonGia(danhSachMatHang, soLuongMatHang, nguongDonGia);
	cout << "\nSo mat hang co don gia lon hon " << nguongDonGia << " la :" << soMatHangThoaManTheoDonGia;
	
	delete[] danhSachMatHang;
	return 0;
}
