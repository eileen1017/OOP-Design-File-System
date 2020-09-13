#pragma once

#include "AbstractCommand.h"

enum cat_command {
	option_invalid = -2

};


class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~CatCommand() = default;
private:
	AbstractFileSystem* fs;


};