#include<iostream>
#include<string>

using namespace std;

void heal(int &current_hp,const int max_hp){
	if(current_hp > max_hp-50)	current_hp=max_hp;
	else						current_hp+=50;

}

int main(){
	int mau_hien_tai=30;
	int mau_toi_da =110 ;
	
	cout << "Mau hien tai :" << mau_hien_tai ;
	
	heal(mau_hien_tai,mau_toi_da);
	cout << "\nMau hien tai :" << mau_hien_tai;
	heal(mau_hien_tai,mau_toi_da);
	cout << "\nMau hien tai :" << mau_hien_tai;

	return 0;
}
