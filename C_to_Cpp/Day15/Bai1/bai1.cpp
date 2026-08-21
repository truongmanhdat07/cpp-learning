#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


float* nhapDaThuc(int &bacDaThuc, string tenDaThuc);
void inDaThuc(float *daThuc, int bacDaThuc);
float* congDaThuc(const float *daThucP, int bacP, const float *daThucQ, int bacQ, int &bacR);


int main() {
    int bacP, bacQ, bacR;
    
    float *daThucP = nhapDaThuc(bacP, "P");
    float *daThucQ = nhapDaThuc(bacQ, "Q");
    
    cout << "Da thuc P(x) vua nhap la: ";
    inDaThuc(daThucP, bacP);
    
    cout << "Da thuc Q(x) vua nhap la: ";
    inDaThuc(daThucQ, bacQ);
    
    float *daThucR = congDaThuc(daThucP, bacP, daThucQ, bacQ, bacR);
    
    delete[] daThucP;
    delete[] daThucQ;
    delete[] daThucR;
    
    return 0;
}


float* nhapDaThuc(int &bacDaThuc, string tenDaThuc) {
    cout << "Nhap da thuc " << tenDaThuc << "(x) :";
    cout << "\nNhap bac cua da thuc: ";
    cin >> bacDaThuc;

    float *heSo = new float[bacDaThuc + 1];

    for (int i = 0; i <= bacDaThuc; i++) {
        cout << "Nhap he so bac " << i << " : ";
        cin >> heSo[i];
    }
    cout << endl;
    
    return heSo; 
}

void inDaThuc(float *daThuc, int bacDaThuc) {
    int soDaIn = 0;
    cout << fixed << setprecision(2);
    
    for (int i = 0; i <= bacDaThuc; i++) {
        if (daThuc[i] == 0) continue;
        
        if (soDaIn == 0) {
            if (daThuc[i] < 0) cout << "-";
        } else {
        	if (daThuc[i] > 0)	 cout << " + ";
            else				 cout << " - ";
        }
        
        float heSo = abs(daThuc[i]);
        
        if (heSo != 1 || i == 0)	cout << heSo;
        if(i > 1)					cout << "x^" << i;
        else if(i == 1)				cout << "x";
        
        soDaIn++;
    }
    
    if (soDaIn == 0) cout << "0";
    cout << endl;
}

float* congDaThuc(const float *daThucP, int bacP, const float *daThucQ, int bacQ, int &bacR) {
    int bacMax = (bacP > bacQ) ? bacP : bacQ;
    
    float *daThucR = new float[bacMax + 1];
    
    for (int i = 0; i <= bacMax; i++) {
        float p = (i <= bacP) ? daThucP[i] : 0;
        float q = (i <= bacQ) ? daThucQ[i] : 0;
        daThucR[i] = p + q;
    }
    
    while (bacMax > 0 && daThucR[bacMax] == 0) {
        bacMax--;
    }
    
    bacR = bacMax;
    
    cout << "\nDa thuc R(x) = P(x) + Q(x) = ";
    inDaThuc(daThucR, bacR);
    
    return daThucR;
}
