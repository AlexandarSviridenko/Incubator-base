#include <iostream>


using namespace std;

int main(){
	int mutant = 0;
	double percentBorn = 0.0;
	int kill = 0;
	int count = 0;
	
	cout << "Input... Number Mutant" << endl;
	cin >> mutant;
	cout << "Input... Increase Percentage Mutant" << endl;
	cin >> percentBorn;
	cout << "Input... Ðow many mutants does the public service kill" << endl;
	cin >> kill;
	
	percentBorn = percentBorn/100; 
	if (mutant < 0 or percentBorn < 0 or kill < 0){
		cout << "Variables are set to wrong values";
	}	
	else { 	if ( (int)(mutant * percentBorn) >= kill) {
				cout << "Mutant win" << endl;
		    }
			else {	if ((mutant + (int)(mutant * percentBorn) - kill) >= 0) {  
						for (int i = 1; mutant > 0; i++){
						mutant = (mutant + (int)(mutant * percentBorn)) - kill;
	    				count = i;
						}		
						cout << "Public service win on the " << count << " day";
					}
			}	
	}
	return 0;
}
