#include<iostream>
#include<string>
using namespace std;

void dotpha(int canco,bool dungdanduoc,int &tuvi,string &canhgioi){
	if(canco >80 || dungdanduoc == true){
		tuvi +=1000;
		canhgioi = "truc co ky";
		cout << "\nDot pha thanh cong len " << canhgioi << " tu vi tang manh";
	}
	else{
		tuvi-=500;
		cout << "\nDot pha that bai , tu vi bi giam ,canh gioi hien tai :" << canhgioi;
	}
}
int main(){
	int canco,tuvi;
	bool dungdanduoc;
	string canhgioi ="luyen khi";
	cout << "Nhap tu vi :";		cin >> tuvi;
	cout << "Nhap can co :";	cin >> canco;
	cout << "Co dung dan duoc khong ( 1 la co , 0 la khong ) :";
	cin >> dungdanduoc;
	dotpha(canco,dungdanduoc,tuvi,canhgioi);
	
	return 0;
}
