#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


class Person {
public:
    Person(string profession, string name) : profession(std::move(profession)), name(std::move(name)) {}

    virtual void Walk(const string &destination) const {
        cout << Prefix() << name << " walks to: " << destination << endl;
    }

    const string profession;
    const string name;

protected:
    string Prefix() const {
        return profession + ": ";
    }
};

class Student : public Person {
public:

    Student(const string &name, string favouriteSong) :
            Person("Student", name),
            favouriteSong(std::move(favouriteSong)) {}

    void Learn() const {
        cout << Prefix() << name << " learns" << endl;
    }

    void Walk(const string &destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << Prefix() << name << " sings a song: " << favouriteSong << endl;
    }

private:
    const string favouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string &name, string subject) : Person("Teacher", name), subject(std::move(subject)) {}

    void Teach() const {
        cout << Prefix() << name << " teaches: " << subject << endl;
    }

private:
    const string subject;
};


class Policeman : Person {
public:
    explicit Policeman(const string &name) : Person("Policeman", name) {}

    void Check(const Person &p) const {
        cout << Prefix() << name << " checks " << p.profession << ". "
             << p.profession << "'s name is: " << p.name << endl;
    }
};


void VisitPlaces(const Person &p, const vector<string> &places) {
    for (const auto &place : places) {
        p.Walk(place);
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
