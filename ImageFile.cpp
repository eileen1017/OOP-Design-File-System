/*
Author: Jon Shidal
Purpose: CSE 332 lab 5, defines the ImageFile class
*/
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include<iostream>

using namespace std;

ImageFile::ImageFile(string n) : name(n), dimensions(0), parent(nullptr) {}

unsigned int ImageFile::getSize() {
	return contents.size();
}

string ImageFile::getName() {
	return name;
}

vector<char> ImageFile::read() {
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* fv) {
	if (fv) { fv->visit(this); }
}

int ImageFile::write(vector<char> data) {
	if (data.size() == 0) { // JS add to starter code
		dimensions = 0;
		contents.clear();
	}
	char dim = data[data.size() - 1] - '0';    // substract ascii value of '0' to convert char to int.
	if (dim >= 0 && dim * dim == data.size() - 1) {
		contents.clear();
		for (size_t i = 0; i < data.size() - 1; ++i) {
			if (data[i] == 'X') {
				contents.push_back('X');
			}
			else if (data[i] == ' ') {
				contents.push_back(' ');
			}
			else {
				dimensions = 0;
				contents.clear();
				return invalidpixel;
			}
		}
		dimensions = dim;
		return success;
	}
	else {
		dimensions = 0; 
		contents.clear();
		return sizemismatch;
	}
}

int ImageFile::append(vector<char> data) {
	return unabletoappend;
}

size_t ImageFile::coordsToIndex(size_t x, size_t y) {
	return dimensions * y + x;
}

int ImageFile::addChild(AbstractFile*) {
	return notacomposite;
}
int ImageFile::removeChild(string name) {
	return notacomposite;
}
AbstractFile* ImageFile::getChild(std::string name) {
	return nullptr;
}
AbstractFile* ImageFile::getParent() {
	return parent;
}
void ImageFile::setParent(AbstractFile* p) {
	parent = p;
}

ImageFile* ImageFile::clone() {
	ImageFile* temp = new ImageFile(name);
	vector<char> temp_contents = this->read();
	temp_contents.push_back((char)(dimensions + '0'));
	temp->write(temp_contents);
	temp->setParent(nullptr);
	return temp;
}

