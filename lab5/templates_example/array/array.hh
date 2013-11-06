////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef __INCLUDED_ARRAY_HH__
#define __INCLUDED_ARRAY_HH__
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
//include files
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "concepts.hh"
#include <iterator>
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
namespace prima{
	////////////////////////////////////////////////////////////////////
	//Forward declarations
	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
///\class array
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///array is an aggregate type that represents a multidimensional array of fixed size to store numbers. It can contain single arrays or matrices or volumnes and so forth
///It cannot be used as a base class becuase as an aggregate, a destructor cannot be explicitly specified and due to this cannot be set virtual
///\param T stored data type
///\param N number of elements in the array
template <typename T, int N>
class array{
public:
	////////////////////////////////////////////////////////////////////
	///\name Type Definitions
	////////////////////////////////////////////////////////////////////
	//@{
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* iterator;
	typedef const T* const_iterator;
	//The variable rfirst is initialized as reverse_iterator<...> rfirst(V.end());. The value obtained when it is dereferenced, however, is *(V.end() - 1). This is a general property: the fundamental identity of reverse iterators is &*(reverse_iterator(i)) == &*(i - 1). This code sample shows why this identity is important: if [f, l) is a valid range, then it allows [reverse_iterator(l), reverse_iterator(f)) to be a valid range as well. Note that the iterator l is not part of the range, but it is required to be dereferenceable or past-the-end.
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Static Methods Members
	////////////////////////////////////////////////////////////////////
	//@{
	///get number of elements.
	///the number of elements is the same as the dimension
	///\return number of elements
	static int size();
	///return the maximum size of an array of the current type
    static size_type max_size();
	///return true if the array has some values.
	static bool empty();
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Data Members
	////////////////////////////////////////////////////////////////////
	//@{
	T m_data[N];
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Operator Overloading
	////////////////////////////////////////////////////////////////////
	//@{
	///assign one array to the calling one.
	///\param right array to compare
	template <typename T1>
	array& operator=(const array<T1,N>& right);
	///assign one array to the calling one.
	///specialization for the same type of array
	///\param right array to compare
	array& operator=(const array& right);
	///Access.
	const_reference operator[](const int right) const;
	reference operator[](const int right);
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Iterators
	////////////////////////////////////////////////////////////////////
	//@{
	const_iterator begin() const;
	const_iterator end() const;
	iterator begin();
	iterator end();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_iterator last() const;
	iterator last();
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Administratives
	////////////////////////////////////////////////////////////////////
	//@{
	///returns the first and last element.
	const_reference front() const;
	const_reference back() const;
	reference front();
	reference back();
	///print array data.
	///\param separator it is used to separate the values
	///\param b it is printed before the first value
	///\param e it is printed after the last value
	void print(std::ostream& os=std::cerr, const std::string separator=" ", const std::string b="", const std::string e="") const;
	///special print function to unsigned char, signed char and char
	void print4char(std::ostream& os=std::cerr, const std::string separator=" ", const std::string b="", const std::string e="") const;
	///set all the coordinates to the given value.
	///the given value is assigned to every coordinate of the array
	///\param right value to use
	///\return reference to calling array
	array& assign(const T right);
	///reverse the entries in the array.
	///the first and the last are interchanged, the second and the one before last are intercheanged and so on. For odd number of entries, the central entry is not affected.
	array& reverse();
	///Algorithm that exchanges a range of values in one location with those in another
	///TODO: specialize the std::swap and add a non-member function swap(array,array)
	void swap(array& right);
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Properties
	////////////////////////////////////////////////////////////////////
	//@{
	///true in the array contains the element right
	bool has(const T right) const;
	///true in the array contains any of the elements in the given right array.
	bool has(const array& right) const;
	//@}



}; //class array<T,N>
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
//\class array<T,1>
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class array<T,1>{
public:
	////////////////////////////////////////////////////////////////////
	///\name Type Definitions
	////////////////////////////////////////////////////////////////////
	//@{
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Static Methods Members
	////////////////////////////////////////////////////////////////////
	//@{
	static int size();
	static size_type max_size();
	static bool empty();
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Data Members
	////////////////////////////////////////////////////////////////////
	//@{
	T m_data;
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Operator Overloading
	////////////////////////////////////////////////////////////////////
	//@{
	template <typename T1>
	array& operator=(const array<T1,1>& right);
	array& operator=(const array& right);
	const_reference operator[](const int index) const;
	reference operator[](const int index);
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Iterators
	////////////////////////////////////////////////////////////////////
	//@{
	const_iterator begin() const;
	const_iterator end() const;
	iterator begin();
	iterator end();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_iterator last() const;
	iterator last();
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Administratives
	////////////////////////////////////////////////////////////////////
	//@{
	const_reference front() const;
	const_reference back() const;
	reference front();
	reference back();
	void print(std::ostream& os=std::cerr, const std::string b="", const std::string e="") const;
	array& assign(const T right);
	array& reverse();
	void swap(array& right);
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Properties
	////////////////////////////////////////////////////////////////////
	//@{
	bool has(const T right) const;
	bool has(const array& right) const;
	//@}

}; //class array<T,1>
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
//\class array<T,0>
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class array<T,0> : private Uncreateable{}; //class array<T,0>
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
///\name External Functions
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////
	///\name Input and Output
	////////////////////////////////////////////////////////////////////
	//@{
	template <typename T, int N>
	std::ostream& operator<< (std::ostream& os, const array<T,N>& right);
	template <int N>
	std::ostream& operator<< (std::ostream& os, const array<unsigned char,N>& right);
	template <int N>
	std::ostream& operator<< (std::ostream& os, const array<signed char,N>& right);
	template <int N>
	std::ostream& operator<< (std::ostream& os, const array<char,N>& right);
	template <typename T>
	std::ostream& operator<< (std::ostream& os, const array<T,1>& right);
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Operator Overloading
	////////////////////////////////////////////////////////////////////
	//@{
	///true if every corresponding coordinate is the same.
	template <typename T, int N>
	bool operator==(const array<T,N>& a, const array<T,N>& b);
	///true if any corresponding coordinate is not the same.
	template <typename T, int N>
	bool operator!=(const array<T,N>& a, const array<T,N>& b);
	///lower than: lexicographical comparison.
	///Returns true if all the entries are smaller than the corresponding right entries
	template <typename T, int N>
	bool operator<(const array<T,N>& a, const array<T,N>& b);
	///greater than: lexicographical comparison.
	///Returns true if at least one entry is greater than the corresponding right entry.
	template <typename T, int N>
	bool operator>(const array<T,N>& a, const array<T,N>& b);
	///not greater than: lexicographical comparison.
	///Returns true if at least any entry is greater than the corresponding right entry.
	template <typename T, int N>
	bool operator<=(const array<T,N>& a, const array<T,N>& b);
	///not lower than: lexicographical comparison.
	///Returns true if any entry is greater or equal than the corresponding right entry.
	template <typename T, int N>
	bool operator>=(const array<T,N>& a, const array<T,N>& b);
	///This explicit functions are required because array can not have a non-explicit casting constructor
	template <typename T, int N>
	bool operator==(const array<T,N>& right, const T value);
	template <typename T, int N>
	bool operator!=(const array<T,N>& right, const T value);
	template <typename T, int N>
	bool operator<(const array<T,N>& right, const T value);
	template <typename T, int N>
	bool operator>(const array<T,N>& right, const T value);
	template <typename T, int N>
	bool operator<=(const array<T,N>& right, const T value);
	template <typename T, int N>
	bool operator>=(const array<T,N>& right, const T value);
	template <typename T, int N>
	bool operator==(const T value, const array<T,N>& right);
	template <typename T, int N>
	bool operator!=(const T value, const array<T,N>& right);
	template <typename T, int N>
	bool operator<(const T value, const array<T,N>& right);
	template <typename T, int N>
	bool operator>(const T value, const array<T,N>& right);
	template <typename T, int N>
	bool operator<=(const T value, const array<T,N>& right);
	template <typename T, int N>
	bool operator>=(const T value, const array<T,N>& right);

	///for the especializations
	///For the functions not listed here, the above functions (depending on N) will be used.
	template <typename T>
	bool operator==(const array<T,1>& a, const array<T,1>& b);
	template <typename T>
	bool operator<(const array<T,1>& a, const array<T,1>& b);
	template <typename T>
	bool operator==(const array<T,1>& right, const T value);
	template <typename T>
	bool operator<(const array<T,1>& right, const T value);
	template <typename T>
	bool operator>(const array<T,1>& right, const T value);
	//@}
////////////////////////////////////////////////////////////////////////////////////////////////////



} //namespace prima
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
//Template Implementations
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//it it necesary until the export keyword sill be supported by g++ compiler
#include "array.cpp"
#include "array1.cpp"
#include "overloads.hh"
////////////////////////////////////////////////////////////////////////////////////////////////////



#endif //__INCLUDED_ARRAY_HH__
////////////////////////////////////////////////////////////////////////////////////////////////////
