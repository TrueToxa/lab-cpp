#include <iostream>
#include <string>

// foo_says(get_foo(msg));
// std::string msg = ...;
// not struct Foo *final* {...};
// struct Foo {
//     void say() const { std::cout << "Foo says: " << msg << "\n"; }
// protected:
//     Foo(const std::string& msg) : msg(msg) { }
// private:
//     const std::string& msg;
// };

struct Fool : Foo{
    Fool(const std::string& msg) : Foo(msg) { }
};

Fool get_foo(std::string msg) {
    Fool foo = {msg};
    return foo;
}

// void foo_says(const Fool& foo) { 
//     foo.say();
// }

// Foo get_foo(std::string msg) {
//     Foo foo(msg);
//     return foo;
// }
// void externalFunction(SecretClass& secret) {
//     SecretClass abc("CODE");
//     secret = abc;
// }

// int main() {
//     std::string msg = "Biba & Boba";
//     foo_says(get_foo(msg));
// }