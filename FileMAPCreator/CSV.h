#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <list>
#include <cstddef>
#include <algorithm>
#include <cstdio>
#include <stdio.h> 
#include <sstream>
#include <cstdlib>

using namespace std;

class CSV
{
	// CLASS PRIVATE VARIABLES
private:
	char n_sign; // var using to detect char in string
	int nr_of_semicolon; // number of semicolon in reading file
	string value; // temporary buffer for reading chars from files
	string *wsk = new string(); // pointer to value*
	list<string> csv_values; // list using to stroe values as 1-column list
	ifstream CSVfile; // var using to operate on input files - reading files
	string outValues; // retrun var for other object
	//-----------------------

	// CLASS PROTECTED VARIABLES
protected:
	//-----------------------

	// CLASS PUBLIC VARIABLES
public:
	int nr_column; // nr of column in CSV file
	int nr_row; // nr of row in CSV file
	string CSVpath; // acces path to reading file
	int Error; // error of load CSV file
	//-----------------------

	// #### PUBLIC METHODS ####

	/// LOAD FILE
	string loadFile();
	/// ----------------

	/// LIST ALL VALUES FROM CSV
	string listAllValuesFromCSV();
	/// ----------------

	/// GET TABLE DIMMENSIONS
	void getRowColumn();
	/// ---------------

	// #####################

	// DEFAULT CONSTRUCTOR
	//-----------------------
	CSV();
	//-----------------------
}; 
