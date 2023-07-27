#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream my_file;
	const char *path="./myf.txt";
	my_file.open(path, ios::out);
	if (!my_file) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		my_file << "Guru99";
		my_file.close();
	}

	my_file.open(path, ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
		char ch;

		while (1) {
			my_file >> ch;
			if (my_file.eof())
				break;

			cout << ch;
		}

	}
	my_file.close();
	return 0;
}
