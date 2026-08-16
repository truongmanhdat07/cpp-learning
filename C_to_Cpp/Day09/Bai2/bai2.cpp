#include<iostream>
#include<string>
using namespace std;

class Tuong{
	private:
		string tenTuong;
		string maTuong;
		string heToc;
		int satThuongCoBan;	
	public:
		Tuong(){};
		~Tuong(){};
		void nhapTuong();
		void inTuong();
		string getHeToc();
		int getSTCB();
		
};

void nhapDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong);
void inDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong);
int thongKeHeToc(Tuong *danhSachTuong, int soLuongTuong, Tuong *danhSachHeToc, string heTocCanTim);
int satThuongCoBanCaoNhat(Tuong *danhSachTuong, int soLuongTuong, int &viTri);

int main(){
	int soLuongTuong;
	cout << "Nhap so luong tuong :";	cin >> soLuongTuong;	cin.ignore();
	Tuong *danhSachTuong = new Tuong[soLuongTuong];
	
	nhapDanhSachTuong(danhSachTuong,soLuongTuong);
	cout << "\nDanh sach tuong vua nhap la :";
	inDanhSachTuong(danhSachTuong,soLuongTuong);
	
	Tuong *danhSachHeToc = new Tuong[soLuongTuong];
	string heTocCanTim;
	cout << "\nNhap toc he can thong ke :";		getline(cin, heTocCanTim);
	int soLuongTuongThuocHeTocCanTim = thongKeHeToc(danhSachTuong, soLuongTuong, danhSachHeToc, heTocCanTim);
	if(soLuongTuongThuocHeTocCanTim){
		cout << "\nDanh sach tuong thuoc toc he " << heTocCanTim << " la :";
		inDanhSachTuong(danhSachHeToc,soLuongTuongThuocHeTocCanTim);
	}
	else	cout << "\nKhong co tuong nao thuoc he toc " << heTocCanTim;
	
	int viTri;
	int maxSTCB = satThuongCoBanCaoNhat(danhSachTuong, soLuongTuong, viTri);
	cout << "\nTuong co sat thuong co ban cao nhat la :" ;
	inDanhSachTuong(&danhSachTuong[viTri], 1);
	
	
	delete[] danhSachTuong;
	delete[] danhSachHeToc;
	return 0;
}
string Tuong::getHeToc(){
	return heToc;
}
int Tuong::getSTCB(){
	return satThuongCoBan;
}

void Tuong::nhapTuong(){
	cout << "\nNhap ma tuong :";	getline(cin, maTuong);
	cout << "Nhap ten tuong :";		getline(cin, tenTuong);
	cout << "Nhap he toc :";		getline(cin, heToc);
	cout << "Nhap STCB :";			cin >> satThuongCoBan;
	cin.ignore();
}
void nhapDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong){
	for(int i=0; i < soLuongTuong; i++){
		cout << "Nhap thong tin tuong thu " << i+1;
		danhSachTuong[i].nhapTuong();
	}
}

void Tuong::inTuong(){
	cout << "\nMa tuong :" << maTuong << " | ten tuong :" << tenTuong << " | he toc :"
		 << heToc << " | sat thuong co ban :" << satThuongCoBan;
}
void inDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong){
	for(int i = 0; i < soLuongTuong; i++){
		danhSachTuong[i].inTuong();
	}
}
int thongKeHeToc(Tuong *danhSachTuong, int soLuongTuong, Tuong *danhSachHeToc, string heTocCanTim){
	int soLuongTuongThuocTocHe = 0;
	for(int i = 0; i < soLuongTuong; i++){
		if(danhSachTuong[i].getHeToc() == heTocCanTim){
			danhSachHeToc[soLuongTuongThuocTocHe] = danhSachTuong[i];
			soLuongTuongThuocTocHe++;
		}
	}
	return soLuongTuongThuocTocHe;
}
int satThuongCoBanCaoNhat(Tuong *danhSachTuong, int soLuongTuong, int &viTri){
	int maxSTCB = danhSachTuong[0].getSTCB();
	viTri = 0;
	
	for(int i=1; i<soLuongTuong; i++){
		if(danhSachTuong[i].getSTCB() > maxSTCB){
			maxSTCB = danhSachTuong[i].getSTCB();
			viTri = i;
		}
	}
	return maxSTCB;
}
