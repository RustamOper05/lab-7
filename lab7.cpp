#include <iostream>
#include <memory>
template <class T> class Circular_Buffer {
private:
    std::unique_ptr<T[]> buffer;
                                 
    size_t head = 0;             
    size_t tail = 0;
    size_t max_size;
    T empty_item;
public:

    Circular_Buffer<T>(size_t max_size)
        : buffer(std::unique_ptr<T[]>(new T[max_size])), max_size(max_size) {};

    void enqueue(T item) {

        if (is_full())
            throw std::runtime_error("buffer is full");

        buffer[tail] = item;

        tail = (tail + 1) % max_size;
    }

    T dequeue() {

        if (is_empty())
            throw std::runtime_error("buffer is empty");

        T item = buffer[head];

        T empty;
        buffer[head] = empty_item;

        head = (head + 1) % max_size;

        return item;
    }

    T front() { return buffer[head]; }

    bool is_empty() { return head == tail; }

    bool is_full() { return tail == (head - 1) % max_size; }

    size_t size() {
        if (tail >= head)
            return tail - head;
        return max_size - head - tail;
    }
};


int main()
{
    Circular_Buffer<int> circle(10);
    
    int x = 10;

    circle.enqueue(x);

    x = circle.dequeue();

    std::cout << x << std::endl;

    return 0;
}