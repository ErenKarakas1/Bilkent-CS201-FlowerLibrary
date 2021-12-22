#include <iostream>
#include "FlowerList.h"
using namespace std;


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

bool FlowerList::retrieve(string flowerName, Flower& flower) const {
    FlowerNode* found = findFlower( flowerName );

    if ( found == NULL ) {
        return false;
    }
    else {
        flower = found->f;
        return true;
    }
}

bool FlowerList::add(string flowerName) {
    FlowerNode* found = findFlower( flowerName );
    if ( found != NULL ) {
        return false;
    }

    if ( isEmpty() ) {
        head = new FlowerNode;
        Flower curr = Flower(flowerName);
        
        head->f = curr;
        head->next = NULL;

        ++size;

        return true;
    }

    FlowerNode* temp = head;

    while ( temp != NULL ) {
        if ( flowerName > temp->f.getName() ) {
            break;
        }
        temp = temp->next;
    }

    FlowerNode* newNode = new FlowerNode;
    Flower curr = Flower( flowerName );

    newNode->f = curr;
    newNode->next = temp->next;

    temp->next = newNode;

    delete found;
    found, temp = NULL;

    ++size;
    return true;
}

bool FlowerList::remove(string flowerName) {
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
