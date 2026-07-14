#include<iostream>
#include<string>

using namespace std;

struct tuChanGia{
	string ten;
	int canhGioi;
	float lucChien;
	
	void nhapThongTin(){
		cout << "Nhap ten :";				getline(cin,ten);
		cout << "Nhap canh gioi :";			cin >> canhGioi;
		cout << "Nhap luc chien :";			cin >> lucChien;
	}
	void dotPha(){
		canhGioi++;
		lucChien *=2;
	}
	void hienThi(){
		cout << "Dao huu :" << ten << " canh gioi :" << canhGioi << " luc chien :" << lucChien;
	}
};

int main(){
	tuChanGia nhanVat;
	
	nhanVat.nhapThongTin();
	nhanVat.hienThi();
	
	nhanVat.dotPha();
	cout << "\n";
	nhanVat.hienThi();
	
	return 0;
}
