#include <iostream>

using namespace std;

void printNumbersConsistOnesInBinary(int number, int m);
int convertDecimalToBinary(int number);
bool isBinaryConsistOnes(int number);

int main()
{
	int number = 0;

	cout << "Input Decimal number: ";
	cin >> number;

	isBinaryConsistOnes(convertDecimalToBinary(number));
	cout <<"Number in binary system: " << convertDecimalToBinary(number) << endl;
	if (isBinaryConsistOnes(convertDecimalToBinary(number))){
		cout << "Yes, 0 and 1 alternate.";
	}	
	else {
		cout << "No, 0 and 1 don't alternate.";
	}	
}

int convertDecimalToBinary(int number) 
{
	int binaryTemp = 0;
	int binaryNumber = 0;
	int tens = 10;
	int counter = 1;
	int saveNumber = 0;
	
	saveNumber = number;
	while(number != 0){ 
		binaryNumber = number % 2;
		number /= 2;              
		binaryNumber = binaryTemp + binaryNumber * counter ;
		binaryTemp = binaryNumber;
		counter *= tens ;	
	}
	return binaryNumber;
}

bool isBinaryConsistOnes(int number){
	int lastNumber = 0;
	while (number > 0){
		if (number % 10 == 0){
			lastNumber = 1;
		}
		else{
			lastNumber = 0;
		}
		number /= 10;
		if (number % 10 != lastNumber){
			return false;
		}
	}
		return true;
}
