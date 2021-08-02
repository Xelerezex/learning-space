#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Parent's class
class Person {
public:
    Person(const string& name, const string& role = "human")
        : _Name(name), _RoleInSociety(role) {};

    virtual void Walk(const string& destination) const
    {
        Activity(cout, "walks to", destination) << endl;
    }
    ostream& Activity(ostream& out, const string& strAct,
        const string& strObject = "", const string& strSeparate_1 = ": ") const
    {
        out << this->_RoleInSociety << strSeparate_1 << this->_Name << " "
            << strAct;
        if (!strObject.empty())
        {
            out << strSeparate_1 << strObject;
        }
        return out;
    }
    virtual string GetName() const { return _Name; }
    virtual string GetRoleInSociety() const { return _RoleInSociety; }

protected:
    // You can't change Name and RoleInSociety
    const string _Name;
    const string _RoleInSociety;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong,
            const string& role = "Student")
        : Person(name, role)
        , _FavouriteSong(favouriteSong) {}

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        // Students like to sing
        SingSong();
    }

    void Learn() const {
        Activity(cout, "learns") << endl;
    }

    void SingSong() const {
        Activity(cout, "sings a song", _FavouriteSong) << endl;
    }

    string GetFavouriteSong() const { return _FavouriteSong; }

private:
    const string _FavouriteSong;
};

class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject,
            const string& role = "Teacher")
        : Person(name, role)
        , _Subject(subject) { }

    void Teach() const {
        Activity(cout, "teaches", _Subject) << endl;
    }

    string GetSubject() const { return _Subject; }

private:
    const string _Subject;
};

class Policeman : public Person {
public:
    Policeman(const string& name, const string& role = "Policeman")
        : Person(name, role) { }

    void Check(const Person& person) const {
        Activity(cout, "checks", person.GetRoleInSociety()) << ". ";
        person.Activity(cout, "", "", "'s name is: ") << endl;
    }
};

// This function allows people to walk in different  places
void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    p.Check(t);
    return 0;
}
