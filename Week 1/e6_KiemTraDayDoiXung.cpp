#include <iostream>
using namespace std;

bool laDayDoiXung(int A[], int n) {
	int i = 0;
	int j = n - 1;
	while(i < n/2) {
		if(A[i] != A[j]) return false;
		i++;
		j--;
	}
	return true;
}


int main() {
	int n;
	int A[100];
	cin >> n;
	for(int  i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << laDayDoiXung(A, n);
}

