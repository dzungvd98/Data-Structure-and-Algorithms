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
	string result = "";
	srand(time(0));
	int k = 0;
	while(k < M) {
		int randomNumber = rand() % (MAX_RANDOM_VALUE - MIN_RANDOM_VALUE + 1) + MIN_RANDOM_VALUE;
		string randomNumberToString =  to_string(randomNumber);;
		cout << randomNumberToString;
		if(!result.find(randomNumberToString)) {
			result = result + randomNumberToString + "-";
			
			k ++;
		}
	}
	cout << result;
}

