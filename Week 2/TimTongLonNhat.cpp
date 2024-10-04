#include <iostream>
using namespace std;

int tongDayConLonNhat(int x[], int n) {
	int currentMax = x[0];
	int globalMax = x[0];
	
	for (int i = 1; i < n; i++) {
		currentMax = max(x[i], currentMax + x[i]);
		globalMax = max(globalMax, currentMax);
	}
	
	if(globalMax > 0) return globalMax;
	return 0;
}

int main() {
	int x[100];
	int n;
	cout << "Nhap so nguyen n: ";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	
	cout << "Tong day con lon nhat: " << tongDayConLonNhat(x, n);
	
	
}

