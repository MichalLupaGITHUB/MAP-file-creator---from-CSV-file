// FileMAPCreator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "CSV.h"
#include "MAP.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <cstddef>
#include <algorithm>
#include <cstdio>
#include <stdio.h> 
#include <cstdlib>
#include <sstream> 

using namespace std;

// GLOBAL VARIABLES
string firstArg; // first arg of exe
string argCSVpath; // second arg of exe
string argMAPpath; // third arg of exe
int resultOfprogram; // fourth arg of exe - return value
int nrOfError; // nr of error
int nrOfArgs; // nor of args
// ---------------------------

// Struct for Service of Errors
struct GroupErrors
{
	int errorLoadCSVfile;
	int errorExtensionMAPfile;
	int errorCreateMAPfile;
};
// ---------------------------

// Chcecking and assignment nr of Error 
int nrOfErrorCheck(int condition)
{
	int local_nrOfError = 0;

	if (condition)
	{
		local_nrOfError = condition;
	}
	else
	{
		local_nrOfError = 0;
	}

	return local_nrOfError;
}
// ---------------------------

// Replace selected character in string to other
string ReplaceAll(string str, const string& from, const string& to)
{
	size_t start_pos = 0;

	while ((start_pos = str.find(from, start_pos)) != string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}
// ---------------------------

int main(int argc, char *argv[])
{	
	//       ############################### HEADER OF PROGRAM ############################### 
	cout << "#########################################################################" << endl;
	cout << "########################### MAP FILE Creator ############################" << endl;
	cout << "#########################################################################" << endl;
	cout << "#### Program converts 'CSV File' to 'MAP File' - required by MORPHEE ####" << endl;
	cout << "#########################################################################" << endl;
	cout << endl;
	cout << "  *** NOTE: It's recomended to start this program as Administrator ***" << endl;
	cout << endl;
	//       ################################################################################# 

	// OBJECTS
	CSV myCSVFile;
	MAP myMAPFile;
	GroupErrors Errors;
	// ------------------------------------

	nrOfArgs = argc; // assignemnt arg value to Global Variable

	// Chcecking nr of args
	if (nrOfArgs < 4)
	{
		goto ERRORS;
	}
	else
	{
		stringstream convertfirstArg(argv[0]);
		stringstream convertargCSVpath(argv[1]);
		stringstream convertargMAPpath(argv[2]);
		stringstream convertresultOfprogram(argv[3]);

		convertfirstArg >> firstArg;
		convertargCSVpath >> argCSVpath;
		convertargMAPpath >> argMAPpath;
		convertresultOfprogram >> resultOfprogram;
	}
	// ------------------------------------

	//// PASSING PARAMETERS
	argCSVpath = ReplaceAll(argCSVpath, string(R"(\)"), string("/")); // replace "\" to "/"
	myCSVFile.CSVpath = argCSVpath;

	myMAPFile.defaultCSVPath = myCSVFile.loadFile(); // Passing path to MAP FILE from CSV FILE

	//// CHECKING ERRORS OF LOAD CSV FILE
	Errors.errorLoadCSVfile = myCSVFile.Error;
	nrOfError = nrOfErrorCheck(Errors.errorLoadCSVfile);

	if (nrOfError > 0)
	{
		goto ERRORS;
	}
	///// ------------------------------------

	myMAPFile.incomeValues = myCSVFile.listAllValuesFromCSV(); // Passing values to MAP FILE from CSV FILE

	//// Passing dimennsions of table to MAP FILE from CSV FILE
	myCSVFile.getRowColumn();
	myMAPFile.MAP_nr_column = myCSVFile.nr_column; 
	myMAPFile.MAP_nr_row = myCSVFile.nr_row;;
	//// ------------------------------------
	
	argMAPpath = ReplaceAll(argMAPpath, string(R"(\)"), string("/")); // replace "\" to "/"
	myMAPFile.MAPlocation = argMAPpath; // assignment arv[Location of MAP file] to object path
	
	//// GENERATING MAP FILE
	OutFile *pointerOnOutFile;
	pointerOnOutFile = &myMAPFile;
	pointerOnOutFile->createFile();

	//// CHECKING ERRORS OF EXTENSION MAP FILE
	Errors.errorExtensionMAPfile = myMAPFile.Error;
	nrOfError = nrOfErrorCheck(Errors.errorExtensionMAPfile);

	if (nrOfError > 0)
	{
		goto ERRORS;
	}
	//// ------------------------------------

	//// CHECKING ERRORS OF CREATE MAP FILE
	Errors.errorCreateMAPfile = myMAPFile.Error;
	nrOfError = nrOfErrorCheck(Errors.errorCreateMAPfile);

	if (nrOfError > 0)
	{
		goto ERRORS;
	}
	//// ------------------------------------

	pointerOnOutFile->generateContent(); // generating MAP File
	
	//// SERVICE OF ERRORS

	//// Table of ERRORS:
	//// 0 - No Errors
	//// 1 - Error of loading CSV FILE (wrong path or file does not exist or wrong extension)
	//// 2 - Wrong extension of MAP File
	//// 3 - Target location does not exist
	//// 4 - Missing argument of fucntion during calling exe file

	ERRORS:

	switch (nrOfError)
	{ 
		case 1:
			resultOfprogram = 1;
			break;

		case 2:
			resultOfprogram = 2;
			break;

		case 3:
			resultOfprogram = 3;
			break;

		default:
			resultOfprogram = 0;

			if (nrOfArgs < 4)
			{
				resultOfprogram = 4;

				cout << endl;
				cout << "-------------------- ERROR ------------------- " << endl;
				cout << "-------- Missing Argument Of Function ---------" << endl;
				cout << endl;
			}

			break;
	}
	//// ------------------------------------
	cout << "Result of program: " << resultOfprogram << endl;

	return resultOfprogram;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

