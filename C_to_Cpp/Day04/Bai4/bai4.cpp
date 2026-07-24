#include<iostream>
#include<string>

using namespace std;

class quaivat{
	protected :
		string ten;
		int mau;	
	public :
		quaivat(string t,int m){
			ten=t;
			mau= (m>=0) ? m : 0;
			
		}
};

class boss : public quaivat{
	private :
		int giap;
	public :
		boss(string t,int m,int g)	 : quaivat(t,m){
			giap=g;
		}
		void hienthi(){
			cout << "\nBoss " << ten << " hien co " << mau << " va " << giap << " giap";
		}
};

int main(){
	boss dracula("Dracula",1800,130);
	dracula.hienthi();
	
	return 0;
}
