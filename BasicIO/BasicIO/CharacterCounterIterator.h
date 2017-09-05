#pragma once
#include "CharacterCounter.h"
#include "FrequencyMap.h"

class CharacterCounterIterator
{
private:
	FrequencyMap fMaps[256];
	int fIndex;
public:
	CharacterCounterIterator(CharacterCounter& aCounter);

	const FrequencyMap& operator*() const;
	CharacterCounterIterator& operator++();
	CharacterCounterIterator operator++(int);
	bool operator==(const CharacterCounterIterator& aOther) const;
	bool operator!=(const CharacterCounterIterator& aOther) const;

	CharacterCounterIterator begin() const;
	CharacterCounterIterator end() const;
};
