#include "iter.hpp"

void add_one( int const &i ) {
	std::cout << i + 1 << std::endl;
}

int main( void ) {
	int array[] = { 0, 1, 2, 3, 4 };
	iter( array, 5, add_one );
	return 0;
}