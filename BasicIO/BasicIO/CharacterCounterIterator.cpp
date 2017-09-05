#include "CharacterCounterIterator.h"

CharacterCounterIterator::CharacterCounterIterator(CharacterCounter & aCounter)
{
	for (int i = 0; i < 256; i++)
	{
		fMaps[i] = FrequencyMap(i, aCounter[i]);
	}
	fIndex = 0;
	while (fIndex < 256 && fMaps[fIndex].getFrequency() == 0)
	{
		fIndex++;
	}
}

const FrequencyMap & CharacterCounterIterator::operator*() const
{
	return fMaps[fIndex];
}

CharacterCounterIterator & CharacterCounterIterator::operator++()
{
	fIndex++;
	while (fIndex < 256 && fMaps[fIndex].getFrequency() == 0)
	{
		fIndex++;
	}
	return *this;
}

CharacterCounterIterator CharacterCounterIterator::operator++(int)
{
	CharacterCounterIterator temp = *this;
	++(*this);
	return temp;
}

bool CharacterCounterIterator::operator==(const CharacterCounterIterator & aOther) const
{
	return (fIndex == aOther.fIndex);
}

bool CharacterCounterIterator::operator!=(const CharacterCounterIterator & aOther) const
{
	return !(*this == aOther);
}

CharacterCounterIterator CharacterCounterIterator::begin() const
{
	CharacterCounterIterator temp = *this;
	temp.fIndex = 0;
	++temp;
	return temp;
}

CharacterCounterIterator CharacterCounterIterator::end() const
{
	CharacterCounterIterator temp = *this;
	temp.fIndex = 256;
	return temp;
}
