template<class T>
struct Stack {
    T array[N];
    int head;

    Stack() {
        head = 0;
    }

    T top() {
        return array[head - 1];
    }

    void push(T other) {
        array[head--] = other;
        return;
    }

    void pop() {
        head--;
        return;
    }

    bool empty() {
        return head;
    }

    int size() {
        return head;
    }
}