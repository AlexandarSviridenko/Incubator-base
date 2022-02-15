#include <iostream>

using namespace std;

void printNumbersConsistOnesInBinary(int number, int m);
int convertDecimalToBinary(int number);
bool isBinaryConsistOnes(int number);

int main()
{
	int number = 0;
	int m = 0;
	
	cout << "After input M, you will get natural numbers, which in the binary system are represented by 1. " << endl;
	cout << "Input M: " << endl; 
	cin >> m;
	if ( m < 1) {
		cout << "Exception. You need input M more 0." << endl;
		main();
	}
	
	printNumbersConsistOnesInBinary(number, m);	
}	

void printNumbersConsistOnesInBinary(int number, int m)
{
	int binaryNumber = 0;		
	while(number != m){
		number++;
		binaryNumber = convertDecimalToBinary(number); // перевод числа в бинарное
		if (isBinaryConsistOnes(binaryNumber)){
			cout << "Decimal number: " << number << ".  Number in binary system: " << binaryNumber << endl;
		}
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
	while(number != 0){ //цикл по переводу в бинарное число
		binaryNumber = number % 2;
		number /= 2;              
		binaryNumber = binaryTemp + binaryNumber * counter;
		binaryTemp = binaryNumber;
		counter *= tens ;	
	}
	return binaryNumber;
}

bool isBinaryConsistOnes(int number) 
{
	while (number > 0){                            
		if (number % 10 == 0){
			return false;
		}
		number /= 10;
	}
	return true;
}
		
