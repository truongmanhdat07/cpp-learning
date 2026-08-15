#include<iostream>
#include<iomanip>
using namespace std;

void nhapMaTran(int **maTran, int capMaTran);
void inMaTran(int **maTran,int capMaTran);
int tongDuongCheoPhu(int **maTran,int capMaTran);
bool maTranDoiXung(int **maTran,int capMaTran);

int main(){
	int capMaTran;
	cout << "Nhap cap cua ma tran :";	cin >> capMaTran;
	int **maTran = new int*[capMaTran];
	for(int i=0; i<capMaTran; i++){
		maTran[i] = new int[capMaTran];
	}
	
	nhapMaTran(maTran,capMaTran);
	cout << "\nMa tran vua nhap la :\n";
	inMaTran(maTran,capMaTran);
	cout << "\nTong duong cheo phu cua ma tran la :" << tongDuongCheoPhu(maTran,capMaTran);
	if(maTranDoiXung(maTran,capMaTran))	cout << "\nDay la ma tran doi xung";
	else				cout << "\nDay khong phai la ma tran doi xung";
	
	for(int i=0; i<capMaTran; i++)	delete[] maTran[i];
	delete[] maTran;
	return 0;
}
void nhapMaTran(int **maTran, int capMaTran){
	for(int i=0; i<capMaTran; i++){
		for(int j=0; j< capMaTran; j++){
			cout << "Nhap phan tu hang " << i+1 << " cot " << j+1 << ":";
			cin >> maTran[i][j];
		}
	}
}
void inMaTran(int **maTran,int capMaTran){
	for(int i=0; i<capMaTran; i++){
		for(int j=0; j<capMaTran; j++){
			cout << setw(5) << maTran[i][j];
		}
		cout << "\n";
	}
}
int tongDuongCheoPhu(int **maTran,int capMaTran){
	int tong = 0;
	for(int i=0; i<capMaTran; i++){			// j = capMaTran-1-i
		tong += maTran[i][capMaTran-i-1];
	}
	return tong;
}
bool maTranDoiXung(int **maTran,int capMaTran){
	for(int i=0; i<capMaTran; i++){
		for(int j=i+1; j<capMaTran; j++){
			if(maTran[i][j] != maTran[j][i])	return false;
		}
	}
	return true;
}
