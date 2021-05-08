#pragma once
#include <iostream>
#include <chrono>
#include <fstream>



class TimeCheck
{
public:
	std::chrono::high_resolution_clock::time_point timeStart;
	std::chrono::high_resolution_clock::time_point timeEnd;

	void time_Start();
	void time_End();
	unsigned int getTime();
	void printResult(std::string);
};

