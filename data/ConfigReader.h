//
// Created by EVGEN on 06.11.23.
//

#ifndef MQTT_TO_OPCUA_CONFIGREADER_H
#define MQTT_TO_OPCUA_CONFIGREADER_H

#include "iostream"
#include "nlohmann/json.hpp"
#include "Flow.h"
#include "Config.h"

namespace elesy_mqtt_adapter {

    /**
     * @brief Class for parsing "flow.json" file
     */
    class ConfigReader {
    public:
        ConfigReader();

        /**
         * @brief Parses flow config file
         *
         * @param file path to config file
         * @return vector of @see Flow
         */
        static std::vector<Flow> ParseFlowConfig(const std::string &file);

        static Config ParseAppConfig(const std::string &file);
    };

} // mqtt_adapter

#endif //MQTT_TO_OPCUA_CONFIGREADER_H
