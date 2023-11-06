//
// Created by EVGEN on 30.10.23.
//

#ifndef MQTT_TO_OPCUA_MQTT_RECEIVER_H
#define MQTT_TO_OPCUA_MQTT_RECEIVER_H

#include <mqtt/async_client.h>
#include "callback.h"



namespace elesy_mqtt_adapter {

    /**
     * @brief Class for connectiong to MQTT broker and receive messages
     */
    class mqtt_receiver {
    private:
        mqtt::async_client &client; ///< paho.mqtt.cpp client class
        callback cb; ///< callback for processing arrived messages and other events
        action_listener listener;

    public:
        /**
         * @brief Connect to MQTT broker
         *
         * @return true, if connection successful, false otherwise
         */
        bool connect();
        /**
         * @brief Disconnect from MQTT broker
         *
         * @return true, if disconnect was successful, false otherwise
         */
        bool disconnect();
        /**
         * @brief subscribe to topic
         *
         * @param topic Topic pattern
         * @param QoS Quality of service
         * @return true, if subscription was successful, false otherwise
         */
        bool subscribe(const std::string& topic, int QoS);
        /**
         * @brief Unsubscribe receiver from topic
         *
         * @param topic Topic path
         * @return
         */
        bool unsubscribe(const std::string& topic);
        /**
         *
         * @param cli paho.mqtt.cpp client
         * @param retry number of reconnect tries
         * @param opts connection options
         */
        explicit mqtt_receiver(mqtt::async_client &cli, opc_sender& sender, std::vector<Flow>& flows);
    };

} // elesy_mqtt_adapter

#endif //MQTT_TO_OPCUA_MQTT_RECEIVER_H
