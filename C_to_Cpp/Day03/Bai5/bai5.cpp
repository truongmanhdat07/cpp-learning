#include<iostream>

using namespace std ;

class phapkhi{
	private :
		int *capdo;
	
	public :
		phapkhi(const int c=7){
			capdo =new int ;
			*capdo =c;
			cout << "\nPhap khi duoc tao ra voi cap do :" << *capdo;
		}
		~phapkhi(){
			cout << "\nPhap khi cap " << *capdo << " da bi pha huy";
			delete capdo;
			capdo = nullptr;
		}
};

int main(){
	phapkhi ThienLongKiem(9);
	
	return 0;
}
