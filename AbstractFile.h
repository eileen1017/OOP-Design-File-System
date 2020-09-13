/*
Author: Jon Shidal
Purpose: CSE 332 lab5, declares an interface for a "File"
*/

#pragma once
#include <string>
#include<vector>

class AbstractFileVisitor;  // forward declarations as needed 
class HierarchicalFileSystem;
class Proxy;


class AbstractFile {
	// friends
	friend class HierarchicalFileSystem;
	friend class SimpleFileSystem;
	friend class Proxy;

public:
	// possible return values
	enum returnvalues { success, notacomposite, invalidpixel, sizemismatch, unabletoappend, unabletowritedirectory, filealreadyexists, childdoesnotexist };

	// functions regarding files functionality
	virtual std::vector<char> read() = 0;  
	virtual int write(std::vector<char>) = 0; // re-writes file
	virtual int append(std::vector<char>) = 0; // appends to current contents
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;

	virtual ~AbstractFile() = default;

	// visitor pattern function
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* clone() = 0;
protected:


	// composite pattern functions, should only be used by file system objects or command objects which should be friended
	virtual int addChild(AbstractFile*) = 0;
	virtual int removeChild(std::string name) = 0;
	virtual void setParent(AbstractFile*) = 0;
	virtual AbstractFile* getChild(std::string name) = 0;
	virtual AbstractFile* getParent() = 0;
	
};