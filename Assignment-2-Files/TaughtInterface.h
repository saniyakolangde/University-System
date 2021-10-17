//interaface to be implemented for Teacher class with pure vitual void functions
#include <list>
class TaughtInterface{
    virtual list<string> getSubjectsTaught()=0;
    virtual void addSubjectsTaught(string)=0;
};