#include "CharacterCounter.h"
#include "CharacterCounterIterator.h"
#include "FrequencyMap.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	CharacterCounter lCounter;
	unsigned char lChar;
	while (cin>> lChar) {
		lCounter.count(lChar);
	}
	
	cout << "The frequencies: " << endl;
	for (CharacterCounterIterator iter(lCounter); iter != iter.end(); iter++)
	{
		cout << (*iter).getCharacter() << ": " << (*iter).getFrequency() << endl;
	}

	return 0;

}
