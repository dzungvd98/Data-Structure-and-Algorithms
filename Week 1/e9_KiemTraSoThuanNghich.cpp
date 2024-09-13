#include <iostream>
using namespace std;

bool laSoThuanNgich(int n) {
	int soBanDau = n;
	int soDao = 0;
	while(n > 0) {
		int chuSo = n % 10;
		soDao = soDao * 10 + chuSo;
		n /= 10;
	}
	return soBanDau == soDao;
}

int main() {
	int n;
	cin >> n;
	if(laSoThuanNgich(n)) {
		cout << n << " la so thuan nghich!";
	} else {
		cout << n << " khong phai la so thuan nghich!";
	}
}

