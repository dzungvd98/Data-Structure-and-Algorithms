#include <iostream>
using namespace std;

int abs(int n) {
	if(n < 0) return n *= -1;
	return n;
}

int timSoGanGiong(int A[], int n, int x) {
	int minSpace = abs(A[0] - x);
	int ketQua = A[0];
	for(int i = 1; i < n; i++) {
		if(minSpace > abs(A[i] - x)) {
			minSpace = abs(A[i] - x);
			ketQua = A[i];
		}
	}
	return ketQua;
}

int main() {
	int n,x;
	int A[100];
	cin >> n;
	for(int  i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> x;
	cout << timSoGanGiong(A, n, x);
	
}

