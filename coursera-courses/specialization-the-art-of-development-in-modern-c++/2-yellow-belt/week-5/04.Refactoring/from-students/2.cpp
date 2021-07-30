#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
    Human(const string& name, const string& type = "Human") : name_(name), type_(type) {}
    virtual void Walk(const string& destination) const{
        cout << introducement_ << " walks to: " << destination << endl;
    }
    string GetName() const { return name_; }
    string GetType() const { return type_; }

protected:
    string name_;
    string type_;
    string introducement_ = type_ + ": " + name_;
};


class Student : public Human {
public:
    Student(string name, string favouriteSong) : Human(name, "Student"),
        _favouriteSong(favouriteSong) { }

    void Learn() {
        cout << introducement_ << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << introducement_ << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << introducement_ << " sings a song: " << _favouriteSong << endl;
    }

private:
    string _favouriteSong;
};


class Teacher : public Human{
public:

    Teacher(string name, string subject) : Human(name, "Teacher"), _subject(subject) {}

    void Teach() {
        cout << introducement_ << " teaches: " << _subject << endl;
    }

private:
    string _subject;
};


class Policeman : public Human {
public:
    Policeman(string name) : Human(name, "Policeman") {}

    void Check(const Human& h) {
        cout << introducement_ << " checks " << h.GetType() << ". " << h.GetType() << "'s name is: " << h.GetName() << endl;
    }

};


void VisitPlaces(const Human& h, vector<string> places) {
    for (auto p : places) {
        h.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}
