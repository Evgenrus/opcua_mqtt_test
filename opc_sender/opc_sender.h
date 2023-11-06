//
// Created by EVGEN on 31.10.23.
//

#ifndef MQTT_TO_OPCUA_OPC_SENDER_H
#define MQTT_TO_OPCUA_OPC_SENDER_H

#include "open62541pp/open62541pp.h"
#include "../data/Flow.h"

namespace elesy_mqtt_adapter {

    /**
     * @brief class for resending messages to OPC-UA server
     */
    class opc_sender {
    private:
        opcua::Client client; // free62541pp client

    public:
        /**
         * @brief disconnect from OPC-UA server
         */
        void disconnect();
        /**
         * @brief send int value to Node
         *
         * @param msg value
         * @param namesp namespace index of Node
         * @param ident identity of Node
         */
        void send_int(const int &msg, uint16_t namesp, const std::string& ident);

        explicit opc_sender(const std::string &endpoint);
    };

} // elesy_mqtt_adapter

#endif //MQTT_TO_OPCUA_OPC_SENDER_H
