#include<iostream>
#include<string>

using namespace std;

const float base_armor = 30;

int main(){
	string ten;
	float stcb;
	bool crit;
	cout << "Nhap ten tuong :";					getline(cin,ten);
	cout << "Nhap sat thuong co ban :";			cin >> stcb;
	cout << "Don danh co chi mang khong :";		cin >> crit;
	
	float sat_thuong_tong = crit ? (stcb *2) : stcb ;
	float sat_thuong_thuc_te = sat_thuong_tong - base_armor;
	if(sat_thuong_thuc_te <0)	sat_thuong_thuc_te =0;
	
	if(crit){
		cout << ten << " co sat thuong co ban la " << stcb << " gay don danh chi mang " << sat_thuong_thuc_te << " sat thuong";
	}
	else{
		cout << ten << " co sat thuong co ban la " << stcb << " gay " << sat_thuong_thuc_te << " sat thuong";
	}
	
	return 0;
}
