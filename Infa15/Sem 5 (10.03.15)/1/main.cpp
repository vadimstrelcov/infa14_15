#include <iostream>

class Base {
public:
    virtual void who() { // определение виртуальной функции
        std::cout << "Base\n";
    }
};

class first_d: public Base {
public:
    void who () { // определение who() применительно к first_d
        std::cout << "First derivation\n";
    }
};
class second_d: public Base {
public:
    void who() { // определение who() применительно к second_d
        std::cout << "Second derivation\n*";
    }
};

// использование в качестве параметра ссылки на базовый класс
void show_who (Base &r) {
    r.who();
}

int main()
{
    Base base_obj;
    first_d first_obj;
    second_d second_obj;
    show_who(base_obj); // доступ к who класса Base
    show_who(first_obj); // доступ к who класса first_d
    show_who(second_obj); // доступ к who класса second_d
    return 0;
}
