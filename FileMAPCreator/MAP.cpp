#include "pch.h"
#include "MAP.h"

// #### PUBLIC METHODS - CLASS MAP  ####

// CREATE MAP FILE
void MAP::createFile()
{
	MAPpath = defaultCSVPath; // assignemt path form CSV File
	MAPFullLocation = MAPlocation + "/" + MAPpath.substr(MAPpath.find_last_of("/") + 1);
	// ----------------------------------------------------------
	
	// Converting extension .csv to .map
	size_t pos = MAPFullLocation.rfind('.'); // nr of bytes until occurence "."

	if (pos != string::npos) // if pos does not contain ".", itself value will be equal npos, so max size of size_t type
	{
		MAPFullLocation.replace(pos, MAPFullLocation.length() - pos, ".map"); // replace extension
	}
	else
	{
		MAPFullLocation.append(".map"); // adding extension if file would be written without extension
	}
	// ----------------------------------------------------------

	// Checking extension of MAP File
	if (MAPFullLocation.substr(MAPFullLocation.find_last_of(".") + 1) != "map")
	{
		cout << "-------------------- ERROR ------------------- " << endl;
		cout << "----- FILE does NOT have .map extension! ------" << endl;
		cout << endl;

		Error = 2; // assignment number of error
		goto ERROR; // go to Label ERROR
	}
	else
	{
		Error = 0; // no error
	}
	// ----------------------------------------------------------
			
	MAPfile.open(MAPFullLocation);

	if (!MAPfile.is_open())
	{
		cout << "-------------------- ERROR ------------------- " << endl;
		cout << "------ Wrong PATH or FILE does NOT exist! -----" << endl;
		cout << endl;

		Error = 3;
	}
	else
	{
		cout << "### MAP FILE has been created ###" << endl;
		Error = 0;
	}

	MAPfile.close();

ERROR: {} // do nothing
	
}
//----------------------

// SAVE VALUES TO MAP FILE FROM CSV FILE
void MAP::generateContent()
{
	MAPfile.open(MAPFullLocation);

	MAPfile << "#1000" << endl;
	MAPfile << "1" << endl;
	MAPfile << ("%c", char(34)) << ("%c", char(34)) << endl; // writing ' " ' from int value formated as char
	MAPfile << ("%c", char(34)) << ("%c", char(34)) << endl;
	MAPfile << ("%c", char(34)) << ("%c", char(34)) << endl;
	MAPfile << MAP_nr_column << " " << MAP_nr_row << endl;
	MAPfile << incomeValues;
	
	MAPfile.close();
	cout << "### MAP FILE has been saved ###" << endl;
	cout << endl;

	size_t sign_found1 = 0;
	size_t sign_found2 = 0;
	sign_found1 = MAPFullLocation.find(':');
	sign_found2 = MAPFullLocation.find('/');
	
	if (sign_found1 == (string::npos) || sign_found2 == (string::npos)) // checking whether in the Path are chars either ":" or "/"
	{
		cout << "### FILE MAP has been located in the same place as EXE FILE ###" << endl;
		cout << endl;
	}	
}
//----------------------

// #####################################

// DEFAULT CONSTRUCTOR - CLASS MAP
MAP::MAP()
{

}
//-----------------------

