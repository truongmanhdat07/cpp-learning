#include<iostream>
#include<string>

using namespace std;

class detu{
	protected :
		string ten;
		string linh_can;
	
	public :
		detu(string ten_moi,string linh_can_moi){
			ten=ten_moi;
			linh_can=linh_can_moi;
		}
		
		void tuluyen(){
			cout << "\nDe tu " << ten << " mang " << linh_can << " dang thu nap linh khi";
		}
};

class luyendansu : public detu{
	private :
		int cap_lo_dinh;
	
	public :
		luyendansu(string ten_moi,string linh_can_moi,int cap_lo_dinh_moi) : detu( ten_moi, linh_can_moi){
			cap_lo_dinh=cap_lo_dinh_moi;
		}
		
		void luyenthuoc(){
			cout << "\n" << ten << " dang dung lo dinh cap " << cap_lo_dinh << " de luyen dan!";
		}
};

int main(){
	luyendansu	detu1("Han Lap","Tu Linh Can",5);
	detu1.tuluyen();
	detu1.luyenthuoc();
	
	return 0;
}
