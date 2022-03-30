#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

   /* //basic map - char key with int value
    map<string, string> dictionary;
     
    dictionary.insert(pair<string, string>("apple", "der Apfel"));
    dictionary.insert(pair<string, string>("banana", "die Banane"));
    dictionary.insert(pair<string, string>("orange", "die Orange, die Apfelsine"));
    dictionary.insert(pair<string, string>("strawberry", "die Erdbeere"));

    //first and second property
    //erase elemeent
   // dictionary.erase()
   //check if a map is empty

    cout << dictionary.size() << endl;
    //type is map<type,type>::iterator
    //this will get a squiggle but it is just a warning
    for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr ) {
        //so now we have a pointer to all these different paris
        //so to access we have to dereference
        cout << itr->first << endl ;
        cout << (*itr).second << endl;
        //or 
        
    } */

    //so test program for a map

    string test = "Hello my name is Joel - Waaaaaaaaaahhhhaaa";

    map<char, int> freq;

    for (int i=0; i < test.length(); ++i){
        char letter = test[i];

        if (freq.find(letter) == freq.end()) {
            freq[letter] = 0;
        }

        freq[letter]++;
        cout << freq[letter] << ", " << letter << endl;
    }




    return 0;

}