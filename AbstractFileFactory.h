/*
Author: Jon Shidal
Purpose: CSE 332 lab 5, this file declares the FileFactory interface
*/

#pragma once
#include "AbstractFile.h"
#include "AbstractFileSystem.h"

class AbstractFileFactory {
public:
	virtual AbstractFile * createFile(std::string path) = 0;
};