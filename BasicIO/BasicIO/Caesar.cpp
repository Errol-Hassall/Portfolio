#include "Caesar.h"

//constructor
//intializes the two arrays, setting each element to 0
Caesar::Caesar()
{
	for (int i = 0; i < 26; i++)
	{
		fCharacterFrequenciesBefore[i] = 0;
		fCharacterFrequenciesAfter[i] = 0;
	}
}

void Caesar::shiftByFour(std::ifstream & aInput, std::ofstream & aOutput)
{
	char lOldChar = aInput.get();
	char lNewChar;
	bool good = aInput.good();
	while (aInput.good())
	{
		if (isalpha(lOldChar)) {
			bool lLower = islower(lOldChar);
			lOldChar = toupper(lOldChar);
			fCharacterFrequenciesBefore[lOldChar - 'A']++;
			lNewChar = 'A' + ((lOldChar - 'A'+ 4) % 26);
			fCharacterFrequenciesAfter[lNewChar - 'A']++;
			if (lLower == true)
			{
				lNewChar = tolower(lNewChar);
			}
			aOutput.put(lNewChar);
		}
		else
		{
			aOutput.put(lOldChar);
		}
		lOldChar = aInput.get();
	}
}

std::ostream & operator<<(std::ostream & aOstream, const Caesar & aObject)
{
	aOstream << "Character frequencies (before, after)" << std::endl;
	for (int i = 0; i < 26; i++)
	{
		aOstream << char(i + 'A') << ": " << aObject.fCharacterFrequenciesBefore[i] << ", " << aObject.fCharacterFrequenciesAfter[i] << std::endl;

	}
	return aOstream;
}
