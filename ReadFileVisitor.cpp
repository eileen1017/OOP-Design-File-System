/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "ReadFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "DirectoryFile.h"
#include<iostream>
#include<vector>
using namespace std;

void ReadFileVisitor::visit(TextFile * file) {
	vector<char> contents = file->read();
	for (size_t i = 0; i < contents.size(); ++i) {
		cout << contents[i];
	}
	cout << endl;
}

void ReadFileVisitor::visit(ImageFile* file) {
	vector<char> contents = file->read();
	// compiler warning here is fine. I want to be able to be negative
	for (int y = file->dimensions - 1; y >= 0; --y) {
		for (int x = 0; x < (int)file->dimensions; ++x) {
			size_t index = file->coordsToIndex(x, y);
			cout << contents[index];
		}
		cout << endl;
	}
	cout << endl;
}

void ReadFileVisitor::visit(DirectoryFile* file) {
	vector<char> contents = file->read();
	for (size_t i = 0; i < contents.size(); ++i) {
		cout << contents[i];
	}
	cout << endl;
}