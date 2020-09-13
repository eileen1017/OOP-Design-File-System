/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/
#pragma once

#include "AbstractCommand.h"

class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~LSCommand() = default;
private:
	AbstractFileSystem* fs;
};
