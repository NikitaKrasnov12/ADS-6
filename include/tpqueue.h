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
        arr = new T[size + 1];
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
        if (isFull()) {
            throw std::sting("Full");
        } else {
            int gugu = end;
            ++count;
            for (int i = start; i < end; i++) {
                if (arr[i].prior < value.prior) {
                    gugu = i;
                    break;
                }
            }
            for (int l = end; l > gugu; l--) {
                arr[l % size] = arr[(l - 1) % size];
            }
            arr[gugu % size] = value;
            ++end;
        }
    }
    T& pop() {
        assert(count > 0);
        T thing = arr[start];
        if (++start > size) {
            start = start - size + 1;
        }
        return thing;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
