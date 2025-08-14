#include "phonebook.hpp"

PhoneBook::PhoneBook() : _count(0), _next(0) {}

void PhoneBook::addContact(const Contact &c) {
  _contacts[_next] = c;
  _next = (_next + 1) % 8;
  if (_count < 8) _count++;
}

int PhoneBook::size() const {
  return (_count < 8) ? _count : 8;
}

const Contact &PhoneBook::getContact(int i) const {
  return _contacts[i];
}
