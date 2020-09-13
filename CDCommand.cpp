/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "CDCommand.h"
#include<iostream>

using namespace std;

CDCommand::CDCommand(AbstractFileSystem * fileSys) : fs(fileSys) {}

int CDCommand::execute(std::string& CWD, std::string options) {
	if (options == "..") { // move to parent directory
		AbstractFile* f = fs->openFile(CWD);
		if (f == nullptr) {
			cout << "current directory doesn't exist" << endl;
			return CWDdoesnotexist;
		}
		// update cwd to go back one directory
		CWD = CWD.substr(0, CWD.find_last_of('/'));
		fs->closeFile(f);
		return success;
	}
	else {
		if (options.find('.') != string::npos) {
			cout << "not a directory" << endl;
			return notadirectory;
		}
		AbstractFile * f = fs->openFile(CWD + "/" + options);
		if (f == nullptr) {
			cout << "directory does not exist" << endl;
			return directorydoesnotexist;
		}
		CWD += '/';
		CWD += options;
		fs->closeFile(f);
		return success;
	}
}
void CDCommand::displayInfo() {
	cout << "changes directories" << endl;
	cout << "Usage: cd <directory name> or cd .." << endl;
}