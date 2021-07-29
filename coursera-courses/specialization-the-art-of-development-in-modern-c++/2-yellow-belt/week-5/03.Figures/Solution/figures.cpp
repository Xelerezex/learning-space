#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>

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

std::shared_ptr<Figure> CreateFigure(std::istringstream& is) {
    std::string figure_name;
    is >> figure_name;

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! MAKE NORMAL OUTPUT
    //if (figure_name == "RECT") {
        double one, two;
        is >> one >> two;
        Rect t(figure_name, one, two);


    //}

    return std::make_shared<Figure>(t);
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
