#pragma once

template<typename Type>
class Deque {
    public:
        Deque() {}

        bool Empty() const {
            return (Front.empty() && Front.empty()) ? true : false;
        }

        size_t Size() const {
            return Front.size() + Back.size();
        }

        void PushFront(const Type& element) {
            Front.insert(Front.begin(), element);
        }

        void PushBack(const Type& element) {
            Back.insert(Back.begin(), element);
        }

        vector<Type> GetVectorFront() const {
            return Front;
        }

        vector<Type> GetVectorBack() const {
            return Back;
        }

    private:
        vector<Type> Front;
        vector<Type> Back;
};

