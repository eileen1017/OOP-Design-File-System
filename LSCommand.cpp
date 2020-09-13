/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "LSCommand.h"
#include "ReadFileVisitor.h"
#include<iostream>
#include "ReadMetadataFileVisitor.h"
using namespace std;

LSCommand::LSCommand(AbstractFileSystem * fileSys) : fs(fileSys) {}

int LSCommand::execute(std::string& CWD, std::string options) {
	AbstractFile* f = fs->openFile(CWD);
	if (f == nullptr) { // file creation failed
		cout << "failed to open directory" << endl;
		return directorydoesnotexist;
	}
	if (options == "-l") {
		vector<char> contents = f->read();
		fs->closeFile(f);
		string filename = CWD + "/";

		for (unsigned int i = 0; i < contents.size(); i++) {
			if (contents[i] == '\n') {
				AbstractFile* f2 = fs->openFile(filename);
				if (f2 == nullptr) { // file creation failed
					cout << "failed to open " << filename << endl;
					return directorydoesnotexist;
				}
				ReadMetadataFileVisitor reader2;
				f2->accept(&reader2);
				fs->closeFile(f2);
				filename = CWD + "/";
			}
			else {
				filename += contents[i];
			}
		}
		return success;
	}
	else {
		ReadFileVisitor oreader;
		f->accept(&oreader);
		fs->closeFile(f);
		return success;
	}
}
void LSCommand::displayInfo() {
	cout << "lists the contents of the current directory" << endl;
	cout << "Usage: ls" << endl;
}