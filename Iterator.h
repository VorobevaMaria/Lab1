#pragma once
#include <io.h>
#include <iostream>
#include <time.h>
#include <string>
#include <windows.h>
using namespace std;
class Iterator
{
	string _mask;
	string _directory;
	
	bool IsDirectory(_finddata_t _findData)
	{
		return ((_findData.attrib & _A_SUBDIR) != 0);
	}
	void Print(_finddata_t _findData);
public:
	Iterator();
	Iterator(char*);
	void Search();
	void Next(string);
	~Iterator();
};

