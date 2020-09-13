/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/
#pragma once
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string path) override;
};