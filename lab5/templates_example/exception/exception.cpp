#include "exception.hh"
//#include <iomanip>
#include <sstream>
//////////////////////////////////////////////////////////////////////////////////////////////////
namespace prima{


////////////////////////////////////////////////////////////////////
//Constructors and destructor
////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
Exception::Exception(const std::string& f, const int l, const std::string& m, const std::string& d) throw() : file(f), line(l), method(m), detail(d){

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
Exception::Exception(const Exception& right) throw() : file(right.file), line(right.line), method(right.method), detail(right.detail){

}







////////////////////////////////////////////////////////////////////
//Administratives
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
void Exception::info() const throw(){
	std::cerr << "Exception:\n";
	std::cerr << "File: " << file << std::endl;
	std::cerr << "Line: " << line << std::endl;
	std::cerr << "Method: " << method << std::endl;
	std::cerr << "Detail: " << detail << std::endl;
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
const std::string&  Exception::what() const throw(){
	return detail;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void Exception::print() const throw(){
	prima::print(method,line,file,detail);
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
Exception& Exception::stack( const std::string& f, const int l, const std::string& m) throw(){
	//save old exception data
	std::stringstream s;
	s << ">>-------------->> " << "Exception thrown in <" << method << "> at line #" << line << " of file <" << file << "> due to:\n" << detail << "\n<<--------------<<";

	//save new exception data
	file = f;
	line = l;
	method = m;
	detail = s.str();

	return *this;
}
////////////////////////////////////////////////////////////////////////////////////////////////////










////////////////////////////////////////////////////////////////////////////////////////////////////
void print(const std::string& method, const int line, const std::string& file, const std::string& detail, bool isStatic){
	std::stringstream s;
	s << "\n\n>>-------------->> ";
	if(isStatic){
		s << "Static Exception \"thrown\"";
	}
	else{
		s << "Exception thrown";
	}
	s << " in <" << method << "> at line #" << line << " of file <" << file << "> due to:\n" << detail << "\n<<--------------<<\n\n";
	std::cerr << s.str() << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////



} //namespace prima
////////////////////////////////////////////////////////////////////////////////////////////////////
