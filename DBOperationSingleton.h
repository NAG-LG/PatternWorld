#ifndef DB_OPERATION_SINGLETON_H
#define DB_OPERATION_SINGLETON_H

#include <iostream>
#include <mutex>

class DBOperationClass{
public:
    void Print(){
        std::cout<<"DBOperationClass print function"<<std::endl;
    }
    DBOperationClass(){
        std::cout<<"DBOperationClass constructor function"<<std::endl;
    }
    ~DBOperationClass(){
        std::cout<<"DBOperationClass destructor function"<<std::endl;
    }
};

class DBOperationSingleton : public DBOperationClass
{
    private:
        DBOperationSingleton();
        virtual ~DBOperationSingleton();
        DBOperationSingleton(const DBOperationSingleton&)=delete;
        DBOperationSingleton& operator=(DBOperationSingleton&) = delete;

    public:
        static DBOperationSingleton *static_object;
        static std::mutex DBOperationSingleton_lock;
        static DBOperationSingleton* getInstance();
        static bool releaseInstance();
};

#endif // DB_OPERATION_SINGLETON_H
