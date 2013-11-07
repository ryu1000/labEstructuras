////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef __INCLUDED_OVERLOADS_HH__
#define __INCLUDED_OVERLOADS_HH__
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
//include files
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
namespace prima{
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator==(const C<T,N>& a, const C<T,N>& b){
	return std::equal(a.begin(),a.end(),b.begin());
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator!=(const C<T,N>& a, const C<T,N>& b){
	return ! (a==b);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator<(const C<T,N>& a, const C<T,N>& b){
	return std::lexicographical_compare(a.begin(),a.end(),b.begin(),b.end());
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator>(const C<T,N>& a, const C<T,N>& b){
	return (b < a);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator<=(const C<T,N>& a, const C<T,N>& b){
	return ! (b < a);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator>=(const C<T,N>& a, const C<T,N>& b){
	return ! (a < b);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator==(const C<T,N>& right, const T value){
	return ( right.begin()==std::search_n(right.begin(), right.end(), N, value) );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator!=(const C<T,N>& right, const T value){
	return ! ( right == value );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator<(const C<T,N>& right, const T value){
	for(typename C<T,N>::const_iterator i=right.begin(); i!=right.end(); ++i){
		if(*i >= value){
			return false;
		}
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator>(const C<T,N>& right, const T value){
	for(typename C<T,N>::const_iterator i=right.begin(); i!=right.end(); ++i){
		if(*i <= value){
			return false;
		}
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator<=(const C<T,N>& right, const T value){
	return ! (right > value);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator>=(const C<T,N>& right, const T value){
	return ! (right < value);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator==(const T value, const C<T,N>& right){
	return ( right == value);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator!=(const T value, const C<T,N>& right){
	return ! ( right == value);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator<(const T value, const C<T,N>& right){
	return ( right > value );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator>(const T value, const C<T,N>& right){
	return ( right < value );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator<=(const T value, const C<T,N>& right){
	return ( right >= value );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int N, template <typename, int> class C>
bool operator>=(const T value, const C<T,N>& right){
	return (right <= value);
}
////////////////////////////////////////////////////////////////////////////////////////////////////


} //namespace prima
////////////////////////////////////////////////////////////////////////////////////////////////////



#endif //__INCLUDED_OVERLOADS_HH__
////////////////////////////////////////////////////////////////////////////////////////////////////