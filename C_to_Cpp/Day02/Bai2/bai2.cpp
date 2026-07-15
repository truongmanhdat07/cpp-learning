#include<iostream>

using namespace std;

float tinhsatthuong(float baseDamage,float multiplier =1.5f){
	return baseDamage * multiplier;
}
float tinhsatthuong(float baseDamage,float bonusDamage,float multiplier){
	return (baseDamage + bonusDamage) * multiplier;
}

int main(){
	cout << "\n" <<tinhsatthuong(100.0f);
	cout << "\n" <<tinhsatthuong(100.0f,2.0f);
	cout << "\n" <<tinhsatthuong(100.0f,50.0f,2.0f);
	
	return 0;
}
