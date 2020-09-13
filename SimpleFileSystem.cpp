/*
Author: Jon Shidal
Purpose: CSE 332 lab 5 - defines the simple file system class
*/

#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"
#include<iostream>
using namespace std;

int SimpleFileSystem::addFile(string path, AbstractFile* fp) {
	if (files.find(path) != files.end()) { // file exists already
		return filealreadyexists;
	}
	else {
		if (fp != nullptr) {
			files.insert({ path,fp });
			return success;
		}
		return nullfile;
	}
}

int SimpleFileSystem::deleteFile(string path) {
	auto it = files.find(path); 
	if (it != files.end()) { // if the file exists
		AbstractFile* fileToDelete = it->second;
		if(openFiles.find(fileToDelete) == openFiles.end()){  // and the file isn't in use
			files.erase(it);
			delete fileToDelete;
			return success;
		}
		else {  // the file is open, can't delete
			return fileisopen;
		}
	}
	else { // file doesn't exist
		return filedoesnotexist; 
	}
}

AbstractFile* SimpleFileSystem::openFile(string path) {
	auto it = files.find(path);
	if (it != files.end()) { // file exists
		AbstractFile* fileToOpen = it->second;
		if (openFiles.find(fileToOpen) == openFiles.end()) { // file is not already open
			openFiles.insert(fileToOpen);
			return fileToOpen;
		}
		else { // file already open
			return nullptr;
		}
	}
	else { // file does not exist
		return nullptr;
	}
}
int SimpleFileSystem::closeFile(AbstractFile* file) {
	auto it = openFiles.find(file);
	if (it != openFiles.end()) { // file is currently open
		openFiles.erase(it);
		return success;
	}
	else { // file not open
		return filenotopen;
	}
}

SimpleFileSystem::~SimpleFileSystem() {
	for (auto it = files.begin(); it != files.end(); ++it) {
		delete it->second;
	}
}

