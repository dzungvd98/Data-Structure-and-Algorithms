#include <iostream>
using namespace std;
const int danhSachMenhGia[10] = {500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000, 500};
int soLuongToTien[10] = {0};

void doiTien(int &soTienCanDoi) {
	for(int i = 0; i < 10; i++) {
		int menhGia = danhSachMenhGia[i];
		if(soTienCanDoi / menhGia > 0 && soTienCanDoi >= 500 ) {
			soLuongToTien[i] = soTienCanDoi / menhGia;
			soTienCanDoi = soTienCanDoi - soLuongToTien[i]*menhGia;
		} 
	}
}

void inSauQuyDoi(int soTienCanDoi) {
	if(soTienCanDoi != 0) {
		cout << "Khong doi duoc!" << endl;
		return;
	}
	for(int i = 0; i < 10; i++) {
		if(soLuongToTien[i] > 0) {
			cout << "Can " << soLuongToTien[i] << " To " << danhSachMenhGia[i] << endl;
		}
	}
}

int main() {
	
	int soTienCanDoi;
	cout << "Nhap so tien can doi: ";
	cin >> soTienCanDoi;
	doiTien(soTienCanDoi);
	inSauQuyDoi(soTienCanDoi);
}

