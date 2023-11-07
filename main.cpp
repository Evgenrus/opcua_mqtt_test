#include <iostream>
#include "mqtt/async_client.h"
#include "mqtt-cli/callback.h"
#include "mqtt-cli/mqtt_receiver.h"
#include "libconfig.h++"

#include "data/ConfigReader.h"
#include "open62541pp/open62541pp.h"

using namespace elesy_mqtt_adapter;

int main(int argc, char* argv[]) {
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