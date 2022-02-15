#include <iostream>
#define MAX_NUMBER 9999999999

using namespace std;

int main(){
	long binaryNumber = 0;
	long rememberBinaryNumber = 0;
	int decimalNumber = 0;
	int rememberLastNumber = 0;
	int i = 1;
	
	cout << "Input binary number(10 digits)" << endl;
	cin >> binaryNumber;

	if (binaryNumber > (long)MAX_NUMBER){
		cout << "Wrong. Binary number more 10 digits.";
		return 1;
	}
	if (binaryNumber < 0){
		cout << "Wrong. Input binary number more 0.";
		return -1;
	}
	rememberBinaryNumber = binaryNumber;
	while (binaryNumber > 0){
		rememberLastNumber = binaryNumber % 10;
		if(!(rememberLastNumber == 0 or rememberLastNumber == 1)){  
			cout << "Exception. It's not a binary number";
			return 2;
		}
		binaryNumber = binaryNumber / 10;
	}
	
	binaryNumber = rememberBinaryNumber;
	while (binaryNumber > 0) {
		rememberLastNumber = binaryNumber % 10;
		binaryNumber = binaryNumber / 10;
		decimalNumber = decimalNumber + i * rememberLastNumber;
		i = i * 2;
	}
	cout << "Decimal number " << decimalNumber;
	return 0;	
}
