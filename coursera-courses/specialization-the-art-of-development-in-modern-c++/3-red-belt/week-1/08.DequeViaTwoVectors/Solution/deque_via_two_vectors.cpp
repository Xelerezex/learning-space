#include <vector>
#include <stdexcept>

using namespace std;


template<typename Type>
class Deque {
    public:
        //ON ASSIGNMENT:
        // 1 PAR
        Deque() {}

        // 2 PAR
        const bool Empty() const {
            return (FrontData.empty() && BackData.empty()) ? true : false;
        }

        // 3 PAR
        const size_t Size() const {
            return FrontData.size() + BackData.size();
        }

        // 4 PAR
        Type& operator[](size_t index){
            if (index < FrontData.size()) {
                return FrontData[index];
            } else {
                auto it = BackData.end();
                advance(it, -(index-1));
                return *it;
            }
        }

        const Type& operator[](size_t index) const{
            if (index < FrontData.size()) {
                return FrontData[index];
            } else {
                auto it = BackData.end();
                advance(it, -(index-1));
                return *it;
            }
        }
        // 5 PAR
        Type& At(size_t index) {
            bool mcond = index < (FrontData.size() + BackData.size());

            if (index < FrontData.size() && mcond) {
                return FrontData[index];
            } else if (index >= FrontData.size() && mcond) {
                auto it = BackData.end();
                advance(it, -(index-1));
                return *it;
            } else {
                throw out_of_range("");
            }
        }

        const Type& At(size_t index) const {
            bool mcond = index < (FrontData.size() + BackData.size());

            if (index < FrontData.size() && mcond) {
                return FrontData[index];
            } else if (index >= FrontData.size() && mcond) {
                auto it = BackData.end();
                advance(it, -(index-1));
                return *it;
            } else {
                throw out_of_range("");
            }
        }

        // 6 PAR
         Type& Front() {
            return *FrontData.begin();
        }

        const Type& Front() const {
            return *FrontData.begin();
        }

        Type& Back() {
            return *BackData.begin();
        }

        const Type& Back() const {
            return *BackData.begin();
        }

        // 7 PAR
        void PushFront(const Type& element) {
            FrontData.insert(FrontData.begin(), element);
        }

        void PushBack(const Type& element) {
            BackData.insert(BackData.begin(), element);
        }


        // GETTERS:
        vector<Type> GetVectorFront() const {
            return FrontData;
        }

        const size_t GetVectorFrontSize() const {
            return FrontData.length();
        }

        vector<Type> GetVectorBack() const {
            return BackData;
        }

        const size_t GetVectorBackSize() const {
            return BackData.length();
        }

    private:
        vector<Type> FrontData;
        vector<Type> BackData;
};




int main() {
    Deque<string> dq;
    return 0;
}

/*Compile error: b'/tmp/submissiona0hqcq59/tmp3luspdqv.cpp:56:24: fatal error: non-const lvalue reference to type \'int\' cannot bind to a temporary of type \'std::vector<int, std::allocator<int> >::iterator\' (aka \'__normal_iterator<int *, std::vector<int, std::allocator<int> > >\')
                return FrontData.end();
                                       ^~~~~~~~~~~~~~~
                                       /tmp/submissiona0hqcq59/tmp3luspdqv.cpp:177:19: note: in instantiation of member function \'Deque<int>::At\' requested here
                                         belts::Assert(d.At(0) == 5, "Wrong elements in deque after PushFront/PushBack");
                  ^
                  1 error generated.
                  '
*/
