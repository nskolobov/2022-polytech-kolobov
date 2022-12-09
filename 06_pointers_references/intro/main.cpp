#include <cassert>
#include <iostream>

unsigned int length(const char* str)
{
	if (str == nullptr) {
		return 0;
	}
	unsigned int size = 0;
	char tmp = str[size];
	while(tmp != '\0') {
		++size;
		tmp = str[size];
	}
	return size;
}

int main()
{
	assert(length("a") == 1);
	assert(length("ab") == 2);
	assert(length("") == 0);
	assert(length("hello world") == 11);
	assert(length(nullptr) == 0);
	std::cout << "Tests passed" << std::endl;
    return 0;
}
