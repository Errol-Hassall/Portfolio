#include "HexBlock.h"

//initializes the variables and sets all the array elements to 0
HexBlock::HexBlock()
{
	fSize = 16;
	for (int i = 0; i < (int)fSize; i++)
	{
		fBuffer[i] = 0;
	}
}

//reads the file, takes 16 bytes out and sets the fSize field to the number of bytes taken out
std::istream & HexBlock::read(std::istream & aIStream)
{
	aIStream.read((char*)fBuffer, fSize);
	fSize = (unsigned long)aIStream.gcount();
	return aIStream;
}

//returns the size of the fSize field
unsigned long HexBlock::size() const
{
	return fSize;
}

//this is the output for the console
//it will out put one line to the console in the specified format
std::ostream & operator<<(std::ostream & aOStream, const HexBlock & aObject)
{
	for (int i = 0; i < (int)aObject.fSize; i++)
	{
		if (i == 8)
		{
			aOStream << "| ";
		}
		aOStream << std::uppercase << std::hex << std::setw(2) << (int)aObject.fBuffer[i] << " "; 
	}
	//Formats the final line by adjusting based on how many elements were printed from fBuffer
	if (aObject.fSize < 16) {
		int lWidth = 51;
		if (aObject.fSize >= 8)
		{
			aOStream << std::setfill(' ') << std::setw(lWidth - 2 - aObject.fSize * 3);
		}
		else
		{
			aOStream << std::setfill(' ') << std::setw(lWidth - aObject.fSize * 3);
		}
		
	}
	for (int i = 0; i < (int)aObject.fSize; i++)
	{
		if (0x1F < aObject.fBuffer[i] && aObject.fBuffer[i] < 0x7F)
		{
			aOStream << (char)aObject.fBuffer[i]; 
		}
		else
		{
			aOStream << ".";
		}
	}
	aOStream << std::endl;
	return aOStream;
	
}
