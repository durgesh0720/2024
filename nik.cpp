#include<iostream>
// Base class (Parent class)
class Animal {
public:
    void makeSound() {
        std::cout << "Some generic sound..." << std::endl;
    }
    void legs()
    {
        std::cout<< "it has 4 legs"<<std::endl;
    }
};

// Derived class (Child class) inheriting from Animal
class Dog : public Animal {
public:
    void bark() {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.makeSound(); // Inherited method from Animal class
    myDog.bark();      // Method specific to Dog class
    myDog.legs();

    return 0;
}
