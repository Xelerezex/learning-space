#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class People {
public:

    People(const string& t = "Nobody", const string& p = "unemployed"):Name(t), Profession(p){
    }

    virtual void Walk(const string& dest) const = 0;

    string GetName() const {
        return Name;
    }

    string GetProfession() const{
        return Profession;
    }

private:
    string Name;
    string Profession;
};

class Student :public People {
public:

    Student(const string& name, const string& favouriteSong):People(name, "Student") {
        FavouriteSong = favouriteSong;
    }

    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override{
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

public:
    string FavouriteSong;
};


class Teacher :public People {
public:

    Teacher(const string& name, const string& subject):People(name, "Teacher") {
        Subject = subject;
    }

    void Teach() const {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override{
        cout << "Teacher: " << GetName() << " walks to: " << destination << endl;
    }

public:
    string Subject;
};


class Policeman :public People {
public:
    Policeman(const string& name):People(name, "Policeman"){}

    void Check(People& t) const {
        cout << "Policeman: " << GetName() << " checks " << t.GetProfession() << ". " << t.GetProfession() <<
            "'s name is: " << t.GetName() << endl;
    }
    void Walk(const string& destination) const override{
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }

};


void VisitPlaces(People& t, vector<string> places) {
    for (const auto& p : places) {
        t.Walk(p);
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
