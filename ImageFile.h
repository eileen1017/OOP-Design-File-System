/*
Author: Jon Shidal
Purpose: CSE 332 lab 5, declares an ImageFile class
*/
#pragma once
#include "AbstractFile.h"
#include <vector>
#include<string>

class ImageFile : public AbstractFile {
	// friends
	friend class ReadFileVisitor;
	friend class SimpleFileSystem;
	friend class HierarchicalFileSystem;
public:
	ImageFile(std::string n);
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;

	virtual ~ImageFile() = default;

	virtual void accept(AbstractFileVisitor*) override;
	virtual ImageFile* clone() override;
protected:
	virtual int addChild(AbstractFile*) override;
	virtual int removeChild(std::string name) override;
	virtual void setParent(AbstractFile*) override;
	virtual AbstractFile* getChild(std::string name) override;
	virtual AbstractFile* getParent() override;

private:
	std::string name;
	char dimensions;
	std::vector<char> contents;
	size_t coordsToIndex(size_t x, size_t y);
	// for composite pattern
	AbstractFile* parent;
};