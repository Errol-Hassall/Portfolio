#pragma once
#include <fstream>
class IFStream12Bits
{
private:
	std::ifstream fIStream;
	char fBuffer[32];
	int fByteCount;
	int fByteIndex;
	int fBitIndex;
	void init();
	void reload();
	int readBit();
public:
	IFStream12Bits();
	IFStream12Bits(const char* aFileName);
	~IFStream12Bits();
	void open(const char* aFileName);
	void close();
	bool fail();
	bool eof();
	IFStream12Bits& operator>>(int& a12BitValue);
};