template<typename T> // int, ll, pll.
class Heap{ // Max Heap, implementation of priority queue.
    vector<T> v = vector<T>(1, T());
    static int p(int const pos) { return pos / 2; } // Parent.
    static int cl(int const pos) { return 2 * pos; } // Left child.
    static int cr(int const pos) { return 2 * pos + 1; } // Right child.
public:
    void push(T el) { // Insert element.
        int pos = v.size();
        v.pb(el); // Heapify up.
        while(pos > 1 && v[pos] > v[p(pos)]) {
            swap(v[pos], v[p(pos)]);
            pos = p(pos);
        }
    }
    void pop() {
        int pos = 1, n = v.size();
        if(n == 1) return; // Error, empty.
        swap(v[1], v[n - 1]);
        v.pop_back();
        n = v.size();
        while(true) { // Heapify down.
            if(cl(pos) >= n) break;
            int posc = cl(pos);
            if(cr(pos) < n && v[cr(pos)] > v[cl(pos)]) posc = cr(pos);
            if(v[pos] < v[posc]) {
                swap(v[pos], v[posc]);
                pos = posc;
            } else break;
        }
    }
    T top() {
        if(v.size() == 1) return numeric_limits<T>::min();
        return v[1];
    }
    int size() {
        return (int)v.size() - 1;
    }
    bool empty() {
        return (int)v.size() == 1;
    }
};

