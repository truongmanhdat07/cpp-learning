#include<iostream>
#include<iomanip>
using namespace std;

void nhap(float **a,int m,int n);
void in(float **a,int m,int n);
float tongcotle(float **a,int m,int n);
void timmax(float **a,int m,int n);

int main(){
	int m,n;
	cout << "Nhap so hang cua mang tran :";	cin >> m;
	cout << "Nhap so cot cua ma tran :"   ; cin >> n;
	float **a = new float*[m];
	for(int i=0;i<m;i++){
		a[i] = new float[n];
	}
	
	nhap(a,m,n);
	cout << "\nMa tran vua nhap la :\n";
	in(a,m,n);
	cout << "\nTong cac phan tu cot le cua ma tran la :" << tongcotle(a,m,n);
	timmax(a,m,n);
	
	for(int i=0;i<m;i++)	delete[] a[i];
	delete[] a;
	return 0;
}
void nhap(float **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << "Nhap a[" << i << "][" << j << "] :";	
			cin >> a[i][j];
		}
	}
}
void in(float **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << setw(5) << a[i][j];
		}
		cout << "\n";
	}
}
float tongcotle(float **a,int m,int n){
	float tong=0;
	for(int j=0;j<n;j+=2){
		for(int i=0;i<m;i++){
			tong += a[i][j];
		}
	}
	return tong;
}
void timmax(float **a,int m,int n){
	float max = a[0][0];
	int hang=0,cot=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max){
				max=a[i][j];
				hang=i+1;
				cot=j+1;
			}
		}
	}
	cout << "\nGia tri lon nhat cua ma tran la :" << max;
	cout << "\nTai vi tri : hang " << hang << " cot " << cot ;
}
