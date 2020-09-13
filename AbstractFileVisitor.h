#pragma once
/*
Author: Jon Shidal
Purpose: CSE 332 lab 5  -declares an interface fro a File Visitor
*/

class TextFile;
class ImageFile;
class DirectoryFile;

class AbstractFileVisitor {
public:
	virtual void visit(TextFile*) = 0;
	virtual void visit(ImageFile*) = 0;
	virtual void visit(DirectoryFile*) = 0;
};