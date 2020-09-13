/*
Author: Jon Shidal
Purpose: CSE 332 lab 5 - this file delares the interface for a command
*/

#pragma once
#include<string>
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class AbstractCommand {
public:
	enum returnvalues { success, failedtocreatefile, failedtoadd, CWDdoesnotexist, notadirectory, directorydoesnotexist,
		filedoesnotexist, fileinuse, failedtocopy };
	virtual int execute(std::string &CWD, std::string options) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};