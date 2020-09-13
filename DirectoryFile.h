/*
Author: Jon Shidal
Purpose: CSE 332 lab 5, declares a directory class
*/
#pragma once
#include "AbstractFile.h"
#include<map>

class DirectoryFile : public AbstractFile {
	//friends
	friend class SimpleFileSystem;
	friend class HierarchicalFileSystem;

public:
	DirectoryFile(std::string n);
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override; 
	virtual int append(std::vector<char>) override; 
	virtual unsigned int getSize() override;
	virtual std::string getName() override;

	virtual ~DirectoryFile();

	virtual void accept(AbstractFileVisitor*) override;
	virtual DirectoryFile* clone() override;
protected:
	virtual int addChild(AbstractFile*) override;
	virtual int removeChild(std::string name) override;
	virtual void setParent(AbstractFile*) override;
	virtual AbstractFile* getChild(std::string name) override;
	virtual AbstractFile* getParent() override;
	virtual int& getCount();
private:
	std::string name;
	std::vector<char> contents;
	AbstractFile* parent;
	std::map<std::string, AbstractFile*> children;
	int count;
};