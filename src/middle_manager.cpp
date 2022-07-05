#include "middle_manager.h"

// getters
int MiddleManager::countMainWorkers() const {
    return (int)workers.size();
}

MainWorker* MiddleManager::getMainWorkerAt(int index) const {
    if( index < 0 ) return nullptr;
    if( index >= workers.size() ) return nullptr;

    return workers[index];
}

// methods

/*!
 * @brief Subroutine cleaning object.
 */
void MiddleManager::Clear() {
    for(auto worker: workers)
        if( worker != nullptr )
            delete worker;
    workers.clear();
    this->setName("none");
}

/*!
 * @brief Subroutine for adding a worker to the list.
 * @param mainWorker - worker.
 */
void MiddleManager::mainWorkerAdd(MainWorker* mainWorker) {
    workers.push_back(mainWorker);
}

/*!
 * @brief The subroutine for distributing tasks to workers.
 * @param task - integer job identifier.
 * @return Returns the number of workers given the job.
 */
int MiddleManager::run(int task) {
    // generating number of tasks
    int hash = task + this->getID();
    srand(hash);
    int tasksCount = rand() % (this->workers.size() + 1);
    int count = 0;  // counter the number of tasks taken by the team

    // distribution of tasks to free workers
    for(int i=0; i<tasksCount; i++) {
        // free worker search cycle
        for(auto worker: workers)
            // if a free worker is found
            if (worker->getTaskType() == '\0') {
                // then give it a task
                worker->setTaskType((char) ((int) 'A' + rand() % 3));
                count++;
                break;
            }// end of if()
    }// end of for-i

    return count;
}
