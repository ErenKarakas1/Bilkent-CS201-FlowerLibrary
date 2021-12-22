#include <iostream>
#include "Flower.h"
using namespace std;


Flower::Flower() {
    head = NULL;
    size = 0;
    this->flowerName = "";
}

Flower::Flower( string flowerName ) {
    head = NULL;
    size = 0;
    this->flowerName = flowerName;
}

Flower::Flower( const Flower& aFlower ) {
    size = aFlower.size;
    flowerName = aFlower.flowerName;

    if ( aFlower.head == NULL ) {
        head = NULL;
    }
    else {
        head = new FeatureNode;
        head->feature = aFlower.head->feature;

        FeatureNode* node = head;

        for ( FeatureNode* curr = aFlower.head->next; curr != NULL; curr = curr->next ) {
            node->next = new FeatureNode;
            node = node->next;
            node->feature = curr->feature;
        }

        node->next = NULL;
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

bool Flower::add( string feature ) {
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
        FeatureNode* curr = head;
        FeatureNode* prev = NULL;

        while ( curr != NULL ) {
            if ( feature < curr->feature ) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        FeatureNode* newNode = new FeatureNode;

        newNode->feature = feature;
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
}

bool Flower::remove( string feature ) {
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
            output += temp->feature + ", ";
            temp = temp->next;
        }
    }

    if ( output == flowerName + ": " ) {
        output += "No feature\n";
    }
    else {
        output = output.substr( 0, output.length() - 2 ) + "\n";
    }

    return output;
}

bool Flower::featureExists( string feature ) const {
    FeatureNode* found = findFeature( feature );

    return found != NULL;
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

        size = aFlower.size;
        flowerName = aFlower.flowerName;

        if ( aFlower.head == NULL ) {
            head = NULL;
        }
        else {
            head = new FeatureNode;
            head->feature = aFlower.head->feature;

            FeatureNode* node = head;

            for ( FeatureNode* curr = aFlower.head->next; curr != NULL; curr = curr->next ) {
                node->next = new FeatureNode;
                node = node->next;
                node->feature = curr->feature;
            }

            node->next = NULL;
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