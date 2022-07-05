#include <iostream>
#include <string>
#include "head_of_the_company.h"
using namespace std;

int main() {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // data
    HeadOfTheCompany head;
    string nameHead;
    int countID,countTeam;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // initialization

    countID = 0;
    // name input
    cout << "Enter name head of the company:";
    cin >> nameHead;
    head.setName(nameHead);
    head.setID(countID++);
    // count team input
    cout << "Enter the number of commands:";
    cin >> countTeam;
    // team create
    for(int i=0; i<countTeam; i++) {
        // data
        auto manager = new MiddleManager();
        string nameManager;
        int countWorkers;
        // name input
        cout << "Enter name middle manager:";
        cin >> nameManager;
        manager->setName(nameManager);
        manager->setID(countID++);
        // count workers input
        cout << "Enter the number of employees in " << nameManager << " is manager's team:";
        cin >> countWorkers;
        // worker create
        for(int i2=0; i2<countWorkers; i2++) {
            // data
            auto worker = new MainWorker();
            string nameWorker;
            // name input
            cout << "Enter name worker:";
            cin >> nameWorker;
            worker->setName(nameWorker);
            worker->setID(countID++);
            // adding an employee to a team
            manager->mainWorkerAdd(worker);
        }// end of for-i2
        // adding a manager with employees to the company
        head.middleManagerAdd(manager);
    }// end of for-i

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // output result
    cout
        << "\n\nInitialization result:\n"
        << "Company head name: " << head.getName() << endl;
    for(int i=0; i<head.countMiddleManagers(); i++) {
        auto manager = head.getMiddleManagerAt(i);
        cout
            << "  Team #" << (i+1) << endl
            << "  Team manager name: " << manager->getName() << endl;
        for(int i2=0; i2<manager->countMainWorkers(); i2++) {
            cout << "    Worker #" << (i2+1) << ": " << manager->getMainWorkerAt(i2)->getName() << endl;
        }// end of for-i2
    }// end of for-i

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // work
    do{
        // data
        int task,count;

        // task input
        cout << "\n>";
        cin >> task;

        // run
        count = head.run(task);

        // output employment of workers
        cout << "Number of tasks taken: " << count << endl;
        head.printReport();
    }
    // terminate the program when all workers are busy with tasks.
    while( head.numberOfUnemployed() > 0 );

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    head.Clear();

    return 0;
}
