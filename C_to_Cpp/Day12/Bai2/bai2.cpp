#include<iostream>
#include<string>

using namespace std;

typedef struct{
	string maTuong;
	string tenTuong;
	string heToc;
	int satThuongCoBan;
}Tuong;

void nhapDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong);
void inDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong);
int thongKeTuongTheoHeToc(Tuong *danhSachTuong, int soLuongTuong, Tuong *danhSachHeToc, string tocHeCanTim);
int tuongCoSatThuongCoBanCaoNhat(Tuong *danhSachTuong,int soLuongTuong,int &viTri);

int main(){
	int soLuongTuong;
	cout << "Nhap so luong tuong :";	cin >> soLuongTuong;	cin.ignore();
	Tuong *danhSachTuong = new Tuong[soLuongTuong];
	
	nhapDanhSachTuong(danhSachTuong, soLuongTuong);
	cout << "\nDanh sach tuong vua nhap la :";
	inDanhSachTuong(danhSachTuong, soLuongTuong);
	
	string heTocCanTim;
	cout << "\nNhap ten he toc can thong ke :";		getline(cin,heTocCanTim);
	Tuong *danhSachHeToc = new Tuong[soLuongTuong];
	int soTuongThoaMan = thongKeTuongTheoHeToc(danhSachTuong,soLuongTuong,danhSachHeToc,heTocCanTim);
	if(soTuongThoaMan == 0)	cout << "\nKhong tim thay tuong thuoc he toc " << heTocCanTim;
	else{
		cout << "\nDanh sach tuong thuoc he toc " << heTocCanTim << " la :";
		inDanhSachTuong(danhSachHeToc,soTuongThoaMan);
	}
	int viTri = 0;
	int satThuongCoBanCaoNhat = tuongCoSatThuongCoBanCaoNhat(danhSachTuong,soLuongTuong,viTri);
	cout << "\nTuong co sat thuong co ban cao nhat la :";
	inDanhSachTuong(&danhSachTuong[viTri],1);

	delete[] danhSachTuong;
	delete[] danhSachHeToc;
	return 0;
}
void nhapDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong){
	for(int i=0; i<soLuongTuong; i++){
		cout << "Nhap thong tin tuong thu " << i+1 << " :";
		cout << "\nMa tuong :";	getline(cin,danhSachTuong[i].maTuong);
		cout << "Ten tuong :";	getline(cin,danhSachTuong[i].tenTuong);
		cout << "He toc :";		getline(cin,danhSachTuong[i].heToc);
		cout << "Sat thuong co ban :";	cin >> danhSachTuong[i].satThuongCoBan;
		cin.ignore();
	}
}
void inDanhSachTuong(Tuong *danhSachTuong, int soLuongTuong){
	for(int i=0; i<soLuongTuong; i++){
		cout << "\nMa tuong :" << danhSachTuong[i].maTuong << " - ten tuong :" << danhSachTuong[i].tenTuong << " - he toc :" << danhSachTuong[i].heToc << " - sat thuong co ban :" << danhSachTuong[i].satThuongCoBan ;
	}
}
int thongKeTuongTheoHeToc(Tuong *danhSachTuong, int soLuongTuong, Tuong *danhSachHeToc, string tocHeCanTim){
	int soTuongThoaMan = 0;
	for(int i=0; i<soLuongTuong; i++){
		if(danhSachTuong[i].heToc == tocHeCanTim){
			danhSachHeToc[soTuongThoaMan] = danhSachTuong[i];
			soTuongThoaMan++;
		}
	}
	return soTuongThoaMan;
}
int tuongCoSatThuongCoBanCaoNhat(Tuong *danhSachTuong,int soLuongTuong,int &viTri){
	int max = danhSachTuong[0].satThuongCoBan;
	viTri = 0;
	for(int i=1; i<soLuongTuong; i++){
		if(danhSachTuong[i].satThuongCoBan > max){
			max = danhSachTuong[i].satThuongCoBan;
			viTri = i;
		}
	}
	return max;
}
