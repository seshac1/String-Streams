#include "ucla_student.h"
#include "usc_student.h"
#include <iostream>
// this include allows us to manipulate the Input and Output easily
#include <iomanip>
// This include allows us to manipulate file streams for easier handling of files
#include <fstream>
// This include allows us to create stringstreams which make it easy to handle and parse string data
#include <sstream>
// This include allows us to use the vector container which is safer than naked arrays
#include <vector>
// This include allows us to access algorithms on standard containers, such as std::sort!
#include <algorithm>

using namespace std;

// function to compare pointers to students
/*bool student_cmp( student * lhs, student * rhs )
{
  // They're not null, we can compare them
  if( lhs != NULL && rhs != NULL ){
    if( lhs->get_birth_year() != rhs->get_birth_year() )
      return lhs->get_birth_year() < rhs->get_birth_year();
    else if( lhs->get_birth_month() != rhs->get_birth_month() )
      return lhs->get_birth_month() < rhs->get_birth_month();
    else
      return lhs->get_birth_day() < rhs->get_birth_day();
  }
  // if only the left-hand side is valid, return true so NULLS go to the end
  else if( lhs != NULL )
    return true;
  // if the right-hand side is valid (or both are invalid), return false so the NULL goes to the end
  return false;
}
*/

int main(){
  student * tmp_student;
  vector<student*> students;
  fstream ucla("UCLA.txt");
  string name, gender, birthdate, first_gen, scholarship, line;
  // read line-by-line
  getline( ucla, line ); // dummy line
  while( getline( ucla, line ), line != "" ){
    // change the separators for pipes, so we can tokenize the string easily
    for( int i = 0; i < (int)line.length(); ++ i )
      if( line[i] == '\t' )
	line[i] = '|';
    // now, create a istringstream with the new string to tokenize
    istringstream tokenizer(line);
    // get the data as if it were lines, from the tokenizer
    getline( tokenizer, name, '|' );
    getline( tokenizer, gender, '|' );
    getline( tokenizer, birthdate, '|' );
    getline( tokenizer, first_gen, '|' );
    // now, construct a new student object
    tmp_student = new ucla_student( name, gender, birthdate, first_gen );
    students.push_back( tmp_student );
  }
  ucla.close();
  // now, open the USC file and read it
  fstream usc("USC.txt");
  getline( usc, line ); // dummy line
  while( getline( usc, line ), line != "" ){
    // change the separators for pipes, so we can tokenize the string easily
    for( int i = 0; i < (int)line.length(); ++ i )
      if( line[i] == '\t' )
	line[i] = '|';
    // now, create a istringstream with the new string to tokenize
    istringstream tokenizer(line);
    // get the data as if it were lines, from the tokenizer
    getline( tokenizer, name, '|' );
    getline( tokenizer, gender, '|' );
    getline( tokenizer, birthdate, '|' );
    getline( tokenizer, scholarship, '|' );
    // now, construct a new student object
    tmp_student = new usc_student( name, gender, birthdate, scholarship );
    students.push_back( tmp_student );
  }
  usc.close();
  // sort the students by birthdate
  sort( students.begin(), students.end(), student_cmp );
  
  // Set the width of the fields to output
  // for the name, we need to find the length of the longest name:
  int width_name = 13; // student_name has 12 characters, plus one
  // standard way to get the maximum value
  for( int i = 0; i < (int)students.size(); ++ i )
    if( students[i]->get_name().length() > width_name )
      width_name = students[i]->get_name().length() + 2; // plus one to adjust properly
  int width_gender = 7; // 6 because the word gender has only 6 characters, plus one
  int width_birthdate = 11; // 10 because YYYY + MM + DD + 2 hyphens = 10 characters, plus one
  int width_first_gen = 26; // the header string has 25 characters, plus one
  int width_scholarship = 12; // the header string has 11 characters, plus one

  // Showing the headers, breaking into multiple lines for easier reading
  cout << setw( width_name ) << std::left << setfill(' ') << "Student_Name" << '\t'
       << setw( width_gender ) << std::left << setfill(' ') << "Gender" << '\t'
       << setw( width_birthdate ) << std::left << setfill(' ') << "Birthdate" << '\t'
       << setw( width_first_gen ) << std::left << setfill(' ') << "First_Gen_College_Student" << '\t'
       << setw( width_scholarship ) << std::left << setfill(' ') << "Scholarship" << '\n';
  
  // iterate through all the students and output their information
  for( student * it : students ){
    // First, we check the type of derived class through `get_information()`: "ucla" means ucla_student, "usc" means usc_student
    // this is so we can perform the correct `dynamic_cast` and access the proper functions,
    // since it is Undefined Behaviour to access derived functions from a pointer to the base class
    // even if we know they're there!
    string student_type = it->get_information();

    // show the values aligned to the right
    cout << setw( width_name ) << setfill(' ') << std::left << it->get_name() << '\t'
	 << setw( width_gender ) << setfill(' ') << std::left << it->get_gender() << '\t'
	 << setw( width_birthdate ) << setfill(' ') << std::left << it->get_birthdate() << '\t';
    if( student_type == "ucla" ){ // create a UCLA student
      // dynamic cast to the derived class desired, this could create slicing
      ucla_student * tmp_ucla = dynamic_cast<ucla_student*>( it );
      // output the data
      cout << setw( width_first_gen ) << setfill(' ') << std::left << tmp_ucla->get_first_gen() << '\n';
      // no need to output more whitespace afterwards
    }
    else if( student_type == "usc" ){ // create a USC student
      // dynamic cast to the derived class desired, this could create slicing
      usc_student * tmp_usc = dynamic_cast<usc_student*>( it );
      // output the data, first an empty string filled with blanks so the alignment is okay
      cout << setw( width_first_gen ) << setfill(' ') << std::left << "" << '\t'
	   << setw( width_scholarship ) << setfill(' ') << std::left << tmp_usc->get_scholarship() << '\n';
    }
  }
  return 0;
}
