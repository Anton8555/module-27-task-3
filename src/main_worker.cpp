#include "main_worker.h"

// constructors
MainWorker::MainWorker() {}

// setters
void MainWorker::setTaskType(char inTaskType) {
    assert( (inTaskType == 'A') || (inTaskType == 'B') || (inTaskType == 'C') );

    taskType = inTaskType;
}

// getters
char MainWorker::getTaskType() const { return taskType; }
