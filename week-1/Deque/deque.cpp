#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template <class Item>
class Deque {
public:
	Deque() = default;

    bool Empty() const {
        return (start.empty() && end.empty());
    }

    size_t Size() const {
        return (start.size() + end.size());
    }

    Item& operator[](size_t index) {
        if (index >= start.size()) {
            return end[index - start.size()];
        }
        else {
            return start[start.size() - index - 1];
        }
    }

    const Item& operator[](size_t index) const {
        if (index >= start.size()) {
            return end[index - start.size()];
        }
        else {
            return start[start.size() - index - 1];
        }
    }

    const Item& At(size_t index) const {
        if (index >= this->Size()) throw out_of_range("out_of_range");
        if (index >= start.size()) {
            return end[index - start.size()];
        }
        else {
            return start[start.size() - index - 1];
        }
    }

    Item& At(size_t index) {
        if (index >= this->Size()) throw out_of_range("out_of_range");
        if (index >= start.size()) {
            return end[index - start.size()];
        }
        else {
            return start[start.size() - index - 1];
        }
    }

    Item& Front() {
        if (!start.empty()) return start.back();
        else return end.at(0);
    }

    Item& Back() {
        if (!end.empty()) return end.back();
        else return start.at(0);
    }

    const Item& Front() const {
        if (!start.empty()) return start.back();
        else return end.at(0);
    }

    const Item& Back() const {
        if (!end.empty()) return end.back();
        else return start.at(0);
    }

    void PushFront(Item i) {
        start.push_back(i);
    }

    void PushBack(Item i) {
        end.push_back(i);
    }

private:
    vector<Item> start, end;
};
