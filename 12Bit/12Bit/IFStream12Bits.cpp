#include "IFStream12Bits.h"
using namespace std;
#include <iostream>
//called by the costructor to initialize the variables
void IFStream12Bits::init()
{
	for (int i = 0; i < 32; i++)
	{
		fBuffer[i] = 0;
	}
	fByteCount = 0;
	fByteIndex = 0;
	fBitIndex = 8;
}

//fills the buffer with data from the file
void IFStream12Bits::reload()
{
	fByteIndex = 0;
	fIStream.read((char*)fBuffer, 32);
	fByteCount = (int)fIStream.gcount();
}

//reads the buffer one bit at a time
int IFStream12Bits::readBit()
{
	int lResult = 0;
	if (fByteCount == 0) reload();
	
	if (eof())
	{
		throw runtime_error("The file is empty there are no more bits");
	}

	if (fBuffer[fByteIndex] & (1 << fBitIndex - 1)) lResult = 1;

	fBitIndex--;
	
	if (fBitIndex == 0)										
	{
		fByteCount--;
		fByteIndex++;
		fBitIndex = 8;
	}

	return lResult;
}

//constructor
IFStream12Bits::IFStream12Bits()
{
	init();
}

//class constructor that takes in a file name
IFStream12Bits::IFStream12Bits(const char * aFileName)
{
	init();
	open(aFileName);
}

//class destructor
IFStream12Bits::~IFStream12Bits()
{
	close();
}

//Opens the specified file
void IFStream12Bits::open(const char * aFileName)
{
	fIStream.open(aFileName, ifstream::binary);
}

//closes the IStream
void IFStream12Bits::close()
{
	fIStream.close();
}

//returns if the IStream has failed
bool IFStream12Bits::fail()
{
	return fIStream.fail();
}

//returns the end of file
bool IFStream12Bits::eof()
{
	return fByteCount == 0;
}

//loops through 12 at a time
//calling read bit to read one bit from the buffer at a time 
//then returns that 12Bit value
IFStream12Bits & IFStream12Bits::operator>>(int & a12BitValue)
{
	int lResult = 0;
	
	for (int i = 0; i < 12; i++)
	{
		int lBit = readBit();
		
		if (lBit == 1)
		{
			lResult = (1 << i) + lResult;
		}
	}

	a12BitValue = lResult;

	return *this;
}
