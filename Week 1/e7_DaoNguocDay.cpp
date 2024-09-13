#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void daoNguocDay(int A[], int n) {
	int i = 0;
	int j = n - 1;
	while(i < n/2) {
		swap(A[i], A[j]);
		i++;
		j--;
	}
}

void inDay(int A[], int n) {
	for(int  i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}
int main() {
	int n;
	int A[100];
	cin >> n;
	for(int  i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	daoNguocDay(A, n);
	inDay(A, n);
}

