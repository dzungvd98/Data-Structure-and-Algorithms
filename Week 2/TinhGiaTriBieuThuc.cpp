#include <iostream>
using namespace std;

float Tinh_E (int n) {
	float E = 0;
	long gt;
	for(int i = 1; i <= n; i++) {
		gt = 1;
		for(int j = 1; j <= i; j++) {
			gt = gt*j;
		}
		E = E + (2*i - 1)*1.0 /gt;
	}
	return E;
}

float Tinh_E_Toi_Uu(int n) {
	float E = 0;
	long gt = 1;
	for(int i = 1; i <= n; i++) {
		gt = gt*i;
		E = E + (2*i - 1)*1.0 /gt;
	}
	return E;
}

int main() {
	int n;
	cout << "Nhap so n: ";
	cin >> n;
	cout << "Ket qua: " << Tinh_E(n) << endl;
}

