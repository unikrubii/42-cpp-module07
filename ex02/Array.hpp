#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T*				_arr;
		unsigned int	_size;

	public:
		// Constructors
		Array();
		Array(unsigned int n);
		Array(const Array &src);

		// Destructor
		~Array();

		// Operator overloads
		Array		&operator=( const Array &rhs );
		// Array		*operator=( const Array *rhs );
		T			&operator[]( int i );
		const T		&operator[] (int i ) const;

		// Member functions
		size_t	getSize() const;

		// Exceptions
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# include "Array.tpp"

#endif