# MQTT to OPC-UA resender

Программа которая переотправляет сообщения, полученные по MQTT на сервер OPC-UA.

## Использование

Для работы программы нужно заполнить два конфигурационных json файла: 
### config.json

Содержит основную конфигурацию для программы.
1. *mqtt_host* — адрес MQTT брокера
2. *client_id* — ID клиента для брокера MQTT
3. *qos* — MQTT Quality of Service (QoS)
4. *opc_host* — адрес OPC-UA сервера
5. *flowfile* — расположение flow.json файла

Пример:

```json
{
  "config" : {
    
    "mqtt_host": "tcp://localhost:1883",
    "client_id": "test_id",
    "qos": 1,
    "opc_host": "opc.tcp://localhost:4840/",
    "flowfile": "flow.json"
  }
}
```

### flow.json
Содержит настройки для пересылки сообщений из MQTT брокера в OPC-UA сервер
1. *topic* — Топик полученного сообщения
2. *node_identifier* — OPC-UA Node identifier
3. *namespace_index* — OPC-UA Node namespace

Пример:
```json
{
  "flows": [
    {
      "topic": "sensors/test1",
      "node_identifier": "testone",
      "namespace_index": 1
    },
    {
      "topic": "sensors/test2",
      "node_identifier": "testtwo",
      "namespace_index": 1
    }
  ]
}
```

## TODO

1. Добавить логгер
2. MQTT and OPC-UA Authentification

## Зависимости

1. [*eclipse/paho.mqtt.cpp*](https://github.com/eclipse/paho.mqtt.cpp) — MQTT C++ client library
2. [*open62541*](https://github.com/open62541/open62541) — Open source implementation of OPC UA (OPC Unified Architecture) aka IEC 62541 licensed under Mozilla Public License v2.0
3. [*open62541pp*](https://github.com/open62541pp/open62541pp) — C++ wrapper of the open62541 OPC UA library
4. [*nlohmann/json*](https://github.com/nlohmann/json) — JSON for Modern C++
