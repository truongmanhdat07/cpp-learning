#include<iostream>
#include<string>
using namespace std;

void tieuthuthucan(string tenmon,int &chisodoi,int &mau,bool &bingodoc){
	if(tenmon =="thit quai vat"){
		bingodoc = true;
		mau -=20;
		chisodoi +=50;
		if(mau <0)			 mau=0;
		if(chisodoi >100)	 chisodoi =100;
	}
	else{
		chisodoi +=30 ;
		bingodoc=false;
		if(chisodoi >100){
			chisodoi=100;
		}
	}
}
int main(){
	string tenmon;
	int chisodoi,mau;
	bool bingodoc=false;
	
	cout << "Nhap ten mon an :"	;	getline(cin,tenmon);
	cout << "Nhap chi so doi :"	;	cin >> chisodoi;
	cout << "Nhap mau :"		;	cin >> mau;
	
	tieuthuthucan(tenmon,chisodoi,mau,bingodoc);
	if(bingodoc && mau==0)	cout << "\nNhan vat bi chet do ngo doc :" << tenmon;
	else if(bingodoc)		cout << "\nNhan vat cua ban bi ngo doc do su dung thit quai vat, bi tru 20 mau";
	else					cout << "\nSu dung thanh cong "	<< tenmon << " ,chi so doi hien tai :" << chisodoi;
	
	return 0;
}
