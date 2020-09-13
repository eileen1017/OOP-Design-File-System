/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "RemoveCommand.h"
#include<iostream>
#include <sstream>
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

// removes a file from the current working directory
int RemoveCommand::execute(std::string& CWD, std::string options) {
	string fullPath = CWD;
	istringstream ss(options);
	string middle_path, option;
	ss >> middle_path;
	if(ss>> option && option=="-r") {
		middle_path = CWD + '/' + middle_path;
		AbstractFile* temp = fs->openFile(middle_path);
		std::vector<char> contents = temp->read();
		string oneFile;
		for (unsigned int i = 0; i < contents.size(); i++) {
			if (contents[i] == '\n') {
				string temp_path = middle_path + '/' + oneFile;
				int r = fs->deleteFile(temp_path);				
				if (r == AbstractFileSystem::fileisopen) {
					cout << oneFile << " is currently in use" << endl;
				}
				oneFile = "";
				continue;
			}
			else {
				oneFile += contents[i];
			}
		}
		fs->closeFile(temp);
		return success;
	}
	fullPath += '/';
	fullPath += options;
	int result = fs->deleteFile(fullPath);
	if (result == AbstractFileSystem::filedoesnotexist) {
		cout << "File does not exist" << endl;
		return filedoesnotexist;
	}
	else if (result == AbstractFileSystem::fileisopen) {
		cout << "File is currently in use" << endl;
		return fileinuse;
	}
	return success;
}
void RemoveCommand::displayInfo() {
	cout << "touch removes a file from the file system and then deletes the file" << endl;
	cout << "Usage: rm <filename>" << endl;
}