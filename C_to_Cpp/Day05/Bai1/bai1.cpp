#include<iostream>
#include<string>

using namespace std;

class tuong {
	protected :
		string ten;
	
	public :
		tuong(string t){
			ten=t;
		}
		
		virtual void kynang() const{
			cout << "\nTuong " << ten << " vua dung chieu";
		}
		
		virtual ~tuong(){
			cout << "\nDa huy tuong " << ten ;
		}
};
class phapsu : public tuong {
	public :
		phapsu(string t) : tuong(t) {
			
		}
		
		void kynang() const override {
			cout << "\n" << ten << " vua tung qua cau lua";
		}
};
class satthu : public tuong {
	public :
		satthu(string t) : tuong(t){
			
		}
		
		void kynang() const override {
			cout << "\n" <<ten << " luot vao bong toi,am sat ke dich";
		}
};

int main(){
	tuong *doihinh[3];
	
	doihinh[0] = new phapsu("Raz");
	doihinh[1] = new satthu("Murad");
	doihinh[2] = new phapsu("Krixi");
	
	
	cout << "\nDoi hinh ra tran :";
	for(int i=0;i<3;i++){
		doihinh[i] -> kynang();
	}
	
	cout << "\nDon dep bo nho :";
	for(int i=0;i<3;i++){
		delete doihinh[i];
	}
	return 0;
}
