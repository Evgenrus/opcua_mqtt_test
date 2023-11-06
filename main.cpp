#include <iostream>
#include "mqtt/async_client.h"
#include "mqtt-cli/callback.h"
#include "mqtt-cli/mqtt_receiver.h"
#include "libconfig.h++"

#include "data/ConfigReader.h"
#include "open62541pp/open62541pp.h"

const std::string SERVER_ADDRESS("tcp://localhost:1883");
const std::string CLIENT_ID("test_id");
const std::string TOPIC("test");

const int QoS = 1;
const int retry = 10;

using namespace elesy_mqtt_adapter;

int main() {
    std::string file = "config.json";

    try {
        auto config = ConfigReader::ParseAppConfig(file);
        auto flows = ConfigReader::ParseFlowConfig(config.FlowFile);

        opc_sender sender(config.OpcEndpoint);

        mqtt::async_client client(config.MqttHost, config.ClientId);
        mqtt::connect_options opts;
        opts.set_clean_session(false);

        mqtt_receiver receiver(client, sender, flows);
        receiver.connect();

        for (const auto& flow : flows) {
            receiver.subscribe(flow.Topic, 1);
        }

        while(std::cin.get() != 'q') {}
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}