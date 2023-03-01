#ifndef student_h
#define student_h
#include <string>


using namespace std;

//must be an abstract class 
class student
{
    
public:
    void set_name(string myname);
    void set_gender(string mygender);
    void set_birthdate(string mybirthday);
    void set_birthdate(int myyear, int mymonth, int myday);
    string get_name() const;
    string get_gender() const;
    string get_birthdate() const;
    int get_birth_year() const;
    int get_birth_month() const;
    int get_birth_day() const;
  // not required since we're using pointers to the objects
  // bool operator<( const student& rhs ) const;
    
    //pure virtual function, this makes it an abstract class
    virtual void set_information(string myinfo) = 0;
    // another virtual function, to get its data as a string
    virtual string get_information() = 0;
    
    
protected:
    string name;
    string gender;
    int birth_day;
    int birth_month;
    int birth_year;
    string information;
    
};


#endif /* student_h */
