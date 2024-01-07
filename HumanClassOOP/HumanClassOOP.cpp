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

class Worker : Human {
public:
    Worker(std::string name, bool gender, int age, int salary, std::string post) : Human(name, gender, age) {
        this->salary = salary;
        this->post = post;
    }

    int getSalary() {
        return salary;
    }
    void setSalary(int newSalary) {
        salary = newSalary;
    }
    std::string getPost() {
        return post;
    }
    void setPost(std::string newPost) {
        post = newPost;
    }
private:
    int salary;
    std::string post; //ну типа этот, ну эээ, блин, как его, а, да, Должность!
};

int main() {
    Human first("Adam", 0, 25);
    Human second("Eve", 1, 20);
    Worker third("John", 0, 54, 90000, "Boss");
}
