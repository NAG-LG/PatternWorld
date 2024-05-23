#include "DBOperationSingleton.h"

DBOperationSingleton *DBOperationSingleton::static_object=nullptr;
std::mutex DBOperationSingleton::DBOperationSingleton_lock;

DBOperationSingleton::DBOperationSingleton()
{
}

DBOperationSingleton::~DBOperationSingleton()
{
}

 DBOperationSingleton* DBOperationSingleton::getInstance(){
    if(DBOperationSingleton::static_object == nullptr){
       std::lock_guard<std::mutex> guard(DBOperationSingleton::DBOperationSingleton_lock);
       if(DBOperationSingleton::static_object == nullptr){
           DBOperationSingleton::static_object = new DBOperationSingleton();
       }
    }
    return DBOperationSingleton::static_object;
}

 bool DBOperationSingleton::releaseInstance(){
     if(DBOperationSingleton::static_object!= nullptr){
       std::lock_guard<std::mutex> guard(DBOperationSingleton_lock);
       if(DBOperationSingleton::static_object != nullptr){
           delete DBOperationSingleton::static_object;
           DBOperationSingleton::static_object = nullptr;
       }
    }
    return true;
}
