#include "loggingevent.h"

namespace logdb {

InternalEventManager::InternalEventManager()
:evNumMax(MAX_EV_NUM)
{
}

InternalEventManager::~InternalEventManager()
{
    for (auto ptr : evList)
        delete ptr;
}

void InternalEventManager::doClearEv(LoggingEventPtr ev)
{
    InternalEventManager *manager = ev->manager;
    manager->clearEv(ev);
}

LoggingEventPtr InternalEventManager::getEmptyEv(bool alloc)
{   

    for(LoggingEventPtr& ptr : evList) {
        if(!ptr->inuse) {
            ptr->inuse = true;
            return ptr;
        }
    }

    if (alloc)
        return allocEv();

    return nullptr;
}

LoggingEventPtr InternalEventManager::allocEv()
{
    LoggingEventPtr ptr = nullptr;
    if (evList.size() < evNumMax) {
        ptr = new LoggingEvent;
        ptr->manager = this;
        evList.push_back(ptr);
    }

    return ptr;
}

void InternalEventManager::clearEv(LoggingEventPtr ev)
{
    ev->file.clear();
    ev->func.clear();
    ev->msg.clear();
    ev->line = 0;
    ev->inuse = false;
    ev->ll = DEFAULT;
    
}

void InternalEventManager::putEv(LoggingEventPtr ev)
{
    clearEv(ev);
}

}