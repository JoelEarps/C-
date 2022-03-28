#include <iostream>
#include <vector>
#include <string>
#pragma once

using namespace std;

class messageProtocol
{

private: 
    vector<string> data;
    int ID;
    int port;
    string Source;

public:
    virtual string Decode() = 0; //Virtual function - each comms method requires different message unpacking
    void setPort(int P);
    int getPort();
    void setID(int id);
    int getID();
    void setSource(string source);
    string getSource();
    void setData( string data[], int dataSize);
    vector<string> getData();

};

