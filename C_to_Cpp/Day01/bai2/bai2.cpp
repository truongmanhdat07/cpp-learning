#include<iostream>

using namespace std;

void sortTwoNumbers(int &a,int &b){
	if(a>b){
		int temp=a;
		a=b;
		b=temp;
	}
}

int main(){
	int x,y;
	cout << "Nhap x :";	cin >> x;
	cout << "Nhap y :";	cin >> y;
	cout << "\nTruoc khi sap xep :" << x << "  " << y;
	sortTwoNumbers(x,y);
	cout << "\nSau khi sap xep   :"   << x << "  " << y;
	
	return 0;
}
