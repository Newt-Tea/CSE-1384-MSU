#include "animal.h"

Animal::Animal()
{
    name = "";
    type = "";
    age = 0;
    weight = 0.0;
}

Animal::Animal(string name, string type, int age, float weight)
{
    this->name = name;
    this->type = type;
    this->age = age;
    this->weight = weight;
}

// getters
string Animal::getName()
{
    return name;
}

string Animal::getType()
{
    return type;
}

int Animal::getAge()
{
    return age;
}

float Animal::getWeight()
{
    return weight;
}

// setters
void Animal::setName(string name)
{
    this->name = name;
}

void Animal::setType(string type)
{
    this->type = type;
}

void Animal::setAge(int age)
{
    this->age = age;
}

void Animal::setWeight(float weight)
{
    this->weight = weight;
}
