#pragma once

#include<iostream>

class CharacterCounter {
private:
	//stores the total num of characters in the file
	int fTotalNumberOfCharacters;
	int fCharacterCounts[256]; //We count all 254 byte values

public:
	//Class constructor used to initialise fTotalNum and fCharacterCounts array
	CharacterCounter();

	//increments the ftotalnumCharacters
	//takes in a char that is store in the array at the location 
	//of the ascii character then it will incremenet that array location
	void count(unsigned char aCharacter);

	//friend function that takes in an ostream and a characterCounter object
	//this will then print the total chracters
	//then will loop through the length of the array
	//if the character count is more than 0 
	//it will print the character and the count along with it
	//then it will return the ostream
	friend std::ostream& operator<<(std::ostream& aOstream, const CharacterCounter& aCharacterCounter);
	
	int operator[](unsigned char aCharacter) const;
};
