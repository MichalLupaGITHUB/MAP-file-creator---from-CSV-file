#pragma once
class OutFile
{
// #### PUBLIC VIRTUAL METHODS ####

public:

	virtual void createFile() = 0; // virtual Method
	virtual void generateContent() = 0; // virtual Method
	 
// ################################

// DEFAULT CONSTRUCTOR	
	OutFile();
//-----------------------
};

