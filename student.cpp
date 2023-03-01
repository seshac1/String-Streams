#include "student.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void student::set_name(string myname)
{
    name = myname;
}

void student::set_gender(string mygender)
{
    gender = mygender;
}

void student::set_birthdate(string mybirthday)
{
  // We know the date is in the format YYYY-MM-DD, we can take advantage of it
  // change the hyphens to whitespace so we can easily parse the string
  for( int i = 0; i < (int)mybirthday.length(); ++ i )
    if( mybirthday[i] == '-' )
      mybirthday[i] = ' ';
  // now, we can parse the string as a stream with <sstream>
  istringstream string_parser(mybirthday);
  // since it already separates by whitespace, we can just use it like std::cin
  string_parser >> birth_year >> birth_month >> birth_day;
}

void student::set_birthdate(int myyear, int mymonth, int myday)
{
  birth_day = myday;
  birth_month = mymonth;
  birth_year = myyear;
}

string student::get_name() const
{
  return name;
}

string student::get_gender() const 
{
  return gender;
}

string student::get_birthdate() const
{
  // we need to make a string consisting of the birthdate
  // we just need to convert the values to a string, we can use an ostringstream
  // it is similar to using std::cout, but instead, we can handle it and pass it values!
  // then just get the resulting string
  ostringstream birthdate;
  birthdate << birth_year << "-" << birth_month << "-" << birth_day;
  // access the internal string representation and return it
  return birthdate.str();
}

int student::get_birth_year() const
{
  return birth_year;
}

int student::get_birth_month() const
{
  return birth_month;
}

int student::get_birth_day() const
{
  return birth_day;
}

// not required since we're using pointers to the objects
// bool student::operator<( const student& rhs ) const
// {
//   if( birth_year != rhs.get_birth_year() )
//     return birth_year < rhs.get_birth_year();
//   else if( birth_month != rhs.get_birth_month() )
//     return birth_month < rhs.get_birth_month();
//   else
//     return birth_day < rhs.get_birth_day();
// }
