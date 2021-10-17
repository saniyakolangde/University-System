//interaface to be implemented for Student class with pure vitual void functions
#include <list>
class EnrolledInterface{
    virtual list<string> getSubjectsEnrolled()=0;
    virtual void addSubjectsEnrolled(string)=0;
};