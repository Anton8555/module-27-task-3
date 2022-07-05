#pragma once

#include <cassert>
#include "human.h"

class MainWorker : public Human {
    // note: \0 - worker is free; A,B,C - the worker is busy with the corresponding task.
    char taskType = '\0';
public:
    // constructors
    MainWorker();

    // setters
    void setTaskType(char inTaskType);

    // getters
    char getTaskType() const;
};
