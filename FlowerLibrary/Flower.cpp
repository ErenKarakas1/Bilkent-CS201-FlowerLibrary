#include <iostream>
#include "Flower.h"
using namespace std;


Flower::Flower() {
    head = NULL;
    size = 0;
}

Flower::Flower(string flowerName) {
    head = NULL;
    size = 0;
    this->flowerName = flowerName;
}

Flower::Flower(const Flower& aFlower) {
    this->flowerName = aFlower.flowerName;

    if (aFlower.head == NULL) {
        head = NULL;
    }
    else {
        head = new FeatureNode;
        head->feature = aFlower.head->feature;
        head->next = aFlower.head->next;

        FeatureNode* temp = aFlower.head->next;
        FeatureNode* curr = head;

        while ( temp != NULL ) {
            curr->next = new FeatureNode;
            curr->next->feature = temp-> feature;
            temp = temp->next;
            curr = curr->next;
        }

        curr->next = NULL;
    }
}

Flower::~Flower() {
    FeatureNode* node = head;

    while ( node != NULL ) {
        head = head->next;
        delete node;
        node = head;
    }

    head = NULL;
}

bool Flower::isEmpty() const {
    return head == NULL;
}

int Flower::getLength() const {
    return size;
}

string Flower::getName() const {
    return flowerName;
}

bool Flower::add(string feature) {
    FeatureNode* found = findFeature( feature );

    if ( found != NULL ) {
        return false;
    }

    if ( isEmpty() ) {
        head = new FeatureNode;

        head->feature = feature;
        head->next = NULL;
        
        ++size;

        return true;
    }
    else {
        FeatureNode* temp = head;

        while ( temp != NULL ) {
            if ( feature > temp->feature ) {
                break;
            }
            temp = temp->next;
        }

        FeatureNode* newNode = new FeatureNode;

        newNode->feature = feature;
        newNode->next = temp->next;

        temp->next = newNode;

        delete found;
        found, temp = NULL;
        
        ++size;
        return true;
    }
}

bool Flower::remove(string feature) {
    FeatureNode* found = findFeature( feature );

    if ( found == NULL ) {
        return false;
    }

    if ( found == head ) {
        head = found->next;
    }
    else {
        FeatureNode* prev = head;

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

string Flower::printFlower() const {
    string output = flowerName + ": ";

    if ( !isEmpty() ) {
        FeatureNode* temp = head;

        while ( temp != NULL ) {
            output += temp->feature + " ";
            temp = temp->next;
        }
    }

    output += "\n";
    return output;
}

Flower& Flower::operator=( Flower& aFlower ) {
    if ( &aFlower != this ) {
        FeatureNode* node = head;

        while ( node != NULL ) {
            head = head->next;
            delete node;
            node = head;
        }

        head = NULL;

        this->flowerName = aFlower.flowerName;

        if ( aFlower.head == NULL ) {
            head = NULL;
        }
        else {
            head = new FeatureNode;
            head->feature = aFlower.head->feature;
            head->next = aFlower.head->next;

            FeatureNode* temp = aFlower.head->next;
            FeatureNode* curr = head;

            while ( temp != NULL ) {
                curr->next = new FeatureNode;
                curr->next->feature = temp-> feature;
                temp = temp->next;
                curr = curr->next;
            }

            curr->next = NULL;
        }
    }
    return *this;
}

Flower::FeatureNode* Flower::findFeature( const string feature ) const {
    if ( !isEmpty() ) {
        FeatureNode* temp = head;

        while ( temp != NULL ) {
            if ( feature == temp->feature ) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}
