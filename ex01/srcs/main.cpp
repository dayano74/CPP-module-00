#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "contact.hpp"
#include "phonebook.hpp"

static std::string promptLine(const std::string &label) {
  std::string s;
  while (true) {
    std::cout << label << ": " << std::flush;
    if (!std::getline(std::cin, s)) {
      std::cout << "\nEOF -> abort input.\n";
      return "";
    }
    if (!s.empty()) return s;
    std::cout << "Empty. Retry.\n";
  }
}

static void doAdd(PhoneBook &pb) {
  Contact c;
  std::string v;
  v = promptLine("First name");
  if (v.empty()) return;
  c.setFirstName(v);
  v = promptLine("Last name");
  if (v.empty()) return;
  c.setLastName(v);
  v = promptLine("Nick name");
  if (v.empty()) return;
  c.setNickname(v);
  v = promptLine("Phone number");
  if (v.empty()) return;
  c.setPhoneNumber(v);
  v = promptLine("Darkest secret");
  if (v.empty()) return;
  c.setDarkestSecret(v);
  pb.addContact(c);
  std::cout << "Contact added.\n";
}

static std::string trimField(const std::string &s) {
  if (s.length() <= 10) {
    std::ostringstream oss;
    oss << std::setw(10) << s;
    return (oss.str());
  }
  return s.substr(0, 9) + ".";
}

static bool isDigits(const std::string &s) {
  if (s.empty()) return false;
  for (size_t i = 0; i < s.size(); ++i)
    if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
  return true;
}

static void showTable(const PhoneBook &pb) {
  int n = pb.size();
  if (n == 0) {
    std::cout << "PhoneBook empty.\n";
    return;
  }
  std::cout << std::endl;
  std::cout << std::setw(10) << "Index" << '|'
            << std::setw(10) << "First name" << '|'
            << std::setw(10) << "Last name" << '|'
            << std::setw(10) << "Nickname" << '\n';
  for (int i = 0; i < n; ++i) {
    const Contact &c = pb.getContact(i);
    std::cout << std::setw(10) << i << '|'
              << trimField(c.getFirstName()) << '|'
              << trimField(c.getLastName()) << '|'
              << trimField(c.getNickname()) << '\n';
  }
  std::cout << "Select index: " << std::flush;
  std::string line;
  if (!std::getline(std::cin, line)) {
    std::cout << "\nEOF -> back.\n";
    return;
  }
  if (!isDigits(line)) {
    std::cout << "Not a number.\n";
    return;
  }
  int idx = std::atoi(line.c_str());
  if (idx < 0 || idx >= n) {
    std::cout << "Invalid index.\n";
    return;
  }
  const Contact &c = pb.getContact(idx);
  std::cout << "First name: " << c.getFirstName() << "\n"
            << "Last name: " << c.getLastName() << "\n"
            << "Nickname: " << c.getNickname() << "\n"
            << "Phone number: " << c.getPhoneNumber() << "\n"
            << "Darkest secret: " << c.getDarkestSecret() << "\n";
}

int main() {
  PhoneBook pb;
  std::string cmd;
  while (true) {
    std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::flush;
    if (!std::getline(std::cin, cmd)) {
      std::cout << "exit.\n";
      break;
    }
    if (cmd.empty()) continue;
    if (cmd == "ADD")
      doAdd(pb);
    else if (cmd == "SEARCH")
      showTable(pb);
    else if (cmd == "EXIT")
      break;
    else
      std::cout << "Unknown command.\n";
  }
  return 0;
}
