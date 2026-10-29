/*
a.exe 1>NULL
std::cerr << ... << std::endl;
*/

#include <iostream>
#include <memory>
#include <functional>

struct List {
  public:
    struct Node {
      public:
        int data;
        std::unique_ptr<Node> next;
    };
  public:
    std::unique_ptr<Node> head;

  public:
    void push(int data) {
        head = std::unique_ptr<Node>(new Node{data, std::move(head)});
    }

    ~List() {
        while (head) {
            auto next = std::move(head->next);
            head = std::move(next);
        }
    }
};


int main() {
  auto single_node = std::make_unique<List::Node>();
  std::function<void(List::Node*)> lambda_deleter = [](List::Node* ptr){ delete ptr; };
  std::unique_ptr<List::Node, std::function<void(List::Node*)>> single_node_custom_deleter{new List::Node, lambda_deleter};
  List my_list;
  for (int value = 0; value < 1000; ++value) {
    my_list.push(value);
  }
  return 0;
}
