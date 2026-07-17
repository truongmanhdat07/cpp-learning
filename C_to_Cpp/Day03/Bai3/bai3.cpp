#include<iostream>
#include<string>

using namespace std;

class tuitruvat{
	private :
		int succhua;
		string *danhsachvatpham;
	
	public :
		tuitruvat(int n){
			succhua = n;
			danhsachvatpham = new string[n];
			cout << "\nTui tru vat co the chua " << n << " mon do da duoc tao";
		}
		
		~tuitruvat(){
			delete[] danhsachvatpham;
			cout << "\nTui tru vat da bi huy, cac vat pham roi ra ngoai khong gian!";
		}
		
		void catvatpham(int vitri,string tenvatpham){
			danhsachvatpham[vitri]=tenvatpham;
		}
		void kiemtra(){
			cout << "\nCac vat pham con lai trong tui la :";
			for(int i=0;i<succhua;i++){
				cout << "\nTen :" << danhsachvatpham[i] ;
			}
		}
};

int main(){
	tuitruvat tui(3);
	
	tui.catvatpham(0,"Huyet Kiem");
	tui.catvatpham(1,"Truc Co Dan");
	tui.catvatpham(2,"Long Lan");
	
	tui.kiemtra();
	
	return 0;
}
