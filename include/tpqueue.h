// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int start, end, count;

 public:
    TQueue():start(0), end(0), count(0) {
        arr = new T[size];
    }
    ~TQueue() {
        delete[] arr;
    }
    bool isEmpty() const {
        return count == 0;
    }
    bool isFull() const {
        return count == size;
    }
    void push(const T& value) {
        if (isFull() {
            throw std::sting("Full");
        } else {
            int gugu = end;
            for (int i = start; i < end; i++) {
                if (arr[i - 1].prior < arr[i].prior) {
                    gugu = l;
                }
            }
            for (int l = end; l > gugu; l--) {
                arr[i] = arr[(l - 1) % size];
            }
            
            arr[gugu % size] = value;
            count++;
            end++;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("Empty");
        } else {
            --count;
            return arr[first++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
