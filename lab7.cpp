#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template<class T>
class CircularBuffer
{
private:
    int capacity = 0;
    int size = 0;
    T* arr = new T[size];
    T* first, * last, * cur_first, * cur_last;
public:
    class Iterator : public iterator<random_access_iterator_tag, T> {
    private:
        T* currentValue;
    public:
        explicit Iterator(T* currentValue) {
            this->currentValue = currentValue;
        }

        [[nodiscard]] T* getCurent() const {
            return currentValue;
        }

        Iterator operator+(int value) {
            currentValue += value;
            return *this;
        }

        Iterator operator-(int value) {
            currentValue -= value;
            return *this;
        }

        T& operator*() const {
            return *currentValue;
        }

        T* operator->() const {
            return currentValue;
        }

        Iterator& operator++() {
            ++currentValue;
            return *this;
        }

        Iterator operator--() {
            currentValue--;
            return *this;
        }

        Iterator& operator=(T* other) {
            currentValue = other;
            return *this;
        }

        bool operator==(const Iterator& other) {
            return this->currentValue = other.currentValue;
        }

        bool operator!=(const Iterator& other) {
            return this->currentValue != other.currentValue;
        }

        bool operator>(const Iterator& other) {
            return this->currentValue > other.currentValue;
        }

        bool operator>=(const Iterator& other) {
            return this->currentValue >= other.currentValue;
        }

        bool operator<(const Iterator& other) {
            return this->currentValue < other.currentValue;
        }

        bool operator<=(const Iterator& other) {
            return this->currentValue <= other.currentValue;
        }
    };

    explicit CircularBuffer(int size_)
    {
        this->capacity = size_ + 0.2 * size_;
        size = size_;
        this->first = &arr[0];
        this->last = &arr[size - 1];
        this->cur_first = this->cur_last = &arr[0];
    }

    [[nodiscard]] Iterator begin()
    {
        return Iterator(arr);
    }
    [[nodiscard]] Iterator end()
    {
        return Iterator(arr + size - 1);
    }
    int capacity_buffer() const
    {
        return capacity;
    }
    int size_buffer() const
    {
        return size;
    }
    void push_back(const T& value)
    {
        *cur_last = value;
        last == cur_last ? cur_last = first : cur_last++;
    }
    void pop_back()
    {
        *cur_last = 0;
        cur_last == first ? cur_last = last : cur_last++;
    }
    T operator [] (int i) const
    {
        return arr[i % capacity];
    }
    void change_capacity(int value)
    {
        if (capacity < value)
            capacity = value;
        else
        {
            if (size > value)
            {
                capacity = value;
            }
            else
            {
                capacity = value;
            }
        }
    }
    void Print()
    {
        for (auto i = &arr[0]; i != &arr[size]; i++)
            cout << *i << ' ';
        cout << endl;
    }
};


int main()
{
    CircularBuffer<int> circle(4);
    
    int x = 14;
    int y = 11;
    int z = 10;
    int j = 9;

    circle.push_back(x);
    
    circle.push_back(y);

    circle.push_back(z);

    cout << circle[1] << endl;;

    reverse(circle.begin(), circle.end());

    circle.Print();

    return 0;
}