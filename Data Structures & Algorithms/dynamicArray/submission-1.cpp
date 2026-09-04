class DynamicArray {
public:

    DynamicArray(int capacity) :
        capacity_{capacity}, size_{0}, start{new int[capacity]} {}

    int get(int i) {
        return *(start + i);
    }

    void set(int i, int n) {
        *(start + i) = n;
    }

    void pushback(int n) {
        ++size_;
        if (size_ > capacity_) {
            resize();
        }
        *(start + size_ - 1) = n;
    }

    int popback() {
        return *(start + size_-- - 1);
    }

    void resize() {
        capacity_ *= 2;
        auto old = start;
        start = new int[capacity_];
        for (int i = 0; i < size_ - 1; ++i) {
            *(start + i) = *(old + i); 
        }
    }

    int getSize() {
        return size_;
    }

    int getCapacity() {
        return capacity_;
    }

private:
    int capacity_;
    int size_;
    int* start;
};
