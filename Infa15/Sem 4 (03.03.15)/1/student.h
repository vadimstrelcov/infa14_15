#include <string>

class student : public human
{
private:
    int score;
    
public:
    student(std::string last_name, std::string name, std::string second_name, int score);
    int get_score();
};
