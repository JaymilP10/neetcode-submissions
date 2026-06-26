class DynamicArray {

private:
    int* numbers;
    int length;
    int capacity;

public:

    DynamicArray(int capacity) : capacity(capacity), length(0) {
        numbers = new int[capacity];
    }

    int get(int i) {
        return numbers[i];
    }

    void set(int i, int n) {
        numbers[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) {
            resize();
        }
        numbers[length] = n;
        length++;
    }

    int popback() {
        if (length > 0) {
            length--;
        }
        return numbers[length];
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < length; i++) {
            newArr[i] = numbers[i];
        }
        delete[] numbers;
        numbers = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
