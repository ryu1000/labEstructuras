//////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef __INCLUDED_CONCEPTS_HH__
#define __INCLUDED_CONCEPTS_HH__
//////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
//include files
////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////
namespace prima{
///This defined properties of the derived classes that have to keep the contraints here established.

////////////////////////////////////////////////////////////////////
///\class Uncreateable
////////////////////////////////////////////////////////////////////
///disallows contruction and destruction of derived classes
class Uncreateable{
	////////////////////////////////////////////////////////////////////
	///\name Contructors and Destructor
	////////////////////////////////////////////////////////////////////
	//@{
private:
	Uncreateable();
protected:
	Uncreateable(const Uncreateable&);
protected:
	virtual ~Uncreateable(){}; //TODO: write it virtual
	//@}

private:
	////////////////////////////////////////////////////////////////////
	///\name Operator Overloading
	////////////////////////////////////////////////////////////////////
	//@{
	Uncreateable& operator=(const Uncreateable&);
	//@}

}; //class Uncreateable
//////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
///\class Uncopyable
////////////////////////////////////////////////////////////////////
///allows contruction and destruction of derived classes but inhibits the copy and assignement of the derived classes.
class Uncopyable{
	////////////////////////////////////////////////////////////////////
	///\name Contructors and Destructor
	////////////////////////////////////////////////////////////////////
	//@{
protected:
	Uncopyable();
private:
	Uncopyable(const Uncopyable&);
protected:
	virtual ~Uncopyable();
	//@}

private:
	////////////////////////////////////////////////////////////////////
	///\name Operator Overloading
	////////////////////////////////////////////////////////////////////
	//@{
	Uncopyable& operator=(const Uncopyable&);
	//@}

}; //class Uncopyable
//////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
///\class Unassignable
////////////////////////////////////////////////////////////////////
///allows contruction and destruction of derived classes but inhibits the assignement of the derived classes.
class Unassignable{
	////////////////////////////////////////////////////////////////////
	///\name Contructors and Destructor
	////////////////////////////////////////////////////////////////////
	//@{
public:
	virtual ~Unassignable(){}; //TODO: write it as a virtual constructor
	//@}

	////////////////////////////////////////////////////////////////////
	///\name Operator Overloading
	////////////////////////////////////////////////////////////////////
	//@{
private:
	Unassignable& operator=(const Unassignable&);
	template <class T>
	Unassignable& operator=(const T& right);
public:
	//@}

}; //class Unassignable
//////////////////////////////////////////////////////////////////////////////////////////////////



} //namespace prima
//////////////////////////////////////////////////////////////////////////////////////////////////



#endif //__INCLUDED_CONCEPTS_HH__
//////////////////////////////////////////////////////////////////////////////////////////////////
