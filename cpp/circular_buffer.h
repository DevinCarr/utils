/*
 * Copyright (c) 2016 Devin Carr
 * Licensed under MIT (https://github.com/devincarr/utils/blob/master/LICENSE)
 */

#pragma once

template <class T>
class CircularBuffer {
public:
    CircularBuffer();
    CircularBuffer(unsigned long long c);
    ~CircularBuffer();
    void push(T);
    T top();
    void pop();
    unsigned long long capacity() { return _capacity; }

private:
    unsigned long long _capacity;
    unsigned long long _size;
    unsigned long long _index;

    T* _buffer;
    
};

template <class T>
CircularBuffer<T>::CircularBuffer():
    _capacity(1), _size(0), _index(0), _buffer(new T[_capacity])
{ }

template <class T>
CircularBuffer<T>::CircularBuffer(unsigned long long c):
    _capacity(c), _size(0), _index(0), _buffer(new T[_capacity])
{ }

template <class T>
CircularBuffer<T>::~CircularBuffer() {
    delete [] _buffer;
}

template <class T>
void CircularBuffer<T>::push(T t) {
    if (_index >= _capacity - 1) {
        _index = 0;
    } else {
        _index++;
    }

    _buffer[_index] = t;
}

template <class T>
T CircularBuffer<T>::top() {
    return _buffer[_index];
}

template <class T>
void CircularBuffer<T>::pop() {
    _buffer[_index] = T();
    if (_index == 0) {
        _index = _capacity - 1;
    } else {
        _index--;
    }
}
