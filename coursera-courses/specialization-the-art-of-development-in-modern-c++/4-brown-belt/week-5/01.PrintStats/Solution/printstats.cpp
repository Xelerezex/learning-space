void PrintStats(vector<Person> persons)
{
    std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << std::endl;;

    std::cout << "Median age for females = "
    << ComputeMedianAge(persons.begin(), std::partition(persons.begin(), persons.end(),
        [] (const Person& person) {
            return person.gender == Gender::FEMALE;
        }))
    << std::endl;

    std::cout << "Median age for males = "
    << ComputeMedianAge(persons.begin(), std::partition(persons.begin(), persons.end(),
        [] (const Person& person) {
            return person.gender == Gender::MALE;
        }))
    << std::endl;

    std::cout << "Median age for employed females = "
    << ComputeMedianAge(persons.begin(), std::partition(persons.begin(), persons.end(),
        [](const Person& person) {
            return person.gender == Gender::FEMALE && person.is_employed == true;
        }))
    << std::endl;

    std::cout << "Median age for unemployed females = "
    << ComputeMedianAge(persons.begin(), std::partition(persons.begin(), persons.end(),
        [](const Person& person) {
            return person.gender == Gender::FEMALE && person.is_employed == false;
        }))
    << std::endl;

    std::cout << "Median age for employed males = "
    << ComputeMedianAge(persons.begin(), std::partition(persons.begin(), persons.end(),
        [](const Person& person) {
            return person.gender == Gender::MALE && person.is_employed == true;
        }))
    << std::endl;

    std::cout << "Median age for unemployed males = "
    << ComputeMedianAge(persons.begin(), std::partition(persons.begin(), persons.end(),
        [](const Person& person) {
            return person.gender == Gender::MALE && person.is_employed == false;
        }))
    << std::endl;
}
