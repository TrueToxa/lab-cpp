Реализуйте функцию void remove_key(List* list_ptr, int key)

List* list_ptr -- указатель на двусвязный список
int key -- значение ключа для удаления
Функция находит указатель на первый узел, который содержит key и удаляет его. Если такого узла нет, то ничего не делает

Учтите все возможные крайние случаи!!!

Для проверки кода можно воспользоваться следующим шаблоном



```cpp
using std::cout;
using std::endl;
void print_list(Node* head_ptr) {
    for (Node *current = head_ptr; current!=nullptr; current = current->next)
        {
            if (current == head_ptr) {
                cout << current->key;
            } else {
                cout << ' ' << current->key;
            }
        }
        cout << endl;
}
```