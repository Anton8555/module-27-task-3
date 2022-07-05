#pragma once

#include "human.h"
#include "main_worker.h"
#include <vector>
using namespace std;

class MiddleManager : public Human {
    vector<MainWorker*> workers;
public:
    // getters
    int countMainWorkers() const;
    MainWorker* getMainWorkerAt(int index) const;

    // methods
    void Clear();
    void mainWorkerAdd(MainWorker* mainWorker);
    int run(int task);
};