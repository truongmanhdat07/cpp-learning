#include<iostream>
#include<string>

using namespace std;


struct tuong{
	string ten;
	int mana;
	
	void dungchieu(){
		cout << "\nTuong "<< ten << " vua danh thuong";
	}
	void dungchieu(int mana_tieu_hao){
		if(mana>=mana_tieu_hao){
			cout << "\nTuong " << ten << " vua dung chieu thanh cong";
			mana -= mana_tieu_hao;
			cout << "\nMana con la :" << mana;
		}
		else	cout << "\nTuong " << ten <<" khong du mana de sai chieu";
	}
};



int main(){
	tuong violet;
	violet.ten  = "Violet";
	violet.mana = 80;
	
	violet.dungchieu();
	violet.dungchieu(50);
	
	return 0;
}
