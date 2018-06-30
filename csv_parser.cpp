#include "csv_parser.h"

csv_parser::csv_parser() {

}

csv_parser::~csv_parser() {
	if (m_if.is_open())
		m_if.close();
	if (m_of.is_open())
		m_of.close();
}

int csv_parser::open(std::string &ifilename, std::string &ofilename) {
	if (!ofilename.empty())
		m_of.open(ofilename.c_str(),std::ios::out);
	else
		m_of.open("output.csv",std::ios::out);

	m_if.open(ifilename.c_str(),std::ios::in);
	if (!m_if.is_open())
		return -1;
	return 0;
}

std::vector<std::string> csv_parser::parse() {
	std::vector<std::string> column;
	std::string row;

	while (std::getline(m_if, row)) {
		column.push_back(row);
		row.clear();
	}

	return column;
}

void csv_parser::write(std::vector<std::string> data) {
	std::vector<std::string>::iterator it;
	for (it = data.begin(); it != data.end(); it++) {
		m_of << *it << "\n";
	}
}