#pragma once
#include "CSV.h"
#include "OutFile.h"
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

class MAP : public OutFile, public CSV
{
	// CLASS PRIVATE VARIABLES
private:
	ofstream MAPfile; // var using to operate on output files - writing files
	string char_YorN; // var using for detect choice regarding way of saving file
	string MAPFullLocation; // full location of MAP File
	//-----------------------

	// CLASS PROTECTED VARIABLES
protected:
	//-----------------------

	// CLASS PUBLIC VARIABLES
public:
	int MAP_nr_column; // nr of column in MAP file
	int MAP_nr_row; // nr of row in MAP file
	string defaultCSVPath; // default Path to writing file taken from CSVPath
	string incomeValues; // var taken from outValues - to write in MAP File
	string MAPpath; // acces path to writing file
	string MAPlocation; // location of MAP file 
	int Error; // error of loading and creating MAP file
	//----------------------
	
	// #### PUBLIC METHODS ####

	// CREATE MAP FILE
	virtual void createFile();
	//----------------------

	// SAVE VALUES TO MAP FILE FROM CSV FILE
	virtual void generateContent();
	//----------------------
	
	// #####################

	// DEFAULT CONSTRUCTOR
	MAP();
	//-----------------------
};
