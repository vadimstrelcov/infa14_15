#include <string>

class human
{
private:
    std::string name;
    std::string last_name;
    std::string second_name;
    
public:
    human(std::string last_name, std::string name, std::string second_name);
    human();
    std::string get_full_name();
};
