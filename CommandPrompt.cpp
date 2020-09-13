/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "CommandPrompt.h"
#include<iostream>
#include <sstream>

using namespace std;

CommandPrompt::CommandPrompt() : CWD("root"), fileSystem(nullptr), fileFactory(nullptr) {}

int CommandPrompt::run() {
	while (1) {
		string input = prompt();
		if (input == "q") {
			return userquit;
		}
		else if (input == "help") {
			listCommands();
		}
		else if (input.find_first_of(' ') == string::npos) { // single word command
			auto it = commands.find(input);
			if (it == commands.end()) {
				cout << "invalid command" << endl;
			}
			else {
				int result = it->second->execute(CWD, ""); // no additional options
				if (result != AbstractCommand::success) {
					cout << "command failed" << endl;
				}
			}
		}
		else{  // multiple words, parse
			istringstream iss(input);
			string command;
			iss >> command; 
			if (command == "help") {
				string commandToDisplay;
				iss >> commandToDisplay;
				auto it = commands.find(commandToDisplay);
				if (it != commands.end()) { // if valid command, display its information
					it->second->displayInfo();
				}
				else {
					cout << "command does not exist" << endl;
				}
			}
			else {
				auto it = commands.find(command);
				if (it != commands.end()) {
					// substring options and call execute
					string options = input.substr(input.find_first_of(' ') + 1, string::npos);
					int result = it->second->execute(CWD, options);
					if (result != AbstractCommand::success) {
						cout << "command failed" << endl;
					}
				}
				else {
					cout << "invalid command" << endl;
				}
			}
		}
	}
}

string CommandPrompt::prompt() {
	cout << "To quit: q, ";
	cout << "For a list of commands: help, ";
	cout << "For information about a specific command: help <command name>" << endl;
	cout << CWD << " $ ";
	string input;
	getline(cin, input);
	return input;
}

void CommandPrompt::listCommands() {
	cout << "Commands:" << endl;
	for (auto it = commands.begin(); it != commands.end(); ++it) {
		cout << it->first << endl;
	}
}

int CommandPrompt::addCommand(string name, AbstractCommand* cmd) {
	auto result = commands.insert({ name,cmd });
	if (result.second) {
		return success;
	}
	else {
		return failedtoaddcommand;
	}
}

void CommandPrompt::setFileSystem(AbstractFileSystem* filesystem) {
	fileSystem = filesystem;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* filefactory) {
	fileFactory = filefactory;
}