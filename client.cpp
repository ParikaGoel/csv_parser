#include "csv_parser.h"
#include "iostream"

int main() {
	csv_parser parser;
	std::vector<std::string> data;
	std::vector<std::string>::iterator it;
	std::string ifile("test.csv");
	std::string ofile("");

	if (parser.open(ifile, ofile) == -1) {
		std::cout << "File does not exist\n";
		return 0;
	}

	//Parse the data from csv file
	data = parser.parse();

	for (it = data.begin(); it != data.end(); it++) {
		// Processing on data can be done
		std::cout<<*it;
	}
	std::cout<<"\n";

	//Write processed data in output csv file
	parser.write(data);

	return 0;
}