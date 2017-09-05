#pragma once
#include <fstream>
#include <string>
#include "HexBlock.h"
class HexDump
{
private:
	HexBlock fData;
	std::ifstream fInput;
public:
	//open input file
	bool open(const std::string& aInputFileName);

	//close input file
	void close();

	// Generate hex dump to standard output. The method has to repeatedly
	// read a HexBlock (i.e., 16 bytes) and produce the corresponding hex
	// dump line consisting of offset and hex dump line for HexBlock object
	// fData. The method should utilize a do-while loop and run as long as
	// the sizeof fData is 16.
	void processInput();

	// Make objects of type HexDump callable. We use objects of type HexDump
	// as functions that take a file name as parameter and return a bool to
	// indicate success or failure of producing a hex dump to standard
	// output. The result is false only if we could not open input.
	bool operator()(const std::string& aInputFileName);
};