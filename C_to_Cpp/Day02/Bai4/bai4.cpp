#include<iostream>

using namespace std;

int main(){
	int n;
	cout << "Nhap so luong quai vat  :";	cin>> n ;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cout << "NHap hp quai thu " << i+1 << " :";
		cin >> a[i];
	}
	int max=a[0] , vitri=0;
	int tong=0;
	for(int i=0;i<n;i++){
		tong+=a[i];
		if(a[i]>max){
			max=a[i];
			vitri=i;
		}
	}
	cout << "\nTong Hp quai la :" << tong;
	cout << "\nQuai co Hp cao nhat la con thu :" << vitri+1 << " voi " << a[vitri] << " Hp";
	
	delete[] a;
	a=nullptr;
	return 0;
}
