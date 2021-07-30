#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person (const string& name, const string& type)
        : Name_(name)
        , type_(type) {}

    virtual void Walk(const string& destination) const {
        cout << Intro() << " walks to: " << destination << endl;
    }

    string GetName() const {
        return Name_;
    }

    string GetType() const {
        return type_;
    }

    string Intro() const {
        return type_ + ": " + Name_;
    }

protected:
    const string Name_;
    const string type_;
};


class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong)
        : Person(name, "Student")
        , FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << Intro() << " learns" << endl;
    }

    void Walk(const string& destination) const {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << Intro() << " sings a song: " << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject)
        : Person(name, "Teacher")
        , Subject(subject) {}

    void Teach() const {
        cout << Intro() << " teaches: " << Subject << endl;
    }

public:
    const string Subject;
};

class Policeman : public Person {
public:
    Policeman(const string& name)
        : Person (name, "Policeman") {}

    void Check(const Person& person) const {
        cout << Intro() << " checks " << person.GetType() << ". " << person.GetType()
            << "'s name is: " << person.GetName() << endl;
    }

};

void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
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
