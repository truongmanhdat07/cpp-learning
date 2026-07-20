#include<iostream>
#include<string>

using namespace std;

class tuong{
	protected :
		string ten;
		int mau;
		int satthuong;
	public :
		tuong(string t,int m,int st){
			ten=t;
			mau=m;
			satthuong=st;
		}
		
		void hienthi(){
			cout << "\n" << ten << " co " << mau << " va co "<< satthuong << " sat thuong" ;
		}
		void danhthuong(){
			cout << "\n" << ten << " danh thuong,gay " << satthuong << " sat thuong";
		}
};
class xathu : public tuong{
	private :
		int tamban;
		
	public :
		xathu(string t,int m,int st,int tb) : tuong(t,m,st){
			tamban=tb;
		}
		
		void danhthuong(){
			cout << "\n" << ten << " giang cung ban o khoang cach " << tamban << " gay " << satthuong << " sat thuong chi mang";
		}
};
class dausi : public tuong{
	private :
		int giap;
		
	public :
		dausi(string t,int m,int st,int g) : tuong(t,m,st){
			giap=g;
		}
		
		void danhthuong(){
			cout << "\n" << ten << " lao vao can chien gay " << satthuong << " sat thuong! (giap hien tai :" << giap << ")";
		}
};

int main(){
	xathu ashe("Ashe",500,65,600);
	dausi garen("Garen",700,55,40);
	
	ashe.hienthi();
	ashe.danhthuong();
	garen.hienthi();
	garen.danhthuong();
	
	return 0;
}
