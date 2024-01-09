#ifndef Queue_hpp
#define Queue_hpp

class Queue
{
    private:
        int first;
        int last;
        int capacity;
        int length;
        int* array;
    
        void reserve(int newCapacity);
    public:
        Queue();
        ~Queue();
        int count();
        bool isEmpty();
        void clear();
        void enqueue(const int& item);
        void dequeue();
        const int& peek();
};

#endif