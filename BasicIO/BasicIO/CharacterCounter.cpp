#include "CharacterCounter.h"
#include <iostream>
using namespace std;
//Constructor for character counter
//This initialises the ftotal to 0
//sets all elements of the arrray to 0
CharacterCounter::CharacterCounter()
{
	fTotalNumberOfCharacters = 0;
	for (int i = 0; i < 256; i++) {
		fCharacterCounts[i] = 0;
	}
}
//count takes in a char
//increments the total num of characters
//finds the decimal value of the ascii character
//increments that character by 1
void CharacterCounter::count(unsigned char aCharacter)
{
	fTotalNumberOfCharacters++;
	fCharacterCounts[aCharacter]++;
}
//This function assigns the aCharacter char to the array
int CharacterCounter::operator[](unsigned char aCharacter) const
{
	return fCharacterCounts[aCharacter];
}

//this << operator takes in an ostream and a characterCounter object constant reference
//sends the total num of characters to the outstream
//then goes through the array element by element and if its greater than 0
//it will send that character to the aOstream
std::ostream & operator<<(std::ostream & aOstream, const CharacterCounter & aCharacterCounter)
{	
	aOstream << "Total characters: " << aCharacterCounter.fTotalNumberOfCharacters;
	for (int i = 0; i < 256; i++)
	{
		if (aCharacterCounter.fCharacterCounts[i] != 0)
		{
			aOstream << (char)i << "\t" << aCharacterCounter.fCharacterCounts[i] << endl;
		}
		
	}
	return aOstream;
}
