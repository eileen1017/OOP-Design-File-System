#pragma once
/*
Author: Jon Shidal
Purpose: CSE 332 lab 5, declares the cd command class
*/
#include "AbstractCommand.h"


class CDCommand : public AbstractCommand {
public:
	CDCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~CDCommand() = default;
private:
	AbstractFileSystem* fs;
};