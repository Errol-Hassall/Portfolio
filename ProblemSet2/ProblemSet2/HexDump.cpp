#include "HexDump.h"
#include <iostream>
using namespace std;

//opens the file
bool HexDump::open(const std::string & aInputFileName)
{
	fInput.open(aInputFileName, fstream::binary);
	if (!fInput.good()) {
		return false;
	}
	return true;
}

//closes the file
void HexDump::close()
{
	fInput.close();
}

//this function will output the file offset 
//then it will call the fData objects read method
//then output each line in a do while loop till end of file
void HexDump::processInput()
{
	int lLineNum = 0;
	do
	{
		fData.read(fInput);
		cout << std::hex << std::setfill('0') << std::setw(8) << lLineNum << ": ";
		cout << fData;
		lLineNum += 16;
	} while (fData.size() >= 16);
}

//turns HexDump into more of a function, making it callable
bool HexDump::operator()(const std::string & aInputFileName)
{
	if (!open(aInputFileName)) {
		return false;
	}
	processInput();
	close();
	return true;
}
