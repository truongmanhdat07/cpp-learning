#include<iostream>
#incluce<string>

using namespace std;

class sinhvien{
	protected:
		string ten;
		string masv;
		
	public:
		sinhvien(string t,string msv){
			ten=t;
			masv=msv;
		}
		virtual float tinhdiem() = 0;
		virtual void inthongtin() = 0;
		
		virtual ~sinhvien(){
			cout << "\nDa don dep bo nho sinh vien " << ten ;
		}
};
