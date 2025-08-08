#include <iostream>
#include <cstring>

void megaphone(int cnt, char *argv[]){
	if(cnt == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return;
	}
	for(int i = 1; i < cnt; i++){
		for(size_t j = 0; j < strlen(argv[i]); j++){
			std::cout << (char)toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]){
	megaphone(argc, argv);
	return 0;
}
