#include <iostream>
#include <string>

using namespace std;

class NhanVat {
protected:
    string ten;
    int mau;

public:
    NhanVat(string t, int m) {
        ten = t;
        if (m >= 0) mau = m;
        else mau = 0;
    }

    virtual void nhanSatThuong(int st) {
        if (mau >= st) mau -= st;
        else mau = 0;
        
        cout << ten << " bi danh trung! Tru " << st << " mau.\n";
    }

    int getMau() const {
        return mau;
    }
};

class QuaiThu : public NhanVat {
public:
    QuaiThu(string t, int m) : NhanVat(t, m) {}
};

class HiepSi : public NhanVat {
public:
    HiepSi(string t, int m) : NhanVat(t, m) {}

    void nhanSatThuong(int st) override {
        int stThucTe = st / 2;
        
        if (mau >= stThucTe) mau -= stThucTe;
        else mau = 0;

        cout << ten << " dung khien chan don! Chi bi tru " << stThucTe << " mau.\n";
    }
}; 


void giaoTranh(NhanVat* mucTieu, int st) {
    mucTieu->nhanSatThuong(st);
}


int main() {
    QuaiThu soi("Ma Soi", 1000);
    HiepSi garen("Garen", 1000);


    giaoTranh(&soi, 200);
    giaoTranh(&garen, 200);

    cout << "\nMau con lai cua Ma Soi: " << soi.getMau() ;
    cout << "\nMau con lai cua Garen:  " << garen.getMau() ;

    return 0;
}
