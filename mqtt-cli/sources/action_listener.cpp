//
// Created by EVGEN on 30.10.23.
//

#include <mqtt/token.h>

#include <utility>
#include "../action_listener.h"
#include "iostream"

namespace elesy_mqtt_adapter {
    void action_listener::on_failure(const mqtt::token &tok) {
        std::cout << name_ << " failure";
        if (tok.get_message_id() != 0)
            std::cout << " for token: [" << tok.get_message_id() << "]" << std::endl;
        std::cout << std::endl;
    }

    void action_listener::on_success(const mqtt::token &tok) {
        std::cout << name_ << " success";
        if (tok.get_message_id() != 0)
            std::cout << " for token: [" << tok.get_message_id() << "]" << std::endl;
        auto top = tok.get_topics();
        if (top && !top->empty())
            std::cout << "\ttoken topic: '" << (*top)[0] << "', ..." << std::endl;
        std::cout << std::endl;
    }

    action_listener::action_listener(std::string name) : name_(std::move(name)) { }
} // elesy_mqtt_adapter