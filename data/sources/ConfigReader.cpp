//
// Created by EVGEN on 06.11.23.
//

#include "../ConfigReader.h"
#include "fstream"
#include "../Flow.h"

namespace elesy_mqtt_adapter {
    ConfigReader::ConfigReader() = default;

    void from_json(nlohmann::json const &j, Flow& f) {
        j.at("topic").get_to(f.Topic);
        j.at("node_identifier").get_to(f.Identifier);
        j.at("namespace_index").get_to(f.NamespaceIndex);
    }

    void from_json(nlohmann::json const &j, Config &c) {
        j.at("mqtt_host").get_to(c.MqttHost);
        j.at("client_id").get_to(c.ClientId);
        j.at("qos").get_to(c.QoS);
        j.at("opc_host").get_to(c.OpcEndpoint);
        j.at("flowfile").get_to(c.FlowFile);
    }

    std::vector<Flow> ConfigReader::ParseFlowConfig(const std::string &file) {
        std::ifstream f(file);

       auto js = nlohmann::json::parse(f);

       std::vector<Flow> flows;
       js.at("flows").get_to(flows);

       return flows;
    }

    Config ConfigReader::ParseAppConfig(const std::string &file) {
        std::ifstream f(file);

        auto js = nlohmann::json::parse(f);

        Config conf;
        js.at("config").get_to(conf);

        return conf;
    }
} // mqtt_adapter
