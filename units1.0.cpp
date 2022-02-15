#include <iostream>

using namespace std;


void printNumbersConsistOnesInBinary(int number, int m);
int convertDecimalToBinary(int number);
bool isBinaryConsistOnes(int number);

int main()
{
	int m = 0;
	int number = 0;

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
	int helpNumberTwo = 2;
	int sequenceNumber = 0;
	int counterSequence = 1;
			
	while(sequenceNumber<m){   
		sequenceNumber = sequenceNumber + counterSequence;
		counterSequence *= helpNumberTwo;
		if (sequenceNumber <= m){	
			binaryNumber = convertDecimalToBinary(sequenceNumber); 	// перевод числа
			if (isBinaryConsistOnes(binaryNumber)){  				// проверка
				cout << "Decimal number: " << sequenceNumber << ".  Number in binary system: " << binaryNumber << endl;
			}
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
		binaryNumber = binaryTemp + binaryNumber * counter ;
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
	
	
	
	
	
	
	
// если нужен только вывод последовательности без проверки 
	
//	void sequence (int m){
		
//	int helpNumberTwo = 2;
//	int sequenceNumber = 0;
//	int counterSequence = 1;

//	while (sequenceNumber<m){
//		sequenceNumber = sequenceNumber + counterSequence;
//		counterSequence *= helpNumberTwo;
//		if(sequenceNumber<=m){
//			cout << " " << sequenceNumber;
//		}
//	}
//}	
