#include<iostream>
#include<string>

using namespace std;

class phapbao{
		public :
			phapbao() {
				cout << "\nPhap bao da duoc them vao";
			}
			virtual ~phapbao(){
				cout << "\nPhap bao da bi huy di";
			}
};
class kiemkhi : public phapbao{
	private :
		int *kiemtran;
	public :
		kiemkhi(){
			kiemtran= new int [10];
			cout << "\nKiem tran gom 10 kiem khi vua duoc them vao";
		}
		~kiemkhi() override{
			cout << "\nKiem tran da bi huy di";
			delete[] kiemtran;
		}
};

int main(){
	phapbao *a= new kiemkhi();
	delete a;
	
	return 0;
}
