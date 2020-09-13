/*
Author: Jon Shidal
Purpose: CSE 332 lab 5, declares a simple file system class, contains a single level of files only - no directories
*/
#pragma once
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include <map>
#include <string>
#include<set>

class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(std::string path, AbstractFile* fp) override;
	virtual int deleteFile(std::string path) override;
	virtual AbstractFile* openFile(std::string path) override;
	virtual int closeFile(AbstractFile* file) override;

	virtual ~SimpleFileSystem();
private:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
	AbstractFileFactory* fileFactory;
};