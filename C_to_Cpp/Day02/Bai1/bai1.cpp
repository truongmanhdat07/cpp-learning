#include<iostream>
using namespace std;

void nhap(int *a,int n){
	for(int i=0;i<n;i++){
	cout << "Nhap phan tu thu " << i+1 << " :";
	cin  >> a[i];
	}
}
void in(int *a,int n){
	cout << "Mang vua nhap la :";
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
void timmax(int *a,int n){
	int max=a[0];
	for(int i=1;i<n;i++){
		if(a[i]>max)	max=a[i];
	}
	cout << "\nSo lon nhat cua mang la :" << max;
}

int main(){
	int n;
	cout << "Nhap n :";
	cin  >> n;
	
	int *a = new int[n];

	nhap(a,n);
	in(a,n);
	timmax(a,n);
	
	delete[] a;
	a=nullptr;
	return 0;
}
