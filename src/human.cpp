#include "human.h"

// constructors
Human::Human() {}

// setters
void Human::setName(const string &inName) { name = inName; }
void Human::setID(int inID) { ID = inID; }

// getters
string Human::getName() const { return name; }
int Human::getID() const { return ID; }
