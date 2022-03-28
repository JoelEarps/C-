#include "messageClass.h"

using namespace std;

int messageProtocol::getPort(){
    return port;
}

void messageProtocol::setPort(int m_port){
    port = m_port;
}

int messageProtocol::getID(){
    return ID;
}

void messageProtocol::setID(int m_id){
    ID = m_id;
}

void messageProtocol::setSource(string m_source) {
    Source = m_source;
}

string messageProtocol::getSource() {
    return Source;
}

void messageProtocol::setData(string m_data[], int m_dataSize){
    //so with an array of items - size must be passed from where the data is defined - so requires pre processing
    //when passed to the function it gets passed as a pointer so doing byte logic would return 0
    for (int i = 0; i < (m_dataSize); i++){
        data.push_back(m_data[i]);
    } 
}

vector<string> messageProtocol::getData() {
    return data;
}