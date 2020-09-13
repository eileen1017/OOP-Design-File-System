#include "Proxy.h"
#include "AbstractFileVisitor.h"
#include<iostream>

using namespace std;


Proxy::Proxy(AbstractFile* af) : name(af->getName()),file(af), parent(nullptr)
{
	
	count = new int(1);
	cout << *count << endl;
}

Proxy::Proxy(Proxy* pf) : name(pf->getName()),file(pf->file), parent(nullptr)
{

	//count = new int(pf->getCount() + 1);
	count = pf->getCount();
	(*count)++;

}

Proxy::~Proxy() 
{
	(*count)--;

	if ((*count) == 0) {

		delete file;
	}
	
}

unsigned int Proxy::getSize() {
	return file->getSize();
}

string Proxy::getName() {
	return file->getName();
}

vector<char> Proxy::read() {
	return file->read();
}

void Proxy::accept(AbstractFileVisitor* fv) {
	file->accept(fv);
}

int Proxy::write(vector<char> data) {
	return file->write(data);
}

int Proxy::append(vector<char> data) {
	return unabletoappend;
}
/*
size_t Proxy::coordsToIndex(size_t x, size_t y) {
	return file->coordsToIndex(x, y);
}*/

int Proxy::addChild(AbstractFile*) {
	return notacomposite;
}
int Proxy::removeChild(string name) {
	return notacomposite;
}
AbstractFile* Proxy::getChild(std::string name) {
	return nullptr;
}
AbstractFile* Proxy::getParent() {
	return parent;
}
void Proxy::setParent(AbstractFile* p) {
	parent = p;
}

Proxy* Proxy::clone() {
	Proxy* temp = new Proxy(this);
	return temp;
}

int* Proxy::getCount() {
	return count;
}