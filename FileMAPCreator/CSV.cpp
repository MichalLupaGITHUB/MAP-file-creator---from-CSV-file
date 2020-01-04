#include "pch.h"
#include "CSV.h"

// #### PUBLIC METHODS - CLASS CSV ####

/// LOAD FILE
string CSV::loadFile()
{
	CSVfile.clear(); // clearing content after next loop
	CSVfile.open(CSVpath); //  opening file

	// Checking whether file has been opened or has appropriate extension
	if (!CSVfile.is_open() || CSVpath.substr(CSVpath.find_last_of(".") + 1) != "csv") // retrun chars after "."
	{
		cout << endl;
		cout << "--------------------------- ERROR ---------------------------" << endl;
		cout << "-- Wrong PATH, FILE does NOT exist or wrong FILE extension --" << endl;
		cout << endl;

		Error = 1; // assignment nr of error
	}
	else
	{
		cout << "### CSV FILE loaded ### " << endl;
		cout << endl;

		Error = 0; // no error
	}

	CSVfile.close(); // closing file

	return CSVpath;
}
/// ----------------

/// LIST ALL VALUES FROM CSV
string CSV::listAllValuesFromCSV()
{
	CSVfile.open(CSVpath);

	while (CSVfile.good()) // reading from file until will not occur end of file
	{
		wsk = &value;
		
		getline(CSVfile, *wsk, ';'); // extract char to *wsk when will occur ";"
		replace(value.begin(), value.end(), ',', '.'); // replace from pointer on first char to end char
		csv_values.push_back(*wsk); // save value on end of list
		nr_of_semicolon++;
	}

	for (list<string>::iterator it = csv_values.begin(); it != csv_values.end(); ++it) // loop form first char to last char
	{
		outValues = outValues + " " + (*it); // adding reading pointer to creating new string
	}

	nr_of_semicolon = nr_of_semicolon - 1; // correction nr of semicolon
	
	CSVfile.close();

	return outValues;
}
/// ----------------

/// GET TABLE DIMMENSIONS
void CSV::getRowColumn()
{
	CSVfile.open(CSVpath);

	while (CSVfile.get(n_sign)) // getting char until end of file
	{
		if (n_sign == '\n')
		{
			nr_row++;
		}

		if (n_sign == ';' && nr_row == 1)
		{
			nr_column++;
		}
	}

	if ((nr_of_semicolon / nr_column) == nr_row) // correction nr of semicolon counted in the file
	{
		nr_row = nr_row - 1;
	}

	CSVfile.close();
}
/// ---------------

// ####################################

// DEFAULT CONSTRUCTOR - CLASS CSV
CSV::CSV()
{

}
//-----------------------