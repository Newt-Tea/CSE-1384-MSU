#include <string>

using std::string;

#ifndef ANIMAL_H
#define ANIMAL_H


class Animal
{
    private:
        string name, type;
        int age;
        float weight;

    public:
        // constructors
        Animal();
        Animal(string name, string type, int age, float weight);

        // getters
        string getName();
        string getType();
        int getAge();
        float getWeight();

        // setters
        void setName(string name);
        void setType(string type);
        void setAge(int age);
        void setWeight(float weight);
};

#endif // ANIMAL_H
