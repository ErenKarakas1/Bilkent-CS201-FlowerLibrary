#include "Flower.h"
using namespace std;
/*
Eren KARAKAS
22002722
*/


class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;

    // getters
    int getLength() const;
    string* getFlowerNames() const;

    // other necessary methods
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    void replace(Flower& flower);
    
    string printFlowers() const;
    FlowerList& operator=( FlowerList& right );

private:
    struct FlowerNode{
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head;
    FlowerNode* findFlower(string flowerName) const;

//the flowers are stored in a sorted singly linear linked list
// ...
//you may define additional member functions and data members, if necessary
};