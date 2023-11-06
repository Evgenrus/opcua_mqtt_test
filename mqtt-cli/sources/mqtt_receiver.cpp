//
// Created by EVGEN on 30.10.23.
//

#include "../mqtt_receiver.h"

namespace elesy_mqtt_adapter {
    bool mqtt_receiver::connect() {
        try {
            client.connect()->wait();
            return true;
        } catch (const mqtt::exception &ex) {
            std::cerr << ex.what() << std::endl;
            return false;
        }
    }

    bool mqtt_receiver::disconnect() {
        try {
            client.disconnect()->wait();
            return true;
        } catch (const mqtt::exception &ex) {
            std::cerr << ex.what() << std::endl;
            return false;
        }
    }

    bool mqtt_receiver::subscribe(const std::string &topic, int QoS) {
        try {
            client.subscribe(topic, QoS, nullptr, listener)->wait();
            return true;
        } catch (const mqtt::exception &ex) {
            std::cerr << ex.what() << std::endl;
            return false;
        }
    }

    bool mqtt_receiver::unsubscribe(const std::string &topic) {
        try {
            client.unsubscribe(topic, mqtt::properties())->wait();
            return true;
        } catch (const mqtt::exception &ex) {
            std::cerr << ex.what() << std::endl;
            return false;
        }
    }

    mqtt_receiver::mqtt_receiver(mqtt::async_client &cli, opc_sender& sender, std::vector<Flow>& flows)
        : client(cli), listener("subscription"), cb(sender, flows) {
        client.set_callback(cb);
    }


} // elesy_mqtt_adapter