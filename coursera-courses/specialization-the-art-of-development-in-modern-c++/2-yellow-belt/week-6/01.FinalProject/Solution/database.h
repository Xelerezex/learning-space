#pragma once


#include "headers.h"
#include "date.h"

using DBType = map<Date, vector<string>>;

class Database {
    public:
        void Add(const Date& date, const string& event);
        void Print(ostream& os) const;

        template <typename Func>
        int RemoveIf(Func eval);

        DBType GetAllData() const;
    private:
        DBType DataBaseStorage;
};

template <typename Func>
int Database::RemoveIf(Func eval) {
    int number_out = 1;

    for (auto& [key, value] : DataBaseStorage) {
        size_t old_size = value.size();

        if (old_size > 1) {
            auto new_end = remove_if(value.begin(), value.end(), [key, eval](string event){
                return eval(key, event);
            });
            value.erase(new_end, value.end());

            number_out =  static_cast<int>(old_size - value.size());
        } else {

            // Так нельзя, ошибка стека. Надо понять как удалять значения внутри мапы
            DataBaseStorage.erase(key);
        }
    }

    return number_out;
}

ostream& operator << (ostream& os, const DBType& DB);

string ParseEvent(istream& is);
