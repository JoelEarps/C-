#include "mqtt.h"

using namespace std;

string MQTT::Decode(){
    return "MQTT";
}

void MQTT::setTopic(string m_topic) {
    Topic = m_topic;
}


string MQTT::getTopic() {
    return Topic;
}

ssize_t MQTT::processMessage(string m_message) {
    string tempMessage = m_message;
    
   /* if (tempMessage != m_message) {
        return 1;
    } else {
        return -1;
    } */
    cout << "Message being processed: " << m_message << endl;
    return 1;
}

