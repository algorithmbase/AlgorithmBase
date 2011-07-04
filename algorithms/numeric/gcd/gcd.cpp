#include <iostream>
using namespace std;

/*
int gcd(int a, int b) {
	int temp;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}*/

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int main() {
	int a, b;
	
	cin >> a >> b;
	
	cout << gcd(a, b) << endl;
}