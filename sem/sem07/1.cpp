#include <iostream> 
using std::cout;
using std::endl;

struct Node {
    int field_int;
    int field_int_secondary;
    double field_double;
};

struct EmtyNode {};

int main() {
    Node my_favorit_node = Node();
    Node * node_array = new Node[12];
    cout << sizeof(char) << endl;
    cout << sizeof(EmtyNode) << endl;
    cout << sizeof(Node) << endl;
    cout << sizeof(my_favorit_node) << endl;
    cout << my_favorit_node.field_int_secondary << endl;
    cout << node_array -> field_int_secondary << endl;
    delete[] node_array;
    return 0;
}