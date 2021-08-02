#include <iostream>
#include <string>
#include <vector>

using namespace std;

//имена/песни/предметы обучения делаем сделаем константными, дабы защитить от случайных изменений
//константность оправдана нынешней задачей, ее легко изменить при корректировке постановленной задачи, к тому же она позволяет не пользоваться акцессорами, что сохраняет часть производительности
//используя объекты аргументами функций, необходимо считывать их через (константные) ссылки -> необходимо пометить методы константностью
//добавив в класс-родитель константное поле данных "профессия", я избавился от перегрузок метода Check в полицейском
//функция walk спокойно размещается в класс-родитель после описанных выше изменений, сокращая код

class Human{
public:
    void Walk(string destination) const{
        cout << profession << ": " << Name << " walks to: " << destination << endl;
    }
    Human(const string& _profession, const string& _name) : profession(_profession), Name(_name){}

    const string profession, Name;
};

class Student : public Human{
public:
    Student(const string& name, const string& favouriteSong) : Human("Student", name), FavouriteSong(favouriteSong) {}

    void Learn() const{
        cout << "Student: " << Name << " learns" << endl;
    }

    void SingSong() const{
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    const string FavouriteSong;
};


class Teacher : public Human{
public:
    Teacher(const string& name, const string& subject) : Human("Teacher", name), Subject(subject) {
    }

    void Teach() const{
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    const string Subject;
};


class Policeman : public Human{
public:
    Policeman(const string& name) : Human("Policeman", name){}

    void Check(const Human& t) const{
        cout << "Policeman: " << Name << " checks " << t.profession << ". " << t.profession << "'s name is: " << t.Name << endl;
    }
};


void VisitPlaces(const Human& t, const vector<string>& places) {
    for (auto p : places) {
        t.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
