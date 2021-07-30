#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human{
public:
    Human(const string& name, const string& type)
        : Name(name), Type(type) {}

    virtual void Walk(const string& destination) const = 0;

    string getName() const{
        return Name;
    }
    string getType() const{
        return Type;
    }
private:
    const string Name;
    const string Type;
};

class Student : public Human {
public:

    Student(const string& name, const string& favouriteSong)
        : Human(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const{
        cout << "Student: " << getName() << " learns" << endl;
    }

    void Walk(const string& destination) const override{
        cout << "Student: " << getName() << " walks to: " << destination << endl;
        cout << "Student: " << getName() << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const{
        cout << "Student: " << getName() << " sings a song: " << FavouriteSong << endl;
    }
private:
    const string FavouriteSong;
};


class Teacher : public Human{
public:

    Teacher(const string& name, const string& subject)
    : Human(name, "Teacher"), Subject(subject){
    }

    void Teach() const{
        cout << "Teacher: " << getName() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override{
        cout << "Teacher: " << getName() << " walks to: " << destination << endl;
    }

private:
    const string Subject;
};


class Policeman : public Human{
public:
    Policeman(const string& name)
    : Human(name, "Policeman"){}

    void Check(const Human& h){
        cout << "Policeman: " << getName() << " checks " << h.getType() << ". " << h.getType() << "'s name is: " << h.getName() << endl;
    }

    void Walk(const string& destination) const override{
        cout << "Policeman: " << getName() << " walks to: " << destination << endl;
    }
};

void VisitPlaces(const Human& h, const vector<string>& places){
    for (auto p : places) {
        h.Walk(p);
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
