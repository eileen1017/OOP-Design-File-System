#include "CatCommand.h"
#include <iostream>
#include <vector>


using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int CatCommand::execute(std::string& CWD, std::string options) {
	if (options.find_last_of(' ') != string::npos) {
		string with_option = options.substr(options.find_last_of(" ") + 1, string::npos);
		string extension = options.substr(options.find_first_of(".") + 1, options.find_first_of(" ") - 2);
		cout << extension << endl;
		if (extension == "img") {
			cout << "Cannot concatenate an image." << endl;
			return option_invalid;
		}
		else {
			if (with_option == "-a") {
				string fname = options.substr(0, options.find_first_of(" "));
				string fpath = CWD + '/' + fname;
				AbstractFile* f = fs->openFile(fpath);
				if (f == nullptr) {
					cout << "current file doesn't exist" << endl;
					return CWDdoesnotexist;
				}
				cout << fpath << endl;
				vector<char> original_text = f->read();
				for (unsigned int i = 0; i < original_text.size(); i++) {
					cout << original_text[i];
				}
				cout << endl;
				cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
				string user_input;
				getline(cin, user_input);
				vector<char> all_inputs;
				while (user_input != ":wq" && user_input != ":q") {
					for (unsigned int i = 0; i < user_input.size(); i++) {
						all_inputs.push_back(user_input.at(i));
					}
					all_inputs.push_back('\n');
					getline(cin, user_input);
				}
				if (user_input == ":wq") {
					f->append(all_inputs);
				}
				else if (user_input == ":q") {
				}
				fs->closeFile(f);
				return success;
			}
			else {
				cout << "option is invalid." << endl;
				return option_invalid;
			}
		}
	}
	else {
		string fpath = CWD + '/' + options;
		AbstractFile* f = fs->openFile(fpath);
		if (f == nullptr) {
			cout << "current file doesn't exist" << endl;
			return CWDdoesnotexist;
		}
		cout << fpath << endl;
		string extension = options.substr(options.find_first_of(".") + 1, options.find_first_of(" ") - 2);
		if (extension == "img") {
			cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
			string user_input;
			getline(cin, user_input);
			vector<char> all_inputs;
			while (user_input != ":wq" && user_input != ":q") {
				for (unsigned int i = 0; i < user_input.size(); i++) {
					all_inputs.push_back(user_input.at(i));
				}
				
				getline(cin, user_input);
			}
			if (user_input == ":wq") {
				int  res = f->write(all_inputs);

			}
			else if (user_input == ":q") {
			}
			fs->closeFile(f);
			return success;
		}
		else {
			cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
			string user_input;
			getline(cin, user_input);
			vector<char> all_inputs;
			while (user_input != ":wq" && user_input != ":q") {
				for (unsigned int i = 0; i < user_input.size(); i++) {
					all_inputs.push_back(user_input.at(i));
				}
				all_inputs.push_back('\n');
				getline(cin, user_input);
			}
			if (user_input == ":wq") {
				f->write(all_inputs);
			}
			else if (user_input == ":q") {
			}
			fs->closeFile(f);
			return success;
		}
	}

}

void CatCommand::displayInfo() {
	cout << "cat is a utility that is useful for concatenating files." << endl;
	cout << "Usage: cat <filename> [-a]" << endl;
}



