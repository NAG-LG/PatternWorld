#include <iostream>
#include "DBOperationSingleton.h"
using namespace std;


void singletonExperiments();
int main()
{
    singletonExperiments();
    return 0;
}

void singletonExperiments(){
    DBOperationSingleton *ptr= DBOperationSingleton::getInstance();
    DBOperationSingleton *ptr1= DBOperationSingleton::getInstance();
    ptr->Print();
    ptr1->Print();
    DBOperationSingleton::releaseInstance();

    DBOperationSingleton *ptr3= DBOperationSingleton::getInstance();
    ptr3->Print();
    DBOperationSingleton::releaseInstance();
}
