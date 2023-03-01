#ifndef usc_student_h
#define usc_student_h
#include <iostream>
#include "student.h"
#include "usc_student.h"

using namespace std;

using namespace std;

class usc_student : public student
{
public:
    
    void set_information(string myinfo);
    // constructor
    usc_student( string myname, string mygender, string mybirthdate, string myscholarship );
    // get_information, to get the info as a string
    string get_information() override;
    string get_scholarship() const;
private:
    //add scholarship
    string scholarship;
};



#endif /* usc_student_h */
