#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void nhapDaThuc(float *daThuc, int bacDaThuc);
void inDaThuc(float *daThuc, int bacDaThuc);
float tinhGiaTri(float *daThuc, int bacDaThuc,float giaTri);
void daoHamDaThuc(float *daThuc, int bacDaThuc, float *daThucDaoHam, int bacDaoHam);

int main(){
	int bacDaThuc;
	cout << "Nhap bac cua da thuc :";	cin >> bacDaThuc;
	float *daThuc = new float[bacDaThuc+1];
	
	nhapDaThuc(daThuc,bacDaThuc);
	cout << "\nDa thuc vua nhap la :";
	inDaThuc(daThuc,bacDaThuc);
	
	float giaTri;
	cout << "\nNhap gia tri cua x:";	cin >> giaTri;
	cout << "\nGia tri cua da thuc tai x la :" << tinhGiaTri(daThuc,bacDaThuc,giaTri);
	
	int bacDaoHam = 0;
	if(bacDaThuc > 0)	bacDaoHam = bacDaThuc - 1;
	float *daThucDaoHam = new float[bacDaoHam+1];
	daoHamDaThuc(daThuc,bacDaThuc,daThucDaoHam,bacDaoHam);
	cout << "\nDao ham cua da thuc la :";
	inDaThuc(daThucDaoHam,bacDaoHam);
	
	float bieuThucTrongCan = ( 2021 + tinhGiaTri(daThuc,bacDaThuc,giaTri) + tinhGiaTri(daThucDaoHam,bacDaoHam,giaTri));
	if(bieuThucTrongCan < 0)	cout << "\nGia tri trong can khong the am";
	else						cout << "\nKet qua cua bieu thuc S la :" << sqrt(bieuThucTrongCan);

	delete[] daThuc;
	delete[] daThucDaoHam;
	return 0;
}
void nhapDaThuc(float *daThuc, int bacDaThuc){
	for(int i=0; i <= bacDaThuc; i++){
		cout << "Nhap he so bac " << i << " :";
		cin >> daThuc[i];
	}
}
void inDaThuc(float *daThuc, int bacDaThuc){
	int soDaIn = 0;
	for(int i=0; i<= bacDaThuc; i++){
		if(daThuc[i] == 0)	continue;
		if(soDaIn == 0){
			if(daThuc[i] < 0)	cout << "-";
		}
		else{
			if(daThuc[i] < 0)	cout << " - ";
			else				cout << " + ";
		}
		
		float heSo = abs(daThuc[i]);
		if(heSo != 1 || i == 0)	cout << fixed << setprecision(2) << heSo;
		if(i > 1)						cout << "x^" << i;
		else if(i == 1)					cout << "x";
		soDaIn++;
	}
	if(soDaIn == 0)	cout << 0;
}
float tinhGiaTri(float *daThuc, int bacDaThuc, float giaTri){
	float giaTriDaThuc = 0;
	for(int i=0; i <= bacDaThuc; i++){
		giaTriDaThuc += daThuc[i] * pow(giaTri,i);
	}
	return giaTriDaThuc;
}
void daoHamDaThuc(float *daThuc, int bacDaThuc, float *daThucDaoHam, int bacDaoHam){
	for(int i=0; i<=bacDaoHam; i++){
		daThucDaoHam[i] = (i+1) * daThuc[i+1];
	}
}
