#include "CPCommand.h"
#include<iostream>
#include <sstream>
using namespace std;

CPCommand::CPCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int CPCommand::execute(std::string& CWD, std::string options) {
	istringstream ss(options);
	string file_name, des_path;
	ss >> file_name;
	ss >> des_path;
	string curr_path = CWD + '/' + file_name;
	AbstractFile* curr_file = fs->openFile(curr_path);
	vector<char> path = curr_file->read();
	AbstractFile* copy_file = curr_file->clone();
	path = copy_file->read();
	fs->closeFile(curr_file);
	des_path += "/" + file_name;
	int result = fs->addFile(des_path, copy_file);
	if (result != success) {
		cout << "failed to copy file to file system" << endl;
		return failedtocopy;
	}
	return result;
}
void CPCommand::displayInfo() {
	cout << "copy file" << endl;
	cout << "Usage: cp <file to copy><full_path_to_destination>" << endl;
}