//packages required

#include <iostream>
#include "mqtt.h"
#include "ble.h"

#include <chrono>
#include <thread>
#include <ctime>  

#include <queue>

using namespace std;

//incoming message 1
string testMessage[3] = {"Test","Array", "Pass"};
int arrSize = sizeof(testMessage)/sizeof(testMessage[0]);

//incoming message 2
string testMessage2[4] = {"Example", "for", "multi", "threading"};
int arrSize2 = sizeof(testMessage)/sizeof(testMessage[0]);

//global message queue (would originally be stored in memory)
queue<string> mqttMessageQueue;
//mutex to stop the queue being accessed at once
mutex queueLock;

//function responsible for adding incoming messages to the processing queue
void MQTTQueue(MQTT mqtt){

    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    auto start = chrono::system_clock::now();
    time_t startTime = chrono::system_clock::to_time_t(start);

    cout << "Time thread started adding to the queue: " << ctime(&startTime) << endl;

    lock_guard<mutex> lock(queueLock);

    vector<string> returnedData = mqtt.getData();

    for (int i = 0; i < returnedData.size(); i++) {
        mqttMessageQueue.push(returnedData[i]);
    }  
        
    sleep_for(seconds(rand() % 5));

    auto end = chrono::system_clock::now();
    time_t endTime = chrono::system_clock::to_time_t(end);
    cout << "Time thread finished adding to the queue: " << ctime(&endTime) <<  endl;
    
}

// processes each element of the queue until it is empty. This function can be called by any object - as the MQTT messages could be processed
//however required rather than individually by each class

void processMQTT(queue<string> messages, MQTT mqtt) {

    while (!messages.empty())
    {
        cout << "Queue length is: " << messages.size() << " ";
        ssize_t processSuccess = mqtt.processMessage(messages.front());
        if (processSuccess == -1) {
            cout << "Processing of Message failed";
            return;
        }
        messages.pop();
    
    } 
    return;
}



int main() {

    cout << "Hello, welcome to my C++ messaging system!" << endl;

    //insantiate derived classes from abstract class
    MQTT mqtt1;
    MQTT mqtt2;
    BLE ble1;

    mqtt1.setPort(123);
    mqtt1.setID(111);
    mqtt1.setSource("MQTT Sensor 1");
    mqtt1.setData(testMessage, arrSize);

    mqtt2.setPort(999);
    mqtt2.setID(000);
    mqtt2.setSource("MQTT Sensor 2");
    mqtt2.setData(testMessage2, arrSize2);

    ble1.setPort(456);
    ble1.setID(222);
    ble1.setSource("Sensor 2");
    
    //MQTT class infromation
    cout << "The message Protocol is : " << mqtt1.Decode() << endl;
    cout << "MQTT Message Source is: " << mqtt1.getSource() << endl;
    cout << "MQTT Port is: " << mqtt1.getPort() << endl;
    cout << "MQTT Message ID is: " << mqtt1.getID() << endl;
    cout << "MQTT Data is : ";
    
    vector<string> returnedData = mqtt1.getData();

    //BLE class information
    cout << "The message Protocol is : " << ble1.Decode() << endl;
    cout << "BLE Message Source is: " << ble1.getSource() << endl;
    cout << "BLE Port is: " << ble1.getPort() << endl;
    cout << "BLE Message ID is: " << ble1.getID() << endl;

    //two threads to simulate two incoming messages
    thread th1 (MQTTQueue, mqtt1);
    thread th2 (MQTTQueue, mqtt2);

    th1.join();
    th2.join();

    processMQTT(mqttMessageQueue, mqtt1);
    
    

    return 0;
}

