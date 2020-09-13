/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/
#pragma once
#include "AbstractCommand.h"

class TouchCommand : public AbstractCommand {
public:
	TouchCommand(AbstractFileFactory* fileFactory, AbstractFileSystem * fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~TouchCommand() = default;
private:
	AbstractFileFactory* ff;
	AbstractFileSystem* fs;
};