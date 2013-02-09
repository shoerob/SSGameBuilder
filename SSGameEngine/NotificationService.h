//
//  NotificationService.h
//  SSGameEngine
//
//  Created by Robert Shoemate on 2/8/13.
//  Copyright (c) 2013 Robert Shoemate. All rights reserved.
//

#ifndef __SSGameEngine__NotificationService__
#define __SSGameEngine__NotificationService__

#include <iostream>
#include <list>

namespace SoftShoe {
    namespace Services {

        /**
         * INotificationSubscriber
         * Objects that want to subscribe to notifications should
         * implement this interface.
         */
        class INotificationSubscriber {
        public:
            INotificationSubscriber() { };
            ~INotificationSubscriber() { };
            
            virtual void OnNotificationReceived(std::string notificationName) = 0;
        };
        
        /**
         * NotificationService
         * This class broadcasts notifications to subscribing objects.
         */
        class NotificationService {
        public:
            NotificationService();
            ~NotificationService();
            
            void SendNotification(std::string notificationName);
            
            void AddSubscriber(INotificationSubscriber *subscriber);
            void RemoveSubscriber(INotificationSubscriber *subscriber);
            
            
        private:
            std::list<INotificationSubscriber *> subscribers;
            
        };
        
    }
}

#endif /* defined(__SSGameEngine__NotificationService__) */
