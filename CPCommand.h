#pragma once

#include "AbstractCommand.h"

class CPCommand : public AbstractCommand
{
public:
	CPCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~CPCommand() = default;
private:
	AbstractFileSystem* fs;
};