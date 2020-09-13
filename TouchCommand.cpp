/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "TouchCommand.h"
#include<iostream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileFactory* fileFactory, AbstractFileSystem* fileSys) : 
	ff(fileFactory), fs(fileSys) { }

int TouchCommand::execute(std::string& CWD, std::string options) {
	string filename;
	if (options.find_last_of('/') != string::npos) {
		// create file with filename only, allows for creating files with directories not currently the working directory
		filename = options.substr(options.find_last_of('/') + 1, string::npos);
	}
	else {
		filename = options;
	}
	AbstractFile * f = ff->createFile(filename);
	if (f == nullptr) { // file creation failed
		cout << "failed to create file" << endl;
		return failedtocreatefile;
	}
	string fullPath = CWD;
	fullPath += '/';
	fullPath += options;
	int result = fs->addFile(fullPath, f);
	if (result != success) {
		cout << "failed to add file to file system, deleting file" << endl;
		delete f;
		return failedtoadd;
	}
	return result;
}
void TouchCommand::displayInfo() {
	cout << "touch creates a file" << endl;
	cout << "Usage: touch <filename>" << endl;
}