#include <iostream>

using namespace std;

int getNumberDischarge(int number);
int getSequenceDigit (int sequenceNumber);

int main(){
	int sequenceNumber = 0;
	int result = 0;
	const int MAX_VALUE = 2147000000;
	
	cout << "Input sequence number in range [1..." << MAX_VALUE << "]: ";
	cin >> sequenceNumber;
	
	if (sequenceNumber <= 0 or sequenceNumber > MAX_VALUE){
		cout << "ERROR: you're went out for allowable range." << endl;
		cout << "Allowable range is [1..." << MAX_VALUE << "]";
		return 1;
	}
	
	result = getSequenceDigit(sequenceNumber);// функция рассмотреть, присвоили результат функции
	
	cout << endl << "The digit of the sequence number " << sequenceNumber << " is " << result;
	return 0;
}

int getSequenceDigit (int sequenceNumber) {
	int sequence = 0;
	int sequenceDigit = 0;
	int count = 0;
	int numberDischarge = 0;
	int i = 1;
	int delimiter = 1;
	
	while (count != sequenceNumber){
		sequence = i * i;//1
		cout << sequence;//1
		numberDischarge = getNumberDischarge(sequence);// как это работает? определяет сколько цифр в числе
		while (numberDischarge > 1){
			sequenceDigit = (sequence / numberDischarge) % delimiter;//условно 4/10 % 1
			
			//cout << "answer   " << sequenceDigit;
			
			numberDischarge /= 10;
			if (count == sequenceNumber){
				break;
			}
			delimiter *= 10;
			i++;
			count++;
		}	
	}
	return sequenceDigit;
}

int getNumberDischarge(int number) {
    int counter = 0;
    int tens = 1;
    int discharge = 0;
    while (number > 0) {
        number /= 10;
        counter++;
        if (counter > 1)
        tens *= 10;
    }
    discharge += tens;
    return discharge;
}
}

