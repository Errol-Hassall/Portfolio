#pragma once

class FrequencyMap
{
private:
	char fChar;
	int fFrequency;

public:
	FrequencyMap();
	FrequencyMap(char aChar, int aFrequency);

	char getCharacter() const;
	int getFrequency() const;
};

