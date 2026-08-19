#include<iostream>
#include<string>
using namespace std;

class DeTu{
	private:
		string maDeTu;
		string tenDeTu;
		string canhGioi;
		int diemCongHien;		
	public:
		DeTu(){};
		~DeTu(){};
		void nhapDeTu();
		void inDeTu();
		string getCanhGioi();
		int getDiemCongHien();
};

void DeTu::nhapDeTu(){
	cout << "\nMa de tu :";	getline(cin,maDeTu);
	cout << "Ten de tu :" ;	getline(cin,tenDeTu);
	cout << "Canh gioi :" ;	getline(cin,canhGioi);
	cout << "Diem cong hien :";		cin >> diemCongHien;	cin.ignore();
}
void DeTu::inDeTu(){
	cout << "\n" <<maDeTu << " - " << tenDeTu << " - " << canhGioi << " - " << diemCongHien;
}
string DeTu ::getCanhGioi(){
	return canhGioi;
}
int DeTu ::getDiemCongHien(){
	return diemCongHien;
}

void nhapDanhSachDeTu(DeTu *danhSachDeTu, int soLuongDeTu);
void inDanhSachDeTu(DeTu *danhSachDeTu, int soLuongDeTu);
int timKiemDeTu(DeTu *danhSachDeTu, int soLuongDeTu, string canhGioiCanTim, int diemCongHienCanTim, DeTu *deTuThoaMan);
void sapXepGiamDanDiemCongHien(DeTu *danhSachDeTu, int soLuongDeTu);

int main(){
	int soLuongDeTu;
	cout << "Nhap so luong de tu :";	cin >> soLuongDeTu;	cin.ignore();
	DeTu *danhSachDeTu = new DeTu[soLuongDeTu];
	
	nhapDanhSachDeTu(danhSachDeTu, soLuongDeTu);
	cout << "\nDanh sach de tu vua nhap la :\n";
	inDanhSachDeTu(danhSachDeTu, soLuongDeTu);
	
	DeTu *deTuThoaMan = new DeTu[soLuongDeTu];
	string canhGioiCanTim;
	cout << "\nNhap ten canh gioi can tim kiem :";	getline(cin,canhGioiCanTim);
	int diemCongHienCanTim;
	cout << "\nNhap diem cong hien can tim kiem :";	cin >> diemCongHienCanTim;
	int soLuongThoaMan = timKiemDeTu(danhSachDeTu, soLuongDeTu, canhGioiCanTim, diemCongHienCanTim, deTuThoaMan);
	cout << "\nDanh sach de tu thuoc canh gioi " << canhGioiCanTim << " co diem cong hien >=" << diemCongHienCanTim << " la :";
	inDanhSachDeTu(deTuThoaMan, soLuongThoaMan);
	
	sapXepGiamDanDiemCongHien(danhSachDeTu, soLuongDeTu);
	cout << "\nDanh sach de tu sau khi sap xep giam dan theo diem cong hien la :\n";
	inDanhSachDeTu(danhSachDeTu, soLuongDeTu);
		
	delete[] danhSachDeTu;
	delete[] deTuThoaMan;
	return 0;
}
void nhapDanhSachDeTu(DeTu *danhSachDeTu, int soLuongDeTu){
	for(int i=0; i<soLuongDeTu; i++){
		cout << "Nhap thong tin cua de tu thu " << i+1 << " :";
		danhSachDeTu[i].nhapDeTu();
	}
}
void inDanhSachDeTu(DeTu *danhSachDeTu, int soLuongDeTu){
	for(int i=0; i<soLuongDeTu; i++){
		danhSachDeTu[i].inDeTu();
	}
}
int timKiemDeTu(DeTu *danhSachDeTu, int soLuongDeTu, string canhGioiCanTim, int diemCongHienCanTim ,DeTu *deTuThoaMan){
	int soLuongThoaMan = 0;
	for(int i=0; i<soLuongDeTu; i++){
		if(canhGioiCanTim == danhSachDeTu[i].getCanhGioi() && danhSachDeTu[i].getDiemCongHien() >= diemCongHienCanTim){
			deTuThoaMan[soLuongThoaMan] = danhSachDeTu[i];
			soLuongThoaMan++;
		}
	}
	return soLuongThoaMan;
}
void sapXepGiamDanDiemCongHien(DeTu *danhSachDeTu, int soLuongDeTu){
	for(int i=0; i<soLuongDeTu-1; i++){
		for(int j=i+1; j<soLuongDeTu; j++){
			if( danhSachDeTu[i].getDiemCongHien() < danhSachDeTu[j].getDiemCongHien() ){
				DeTu temp = danhSachDeTu[i];
				danhSachDeTu[i] = danhSachDeTu[j];
				danhSachDeTu[j] = temp;
			}
		}
	}
}
