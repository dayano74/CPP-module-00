#!/bin/sh
{
  printf '%s\n' \
    ADD Alice Anderson Ali 111-111 "Secret A" \
    ADD Bob Brown Bobo 222-222 "Secret B" \
    ADD Carol Clark CC 333-333 "Secret C" \
    ADD Dave Davis DD 444-444 "Secret D" \
    ADD Eve Evans Ev 555-555 "Secret E" \
    ADD Frank Foster Franky 666-666 "Secret F" \
    ADD Grace Green G 777-777 "Secret G" \
    ADD Heidi Hill H 888-888 "Secret H" \
    SEARCH 0
  cat
} | ./phonebook