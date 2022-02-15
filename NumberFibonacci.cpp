#include <iostream>

using namespace std;

void fibonacciNumber(int n);

int main()
{
	int n = 0;

	cout << "Input the N-th number of the sequence Fibonacci: " << endl; 
	cin >> n;
	if ( n < 1){
		cout << "Exception. You need input N more 0." << endl;
		main();
	}
	
	fibonacciNumber(n);
}

void fibonacciNumber(int n)
{
	unsigned long long firstNumber = 0;
	unsigned long long secondNumber = 1;
	unsigned long long finalNumber = 0; 
	int counter = 2;
	
	cout << firstNumber << " " << secondNumber;
	while(counter != n){
		finalNumber = firstNumber + secondNumber;
		firstNumber = secondNumber;
		secondNumber = finalNumber;
		counter++;
		cout << " " << finalNumber;
	}
}
