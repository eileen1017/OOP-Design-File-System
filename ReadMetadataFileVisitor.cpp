/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "ReadMetadataFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "DirectoryFile.h"
#include<iostream>
#include<vector>
using namespace std;

void ReadMetadataFileVisitor::visit(TextFile* file) {
	cout << file->getName() << "\t" << "text\t size: " << file->getSize();
	cout << endl;
}

void ReadMetadataFileVisitor::visit(ImageFile* file) {
	cout << file->getName() << "\t" << "image\t size: " << file->getSize();
	cout << endl;
}

void ReadMetadataFileVisitor::visit(DirectoryFile* file) {
	cout << file->getName() << "\t" << "directory\t size: " << file->getSize();
	cout << endl;
}