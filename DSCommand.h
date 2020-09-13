#pragma once
#include "AbstractCommand.h"

enum ds_command {
	ds_invalid = -2

};

class DSCommand : public AbstractCommand {
public:
	DSCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~DSCommand() = default;
private:
	AbstractFileSystem* fs;


};