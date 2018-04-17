// IoStreamHandsON.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

void StringTest();
void Readfile();
void WriteFile();

int main()
{
	//Readfile();
	//WriteFile();
	StringTest();


}

void StringTest()
{
	std::string str;
	for (char c{ 'a' }; c <= 'z'; ++c)
	{
		str.push_back(c);
		std::cout << std::setw(3) << str.capacity() << '\t' << str.size() << '\t' << str << '\n';

	}
	std::cout << str[5] << ' ' << str.at(12) << '\n';

	std::stringstream strstream;
	strstream << 3.1415926535;
	strstream >> str;
	std::cout << str << '\n';

	system("pause");

}

void Readfile()
{
	std::string filename{"Readme.txt"};
	std::ifstream inStream{ filename };
	if (!inStream)
	{
		std::cout << "Error opening the file: " << filename << '\n';
		return;
	}
	

	std::string str;
	while (inStream.good())
	{
	inStream >> str;
	if (inStream.good())
	{
	std::cout << str<< '\n';
	}
	
	//std::cin.get();
	}
	if (inStream.eof()) std::cout << "eof state is set\n";
	if (inStream.fail()) std::cout << "fail state is set\n";
	if (inStream.bad()) std::cout << "bad state is set\n";
	system("pause");

	inStream.clear();
	inStream.seekg(0, inStream.beg);
	while (inStream.good())
	{
		std::getline(inStream, str);
		std::cout << str << '\n';

	}
	if (inStream.eof()) std::cout << "eof state is set\n";
	if (inStream.fail()) std::cout << "fail state is set\n";
	if (inStream.bad()) std::cout << "bad state is set\n";


	system("pause");
}

void WriteFile()
{

	std::string filename{ "output.txt" };

	std::ofstream outFile{filename};
	if (!outFile)
	{
		std::cout << "Opening the file to write has failed: " << filename << '\n';
		return;

	}

	for (char c{'a'}; c<= 'z'; ++c)
	{
		outFile << c << ' ';

	}
}
