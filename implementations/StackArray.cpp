#include <iostream>
#define ERROR1 "Error: Stack overflow!"
#define ERROR2 "Error: Stack underflow!"
#define ERROR3 "Error: Invalid position"
using std::cout, std::cin, std::cerr, std::endl;


class StackArray{
private:
    int size;
    int top;
    int *addr;
private:
    int* allocateMemory(int _size){
        return new int[_size];
    }
public:
    // Init stack with default size of 10.
    StackArray() : top(-1), size(10) {
        addr = allocateMemory(size);
    }

    explicit StackArray(int _size) : top(-1), size(_size) {
        addr = allocateMemory(_size);
    }

    bool isEmpty() const {
        return top==-1;
    }

    bool isFull() const {
        return top==size-1;
    }
    void display() const {
        if (isEmpty()) {
            cerr << ERROR2 << endl;
            return;
        }
        for(int i=top; i>=0; i--) cout << addr[i] << " ";
        cout << endl;
    }

    void push(int _x) {
        if(isFull()){
            cerr << ERROR1 << endl;
            return;
        }
        addr[++top] = _x;
    }

    int pop() {
        if(isEmpty()) {
            cout << ERROR2 << endl;
            return -1;
        }
        return addr[top--];
    }

    int peek(int pos){
        // Formula: index = top-pos+1
        int x = -1, index = top-pos+1;
        if(index<0) cerr << ERROR3 << endl;
        else x = addr[index];
        return x;
    }

    int stackTop(){
        int x = -1;
        if(isEmpty()) cout << ERROR2 << endl;
        else x = addr[top];
        return x;
    }

    // TODO 1: Implement a function to fill the stack with random values.
    void populate(int _lim = 10){
        srand((unsigned) time(NULL));
        for(int i=0; i<size; i++, top++){
            addr[i] = 1 + rand() % _lim;
        }
    }

    // TODO 2: Implement a static method for interface functions.
    static void interface(){
        cout << "Stack class written by Shiven Saini!" << endl;
        cout << "Default initialized size of the stack is 10 elements." << endl;
        cout << "Methods available are => \n";
        cout << "\t1. push(element) : to insert an element." << endl;
        cout << "\t2. pop() : to return and remove the top most element." << endl;
        cout << "\t3. populate(lim) : to fill the stack with random values till limit (default 10)." << endl;
        cout << "\t4. display() : to print the stack elements." << endl;
        cout << "\t5. peek(pos) : to get the value at position pos." << endl;
        cout << "\t6. stackTop() : to return the element at top." << endl;
        cout << "\t7. isFull() : to check whether the stack is full or not." << endl;
        cout << "\t8. isEmpty() : to check whether the stack is empty or not.\n" << endl;
    }
};

int main() {
    StackArray::interface();

    return 0;
}
