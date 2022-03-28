#include <string>
#include <iostream>

class Animal
{
public:
    virtual std::string Voice() const
    {
        return "Not implemented yet";
    }
    virtual ~Animal()
    {
    }
};


class Tiger: public Animal
{
    std::string Voice() const override
    {
        return "Rrrr";
    }
    public:
        ~Tiger()
        {
            std::cout << "Tiger deleted!" << std::endl;
        }
};


class Wolf: public Animal
{
    std::string Voice() const override
    {
        return "Wooo";
    }
    public:
        ~Wolf()
        {
            std::cout << "Wolf deleted!" << std::endl;
        }
};


class Fox: public Animal
{
    std::string Voice() const override
    {
        return "Tyaf";
    }
    public:
        ~Fox()
        {
            std::cout << "Fox deleted!" << std::endl;
        }
};

