#include <iostream>
#include <climits>
using std::cout, std::cin, std::endl;

class ArrayADT {
private:
    int size;
    int length;
    int *addr;
private:
    int* allocateMemory(int _size) {
        return new int[_size];
    }
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
public:
    // Default constructor with empty parameters. (Default size is 10 elements)
    ArrayADT() : size(10), length(0) {
        addr = allocateMemory(size);
    }

    ArrayADT(int _size) : size(_size), length(0) {
        addr = allocateMemory(size);
    }

    ~ArrayADT() {
        cout << "Freeing up the memory....." << endl;
        delete addr;
        cout << "Done!" << endl;
    }

    void populate(int lim = 10){
        srand((unsigned) time(NULL));
        for (int i=0; i<size; i++, length++){
            addr[i] = 1 +(rand() % lim);
        }
    }

    void display(){
        if(length==0) {
            cout << "Error: array is empty!" << endl;
            return;
        }
        for (int i=0; i<length; i++){
            cout << addr[i] << ' ';
        }
        cout << endl;
    }

    void insert(int x) {
        if(length==size){
            cout << "Error: array is already filled to the limit!" << endl;
            return;
        }
        addr[length++] = x;
    }

    void insert(int pos, int x) {
        if(length==size){
            cout << "Error: array is already filled to the limit!" << endl;
            return;
        }

        for(int i=length; i>pos; i--){
            addr[i] = addr[i-1];
        }
        addr[pos] = x;
        length++;
    }

    void remove(){
        if(length==0) {
            cout << "Error: array is empty!" << endl;
            return;
        }
        length--;
    }

    void remove(int pos){
        if(length==0) {
            cout << "Error: array is empty!" << endl;
            return;
        }

        for(int i=pos; i<length-1; i++){
            addr[i] = addr[i+1];
        }
        length--;
    }

    int get(int pos){
        if(pos>=0 && pos<length){
            return addr[pos];
        }
        cout << "Error: No value allocated at position " << pos << endl;
        return -1;
    }

    void set(int pos, int x){
        if(pos>=0 && pos<length) {
            addr[pos] = x;
            return;
        }
        cout << "Error: invalid position!" << endl;
    }

    int max(){
        int max_value = INT_MIN;
        for(int i=0; i<length; i++){
            if(addr[i]>max_value) max_value = addr[i];
        }
        return max_value;
    }

    int min(){
        int min_value = INT_MAX;
        for(int i=0; i<length; i++){
            if(addr[i]<min_value) min_value = addr[i];
        }
        return min_value;
    }

    int total(){
        int total_value = 0;
        for(int i=0; i<length; i++){
            total_value += addr[i];
        }
        return total_value;
    }

    int search(int key){
        // Linear search algorithm but can be improved.
        // Transposition and move to head methods to increase efficiency.
        for(int i=0; i<length; i++){
            if(addr[i]==key) return i;
        }
        return -1;
    }

    void reverse(){
        // Approach :- using two sliding pointers method.
        for(int i=0, j=length-1; i<j; i++, j--){
            swap(addr[i], addr[j]);
        }
    }

    void reverseButWorse(){
        // Create another auxiliary array and store the elements of first array
        // in reverse order in it. Then simply copy the element back to the first array.
        int* auxArray = allocateMemory(length);

        for(int i=0, j=length-1; i<length; i++, j--){
            auxArray[i] = addr[j];
        }

        for(int i=0; i<length; i++){
            addr[i] = auxArray[i];
        }
        delete auxArray;
    }

    static void interface(){
        cout << "Array class written by Shiven Saini!" << endl;
        cout << "Default initialized size of the array is 10 elements." << endl;
        cout << "Methods available are => \n";
        cout << "\t1. display() : to display the array elements." << endl;
        cout << "\t2. insert(pos) : to insert an element at any position. (Default is last index)" << endl;
        cout << "\t3. remove(pos) : to remove the element from the array. (Default is last index)" << endl;
        cout << "\t4. populate(lim) : to fill the array with random values upto an upper limit." << endl;
        cout << "\t5. get(pos) : to return the value at index pos." << endl;
        cout << "\t6. set(pos, value) : to set the value at index pos." << endl;
        cout << "\t7. max() : to return the maximum value in the array." << endl;
        cout << "\t8. min() : to return the minimum value in the array." << endl;
        cout << "\t9. total() : to return the total value in the array." << endl;
        cout << "\t10. search(value) : to search for the index of given value." << endl;
        cout << "\t11. reverse() : to reverse the array." << endl;
        cout << "\t12. reverseButWorse() : to reverse the array. (Another not recommended implementation!)" << endl;
    }
    // TODO 1: add function to sort the array.
    // TODO 2: add function merge to merge two sorted arrays.
    // TODO 3: add function to perform shift and rotate operations on arrays.
    // TODO 4: add function to overload + operator for concatenation of arrays.
    // TODO 5: add function to increase the size of an array object. (Default is by 2x times)
};

int main(){
    ArrayADT::interface();

    return 0;
}