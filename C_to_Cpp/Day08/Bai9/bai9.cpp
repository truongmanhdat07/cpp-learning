#include<iostream>
#include<string>

using namespace std;

void kichhoathetoc(string ten,int soluong,bool &kichhoat){
	if(ten=="thien cung"){
		if(soluong>=4){
			cout << "\nKich hoat thanh cong, tang 35% chi so";
			kichhoat=1;
		}
		else if(soluong>=2){
			cout << "\nKich hoat thanh cong, tang 15% chi so";
			kichhoat=1;
		}
		else{
			cout << "\nKich hoat that bai";
			kichhoat=0;
		}		
	}
	else{
		cout << "\nHe toc khong hop le";
		kichhoat=0;
	}
}
int main(){
	string tenhetoc;
	int soluongtuong;
	bool kichhoat;
	cout << "Nhap ten he toc :" ;	getline(cin,tenhetoc);
	cout << "Nhap so luong tuong thuoc he toc " << tenhetoc << " :";	cin >> soluongtuong;
	kichhoathetoc(tenhetoc,soluongtuong,kichhoat);
	if(kichhoat)	cout << "\nDa kich hoat thanh cong toc he :" << tenhetoc;
	else			cout << "\nKich hoat that bai toc he :"		 << tenhetoc;
	
	return 0;
}
