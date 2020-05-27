#include <bits/stdc++.h>

using namespace std;

bool isPrime(unsigned int n) {
	if(n == 1)
		return false;
	unsigned int sqrtN = sqrt(n);
	for(unsigned int i = 2; i <= sqrtN; ++i)
		if(n % i == 0)
			return false;
	return true;
}

int countOneDigits(unsigned int n) {
	int sum(0);
	while(n != 0) {
		if(n & 1)
			++sum;
		n >>= 1;
	}
	return sum;
}

int main(void) {
	unsigned int P, i;
	int digitsP;
	while(cin >> P) {
		if(P == 0)
			return 0;
		digitsP = countOneDigits(P);
		for(i = P; i > 0; --i)
			if(isPrime(i) && (digitsP == countOneDigits(i))) {
				cout << i << endl;
				break;
			}
		if(i == 0)
			cout << 0 << endl;
	}
}
