//
// Created by EVGEN on 30.10.23.
//

#ifndef MQTT_TO_OPCUA_CALLBACK_H
#define MQTT_TO_OPCUA_CALLBACK_H

#include "mqtt/async_client.h"
#include "action_listener.h"
#include "../opc_sender/opc_sender.h"

namespace elesy_mqtt_adapter {
    /**
     * @author Evgenii Petukhov
     *
     * callback for handling MQTT events
     */
    class callback : public virtual mqtt::callback {
        opc_sender sender;
        std::vector<Flow> flows;
        /**
         * @brief Called when connection with broker has been established
         *
         * @param msg Received message
         */
        void connected(const mqtt::string &msg) override;

        /**
         * @brief called when connection with broker has been lost
         *
         * @param Received message
         */
        void connection_lost(const mqtt::string &msg) override;
        /**
         * @brief Called when message delivery has been completed
         *
         * @param tok pointer to delivery token
         */
        void delivery_complete(mqtt::delivery_token_ptr tok) override;
        /**
         * @brief Called when message from broker has been delivered
         *
         * @param msg
         */
        void message_arrived(mqtt::const_message_ptr msg) override;

    public:
        callback(opc_sender &send, std::vector<Flow> &flow);
    };
}

#endif //MQTT_TO_OPCUA_CALLBACK_H
