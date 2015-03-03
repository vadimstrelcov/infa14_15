#include <string>

class advstudent : public student
{
private:
    bool flag;
    
public:
    advstudent(std::string last_name, std::string name, std::string second_name, int score, bool Flag);
    advstudent();
    bool get_flag();
};
