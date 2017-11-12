#include "Iterator.h"



void Iterator::Next(string Directory)
{
	intptr_t findSubHandle=NULL;
	if (findSubHandle == -1L)
		return;
	do
	{
		if (findSubHandle == NULL)
		{
			cout << Directory;
			findSubHandle = _findfirst((Directory + _mask).c_str(), &_findData);
		}
		else
		{
			if (_findnext(findSubHandle, &_findData) != 0)
				return;
		}
		if ((strcmp(_findData.name, ".") == 0) || (strcmp(_findData.name, "..") == 0))
			continue;
		if (IsDirectory())
		{
			/*cout << Directory << " " << _findData.name << endl;*/
			/*intptr_t findSubData;*/
			system("pause");
			/*findSubData = _findHandle;*/
			Next(Directory+"\\"+_findData.name);
			/*_findHandle = findSubData;*/
		}
		Print();
	}
	while (1);
	_findclose(findSubHandle);
}

void Iterator::Print()
{
	/*if (!IsDirectory())*/
	{
		cout << "File" << ": " <<_findData.name << endl <<	"Size: " << _findData.size << endl <<	"Attrib: " << _findData.attrib << endl;
		   /*"Time create: " << localtime_s(_findData.time_create) << endl*/
	}
}

bool Iterator::Mask(string Mask)
{
	if (strcmp(_findData.name, Mask.c_str()) == 0)
	return true;
}

Iterator::Iterator()
{
}

Iterator::Iterator(char * Directory)
{
	_firstHandle = true;
	_findHandle = NULL;
	_mask = "*.*";
	_directory = Directory;
}

void Iterator::Search()
{    
	/*cout << "Enter a mask: ";
	cin >> _mask;*/
	Next(_directory);
}


Iterator::~Iterator()
{
}
