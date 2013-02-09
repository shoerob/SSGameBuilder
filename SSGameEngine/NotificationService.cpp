//
//  NotificationService.cpp
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/8/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#include "NotificationService.h"

using namespace SoftShoe::Services;

NotificationService::NotificationService() {
    
}

NotificationService::~NotificationService() {
    
}

void NotificationService::SendNotification(std::string notificationName) {    
    for (std::list<INotificationSubscriber *>::iterator it = subscribers.begin(); it != subscribers.end(); ++it) {
        (*it)->OnNotificationReceived(notificationName);
    }
}

void NotificationService::AddSubscriber(SoftShoe::Services::INotificationSubscriber *subscriber) {
    this->subscribers.push_back(subscriber);
}

void NotificationService::RemoveSubscriber(SoftShoe::Services::INotificationSubscriber *subscriber) {
    this->subscribers.remove(subscriber);
}