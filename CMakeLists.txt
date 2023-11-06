cmake_minimum_required(VERSION 3.26)
project(mqtt_to_opcua)

set(CMAKE_CXX_STANDARD 23)

find_package(open62541pp CONFIG REQUIRED)

add_subdirectory(3rdparty/json)
add_subdirectory(3rdparty/paho.mqtt.c)
add_subdirectory(3rdparty/paho.mqtt.cpp)

find_package(OpenSSL REQUIRED)
find_package(open62541 REQUIRED COMPONENTS Events)
find_library(paho-mqttpp3 NAMES libpaho-mqttpp3.a REQUIRED)
find_library(paho-mqtt3a NAMES libpaho-mqtt3a.so REQUIRED)

add_library(pahottpp STATIC IMPORTED)
set_target_properties(pahottpp PROPERTIES IMPORTED_LOCATION ${paho-mqttpp3})

add_library(pahomqtt3a SHARED IMPORTED)
set_property(TARGET pahomqtt3a PROPERTY IMPORTED_LOCATION ${paho-mqtt3a})

find_package(OpenSSL REQUIRED)

add_executable(mqtt_to_opcua main.cpp
        mqtt-cli/sources/action_listener.cpp
        mqtt-cli/action_listener.h
        mqtt-cli/sources/callback.cpp
        mqtt-cli/callback.h
        mqtt-cli/sources/mqtt_receiver.cpp
        mqtt-cli/mqtt_receiver.h
        opc_sender/sources/opc_sender.cpp
        opc_sender/opc_sender.h
        opc_sender/exceptions/opc_sender_exceptions.h
        data/sources/ConfigReader.cpp
        data/ConfigReader.h
        data/Flow.h
        data/Config.h
)

target_link_libraries(mqtt_to_opcua pahottpp)
target_link_libraries(mqtt_to_opcua pahomqtt3a)
target_link_libraries(mqtt_to_opcua open62541)
target_link_libraries(mqtt_to_opcua open62541pp)
target_link_libraries(mqtt_to_opcua nlohmann_json)