/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/
#pragma once
#include <string>
#include<map>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CommandPrompt {
public:
	enum returnvalues { success, userquit, failedtoaddcommand };
	CommandPrompt();
	int run();
	int addCommand(std::string, AbstractCommand*);
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	~CommandPrompt() = default;
	
private:
	std::map<std::string, AbstractCommand*> commands;
	std::string CWD;
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;

	std::string prompt();
	void listCommands();
};