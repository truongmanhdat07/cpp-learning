#include <iostream>
#include <string>
using namespace std;

struct Sach {
	string maSach;
	string tenSach;
	string tenTacGia;
	int giaTien;
};

void nhapDanhSachSach(Sach *danhSach, int soLuong);
void inDanhSachSach(Sach *danhSach, int soLuong);
void timSachTheoTacGia(Sach *danhSach, int soLuong, string tacGiaCanTim);
void sapXepTheoGiaTienGiamDan(Sach *danhSach, int soLuong);

int main() {
	int soLuong;
	cout << "Nhap so luong sach: ";	
	cin >> soLuong;
	cin.ignore();
	
	Sach *danhSach = new Sach[soLuong];
	
	nhapDanhSachSach(danhSach, soLuong);
	
	cout << "\n--- DANH SACH SACH VUA NHAP ---\n";
	inDanhSachSach(danhSach, soLuong);
	
	string tacGiaCanTim;
	cout << "\nNhap ten tac gia can tim: ";
	getline(cin, tacGiaCanTim);
	timSachTheoTacGia(danhSach, soLuong, tacGiaCanTim);
	
	sapXepTheoGiaTienGiamDan(danhSach, soLuong);
	
	cout << "\n--- DANH SACH SAU KHI SAP XEP GIAM DAN ---\n";
	inDanhSachSach(danhSach, soLuong);
	
	delete[] danhSach;
	return 0;
}

void nhapDanhSachSach(Sach *danhSach, int soLuong) {
	for(int i = 0; i < soLuong; i++) {
		cout << "\nNhap sach thu " << i + 1 << ":\n";
		cout << "Nhap ma sach: ";    getline(cin, danhSach[i].maSach);			
		cout << "Nhap ten sach: ";   getline(cin, danhSach[i].tenSach);			
		cout << "Ten tac gia: ";     getline(cin, danhSach[i].tenTacGia);
		cout << "Gia tien: ";        cin >> danhSach[i].giaTien;	
		cin.ignore(); 
	}
}

void inDanhSachSach(Sach *danhSach, int soLuong) {
	for(int i = 0; i < soLuong; i++) {
		cout << danhSach[i].maSach << " - " 
		     << danhSach[i].tenSach << " - " 
		     << danhSach[i].tenTacGia << " - " 
		     << danhSach[i].giaTien << "\n";
	}
}

void timSachTheoTacGia(Sach *danhSach, int soLuong, string tacGiaCanTim) {
	bool daTimThay = false;
	cout << "\n--- KET QUA TIM KIEM ---\n";
	for(int i = 0; i < soLuong; i++) {
		if(danhSach[i].tenTacGia == tacGiaCanTim) {
			cout << danhSach[i].maSach << " - " 
			     << danhSach[i].tenSach << " - " 
			     << danhSach[i].tenTacGia << " - " 
			     << danhSach[i].giaTien << "\n";
			daTimThay = true;
		}
	}
	if(!daTimThay) {
		cout << "Khong co sach nao cua tac gia nay!\n";
	}
}

void sapXepTheoGiaTienGiamDan(Sach *danhSach, int soLuong) {
	for(int i = 0; i < soLuong - 1; i++) {
		for(int j = i + 1; j < soLuong; j++) {
			if(danhSach[i].giaTien < danhSach[j].giaTien) {
				Sach temp = danhSach[i];
				danhSach[i] = danhSach[j];
				danhSach[j] = temp;
			}
		}
	}
}
