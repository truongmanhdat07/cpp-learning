#include<iostream>
#include<string>
using namespace std;

void tinhsatthuong(int stg,int giapdich,int &maudich,bool &bihaguc){
	float sttt = stg * 100/(100+giapdich) ;
	maudich -= sttt;
	if(maudich<=0){
		maudich=0;
		bihaguc=true;
	}
}
int main(){
	int stg,giapdich,maudich;
	bool bihaguc=false;
	cout << "Nhap sat thuong goc :";	cin >> stg;
	cout << "Nhap giap cua ke dich :";	cin >> giapdich;
	cout << "Nhap mau cua ke dich :";	cin >> maudich;
	tinhsatthuong(stg,giapdich,maudich,bihaguc);
	if(bihaguc)	cout << "Ke dich da bi ha guc";
	else 		cout << "Ke dich con " << maudich << " mau";
	
	return 0;
}
