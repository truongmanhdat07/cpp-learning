#include<iostream>

using namespace std;

class ketsat{
	private :
		int sovang;
		
	public :
		ketsat(){
			sovang = 0;
		}
		void napvang(int sl){
			if(sl>=0){
				cout<< "\nNap thanh cong " << sl << " vang";
				sovang += sl;
			}
			else		cout << "\nSo luong phai lon hon 0";
		}
		void rutvang(int sl){
			if(sovang>=sl){
				cout << "\nRut thanh cong " << sl << " vang";
				sovang -= sl;
			}
			else		cout << "\nKhong du " << sl << " vang de rut";
		}
		int getvang(){
			return sovang;
		}
};

int main(){
	ketsat a;
	cout << "\nSo vang hien dang co :" << a.getvang() << " vang";
	a.napvang(30);
	a.rutvang(50);
	a.rutvang(25);
	cout << "\nSo vang hien dang co :" << a.getvang() << " vang";
	
	return 0;
}
