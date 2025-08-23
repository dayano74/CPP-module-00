#ifndef PHONEBOOK_CLI_HPP
#define PHONEBOOK_CLI_HPP

#include <string>

class PhoneBook;

std::string promptLine(const std::string& label);
void doAdd(PhoneBook& pb);
void showTable(const PhoneBook& pb);

#endif // PHONEBOOK_CLI_HPP
