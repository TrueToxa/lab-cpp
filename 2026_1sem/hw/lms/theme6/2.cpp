// #include <iostream>

// #include <cstddef>



// class IntArray {

// private:

//     int* data_;

//     std::size_t size_;



// public:

//     IntArray(std::size_t size);

//     IntArray(const IntArray& other);

//     ~IntArray();



//     int& operator[](std::size_t index);

//     std::size_t size() const;

// };

IntArray::IntArray(std::size_t size)
{
    size_ = size;
    data_ = new int[size];
}

IntArray::IntArray(const IntArray& other)
{
    // TODO
}

IntArray::~IntArray()
{
    // TODO
}

int& IntArray::operator[](std::size_t index)
{
    return data_[index];
}

std::size_t IntArray::size() const
{
    return size_;
}