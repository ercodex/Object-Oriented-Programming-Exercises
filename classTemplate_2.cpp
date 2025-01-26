#include <iostream>
using namespace std;

// Bir yığın (stack) veri yapısı için genel sınıf tanımı
template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    void push(T element) {
        if (top == capacity - 1) {
            cout << "Stack taşma hatasi!\n";
            return;
        }
        arr[++top] = element;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack boş!\n";
            return T();
        }
        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    cout << "Pop edilen eleman: " << intStack.pop() << endl;

    Stack<string> stringStack(5);
    stringStack.push("Merhaba");
    stringStack.push("Dunya");
    cout << "Pop edilen eleman: " << stringStack.pop() << endl;

    return 0;
}
