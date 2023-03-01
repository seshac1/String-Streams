#include "ucla_student.h"

using namespace std;

ucla_student::ucla_student( string myname, string mygender, string mybirthdate, string myfirstgen )
{
  name = myname;
  gender = mygender;
  set_birthdate( mybirthdate );
  first_gen = myfirstgen;
}

void ucla_student::set_information(string myinfo)
{
    first_gen = myinfo;
}

string ucla_student::get_first_gen() const
{
  return first_gen;
}

string ucla_student::get_information()
{
  return "ucla";
}






