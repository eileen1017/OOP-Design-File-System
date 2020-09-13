/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "HierarchicalFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"
#include "DirectoryFile.h"

using namespace std;

AbstractFile* HierarchicalFileFactory::createFile(string path) {
	const int extension_length = 3;
	if (path.find_first_of('.') == string::npos) { // if no extension...
		AbstractFile* file = new DirectoryFile(path);
		return file;
	}
	else if (path.size() > extension_length + 1) { // +1 for the '.'
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
