#include<iostream>
#include<string>
using namespace std;

class phapbao{
	private :
		string tenphapbao;
		int doben;
	
	public :
		phapbao(){
			tenphapbao= "Chua dat ten";
			doben=100;
		}
		
		void setten(string ten){
			tenphapbao=ten;
		}
		void setdoben(int db){
			if(db >=0 && db <=100){
				doben=db;
			}
			else	cout << "\nDo ben khong hop le!";
		}
		int getdoben(){
			return doben;
		}
	
		void sudung(){
			if(doben <10)	cout << "\nPhap bao da hu hong, khong the su dung!" ;
			else{
				cout << "\nDao huu Dat dang thoi dong " << tenphapbao;
				doben -=10;
			}
		}
};

int main(){
	phapbao pb;
	pb.setten("Thien Cang Kiem");
	pb.setdoben(15);
	
	cout << "Test :";
	cout << "\nDo ben hien tai :" << pb.getdoben();
	
	pb.sudung();
	cout << "\nDo ben sau khi su dung 1 lan la :" << pb.getdoben();
	pb.sudung();
	cout << "\nDo ben sau khi su dung 2 lan la :" << pb.getdoben();
	
	return 0;
}
