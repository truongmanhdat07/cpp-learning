#include<iostream>
#include<string>

using namespace std;

class tuong{
	public :
		void dungchieu(){
			cout << "\nTuong vua dung chieu voi muc tieu";
		}
};
class satthu : public tuong{
	public :
		void dungchieu(){
			cout << "\nTuong vua am sat voi muc tieu";
		}
};
class hotro : public tuong{
	public :
		void dungchieu(){
			cout << "\nTuong vua hoi mau cho dong doi";
		}
};
int main(){
	tuong violet;
	violet.dungchieu();
	satthu murad;
	murad.dungchieu();
	hotro alice;
	alice.dungchieu();
	
	return 0;
}
