#include<iostream>
#include<string>

using namespace std;

class detu{
	private :
		string ten;
		int tuvi;
	
	public :	
		detu(){
			ten= "Vo danh";
			tuvi=0;
			cout << "\nMot de tu ky danh vua gia nhap tong mon";
		}
		detu(string tenmoi,int tuvimoi){
			ten=tenmoi;
			tuvi=tuvimoi;
			cout << "\nThien tai :" << ten << " da duoc thu nhan voi tu vi :" << tuvi;
		}
		void hienthi(){
			cout << "\nTen de tu :" << ten;
			cout << "\nTu vi :" << tuvi ;
		}
};

int main(){
	detu dt1;
	detu dt2("Han Lap",4);
	
	dt1.hienthi();
	dt2.hienthi();
	
	return 0;
}
