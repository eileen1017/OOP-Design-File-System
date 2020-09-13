#pragma once
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include "Proxy.h"
enum{success,failedtolink};
class SymbolicLink: public AbstractCommand
{

private: 
	AbstractFile* realFile;
	AbstractFileSystem* fs;
	AbstractFileFactory* ff;
public: 
	SymbolicLink(AbstractFileSystem* filesys, AbstractFileFactory* fileFactory);
	void displayInfo();
	virtual int execute(std::string& CWD, std::string options);
	virtual ~SymbolicLink() = default;
};
