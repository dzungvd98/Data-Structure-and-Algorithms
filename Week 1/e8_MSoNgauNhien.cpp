#include <iostream>
#include <cstdlib> 
#include <time.h>
#include <string>
using namespace std;
const int MAX_RANDOM_VALUE = 1000000;
const int MIN_RANDOM_VALUE = 1;

bool isNumberExist(int* A, int size, int num) {
	for(int i = 0; i < size; i++) {
		if(A[i] == num) {
			return true;
		}
	}
	return false;
}

int main() {
	int M;
	cin >> M;
	int* A = new int[M];
	srand(time(0));
	int k = 0;
	while(k < M) {
		int randomNumber = rand() % (MAX_RANDOM_VALUE - MIN_RANDOM_VALUE + 1) + MIN_RANDOM_VALUE;
		if(isNumberExist(A, k+1, randomNumber) == false) {
			A[k] = randomNumber;
			k++;
		}
	}
	for(int i = 0; i < M; i++) {
		
		cout << A[i] << " ";
	}
}

