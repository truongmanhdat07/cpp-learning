#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Nguoi{
	private:
		string hoTen;
		int namSinh;
	public:
		void nhap();
		void in();
		string getHoTen();
		int getNamSinh();
};

class SinhVien : public Nguoi{
	private:
		string maSinhVien;
		float diemTrungBinh;
	public:
		void nhap();
		void in();
		string getMaSinhVien();
		float getDiemTrungBinh();
};


void Nguoi::nhap(){
	cout << "\nNhap ho va ten :";	getline(cin, hoTen);
	cout << "Nhap nam sinh :";		cin >> namSinh;	cin.ignore();
}
void Nguoi::in(){
	cout << "\n" <<left << setw(20) << hoTen << left << setw(10) << namSinh;
}
string Nguoi::getHoTen(){
	return hoTen;
}
int Nguoi::getNamSinh(){
	return namSinh;
}


void SinhVien::nhap(){
	Nguoi::nhap();
	cout << "Nhap ma sinh vien :";		getline(cin, maSinhVien);
	cout << "Nhap diem trung binh :";	cin >> diemTrungBinh;	cin.ignore();
}
void SinhVien::in(){
	Nguoi::in();
	cout << left << setw(15) << maSinhVien << left << setw(15) << fixed <<setprecision(2) << diemTrungBinh;
}
string SinhVien::getMaSinhVien(){
	return maSinhVien;
}
float SinhVien::getDiemTrungBinh(){
	return diemTrungBinh;
}


void nhapDanhSachSinhVien(SinhVien *danhSachSinhVien, int soLuongSinhVien);
void inDanhSachSinhVien(SinhVien *danhSachSinhVien, int soLuongSinhVien);
int thongKeDiemTrungBinh(SinhVien *danhSachSinhVien, int soLuongSinhVien, float nguongDiemTrungBinh);
bool timKiemSinhVien(SinhVien *danhSachSinhVien, int soLuongSinhVien, string maSinhVienCanTim, int &viTri);

int main(){
	int soLuongSinhVien;
	cout << "Nhap so luong sinh vien :";	cin >> soLuongSinhVien;		cin.ignore();
	SinhVien *danhSachSinhVien = new SinhVien[soLuongSinhVien];
	
	nhapDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
	inDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
	
	float nguongDiemTrungBinh;
	cout << "\nNhap nguong diem trung binh :";	cin >> nguongDiemTrungBinh;
	int soLuongSinhVienThoaMan = thongKeDiemTrungBinh(danhSachSinhVien, soLuongSinhVien, nguongDiemTrungBinh);
	cout << "\nSo luong sinh vien co diem trung binh cao hon " << nguongDiemTrungBinh << " la :" << soLuongSinhVienThoaMan;
	
	string maSinhVienCanTim;
	cout << "\nNhap ma sinh vien can tim :";	cin.ignore();	getline(cin, maSinhVienCanTim);
	int viTri = -1;
	if(timKiemSinhVien(danhSachSinhVien, soLuongSinhVien, maSinhVienCanTim, viTri)){
		cout << "\nDa tim thay sinh vien co ma sinh vien la " << maSinhVienCanTim;
		inDanhSachSinhVien(&danhSachSinhVien[viTri], 1);
	}
	else	cout << "\nKhong tim thay sinh vien co ma sinh vien " << maSinhVienCanTim;
	
	delete[] danhSachSinhVien;
	return 0;
}


void nhapDanhSachSinhVien(SinhVien *danhSachSinhVien, int soLuongSinhVien){	 
	
	for(int i=0; i<soLuongSinhVien; i++){
		cout << "Nhap thong tin sinh vien thu " << i+1 << " :";
		danhSachSinhVien[i].nhap();
	}
}

void inDanhSachSinhVien(SinhVien *danhSachSinhVien, int soLuongSinhVien){
	cout << left << setw(20) << "\nHo Va Ten" << left << setw(10) << "Nam Sinh"
		 << left << setw(15) << "Ma Sinh Vien" << left << setw(15) << fixed <<setprecision(2) << "Diem Trung Binh";
	
	for(int i=0; i<soLuongSinhVien; i++){
		danhSachSinhVien[i].in();
	}
}

int thongKeDiemTrungBinh(SinhVien *danhSachSinhVien, int soLuongSinhVien, float nguongDiemTrungBinh){
	int dem = 0;
	for(int i=0; i<soLuongSinhVien; i++){
		if(danhSachSinhVien[i].getDiemTrungBinh() >= nguongDiemTrungBinh){
			dem++;
		}
	}
	return dem;
}

bool timKiemSinhVien(SinhVien *danhSachSinhVien, int soLuongSinhVien, string maSinhVienCanTim, int &viTri){
	for(int i=0; i<soLuongSinhVien; i++){
		if(danhSachSinhVien[i].getMaSinhVien() == maSinhVienCanTim){
			viTri = i;
			return true;
		}
	}
	return false;
}
