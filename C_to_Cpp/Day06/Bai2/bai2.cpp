#include<iostream>
#include<string>

using namespace std;

class thanhvienclb{
	protected:
		string ten;
	public:
		thanhvienclb(string t){
			ten=t;
		}
		virtual void tapluyen() =0;
		virtual ~thanhvienclb(){
			cout << "\nDa huy ho so thanh vien :" << ten;
		}
};
class thanhvienchaybo : public thanhvienclb{
	private:
		int *lichtrinhchaybo;
	public:
		thanhvienchaybo(string t):thanhvienclb(t){
			lichtrinhchaybo= new int[7];
		}
		void tapluyen() override{
			cout << "\nDang khoi dong chay bo";
		}
		~thanhvienchaybo() override{
			cout << "\nHuy lich trinh chay va giai phong bo nho";
			delete[] lichtrinhchaybo;
		}
};
int main(){
	thanhvienclb *tv= new thanhvienchaybo("Son");
	delete tv;
	
	return 0;
}
