/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "SimpleFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"

using namespace std;

AbstractFile * SimpleFileFactory::createFile(string path) {
	const int extension_length = 3;
	if (path.find_first_of('.') == string::npos) { // if no extension...
		return nullptr;
	}
	else if (path.size() > extension_length + 1) {   // add one for the '.'
		string fileType = path.substr(path.size() - extension_length, extension_length);
		if (fileType == "img") {
			AbstractFile* file = new ImageFile(path);
			return file;
		}
		else if (fileType == "txt") {
			AbstractFile* file = new TextFile(path);
			return file;
		}
		else {
			return nullptr;
		}
	}
	else {
		return nullptr;
	}
}

