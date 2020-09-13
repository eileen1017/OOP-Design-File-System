/*
Author: Jon Shidal
Purpose: cse 332 lab 5, declares an interface for a file system
*/
#pragma once
#include "AbstractFile.h"
#include<string>
#include<vector>
class AbstractFileSystem {
public :
	// possible return values
	enum returnvalues {success, filealreadyexists, nullfile, filedoesnotexist, fileisopen, filenotopen, invalidpath, locationdoesnotexist, filealreadyadded,
		locationnotadirectory, cantdeleteroot, directorynotempty, unabletodeletedirectory
	};

	virtual int addFile(std::string path, AbstractFile* fp) = 0;
	virtual int deleteFile(std::string path) = 0;
	virtual AbstractFile* openFile(std::string path) = 0;
	virtual int closeFile(AbstractFile * file) = 0;

	virtual ~AbstractFileSystem() = default;
};