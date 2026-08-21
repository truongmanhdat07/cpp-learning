#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class HangHoa{
	private:
		string maHang;
		string tenHang;
		int soLuong;
		float donGia;
		float tongGiaTri;

	public:
		void nhap();
		void xuat();
		float getDonGia();
		float getTongGiaTri();
		int getSoLuong();
		string getMaHang();
		string getTenHang();
};

void HangHoa::nhap(){
	cout << "\nNhap ma hang hoa :";	getline(cin, maHang);
	cout << "Nhap ten hang hoa :";	getline(cin, tenHang);
	cout << "Nhap so luong :";		cin >> soLuong;
	cout << "Nhap don gia :";		cin >> donGia;	cin.ignore();
	tongGiaTri = soLuong * donGia;
}

void HangHoa::xuat(){
	cout << left << setw(10) << maHang << left << setw(20) << tenHang << left << setw(12) << soLuong 
		   << left << setw(12) << donGia << left << setw(15) << tongGiaTri << endl;
}

float HangHoa::getDonGia(){
	return donGia;
}

float HangHoa::getTongGiaTri(){
	return tongGiaTri;
}

int HangHoa::getSoLuong(){
	return soLuong;
}

string HangHoa::getMaHang(){
	return maHang;
}
string HangHoa::getTenHang(){
	return tenHang;
}


void nhapHangHoa(HangHoa *danhSachHangHoa, int soLuongHangHoa);
void xuatHangHoa(HangHoa *danhSachHangHoa, int soLuongHangHoa);
void sapXepGiamDanTongGiaTri(HangHoa *danhSachHangHoa, int soLuongHangHoa);
HangHoa* thongKeSoLuongHangHoa(HangHoa *danhSachHangHoa, int soLuongHangHoa, int nguongSoLuong, int &soHangSapHet);
void xuatDanhSachHangHoaSapHet(HangHoa *danhSachHangSapHet, int soHangSapHet, string tenFileOutput, int nguongSoLuong);


int main(){
	int soLuongHangHoa;
	cout << "Nhap so luong hang hoa :";	cin >> soLuongHangHoa; cin.ignore();
	HangHoa *danhSachHangHoa = new HangHoa[soLuongHangHoa];
	
	nhapHangHoa(danhSachHangHoa, soLuongHangHoa);
	cout << "\nDanh sach hang hoa vua nhap la :" << endl;
	xuatHangHoa(danhSachHangHoa, soLuongHangHoa);
	
	sapXepGiamDanTongGiaTri(danhSachHangHoa, soLuongHangHoa);
	cout << "\nDanh sach hang hoa sau khi sap xep giam dan theo tong gia tri la :" << endl;
	xuatHangHoa(danhSachHangHoa, soLuongHangHoa);
	
	int soHangSapHet;
	int nguongSoLuong;
	cout << "\nNhap nguong so luong can kiem tra :";	cin >> nguongSoLuong;
	HangHoa *danhSachHangSapHet = thongKeSoLuongHangHoa(danhSachHangHoa, soLuongHangHoa, nguongSoLuong, soHangSapHet);
	
	string tenFileOutput;
	cin.ignore();
	cout << "\nNhap ten file chua danh sach hang hoa sap het :";	getline(cin, tenFileOutput);
	xuatDanhSachHangHoaSapHet(danhSachHangSapHet, soHangSapHet, tenFileOutput, nguongSoLuong);
	
	delete[] danhSachHangHoa;
	delete[] danhSachHangSapHet;
	return 0;
}
void nhapHangHoa(HangHoa *danhSachHangHoa, int soLuongHangHoa){
	for(int i=0; i<soLuongHangHoa; i++){
		cout << "Nhap thong tin cua hang hoa thu " << i+1 << " :";
		danhSachHangHoa[i].nhap();
	}
}
void xuatHangHoa(HangHoa *danhSachHangHoa, int soLuongHangHoa){
	cout << left << setw(10) << "Ma hang" << left << setw(20) << "ten hang" << left << setw(12) << "so luong" 
		 << left << setw(12) << "don gia" << left << setw(15) << "tong gia tri" << endl;
	
	for(int i=0; i<soLuongHangHoa; i++){
		danhSachHangHoa[i].xuat();
	}
}
void sapXepGiamDanTongGiaTri(HangHoa *danhSachHangHoa, int soLuongHangHoa){
	for(int i=0; i<soLuongHangHoa -1 ; i++){
		for(int j=i+1; j<soLuongHangHoa; j++){
			if( danhSachHangHoa[i].getTongGiaTri() < danhSachHangHoa[j].getTongGiaTri() ){
				HangHoa temp = danhSachHangHoa[i];
				danhSachHangHoa[i] = danhSachHangHoa[j];
				danhSachHangHoa[j] = temp;
			}
		}
	}
}
HangHoa* thongKeSoLuongHangHoa(HangHoa *danhSachHangHoa, int soLuongHangHoa, int nguongSoLuong, int &soHangSapHet){
	soHangSapHet = 0;
	for(int i=0; i<soLuongHangHoa; i++){
		if(danhSachHangHoa[i].getSoLuong() < nguongSoLuong){
			soHangSapHet++;
		}
	}
	if(soHangSapHet == 0)	return nullptr;
	
	HangHoa *danhSachHangHoaSapHet = new HangHoa[soHangSapHet];
	
	int viTri = 0;
	for(int i=0; i<soLuongHangHoa; i++){
		if(danhSachHangHoa[i].getSoLuong() < nguongSoLuong){
			danhSachHangHoaSapHet[viTri] = danhSachHangHoa[i];
			viTri++;
		}
	}
	
	return danhSachHangHoaSapHet;
}
void xuatDanhSachHangHoaSapHet(HangHoa *danhSachHangSapHet, int soHangSapHet, string tenFileOutput,int nguongSoLuong){
	ofstream fileOut(tenFileOutput);
	if(soHangSapHet == 0){
		fileOut << "\nKho hang an toan";
		return;
	}
	fileOut << "\nDanh sach hang hoa co so luong nho hon " << nguongSoLuong << " la :" << endl;
	fileOut << left << setw(10) << "Ma hang" << left << setw(20) << "ten hang" << left << setw(12) << "so luong" 
    		  << left << setw(12) << "don gia" << left << setw(15) << "tong gia tri" << endl;
	
	for(int i=0; i<soHangSapHet; i++){
		fileOut << left << setw(10) << danhSachHangSapHet[i].getMaHang()  
				<< left << setw(20) << danhSachHangSapHet[i].getTenHang() 
				<< left << setw(12) << danhSachHangSapHet[i].getSoLuong() 
				<< left << setw(12) << danhSachHangSapHet[i].getDonGia() 
				<< left << setw(15) << danhSachHangSapHet[i].getTongGiaTri() << endl; 
	}
	cout << "\nDa xuat danh sach hang hoa sap het vao file " << tenFileOutput << " thanh cong!" << endl;
}
