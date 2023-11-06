//
// Created by EVGEN on 30.10.23.
//

#ifndef MQTT_TO_OPCUA_ACTION_LISTENER_H
#define MQTT_TO_OPCUA_ACTION_LISTENER_H

#include "mqtt/iaction_listener.h"

namespace elesy_mqtt_adapter {

    class action_listener : public virtual mqtt::iaction_listener {
        std::string name_;

        void on_failure(const mqtt::token &asyncActionToken) override;
        void on_success(const mqtt::token &asyncActionToken) override;

    public:
        action_listener(std::string  name);
    };

} // elesy_mqtt_adapter

#endif //MQTT_TO_OPCUA_ACTION_LISTENER_H
