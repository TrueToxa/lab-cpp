#include <iostream>
#include <string>

class Person {
protected:
  std::string name_;

public:
  explicit Person(std::string const &name) : name_(name) {}
  virtual std::string hello() = 0;
};

class Mister : public Person {
public:
  explicit Mister(std::string const &name) : Person(name) {}
  std::string hello() override {
    return "Hello, I am Mister " + Person::name_;
  }  // Возвращает строку Hello, I am Mister %name_%
};

class Miss : public Person {
public:
  explicit Miss(std::string const &name) : Person(name) {}
  std::string hello() override {
    return "Hello, I am Miss " + Person::name_;
  }   // Возвращает строку Hello, I am Miss %name_%
};

class Professor : public Person {
private:
  std::string surname_;

public:
  explicit Professor(std::string const &name, std::string const &surname): Person(name), surname_(surname) {}
  std::string hello() override {
    return "Hello, I am Professor " + surname_;
  }  // Возвращает строку Hello, I am Professor %surname_%
};

int main() {
    Professor prof = Professor("Grigory", "Ivanov");
    Miss miss = Miss("Anna");
    Mister mister = Mister("Pedro");
    std::cout << prof.hello() << std::endl;  // "Hello, I am Professor Ivanov"
    std::cout << miss.hello() << std::endl;  // "Hello, I am Miss Anna"
    std::cout << mister.hello() << std::endl;  // "Hello, I am Mister Pedro"
    return 0;
}