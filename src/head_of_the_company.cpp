#include "head_of_the_company.h"

// getters
int HeadOfTheCompany::countMiddleManagers() const {
    return (int)middleManagers.size();
}

MiddleManager* HeadOfTheCompany::getMiddleManagerAt(int index) const {
    if( index < 0 ) return nullptr;
    if( index >= middleManagers.size() ) return nullptr;

    return middleManagers[index];
}

// methods

/*!
 * @brief Subroutine cleaning object.
 */
void HeadOfTheCompany::Clear() {
    for(auto manager: middleManagers)
        if( manager != nullptr ) {
            manager->Clear();
            delete manager;
        }
    middleManagers.clear();
    this->setName("none");
}

/*!
 * @brief Subroutine for adding a manager to the list.
 * @param mainWorker - manager.
 */
void HeadOfTheCompany::middleManagerAdd(MiddleManager* middleManager) {
    middleManagers.push_back(middleManager);
}

/*!
 * @brief A subroutine for distributing tasks to groups.
 * @param task - integer job identifier.
 * @return Returns the number of workers given the job.
 */
int HeadOfTheCompany::run(int task) {
    int count = 0;

    for(const auto manager: middleManagers)
        count += manager->run(task);

    return count;
}

/*!
 * @brief A subroutine that prints the employment status of workers to the console.
 */
void HeadOfTheCompany::printReport() const {
    for(const auto manager: middleManagers) {
        cout << "Team manager name: " << manager->getName() << endl;
        for(int i=0; i<manager->countMainWorkers(); i++) {
            auto worker = manager->getMainWorkerAt(i);
            char type = worker->getTaskType();
            cout
                    << "  Worker #" << (i+1) << ": " << worker->getName() << endl
                    << "    Task type: " << (type=='\0'?'-':type) << endl;
        }// end of for-i2
    }// end of for-i
}

/*!
 * @brief Subroutine for calculating the number of free workers.
 * @return Returns the number of free workers.
 */
int HeadOfTheCompany::numberOfUnemployed() const {
    int count = 0;

    for(const auto manager: middleManagers) {
        for(int i=0; i<manager->countMainWorkers(); i++) {
            auto worker = manager->getMainWorkerAt(i);
            if( worker->getTaskType() == '\0' )
                count++;
        }// end of for-i2
    }// end of for-i

    return count;
}
