#include <iostream>
#include "FlowerList.h"
using namespace std;
/*
Eren KARAKAS
22002722
*/


FlowerList::FlowerList() {
    head = NULL;
    size = 0;
}

FlowerList::FlowerList(const FlowerList& aList) {
    size = aList.size;

    if ( aList.head == NULL ) {
        head = NULL;
    }
    else {
        head = new FlowerNode;
        head->f = aList.head->f;

        FlowerNode* node = head;

        for ( FlowerNode* curr = aList.head->next; curr != NULL; curr = curr->next ) {
            node->next = new FlowerNode;
            node = node->next;
            node->f = curr->f;
        }

        node->next = NULL;
    }
}

FlowerList::~FlowerList() {
    FlowerNode* node = head;

    while ( node != NULL ) {
        head = head->next;
        delete node;
        node = head;
    }

    head = NULL;
}

bool FlowerList::isEmpty() const {
    return head == NULL;
}

int FlowerList::getLength() const {
    return size;
}

string* FlowerList::getFlowerNames() const {
    int index = 0;
    string* names = new string[size];
    FlowerNode* temp = head;

    while ( temp != NULL ) {
        names[index] = temp->f.getName();
        temp = temp->next;
        ++index;
    }

    return names;
}

bool FlowerList::retrieve( string flowerName, Flower& flower ) const {
    FlowerNode* found = findFlower( flowerName );

    if ( found == NULL ) {
        return false;
    }
    else {
        FlowerNode* curr = head;

        while ( curr != NULL ) {
            if ( flowerName == curr->f.getName() ) {
                break;
            }
            curr = curr->next;
        }

        flower = curr->f;
        return true;
    }
}

bool FlowerList::add( string flowerName ) {
    FlowerNode* found = findFlower( flowerName );

    if ( found != NULL ) {
        return false;
    }

    if ( isEmpty() ) {
        head = new FlowerNode;
        Flower curr = Flower( flowerName );
        
        head->f = curr;
        head->next = NULL;

        ++size;

        return true;
    }

    FlowerNode* curr = head;
    FlowerNode* prev = NULL;

    while ( curr != NULL ) {
        if ( flowerName < curr->f.getName() ) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    FlowerNode* newNode = new FlowerNode;
    Flower newFlower = Flower( flowerName );

    newNode->f = newFlower;
    newNode->next = curr;

    if ( prev == NULL ) {
        head = newNode;

    }
    else {
        prev->next = newNode;
    }

    delete found;
    found, curr, prev = NULL;

    ++size;
    return true;
}

bool FlowerList::remove( string flowerName ) {
    FlowerNode* found = findFlower( flowerName );
    
    if ( found == NULL ) {
        return false;
    }

    if ( found == head ) {
        head = found->next;
    }
    else {
        FlowerNode* prev = head;

        while ( prev->next != found ) {
            prev = prev->next;
        }

        prev->next = found->next;
    }

    delete found;
    found = NULL;

    --size;
    return true;
}

void FlowerList::replace( Flower& flower ) {
    FlowerNode* curr = head;

    while ( curr != NULL ) {
        if ( flower.getName() == curr->f.getName() ) {
            break;
        }
        curr = curr->next;
    }
    curr->f = flower;

}

string FlowerList::printFlowers() const {
    string output = "";
    FlowerNode* temp = head;

    while ( temp != NULL ) {
        output += temp->f.printFlower();
        temp = temp->next;
    }

    temp = NULL;
    return output;
}

FlowerList& FlowerList::operator=( FlowerList& right ) {
    if ( &right != this ) {
        FlowerNode* node = head;

        while ( node != NULL ) {
            head = head->next;
            delete node;
            node = head;
        }

        head = NULL;

        size = right.size;

        if ( right.head == NULL ) {
            head = NULL;
        }
        else {
            head = new FlowerNode;
            head->f = right.head->f;

            FlowerNode* node = head;

            for ( FlowerNode* curr = right.head->next; curr != NULL; curr = curr->next ) {
                node->next = new FlowerNode;
                node = node->next;
                node->f = curr->f;
            }

            node->next = NULL;
        }
    }
    return *this;
}

FlowerList::FlowerNode* FlowerList::findFlower( const string flowerName ) const {
    if ( !isEmpty() ) {
        FlowerNode* temp = head;

        while ( temp != NULL ) {
            if ( flowerName == temp->f.getName() ) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}
