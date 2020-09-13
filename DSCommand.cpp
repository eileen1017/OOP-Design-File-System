#include "DSCommand.h"
#include <iostream>

using namespace std;

DSCommand::DSCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int DSCommand::execute(std::string& CWD, std::string options) {
	if (options.find_last_of(' ') != string::npos) {
		string with_option = options.substr(options.find_last_of(" ") + 1, string::npos);
		if (with_option == "-d") {
			string fname = options.substr(0, options.find_first_of(" "));
			string fpath = CWD + '/' + fname;

			string extension = fname.substr(fname.find_first_of(".") + 1, string::npos);
			AbstractFile* f = fs->openFile(fpath);
			cout << "fpath : " << fpath << endl;
			if (f == nullptr) {
				cout << "current file doesn't exist" << endl;
				return CWDdoesnotexist;
			}
			if (extension == "img") {
				vector<char> original_text = f->read();
				for (unsigned int i = 0; i < original_text.size(); i++) {
					cout << original_text[i];
				}
				cout << endl;

			}
			else {
				vector<char> original_text = f->read();
				for (unsigned int i = 0; i < original_text.size(); i++) {
					cout << original_text[i];
				}
				cout << endl;
			}
			fs->closeFile(f);
			return success;
		}
		else {
			cout << "option is invalid." << endl;
			return ds_invalid;
		}

	}
	else {
		string fpath = CWD + '/' + options;
		AbstractFile* f = fs->openFile(fpath);
		if (f == nullptr) {
			cout << "current file doesn't exist" << endl;
			return CWDdoesnotexist;
		}
		string extension = options.substr(options.find_first_of(".") + 1, string::npos);

		if (extension == "img") {
			vector<char> original_text = f->read();
			int img_size = (int)sqrt(original_text.size());
			for (int i = 0; i < img_size; i++) {
				cout << "";
				for (int j = 0; j < img_size; j++) {
					cout << original_text[j * img_size + i];
				}
				cout << endl;
			}
			cout << endl;

		}
		else {
			vector<char> original_text = f->read();
			for (unsigned int i = 0; i < original_text.size(); i++) {
				cout << original_text[i];
			}
			cout << endl;
		}
		fs->closeFile(f);
		return success;
	}
}

void DSCommand::displayInfo() {
	cout << "ds opens a file and displays its contents." << endl;
	cout << "Usage: ds <filename> [-d]" << endl;
}