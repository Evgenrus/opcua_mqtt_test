//
// Created by EVGEN on 30.10.23.
//

#include "../callback.h"

void elesy_mqtt_adapter::callback::connected(const mqtt::string &msg) {
    std::cout << "Connected" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}

void elesy_mqtt_adapter::callback::connection_lost(const mqtt::string &) {
    std::cerr << "\t\tConnection lost";
    std::cerr << "---------------------------------------------------------" << std::endl;
}

void elesy_mqtt_adapter::callback::delivery_complete(mqtt::delivery_token_ptr) { }

void elesy_mqtt_adapter::callback::message_arrived(mqtt::const_message_ptr msg) {
    std::cout << "Message arrived" << std::endl;
    std::cout << "\tTOPIC: " << msg->get_topic() << std::endl;
    std::cout << "\tPAYLOAD: " << msg->to_string() << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    try {
        for (const auto& flow : flows) {
            if (flow.Topic == msg->get_topic()) {
                auto parsed = std::stoi(msg->to_string());

                sender.send_int(parsed, flow.NamespaceIndex, flow.Identifier);
            }
        }
    } catch(std::exception &ex) {
        std::cerr << ex.what() <<std::endl;
    }
}

elesy_mqtt_adapter::callback::callback(opc_sender &send, std::vector<Flow> &flow)
    : sender(send), flows(flow) { }
