#include "human.h"
#include "student.h"
#include "advstudent.h"
#include <string>

advstudent::advstudent(std::string last_name, std::string name, std::string second_name, int score, bool Flag):student(last_name, name, second_name, score) {
    this->flag=Flag;
}

advstudent::advstudent() {
}

bool advstudent::get_flag() {
    return this->flag;
}

