#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class NhanVat{
	private:
		string ten;
		int mau;
	public:
		string getTen();
		int getMau();
		void nhap();
		void in();
};

class Tuong : public NhanVat{
	private:
		string vaiTro;
		int satThuong;
	public:
		string getVaiTro();
		int getSatThuong();
		void nhap();
		void in();
};


string NhanVat::getTen(){
	return ten;
}

int NhanVat::getMau(){
	return mau;
}

string Tuong::getVaiTro(){
	return vaiTro;
}

int Tuong::getSatThuong(){
	return satThuong;
}

void NhanVat::nhap(){
	cout << "\nNhap ten :";		getline(cin, ten);
	cout << "Nhap mau :";		cin >> mau;		cin.ignore();
}

void NhanVat::in(){
	cout << left << setw(20) << ten << left << setw(10) << mau;
}

void Tuong::nhap(){
	NhanVat::nhap();
	cout << "Nhap vai tro :";		getline(cin, vaiTro);
	cout << "Nhap sat thuong :";	cin >> satThuong;	cin.ignore();
}

void Tuong::in(){
	NhanVat::in();
	cout << left << setw(12) << vaiTro << left << setw(12) << satThuong <<endl;
}


void nhapDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong);
void inDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong);
Tuong* thongKeTuongThapMau(Tuong *danhSachTuong, int soLuongTuong, int nguongMau, int &soLuongTuongThapMau);
Tuong* thongKeTuongChuLuc(Tuong *danhSachTuong, int soLuongTuong, int nguongSatThuong, int &soLuongTuongChuLuc);

int main(){
	int soLuongTuong;
	cout << "Nhap so luong tuong :";	cin >> soLuongTuong;    cin.ignore();
	Tuong *danhSachTuong = new Tuong[soLuongTuong];
	
	nhapDanhSachTuong(danhSachTuong, soLuongTuong);
	
	cout << "\nDanh sach tuong vua nhap la :\n";
	inDanhSachTuong(danhSachTuong, soLuongTuong);
	
	int nguongMau;
	cout << "\nNhap nguong mau can thong ke :";		cin >> nguongMau;
	int soLuongTuongThapMau ;
	Tuong *danhSachTuongThapMau = thongKeTuongThapMau(danhSachTuong, soLuongTuong, nguongMau, soLuongTuongThapMau);
	if(soLuongTuongThapMau == 0)	cout << "\nKhong co tuong nao co mau thap hon " << nguongMau << "!";
	else{
		cout << "Co " << soLuongTuongThapMau << " tuong co mau thap hon " << nguongMau;
		cout << "\nDanh sach tuong co mau thap hon " << nguongMau << " la :\n";
		inDanhSachTuong(danhSachTuongThapMau, soLuongTuongThapMau);
	}
	
	int nguongSatThuong;
	cout << "\nNhap nguong sat thuong can thong ke :";		cin >> nguongSatThuong;
	int soLuongTuongChuLuc ;
	Tuong *danhSachTuongChuLuc = thongKeTuongChuLuc(danhSachTuong, soLuongTuong, nguongSatThuong, soLuongTuongChuLuc);
	if(soLuongTuongChuLuc == 0)	cout << "\nKhong co tuong nao co sat thuong cao hon " << nguongSatThuong << "!";
	else{
		cout << "Co " << soLuongTuongChuLuc << " tuong co sat thuong cao hon " << nguongSatThuong;
		cout << "\nDanh sach tuong co sat thuong cao hon " << nguongSatThuong << " la :\n";
		inDanhSachTuong(danhSachTuongChuLuc, soLuongTuongChuLuc);
	}
	delete[] danhSachTuong;
	delete[] danhSachTuongThapMau;
	delete[] danhSachTuongChuLuc;
	return 0;
}


void nhapDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong){
	for(int i=0; i<soLuongTuong; i++){
		cout << "Nhap thong tin tuong thu " << i+1 << " :";
		danhSachTuong[i].nhap();
	}
}

void inDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong){
	cout << left << setw(20) << "Ten" << left << setw(10) << "Mau"
	     << left << setw(12) << "Vai Tro" << left << setw(12) << "Sat Thuong" << endl;
	for(int i=0; i<soLuongTuong; i++){
		danhSachTuong[i].in();
	}
}

Tuong* thongKeTuongThapMau(Tuong *danhSachTuong, int soLuongTuong, int nguongMau, int &soLuongTuongThapMau){
	soLuongTuongThapMau = 0;
	
	for(int i=0; i<soLuongTuong; i++){
		if(danhSachTuong[i].getMau() < nguongMau )	soLuongTuongThapMau ++;
	}
	
	if(soLuongTuongThapMau == 0)	return nullptr;
	
	Tuong *danhSachTuongThapMau = new Tuong[soLuongTuongThapMau];
	int dem = 0;
	for(int i=0; i<soLuongTuong; i++){
		if(danhSachTuong[i].getMau() < nguongMau ){
			danhSachTuongThapMau[dem] = danhSachTuong[i];
			dem++;
		}
	}
	
	return danhSachTuongThapMau;
}

Tuong* thongKeTuongChuLuc(Tuong *danhSachTuong, int soLuongTuong, int nguongSatThuong, int &soLuongTuongChuLuc){
	soLuongTuongChuLuc = 0;
	
	for(int i=0; i<soLuongTuong; i++){
		if(danhSachTuong[i].getSatThuong() > nguongSatThuong )	soLuongTuongChuLuc ++;
	}
	
	if(soLuongTuongChuLuc == 0)	return nullptr;
	
	Tuong *danhSachTuongChuLuc = new Tuong[soLuongTuongChuLuc];
	int dem = 0;
	for(int i=0; i<soLuongTuong; i++){
		if(danhSachTuong[i].getSatThuong() > nguongSatThuong ){
			danhSachTuongChuLuc[dem] = danhSachTuong[i];
			dem++;
		}
	}
	
	return danhSachTuongChuLuc;	
}
