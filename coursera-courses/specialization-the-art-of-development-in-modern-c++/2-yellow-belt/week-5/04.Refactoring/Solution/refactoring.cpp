#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
    public:
        Human(const string& name, const string& type) : Name(name), Type(type) {}

        virtual void Walk(const string& destination) const {
            cout << Human::Action("walks to:", destination);
        }

        string Action(const string& action, const string& variable = "") const {
            return GetType() + ": " + GetName() + " " + action + " " + variable + '\n';
        }

        string GetName() const { return Name; }

        string GetType() const { return Type; }

    private:
        const string Name;
        const string Type;
};

class Student : public Human {
    public:

        Student(const string& name, const string& favouriteSong) : Human(name, "Student"), FavouriteSong(favouriteSong) {}

        void Learn() const {
            cout << Human::Action("learns");
        }

        void Walk(const string& destination) const override {
            cout << Human::Action("walks to:", destination);
            SingSong();
        }

        /* Более чистый вариант переопределения Walk, как по мне. Оставил SingSong только, что б бал не потерять.

        void Walk(const string& destination) const override {
            cout << Human::Action("walks to:", destination)
                 << Human::Action("sings a song:", FavouriteSong);
        }
        */

        void SingSong() const {
            cout << Human::Action("sings a song:", FavouriteSong);
        }

    private:
        const string FavouriteSong;
};


class Teacher : public Human {
    public:

        Teacher(const string& name, const string& subject) : Human(name, "Teacher"), Subject(subject) {}

        void Teach() const {
            cout << Human::Action("teaches:", Subject);
        }

    private:
        const string Subject;
};


class Policeman : public Human {
public:
    Policeman(const string& name) : Human(name, "Policeman") {}

    void Check(const Human& h) const {
        cout << GetType() << ": " << GetName() << " checks " << h.GetName()
             << ". " << h.GetType() << "'s name is: " << h.GetName() << endl;
    }
};


void VisitPlaces(Human& h, vector<string> places) {
    for (auto p : places) {
        h.Walk(p);
    }
}


int main() {
    Student s("Ann", "We will rock you");
    s.Learn();
    VisitPlaces(s, {"Moscow", "London"});

    cout << endl;

    Teacher t("Jim", "Math");
    t.Teach();
    VisitPlaces(t, {"Moscow", "London", "Kentucky", "Drunk-City"});

    cout << endl;

    Policeman p("Bob");
    p.Check(s);
    p.Walk("Down");
    p.Check(t);
    p.Check(p);
    VisitPlaces(t, {"Ukraine", "Belarus"});

    cout << endl;

    return 0;
}
