#include <iostream>
#include <memory>
using namespace std;

// unique_ptr

class NodeGood {
public:
    weak_ptr<Node> next;
};

class NodeBad {
public: 
    shared_ptr<Node> next;
};


int main() {
    auto ptr = make_unique<double[]>(10);
    auto ptr_ = make_unique<double>(10);
    cout << ptr.get()[0] << endl;
    cout << ptr.get()[5] << endl;
    cout << ptr_.get()[0] << endl;

    // double* ptr_d = new double(20);
    auto sh_ptr0 = make_shared<double>(20);
    auto sh_ptr1 = shared_ptr(sh_ptr0);
    cout << sh_ptr1.use_count() << endl;
    sh_ptr0.reset();
    cout << sh_ptr1.use_count() << endl;
    sh_ptr1.reset();

    {
        auto node_a = make_shared<NodeGood>();
        auto node_b = make_shared<NodeGood>();
        node_a->next = node_b;
        node_b->next = node_a;
        // cout << node_a.use_count() << endl;
        // cout << node_b.use_count() << endl;
    }
    return 0;
}

//shared_ptr
/*
оповещение о событии - retranslator
    - observer1
    - observer2
    -...
    автоматически удаляются
*/

class my_shared_ptr {
    class my_counter {};
};