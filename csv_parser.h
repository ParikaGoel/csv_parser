#ifndef CSV_H
#define CSV_H

#include "fstream"
#include "string"
#include "vector"

class csv_parser {
private:
	std::ifstream m_if;
	std::ofstream m_of;
public:
	csv_parser();
	~csv_parser();
	int open(std::string &ifilename, std::string &ofilename);
	std::vector<std::string> parse();
	void write(std::vector<std::string> data);
};

#endif
