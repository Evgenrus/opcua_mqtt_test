//
// Created by EVGEN on 03.11.23.
//

#ifndef MQTT_TO_OPCUA_OPC_SENDER_EXCEPTIONS_H
#define MQTT_TO_OPCUA_OPC_SENDER_EXCEPTIONS_H

#include <exception>
#include <utility>

namespace elesy_mqtt_adapter {

    class ClientNotConnectedException : std::exception {
    public:
        ClientNotConnectedException(std::string message) : message{std::move(message)} {}
        ClientNotConnectedException() {}

        [[nodiscard]]
        const char* what() const noexcept override {
            return message.c_str();
        }
    private:
        std::string message; //сообщение об ошибке
    };

} // elesy_mqtt_adapter

#endif //MQTT_TO_OPCUA_OPC_SENDER_EXCEPTIONS_H
