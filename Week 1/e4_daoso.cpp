#include <iostream>
using namespace std;

void DaoSo(int &n) {
	int ketQua = 0;
	while(n > 0) {
		int chuSo = n % 10;
		ketQua = ketQua*10 + chuSo;
		n /= 10;
	}
	n = ketQua;
}

int main() {
	int n;
	cin >> n;
	DaoSo(n);
	cout << "So dao la: " << n;
}

