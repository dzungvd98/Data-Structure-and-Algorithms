#include <iostream>
#include <cstdlib> 
#include <time.h>
#include <string>
using namespace std;
const int MAX_RANDOM_VALUE = 1000000;
const int MIN_RANDOM_VALUE = 1;

void TaoDayNN_1_Improved(List &ds, int N, int max) {
    ds.n = 0;
    
    srand(time(NULL));
    
    for (int i = 1; i <= max && ds.n < N; ++i) {
        if (rand() % (max - i + 1) < N - ds.n) {
            ds.nodes[ds.n++] = i;
        }
    }

    // xao tron thu tu neu muon
    for (int i = ds.n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = ds.nodes[i];
        ds.nodes[i] = ds.nodes[j];
        ds.nodes[j] = temp;
    }
}

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

