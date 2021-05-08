#include "pch.h"
#include "TimeCheck.h"


void TimeCheck::time_Start()
{
	timeStart = std::chrono::high_resolution_clock::now();
}

void TimeCheck::time_End()
{
	timeEnd = std::chrono::high_resolution_clock::now();
}

unsigned int TimeCheck::getTime()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
}

void TimeCheck::printResult(std::string fileName)
{
	std::ofstream fout;
	fout.open(fileName, std::ofstream::app);
	fout << getTime() << std::endl;
	fout.close();
}

