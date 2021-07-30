#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>

class Figure {
    public:
        Figure(const std::string& name) : name_(name) {}

        virtual std::string Name() const = 0;
        virtual double Perimeter() = 0;
        virtual double Area() = 0;

        std::string GetName() const {
            return name_;
        }
    private:
        const std::string name_;
};

class Triangle : public Figure {
    public:
        Triangle(const std::string& name, const double& fpart, const double& spart, const double& tpart) : Figure(name), fpart_(fpart), spart_(spart), tpart_(tpart) {}

        std::string Name() const override {
            return GetName();
        }

        double Perimeter() override {
            return (fpart_ + spart_ + tpart_);
        }

        double Area() override {
            double p = Perimeter() / 2;
            return sqrt(p * (p - fpart_) * (p - spart_) * (p - tpart_));
        }

    private:
        const double fpart_;
        const double spart_;
        const double tpart_;
};

class Rect : public Figure {
    public:
        Rect(const std::string& name, const double& width, const double& height) : Figure(name), width_(width), height_(height) {}

        std::string Name() const override {
            return GetName();
        }

        double Perimeter() override {
            return (width_ + height_) * 2;
        }

        double Area() override {
            return width_ * height_;
        }

    private:
        const double width_;
        const double height_;
};

class Circle : public Figure {
    public:
        Circle(const std::string& name, const double& radius) : Figure(name), radius_(radius) {}

        std::string Name() const override {
            return GetName();
        }

        double Perimeter() override {
            return 2 * (3.14 * radius_);
        }

        double Area() override {
            return 3.14 * radius_ * radius_;
        }

    private:
        const double radius_;
};

std::shared_ptr<Figure> CreateFigure(std::istringstream& is) {
    std::string figure_name;
    std::shared_ptr<Figure> figure;

    is >> figure_name;

    if (figure_name == "TRIANGLE") {
        double one, two, three;
        is >> one >> two >> three;
        Triangle tr(figure_name, one, two, three);

        figure = std::make_shared<Triangle>(tr);
    } else if (figure_name == "RECT") {
        double one, two;
        is >> one >> two;
        Rect t(figure_name, one, two);

        figure = std::make_shared<Rect>(t);
    } else {
        double one;
        is >> one;
        Circle c(figure_name, one);

        figure = std::make_shared<Circle>(c);
    }

    return figure;
}

int main() {
    std::vector<std::shared_ptr<Figure>> figures;

    for (std::string line; getline(std::cin, line);) {

        std::istringstream is(line);

        std::string command;

        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> std::ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                std::cout << std::fixed << std::setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << std::endl;
            }
        }
    }
    return 0;
}
