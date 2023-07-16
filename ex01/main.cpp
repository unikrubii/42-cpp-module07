#include "Iter.hpp"
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

void add_one( int const &i ) {
	std::cout << i + 1 << std::endl;
}

int main( void ) {
	{
		int array[] = { 0, 1, 2, 3, 4 };
		iter( array, 5, add_one );
		std::cout << "=====================" << std::endl;
	}
	{
		int tab[] = { 0, 1, 2, 3, 4 };
		Awesome tab2[5];

		iter( tab, 5, print<const int> );
		iter( tab2, 5, print<Awesome> );
	}
	return 0;
}