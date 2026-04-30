#include <iostream>
#include <string>

using std::cout, std::endl, std::cin;
struct Student
{
    std::string name;
    int mark;
};

/*
Формат ввода
N: число людей в списке
N пар (имя, число): имя студента и его средний балл
M: средний пороговый балл, float

Формат вывода
Список имен студентов через пробел,
которые прошли порог в M баллов.
Имена идут в порядке возрастания среднего балла.
Если имена совпадают, то выводить в лексикографическом порядке
*/

void swap(int &lhv, int &rhv)
{
    int tmp = lhv;
    lhv = rhv;
    rhv = tmp;
}
void swap(Student &lhv, Student &rhv)
{
    Student tmp = lhv;
    lhv = rhv;
    rhv = tmp;
}

void quick_sort(int *arr, int l_idx, int r_idx, int size)
{
    if (l_idx >= r_idx) {
        return;
    }
    int l_tmp = l_idx, r_tmp = r_idx;

    int op = arr[(l_idx + r_idx) / 2];
    while (l_idx <= r_idx)
    {
        while (l_idx <= r_idx && arr[l_idx] < op)
            ++l_idx;
        while (l_idx <= r_idx && arr[r_idx] > op)
            --r_idx;
        if (l_idx <= r_idx) {
            swap(arr[l_idx], arr[r_idx]);
            ++l_idx;
            --r_idx;
        }
    }
    if (l_tmp < r_idx)
        quick_sort(arr, l_tmp, r_idx, size);

    if (l_idx < r_tmp)
        quick_sort(arr, l_idx, r_tmp, size);
}

void quick_sort(Student *arr, int l_idx, int r_idx, int size)
{
    if (l_idx >= r_idx) {
        return;
    }
    int l_tmp = l_idx, r_tmp = r_idx;

    Student op = arr[(l_idx + r_idx) / 2];
    while (l_idx <= r_idx)
    {
        while (l_idx <= r_idx && (arr[l_idx].mark < op.mark || (arr[l_idx].mark == op.mark &&  arr[l_idx].name < op.name)))
            ++l_idx;
        while (l_idx <= r_idx && (arr[r_idx].mark > op.mark || (arr[r_idx].mark == op.mark &&  arr[r_idx].name > op.name)))
            --r_idx;
        if (l_idx <= r_idx){
            swap(arr[l_idx], arr[r_idx]);
            ++l_idx;
            --r_idx;
        }   
    }

    if (l_tmp < r_idx)
        quick_sort(arr, l_tmp, r_idx, size);

    if (l_idx < r_tmp)
        quick_sort(arr, l_idx, r_tmp, size);
}

void print_students(Student *students, int N)
{
    for (unsigned idx = 0; idx < N; ++idx)
    {
        cout << students[idx].name << ' ' << students[idx].mark << endl;
    }
    cout << endl;
    return;
}

int main()
{
    // input
    int N;
    cin >> N;
    Student *students = new Student[N];
    for (unsigned idx = 0; idx < N; ++idx)
    {
        cin >> students[idx].name >> students[idx].mark;
    }
    float M;
    cin >> M;

    // print_students(students, N);
    // processing and output
    quick_sort(students, 0, N-1, N);

    for (unsigned idx = 0; idx < N; ++idx)
    {
        if (students[idx].mark >= M)
        {
            cout << students[idx].name << ' ';
        }
    }
    

    delete[] students;
    return 52;
}