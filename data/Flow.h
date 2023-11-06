//
// Created by EVGEN on 06.11.23.
//

#ifndef MQTT_TO_OPCUA_FLOW_H
#define MQTT_TO_OPCUA_FLOW_H

#include <string>
#include "nlohmann/json.hpp"

namespace elesy_mqtt_adapter {

    /**
     * @brief Class for serializing "flow.json" configuration file
     *
     * flow allows user to define message redirection from message from MQTT topic to OPC-UA node
     */
    class Flow {
    public:
        std::string Topic; //MQTT topic
        std::string Identifier; // OPC-UA Node identifier
        uint16_t    NamespaceIndex; //OPC-UA Node namespace index
    };
} // elesy_mqtt_adapter

#endif //MQTT_TO_OPCUA_FLOW_H
