#include<iostream>
#include<string>
using namespace std;

class sach{
	private:
		string masach;
		string tensach;
		string tentacgia;
		int giatien;
	public:
		sach(string ms,string ts,string ttg,int t){
			masach=ms;
			tensach=ts;
			tentacgia=ttg;
			giatien=t;
		}
		void nhap(){
			cout << "Nhap ma sach :" ;	getline(cin,masach);
			cin.ignore();
			cout << "Nhap ten sach :";	getline(cin,tensach);
			cout << "Ten tac gia :"	 ;	getline(cin,tentacgia);
			cout << "Gia tien :"	 ;  cin >> giatien;	
		}
};

void nhapsach(sach *a,int n);

int main(){
	int n;
	cout << "Nhap so luong sach :";	cin >> n;
	
	sach *a = new sach[n];
	
	delete[] a;
	return 0;
}
void nhapsach(sach *a,int n);
