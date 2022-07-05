#pragma once

#include "human.h"
#include "middle_manager.h"
#include <iostream>
#include <vector>
using namespace std;

class HeadOfTheCompany : public Human {
    vector<MiddleManager*> middleManagers;
public:
    // getters
    int countMiddleManagers() const;
    MiddleManager* getMiddleManagerAt(int index) const;

    // methods
    void Clear();
    void middleManagerAdd(MiddleManager* middleManager);
    int run(int task);
    void printReport() const;
    int numberOfUnemployed() const;
};