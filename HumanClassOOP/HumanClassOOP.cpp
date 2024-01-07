#include <iostream>

class Human {
public:
    Human(std::string name, bool gender, int age) {
        this->name = name;
        this->gender = gender;
        this->age = age;
    }
    std::string getName() {
        return name;
    }
    void setName(std::string newName) {
        name = newName;
    }
    bool getGender() {
        return gender;
    }
    void setGender(bool newGender) {
        gender = newGender;
    }
    int getAge() {
        return age;
    }
    void setAge(int newAge) {
        age = newAge;
    }
private:
    std::string name;
    bool gender; //0 - male, 1 - female
    int age;
};


int main()
{
    Human first("Adam", 0, 25);
    Human second("Eve", 1, 20);
}
