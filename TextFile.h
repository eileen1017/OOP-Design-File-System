/*
Author: Jon Shidal
Purpose: CSE332 lab 5, declares a TextFile class
*/
#pragma once

#include "AbstractFile.h"
#include<vector>

class TextFile : public AbstractFile {
	//friends
	friend class SimpleFileSystem;
	friend class HierarchicalFileSystem;
public:
	TextFile(std::string n);
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;

	virtual ~TextFile() = default;

	virtual void accept(AbstractFileVisitor*) override;
	virtual TextFile* clone() override;
protected:
	virtual int addChild(AbstractFile*) override;
	virtual int removeChild(std::string name) override;
	virtual void setParent(AbstractFile*) override;
	virtual AbstractFile* getChild(std::string name) override;
	virtual AbstractFile* getParent() override;
private:
	std::vector<char> contents;
	std::string name;
	AbstractFile* parent;
	int count;
};