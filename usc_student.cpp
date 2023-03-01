#include <iostream>
#include "usc_student.h"

using namespace std;

usc_student::usc_student(string myname, string mygender, string mybirthdate, string myscholarship)
{
  name = myname;
  gender = mygender;
  set_birthdate(mybirthdate);
  scholarship = myscholarship;
}

void usc_student::set_information(string myinfo)
{
    scholarship = myinfo;
}

string usc_student::get_scholarship() const
{
  return scholarship;
}

string usc_student::get_information()
{
  return "usc";
}
