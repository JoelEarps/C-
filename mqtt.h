#include "messageClass.h"
#pragma once

using namespace std;

class MQTT : public messageProtocol {
    private:

    string Topic;
    
    public:

    string Decode();
    void setTopic(string Topic);
    string getTopic();
    ssize_t processMessage(string message);

};