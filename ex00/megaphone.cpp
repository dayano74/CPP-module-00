#include <cctype>
#include <cstring>
#include <iostream>

void megaphone(int cnt, char* argv[]) {
  if (cnt == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return;
  }
  for (int i = 1; i < cnt; i++) {
    const char* s = argv[i];
    const std::size_t len = std::strlen(s);
    for (size_t j = 0; j < len; j++) {
      unsigned char ch = static_cast<unsigned char>(s[j]);
      std::cout << static_cast<char>(std::toupper(ch));
    }
  }
  std::cout << '\n';
}

int main(int argc, char* argv[]) {
  megaphone(argc, argv);
  return 0;
}
