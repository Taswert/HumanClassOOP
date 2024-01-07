#include <iostream>

class Creature {
public:
    bool getIsAlive() {
        return isAlive;
    }
    void setIsAlive(bool newIsAlive) {
        isAlive = newIsAlive;
    }
private:
    bool isAlive = true;
};

class Human : public Creature {
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

    virtual void printMe() {
        std::cout << "Name: " << name << "\nGender: " << (gender == 1 ? "Female" : "Male") << "\nAge: " << age << std::endl << std::endl;
    }
private:
    std::string name;
    bool gender; //0 - male, 1 - female
    int age;
};

class Worker : public Human {
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

    void printMe() override {
        std::cout << "Name: " << getName() << "\nGender: " << (getGender() == 1 ? "Female" : "Male") << "\nAge: " << getAge() << "\nSalary: " << salary << "\nPost: " << post << std::endl << std::endl;
    }
private:
    int salary;
    std::string post; //ну типа этот, ну эээ, блин, как его, а, да, Должность!
};

//Ну, поехали
class Vehicle {
public:
    Vehicle(std::string name, int capacity) {
        this->name = name;
        this->capacity = capacity;
    }

    int getCapacity() {
        return capacity;
    }
    void setCapacity(int newCapacity) {
        capacity = newCapacity;
    }

    std::string getName() {
        return name;
    }
    void setName(std::string newName) {
        name = newName;
    }

    virtual void printMe() {
        std::cout << "Name: " << name << "\nCapacity: " << capacity << std::endl << std::endl;
    }
private:
    int capacity;
    std::string name;
};

class Ship : public Vehicle {
public:
    Ship(std::string name, int capacity, int waterSpeed) : Vehicle(name, capacity) {
        this->waterSpeed = waterSpeed;
    }

    int getWaterSpeed() {
        return waterSpeed;
    }
    void setWaterSpeed(int newWaterSpeed) {
        waterSpeed = newWaterSpeed;
    }

    void printMe() override {
        std::cout << "Name: " << getName()<< "\nCapacity: " << getCapacity() << "\nWater speed: " << waterSpeed << std::endl << std::endl;
    }
private:
    int waterSpeed;
};

class Car : public Vehicle {
public:
    Car(std::string name, int capacity, int groundSpeed) : Vehicle(name, capacity) {
        this->groundSpeed = groundSpeed;
    }

    int getGroundSpeed() {
        return groundSpeed;
    }
    void setGroundSpeed(int newGroundSpeed) {
        groundSpeed = newGroundSpeed;
    }

    void printMe() override {
        std::cout << "Name: " << getName() << "\nCapacity: " << getCapacity() << "\nGround speed: " << groundSpeed << std::endl << std::endl;
    }
private:
    int groundSpeed;
};

class Helicopter : public Car {
public:
    Helicopter(std::string name, int capacity, int groundSpeed, int airSpeed) : Car(name, capacity, groundSpeed) {
        this->airSpeed = airSpeed;
    }

    int getAirSpeed() {
        return airSpeed;
    }
    void setAirSpeed(int newAirSpeed) {
        airSpeed = newAirSpeed;
    }

    void printMe() override {
        std::cout << "Name: " << getName() << "\nCapacity: " << getCapacity() << "\nGround speed: " << getGroundSpeed() << "\nAir Speed: " << airSpeed << std::endl << std::endl;
    }
private:
    int airSpeed;
};

class Tank : public Car {
public:
    Tank(std::string name, int capacity, int groundSpeed, int firePower) : Car(name, capacity, groundSpeed) {
        this->firePower = firePower;
    }

    int getFirePower() {
        return firePower;
    }
    void setFirePower(int newFirePower) {
        firePower = newFirePower;
    }

    void printMe() override {
        std::cout << "Name: " << getName() << "\nCapacity: " << getCapacity() << "\nGround speed: " << getGroundSpeed() << "\nFire Power: " << firePower << std::endl << std::endl;
    }
private:
    int firePower;
};

class Horse : public Creature, public Car {
public:
    Horse(std::string name, int capacity, int groundSpeed, bool isHungry) : Car(name, capacity, groundSpeed) {
        this->isHungry = isHungry;
    }

    bool getIsHungry() {
        return isHungry;
    }
    void setIsHungry(bool newIsHungry) {
        isHungry = newIsHungry;
    }
    void printMe() override {
        std::cout << "Name: " << getName() << "\nCapacity: " << getCapacity() << "\nGround Speed: " << getGroundSpeed() << "\nIs it hungry? - " << (isHungry == 1 ? "Yes" : "No") << std::endl << std::endl;
    }
private:
    bool isHungry;
};

//Interface
class Printer {
public:
    virtual void printMe() = 0;
};

//AbstractClass
class HelloThing : public Printer {
public:
    void printMe() override {
        std::cout << "Hiiii" << std::endl;
    }
    virtual void someMethod() = 0;
};

class ChildOfHelloThing : public HelloThing {
public:
    void someMethod() override {
        std::cout << "Byeee" << std::endl;
    }
};


int main() {
    Human first("Adam", 0, 25);
    Human second("Eve", 1, 20);
    Worker third("John", 0, 54, 90000, "Boss");
    third.printMe();
    std::cout << "John is getting demotion...        And older...\n" << std::endl;
    third.setAge(55);
    third.setSalary(1-0+9);
    third.setPost("Dvornyaga");
    third.printMe();
    first.printMe();
    second.printMe();

    Tank myLovelyTank("Rat", 6, 30, 100);
    myLovelyTank.printMe();

    Horse myLovelyHorse("Apple", 2, 60, true);
    myLovelyHorse.printMe();

    ChildOfHelloThing idk;
    idk.printMe();
    idk.someMethod();
}
