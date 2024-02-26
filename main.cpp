#include<iostream>
#include<stdexcept>
using namespace std;

class yasmine
{
private:
    size_t size;
    int *data;
    size_t capacity;
public:
    yasmine()
    {
        capacity = 2;
        data = new int[capacity];
        size = 0;
    }

    yasmine(size_t size)
    {
        capacity = 2;
        data = new int[capacity];
        this->size = size;
    }

    yasmine(const yasmine& other)
    {
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~yasmine()
    {
        delete[] data;
    }

    void resize()
    {
        size_t newCapacity = max(2 * static_cast<int>(size), 2);
        int* arr = new int[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = data[i];
        }
        delete[] data;
        data = arr;
        capacity = newCapacity;
    }

    size_t getSize()
    {
        return size;
    }

    void insertFront(int value)
    {
        if (size == capacity)
            resize();
        for (int i = size; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }

    void insertEnd(int value)
    {
        if (size == capacity)
            resize();
        data[size++] = value;
    }

    void removeEnd()
    {
        if (size == 0)
            cout << "There are no items to remove";
        else
            size--;
    }

    void removeFront()
    {
        if (size == 0)
            cout << "There are no items to remove";
        else
        {
            for (int i = 0; i < size - 1; i++)
            {
                data[i] = data[i + 1];
            }
            size--;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
    }
};

int main()
{
    yasmine y;
    y.insertFront(2);
    y.insertFront(8);
    y.insertFront(3);
    y.insertFront(9);
    y.print();

    return 0;
}
