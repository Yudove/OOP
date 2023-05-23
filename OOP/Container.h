#ifndef _CONTAINER_H_
#define _CONTAINER_H_

template <typename T>
class Container {
private:
    T* arr;
    int arrlen;
    int arrIndex;

public:
    Container(int len = 50) : arrIndex(0)
    {
        arr = new T[len];
        arrlen = len;
    }
    
    T& operator[](int idx) {
        if (idx < 0 || idx >= arrlen) {
            cout << "段引" << endl;
            exit(1);
        }
        return arr[idx];
    }
    T operator[](int idx) const {
        if (idx < 0 || idx >= arrlen) {
            cout << "段引" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int GetArrlen() const {
        return arrlen;
    }

    ~Container() {
        delete[] arr;
    }
};



#endif