//
// Created by EVGEN on 31.10.23.
//

#include <iostream>
#include "../opc_sender.h"
#include "../exceptions/opc_sender_exceptions.h"

namespace elesy_mqtt_adapter {

    void opc_sender::disconnect() {
        if(!client.isConnected())
            throw ClientNotConnectedException("client is not connected");

        client.disconnect();
    }

    void opc_sender::send_int(const int &msg, const uint16_t namesp, const std::string& ident) {
        auto node = client.getNode({namesp, ident});

        node.writeValueScalar(msg);
    }

    opc_sender::opc_sender(const std::string &endpoint) {
        client.connect(endpoint);
    }

} // elesy_mqtt_adapter