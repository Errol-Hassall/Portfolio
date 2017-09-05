#include "OFStream12Bits.h"

using namespace std;

void OFStream12Bits::init()
{
	for (int i = 0; i < 32; i++)
		fBuffer[i] = 0;

	fByteIndex = 0;
	fBitIndex = 8;
}

void OFStream12Bits::writeBit0()
{
	fBitIndex--;
	finishWriteBit();
}

void OFStream12Bits::writeBit1()
{
	fBuffer[fByteIndex] += 1 << (fBitIndex - 1);
	fBitIndex--;
	finishWriteBit();
}

OFStream12Bits::OFStream12Bits()
{
	init();
}

void OFStream12Bits::finishWriteBit()
{
	if (fBitIndex == 0)
	{
		if (fByteIndex == 31)
		{
			fByteIndex++;
			flush();
		}
		else
		{
			fByteIndex++;
			fBitIndex = 8;
		}
	}
}

OFStream12Bits::OFStream12Bits(const char* aFileName)
{
	init();
	open(aFileName);
}

OFStream12Bits::~OFStream12Bits()
{
	close();
}

void OFStream12Bits::open(const char* aFileName)
{
	fOStream.open(aFileName, ofstream::binary);
}

bool OFStream12Bits::fail()
{
	return fOStream.fail();
}

void OFStream12Bits::close()
{
	flush();
	fOStream.close();
}

void OFStream12Bits::flush()
{
	fOStream.write(fBuffer, fByteIndex + (fBitIndex % 8 ? 1 : 0));
	init();
}

OFStream12Bits& OFStream12Bits::operator <<(int a12BitValue)
{
	for (int i = 0; i < 12; i++)	// write 12 Bits
	{
		if (a12BitValue & 0x01)	// The current lowest bit is set.
			writeBit1();
		else
			writeBit0();
		a12BitValue >>= 1;			// Code := Code / 2
	}

	return *this;
}