#include <cctype>
#include <cstring>
#include <iostream>

void megaphone(int cnt, char* argv[]) {
  if (cnt == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return;
  }
  for (int i = 1; i < cnt; i++) {
    for (size_t j = 0; j < strlen(argv[i]); j++) {
      unsigned char ch = static_cast<unsigned char>(argv[i][j]);
      std::cout << static_cast<char>(std::toupper(ch));
    }
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  megaphone(argc, argv);
  return 0;
}
