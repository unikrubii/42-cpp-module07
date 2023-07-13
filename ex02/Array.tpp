#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

// Constructors
template <typename T>
Array<T>::Array() : _size( 0 ) {
	_arr = new T[ 0 ];
}

template <typename T>
Array<T>::Array( unsigned int n ) : _size( n ) {
	_arr = new T[ n ];
}

template <typename T>
Array<T>::Array( const Array &src ) {
	this->_arr = NULL;
	*this = src;
}

// Destructor
template <typename T>
Array<T>::~Array() {
	delete [] _arr;
}

// Operator overloads
template <typename T>
Array<T> &Array<T>::operator=( const Array &rhs ) {
	if ( _arr ) {
		delete [] _arr;
	}
	if ( this != &rhs ) {
		_arr = new T[ rhs.getSize() ];
		_size = rhs.getSize();
		for (int i = 0; i < static_cast<int>( _size ); i++)
			_arr[ i ] = rhs[ i ];
	}
	return *this;
}

// template <typename T>
// Array<T> *Array<T>::operator=( const Array *rhs ) {
// 	if ( _arr ) {
// 		delete [] _arr;
// 	}
// 	if ( this != rhs ) {
// 		_arr = new T[ rhs->getSize() ];
// 		_size = rhs->getSize();
// 	}
// 	return *this;
// }

template <typename T>
T &Array<T>::operator[]( int i ) {
	if ( i < 0 || i >= static_cast<int>( _size ) )
		throw Array::OutOfBoundsException();
	return _arr[ i ];
}

template <typename T>
const T &Array<T>::operator[]( int i ) const {
	if ( i < 0 || i >= static_cast<int>( _size ) )
		throw Array::OutOfBoundsException();
	return _arr[ i ];
}

// Member functions
template <typename T>
size_t	Array<T>::getSize() const {
	return _size;
}

// Exceptions
template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw() {
	return "Error: Index out of bounds";
}

#endif