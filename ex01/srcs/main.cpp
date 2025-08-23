#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "PhoneBookCLI.hpp"

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
