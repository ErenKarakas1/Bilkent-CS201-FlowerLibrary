#include <iostream>
#include "FlowerLibrary.h"
using namespace std;


FlowerLibrary::FlowerLibrary() {
    FlowerList flowerList = FlowerList();
    flowers = flowerList;
}

FlowerLibrary::~FlowerLibrary() {

}

void FlowerLibrary::addFlower( string name ) {
    string lowercase_name = translate( name );
  	
    if ( !flowers.add(lowercase_name ) ) {
        cout << lowercase_name << " cannot be added into the library because it already exists." << endl;
    }
    else {
        cout << lowercase_name << " has been added into the library." << endl;
    }
}

void FlowerLibrary::removeFlower( string name ) {
    string lowercase_name = translate( name );

    cout << lowercase_name;
    if ( flowers.remove(lowercase_name ) ) {
        cout << " has been removed from the library." << endl;
    }
    else {
        cout << "  cannot be removed because it's not in the library." << endl;
    }
}

void FlowerLibrary::listFlowers() const {
    if ( !flowers.isEmpty() ) {
        cout << flowers.printFlowers();
    }
    else {
        cout << "Library is empty.";
    }
}

void FlowerLibrary::listFeatures(string name) const {
    Flower flower;
    string lowercase_name = translate( name );
    
    if ( !flowers.retrieve(lowercase_name, flower ) ) {
        cout << lowercase_name << " isn't found in library" << endl;
    }
    else {
        cout << flower.printFlower();
    }
}

void FlowerLibrary::addFeature( string name,string feature ) {
    Flower flower;
    string lowercase_name = translate( name );
    string lowercase_feature = translate( feature );

    if ( !flowers.retrieve( lowercase_name, flower ) ) {
        cout << lowercase_name << " isn't found in library" << endl;
    }
    else {
        if ( !flower.add(lowercase_feature ) ) {
            cout << lowercase_feature << " already exists in " << lowercase_name << endl;
        }
        else {
            cout << lowercase_feature << " is added into " << lowercase_name << endl;
        }
    }
}

void FlowerLibrary::removeFeature( string name, string feature ) {
    Flower flower;
    string lowercase_name = translate( name );
    string lowercase_feature = translate( feature );

    if ( !flowers.retrieve(lowercase_name, flower ) ) {
        cout << lowercase_name << " isn't found in library" << endl;
    }
    else {
        if ( !flower.remove(lowercase_feature ) ) {
            cout << lowercase_feature << " doesn't exist in " << lowercase_name << endl;
        }
        else {
            cout << lowercase_feature << " is removed from " << lowercase_name << endl;
        }
    }
}

void FlowerLibrary::findFlowers( string feature ) const {
    Flower flower;

    int size = flowers.getLength();
    string* flowerNames = flowers.getFlowerNames();
  
    string lowercase_feature = translate( feature );
    string output = lowercase_feature + " flowers: ";

    for ( int i = 0; i < size; ++i ) {
        flowers.retrieve( flowerNames[i], flower );
        if ( flower.featureExists( lowercase_feature ) ) {
            output += flower.getName() + ", ";
        }
    }

    if ( output == lowercase_feature + " flowers: " ) {
        output += "there is no such flower";
    }
    else {
        output = output.substr( 0, output.length() - 2 );
    }

    delete [] flowerNames;
    cout << output << endl;
}

string FlowerLibrary::translate( string name ) const {
    string name_copy = name;

    for ( int i = 0; i < name.length(); ++i ) {
  		name_copy[i] = tolower( name[i] );
  	}

    return name_copy;
}