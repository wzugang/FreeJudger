
#ifndef IMUST_OJ_TASK_MANAGER_H
#define	IMUST_OJ_TASK_MANAGER_H

#include <list>

#include "../util/Utility.h"
#include "../platformlayer/PlatformLayer.h"
#include "../thread/Thread.h"

namespace IMUST
{

class JUDGER_API ITask
{
public:
    ITask();
    virtual ~ITask();

    virtual bool run() = 0;
};

class JUDGER_API TaskManager
{
public:
    TaskManager();
    ~TaskManager();

    void lock();
    void unlock();

    bool hasTask();
    void addTask(ITask *task);
    ITask *popTask();

private:
    typedef std::list<ITask *> TaskListType;
    TaskListType taskList_;

    Mutex   mutex_;
};





}   // namespace IMUST

#endif  // IMUST_OJ_TASK_MANAGER_H