#pragma once

#include <iostream>
#include <fstream>

class Caesar
{
private:
	int fCharacterFrequenciesBefore[26];
	int fCharacterFrequenciesAfter[26];

public:
	Caesar();
	
	void shiftByFour(std::ifstream& aInput, std::ofstream& aOutput);

	friend std::ostream& operator<< (std::ostream& aOstream, const Caesar& aObject);

};
