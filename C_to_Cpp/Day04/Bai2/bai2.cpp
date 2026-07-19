#include<iostream>
#include<string>

using namespace std;

class yeuthu{
	protected :
		string ten;
	
	public :
		yeuthu(string tenmoi){
			ten=tenmoi;
		}
		
		void keugao(){
			cout << "\n" <<ten << " gam len 1 tieng vang dong ca khu rung";
		}
};

class giaolong : public yeuthu{
	public :
		giaolong(string tenmoi) : yeuthu(tenmoi){
		
	}
		void keugao(){
			cout << "\n" << ten << " thet ra mot tieng long ngam, hoang vu noi bao tap!";
		}
};

class toannghe : public yeuthu{
	public :
		toannghe(string tenmoi) : yeuthu(tenmoi){
			
		}
		void keugao(){
			cout << "\n" <<ten << " rong len, phun ra mot bien lua ruc chay!";
		}
};

int main(){
	yeuthu yt1("Linh vuong");
	giaolong gl1("Phan Thien Long To");
	toannghe tn1("Ngao Truong Khong");
	
	yt1.keugao();
	gl1.keugao();
	tn1.keugao();
	
	return 0;
	
}
