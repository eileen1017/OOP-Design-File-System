/*
Author: Jon Shidal
Purpose: CSE 332 lab 5, defines the directory class
*/

#include "DirectoryFile.h"
#include "AbstractFileVisitor.h"
#include<iostream>
#include<sstream>

using namespace std;

DirectoryFile::DirectoryFile(string n) : name(n), parent(nullptr), count(1) {}

unsigned int DirectoryFile::getSize() { 
	return contents.size();
}

string DirectoryFile::getName() {
	return name;
}

vector<char> DirectoryFile::read() {
	return contents;
}

void DirectoryFile::accept(AbstractFileVisitor* fv) {
	if (fv) { fv->visit(this); }
}

int DirectoryFile::write(vector<char> data) { // shouldn't be able to write a directory, only append
	return unabletowritedirectory;
}

int DirectoryFile::append(vector<char> data) {
	return unabletowritedirectory;
}

int DirectoryFile::addChild(AbstractFile* f) {
	auto it = children.find(f->getName()); 
	if (it != children.end()) { // file already exists with the same name
		return filealreadyexists;
	}
	children.insert({ f->getName(),f });    
	string data = f->getName();
	for (size_t i = 0; i < data.size(); ++i) {   // write the name of the file to the directory contents
		contents.push_back(data[i]);
	}
	// new line for a new file
	contents.push_back('\n');
	return success;
}

int DirectoryFile::removeChild(string name) {
	auto it = children.find(name);
	if (it == children.end()) {// child doesn't exist
		return childdoesnotexist;
	}
	children.erase(it); // remove it
	// remove filename from contents
	stringstream before;
	stringstream after;
	for (size_t i = 0; i < contents.size(); ++i) {
		before << contents[i];
	}
	string childName;
	while (before >> childName) {
		if (childName == name) { // if we found the file, don't insert(remove it)
		}
		else {
			after << childName << '\n'; // insert, don't forget the linebreak
		}
	}
	contents.clear();  // clear current contents and rewrite from "after"
	char c;
	after >> noskipws;
	while (after >> c) {
		contents.push_back(c);
	}
	return success;
}

AbstractFile* DirectoryFile::getChild(std::string name) {
	auto it = children.find(name);
	if (it != children.end()) {
		return it->second;
	}
	else {
		return nullptr;
	}
}
AbstractFile* DirectoryFile::getParent() {
	return parent;
}
void DirectoryFile::setParent(AbstractFile* p) {
	parent = p;
}

DirectoryFile::~DirectoryFile() {
	for (auto it = children.begin(); it != children.end(); ++it) {
		delete it->second;
	}
}

DirectoryFile* DirectoryFile::clone() {
	return nullptr;
}

int& DirectoryFile::getCount() {
	return count;
}