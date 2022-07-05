#pragma once

#include <string>
using namespace std;

class Human {
    int ID = 0;
    string name;
public:
    // constructors
    Human();

    // setters
    void setName(const string &inName);
    void setID(int inID);

    // getters
    string getName() const;
    int getID() const;
};