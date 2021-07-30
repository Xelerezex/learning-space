#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const float pi = 3.14;

class Figure {
public:
  Figure(const string& type)
      : Type(type) {}

  virtual string Name() = 0;
  virtual float Perimeter() = 0;
  virtual long double Area() = 0;

  // Виртуальный деструктор.
  // При отсутствии проблем компиляции данного решения строка не является
  // необходимой и может быть опущена.
  // А вот что такое виртуальный деструктор - Вы узнаете уже на черном поясе.
  virtual ~Figure() = default;

  const string Type;
};

class Rect : public Figure {
public:
  Rect(int& w, int& h)
      : Figure("RECT")
      , P(2 * w + 2 * h)
      , S(w * h) {
  }

  float Perimeter() override {
    return P;
  }
  long double Area() override {
    return S;
  }
  string Name() override {
    return Type;
  }
private:
  int P;
  double S;
};

class Circle : public Figure {
public:
  Circle (int& r)
      : Figure("CIRCLE")
      , P(2 * pi * r)
      , S(pi * r * r) {}

  float Perimeter() override {
    return P;
  }
  long double Area() override {
    return S;
  }
  string Name() override {
    return Type;
  }
private:
  float P;
  double S;
};

class Triangle : public Figure {
public:
  Triangle(int& a, int& b, int& c)
      : Figure("TRIANGLE") {
    P = a + b + c;
    S = sqrtl((P/2)*(P/2 - a)*(P/2 - b)*(P/2 - c));
  }

  float Perimeter() override {
    return P;
  }
  long double Area() override {
    return S;
  }
  string Name() override {
    return Type;
  }
private:
  float P;
  long double S;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
  shared_ptr<Figure> fig;

  string figure_name;
  is >> figure_name;
  if(figure_name == "RECT") {
    int a, b;
    is >> a >> b;
    fig = make_shared<Rect>(a, b);
    return fig;
  }
  if (figure_name == "TRIANGLE") {
    int a, b, c;
    is >> a >> b >> c;
    fig = make_shared<Triangle>(a, b, c);
    return fig;
  }
  if (figure_name == "CIRCLE") {
    int r;
    is >> r;
    fig = make_shared<Circle>(r);
    return fig;
  }
  throw std::invalid_argument("invalid figure name was specified");
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
