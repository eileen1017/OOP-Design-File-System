#include "SymbolicLink.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
SymbolicLink::SymbolicLink(AbstractFileSystem* fileSys, AbstractFileFactory* fileFactory)
{
	this->fs = fileSys;
	this->realFile = nullptr;
	this->ff = fileFactory;
}

void SymbolicLink::displayInfo() {
	cout << "Usage: sym <filename> <full_path_to_destination>" << endl;
}

int SymbolicLink::execute(std::string& filename, std::string despath) 
{
	istringstream ss(despath);
	string file_name, des_path;
	ss >> file_name;
	ss >> des_path;
	string curr_path = filename +"/" + file_name;


	realFile = fs->openFile(curr_path);
	fs->closeFile(realFile);		
	
	des_path += "/"+file_name;
	AbstractFile* proxy_file;
	int result = success, result2 = success;
	if (Proxy * d = dynamic_cast<Proxy*>(realFile)) {
		AbstractFile* proxy_file2 = new Proxy(d);
		//result = fs->addFile(curr_path, d);
		result2 = fs->addFile(des_path, proxy_file2);
	}
	else {
		realFile = realFile->clone();
		fs->deleteFile(curr_path);
		proxy_file = new Proxy(realFile);
		AbstractFile* proxy_file2 = new Proxy(dynamic_cast<Proxy*>(proxy_file));
		
		result = fs->addFile(curr_path, proxy_file);
		result2 = fs->addFile(des_path, proxy_file2);
	}

	
	if (result2 != success || result !=success) {
		cout << "failed to link file to file system" << endl;

		return failedtolink;
	}
	//return result;
	return 0;
}