/*
Author: Jon Shidal
Purpose: CSE 332 lab 5, declares a hierarchical file system that includes support for directory files
*/

#pragma once
#include "AbstractFileSystem.h"
#include "DirectoryFile.h"
#include "Proxy.h"
#include<map>
#include<set>
#include "AbstractFileFactory.h"

class HierarchicalFileSystem : public AbstractFileSystem {
public:
	HierarchicalFileSystem();
	virtual int addFile(std::string path, AbstractFile*) override;
	virtual int deleteFile(std::string path) override;
	virtual AbstractFile* openFile(std::string path) override;
	virtual int closeFile(AbstractFile* file) override;

	virtual ~HierarchicalFileSystem();
private:
	AbstractFile* parsePath(std::string path);
	DirectoryFile* rootDirectory;
	std::set<AbstractFile*> openFiles;
};