#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

#include "contact.hpp"

class PhoneBook {
 private:
  Contact _contacts[8];
  int _count;
  int _next;

 public:
  PhoneBook();
  void addContact(const Contact &c);
  int size() const;
  const Contact &getContact(int i) const;
};

#endif
