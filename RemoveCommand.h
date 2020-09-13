/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/
#pragma once
#include "AbstractCommand.h"


class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem* filesys);
	virtual int execute(std::string& filename, std::string des_path) override;
	virtual void displayInfo() override;
	virtual ~RemoveCommand() = default;
private: 
	AbstractFileSystem* fs;
};