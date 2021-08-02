#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person (const string& type, const string& name)
        : Type(type), Name(name){
        }

    virtual void Walk(const string& destination) const {
        DoAction("walks to", destination);
    }

protected:
    void DoAction(const string& action, const string& object) const {
        cout << Type << ": " << Name << " " << action;
        if (!object.empty()) {
            cout << " " << object;
        }
        cout << endl;
    }

public:
    const string Type;
    const string Name;
};


class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong)
        : Person("Student", name), FavouriteSong(favouriteSong) {
    }

    void Walk(const string& destination) const override {
        DoAction("walks to", destination);
        SingSong();
    }

    void SingSong() const {
        DoAction("sings a song", FavouriteSong);
    }

    void Learn() const {
        DoAction("learns", "");
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject)
        : Person("Teacher", name), Subject(subject) {
    }

    void Teach() const {
        DoAction("teaches", Subject);
    }

private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name)
        : Person("Policeman", name) {
    }

    void Check(Person& p) const {
        cout << Type << ": " << Name << " checks " << p.Type << ". " << p.Type << "'s name is: " << p.Name << endl;
    }
};


void VisitPlaces(const Person& t, const vector<string>& places) {
    for (auto& p : places) {
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
