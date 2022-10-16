template<class T>
struct Stack {
    T array[N];
    int head;

    Stack() {
        head = -1;
    }

    T top() {
        return array[head];
    }

    void push(T other) {
        array[++head] = other;
        return;
    }

    void pop() {
        --head;
        return;
    }
}