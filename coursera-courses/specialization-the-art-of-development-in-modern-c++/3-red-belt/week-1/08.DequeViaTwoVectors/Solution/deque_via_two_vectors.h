#pragma once

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
        Type& operator[](size_t index) {
            bool cond1 = FrontData.empty();
            bool cond2 = BackData.empty();

            if (!cond1 && !cond2) {

                if (index < FrontData.size()) {
                    auto iter = (FrontData.end() - 1) - static_cast<int>(index);
                    return *iter;

                } else if (index >= FrontData.size()) {

                    return BackData[static_cast<int>(index) - (FrontData.size())];
                }
            } else if (cond1 && !cond2) {
                return BackData[static_cast<int>(index)];
            } else if (!cond1 && cond2) {
                auto iter = (FrontData.end() - 1) - static_cast<int>(index);
                return *iter;
            }
        }

        const Type& operator[](size_t index) const  {
            bool cond1 = FrontData.empty();
            bool cond2 = BackData.empty();

            if (!cond1 && !cond2) {

                if (index < FrontData.size()) {
                    auto iter = (FrontData.end() - 1) - static_cast<int>(index);
                    return *iter;

                } else if (index >= FrontData.size()) {

                    return BackData[static_cast<int>(index) - (FrontData.size())];
                }
            } else if (cond1 && !cond2) {
                return BackData[static_cast<int>(index)];
            } else if (!cond1 && cond2) {
                auto iter = (FrontData.end() - 1) - static_cast<int>(index);
                return *iter;
            }
        }

        // 5 PAR
/*        Type& At(size_t index) {

        }*/

/*        const Type& At(size_t index) const {

        }*/

        // 6 PAR
         Type& Front() {
            return FrontData.back();
        }

        const Type& Front() const {
            return FrontData.back();
        }

        Type& Back() {
            return BackData.back();
        }

        const Type& Back() const {
            return BackData.back();
        }

        // 7 PAR
        void PushFront(const Type& element) {
            FrontData.push_back(element);
        }

        void PushBack(const Type& element) {
            BackData.push_back(element);
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
