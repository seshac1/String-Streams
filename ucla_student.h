#ifndef ucla_student_h
#define ucla_student_h
#include "student.h"
#include <iostream>
#include "ucla_student.h"

using namespace std;

class ucla_student : public student
{
public:
    
    //add first_gen
    void set_information(string myinfo);
    // constructor
    ucla_student( string myname, string mygender, string mybirthdate, string myfirstgen );
    // get_information
    string get_information() override;
    string get_first_gen() const;
    
private:
    string first_gen;
};


#endif /* ucla_student_h */
