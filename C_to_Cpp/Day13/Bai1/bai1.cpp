#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void docMaTranTuFile(ifstream &fileIn, int **maTran,int soHang, int soCot, string tenFile);
void inMaTran(int **maTran, int soHang, int soCot);
bool laSoNguyenTo(int soCanKiemTra);
int demSoNguyenTo(int **maTran, int soHang, int soCot);
void sapXepMang(int *mang, int soPhanTu);
void sapXepMaTranTheoHang(int **maTran, int soHang, int soCot);
bool xuatMaTranRaFile(int **maTran, int soHang, int soCot,string tenFileOutput);

int main(){
	int soHang, soCot;
	string tenFileInput;
	cout << "Vui long nhap ten file can doc :";		getline(cin,tenFileInput);
	ifstream fileIn(tenFileInput);
	if(!fileIn){
		cerr << "Khong the mo file " << tenFileInput << "!";
		return 1;
	}
	
	fileIn >> soHang >> soCot;
	int **maTran = new int*[soHang];
	for(int i=0; i<soHang; i++){
		maTran[i] = new int[soCot];
	}
	
	docMaTranTuFile(fileIn, maTran, soHang, soCot, tenFileInput);
	cout << "\nMa tran vua doc tu file " << tenFileInput << " la :\n";
	inMaTran(maTran, soHang, soCot);
	int soNguyenTo = demSoNguyenTo(maTran, soHang, soCot);
	cout << "\nSo so nguyen to co trong ma tran la :" << soNguyenTo;
	sapXepMaTranTheoHang(maTran, soHang, soCot);
	cout << "\nMa tran sau khi sap xep tang dan theo hang la :\n";
	inMaTran(maTran, soHang, soCot);
	
	string tenFileOutput;
	cout << "\nVui long nhap ten file can xuat :";	getline(cin, tenFileOutput);
	bool inThanhCong = xuatMaTranRaFile(maTran, soHang, soCot, tenFileOutput);
	
	for(int i=0; i<soHang; i++)	delete[] maTran[i];
	delete[] maTran;
	return inThanhCong ? 0 : 1;
}
void docMaTranTuFile(ifstream &fileIn, int **maTran, int soHang, int soCot, string tenFileInput){
	for(int i=0; i<soHang; i++){
		for(int j=0; j<soCot; j++){
			fileIn >> maTran[i][j];
		}
	}
	cout << "\nDoc thanh cong file " << tenFileInput << "!";
}
void inMaTran(int **maTran, int soHang, int soCot){
	for(int i=0; i<soHang; i++){
		for(int j=0; j<soCot; j++){
			cout << setw(5) << maTran[i][j];
		}
		cout << "\n";
	}
}
bool laSoNguyenTo(int soCanKiemTra){
	if(soCanKiemTra < 2)	return false;
	for(int i=2 ; i*i <= soCanKiemTra; i++){
		if(soCanKiemTra % i == 0)	return false;
	}
	return true;
}
int demSoNguyenTo(int **maTran, int soHang, int soCot){
	int dem = 0;
	for(int i=0; i<soHang; i++){
		for(int j=0; j<soCot; j++){
			if( laSoNguyenTo(maTran[i][j]) )	dem++;
		}
	}
	return dem;
}
void sapXepMang(int *mang, int soPhanTu){
	for(int i=0 ; i<soPhanTu-1; i++){
		for(int j=i+1; j<soPhanTu; j++){
			if(mang[i] > mang[j]){
				int temp = mang[i];
				mang[i] = mang[j];
				mang[j] = temp;
			}
		}
	}
}
void sapXepMaTranTheoHang(int **maTran, int soHang, int soCot){
	for(int i=0; i<soHang; i++){
		sapXepMang(maTran[i], soCot);
	}
}
bool xuatMaTranRaFile(int **maTran, int soHang, int soCot,string tenFileOutput){
	ofstream fileOut(tenFileOutput);
	if(!fileOut){
		cerr << "\nKhong the mo file " << tenFileOutput << "!";
		return false;
	}
	fileOut << soHang << " " << soCot << "\n";
	for(int i=0; i<soHang; i++){
		for(int j=0; j<soCot; j++){
			fileOut << setw(5) << maTran[i][j];
		}
		fileOut << "\n";
	}
	cout << "\nXuat ma tran thanh cong vao file " << tenFileOutput << "!";
	return true;
}
