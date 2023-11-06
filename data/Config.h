//
// Created by EVGEN on 06.11.23.
//

#ifndef MQTT_TO_OPCUA_CONFIG_H
#define MQTT_TO_OPCUA_CONFIG_H

#include <string>

namespace elesy_mqtt_adapter {

    class Config {
    public:
        std::string MqttHost;
        std::string ClientId;
        int QoS;
        std::string OpcEndpoint;
        std::string FlowFile;
    };

} // elesy_mqtt_adapter

#endif //MQTT_TO_OPCUA_CONFIG_H
