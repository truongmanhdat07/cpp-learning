#include<iostream>
#include<string>

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
class sinhvienit : public sinhvien{
	private:
		float diemcode;
		float diemtoan;
	public:
		sinhvienit(string t,string msv,float code,float toan) : sinhvien(t,msv){
			diemcode=code;
			diemtoan=toan;
		}
		float tinhdiem(){
			return (diemcode+diemtoan)/2;
		}
		void inthongtin(){
			cout << "\nSinh vien :" << ten << " co ma sinh vien " << masv << " co diem tong ket la :" << tinhdiem();
		}
};
class sinhvienngonngu : public sinhvien{
	private:
		float ielts;
	public:	
		sinhvienngonngu(string t,string msv,float ie):sinhvien(t,msv){
			ielts=ie;
		}
		float tinhdiem(){
			if(ielts>=7)			return 10;
			else if(ielts >=6.0)	return 8.5;
			else					return 7.0;
		}
		void inthongtin(){
			cout << "\nSinh vien :" << ten << " co ma sinh vien " << masv << " co diem tong ket la :" << tinhdiem();
		}
};

int main(){
	sinhvien *k66[2];
	k66[0]= new sinhvienit("Hoang","H001",7,8);
	k66[1]= new sinhvienngonngu("Linh","H002",8.0);
	
	for(int i=0;i<2;i++){
		k66[i] -> inthongtin();
	}
	
	for(int i=0;i<2;i++){
		delete k66[i];
	}
	
	return 0;
}
