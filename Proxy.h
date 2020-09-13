#pragma once

#include "AbstractFile.h"
class SymblicLink;
class Proxy: public AbstractFile
{
	friend class SymbolicLink;
public:
	// functions regarding files functionality
	Proxy(AbstractFile* af);
	Proxy(Proxy* pf);
	virtual std::vector<char> read();
	virtual int write(std::vector<char>); // re-writes file
	virtual int append(std::vector<char>); // appends to current contents
	virtual unsigned int getSize();
	virtual std::string getName();

	virtual ~Proxy();

	// visitor pattern function
	virtual void accept(AbstractFileVisitor*);
	virtual Proxy* clone();
protected:


	// composite pattern functions, should only be used by file system objects or command objects which should be friended
	virtual int addChild(AbstractFile*);
	virtual int removeChild(std::string name);
	virtual void setParent(AbstractFile*);
	virtual AbstractFile* getChild(std::string name);
	virtual AbstractFile* getParent();
	virtual int* getCount();
	AbstractFile* file;
	int* count;
private:
	std::string name;
	
	AbstractFile* parent;
};
