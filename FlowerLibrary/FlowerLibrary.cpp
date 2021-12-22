#include <iostream>
#include "FlowerLibrary.h"
using namespace std;


FlowerLibrary::FlowerLibrary() {
    FlowerList flowerList = FlowerList();
    flowers = flowerList;
}

FlowerLibrary::~FlowerLibrary() {
    delete &flowers;
}

void FlowerLibrary::addFlower(string name) {
    string lowercase_name = translate(name);
  	
    if (!flowers.add(lowercase_name)) {
        cout << lowercase_name << " cannot be added into the library because it already exists." << endl;
    }
}

void FlowerLibrary::removeFlower(string name) {
    string lowercase_name = translate(name);

    cout << lowercase_name;
    if (flowers.remove(lowercase_name)) {
        cout << " has been removed from the library." << endl;
    }
    else {
        cout << "  cannot be removed because it's not in the library." << endl;
    }
}

void FlowerLibrary::listFlowers() const {
    if ( !flowers.isEmpty() ) {
    }
    else {
        cout << "Library is empty.";
    }

    cout << endl;
}

void FlowerLibrary::listFeatures(string name) const {
    Flower flower;
    string lowercase_name = translate(name);
    
    if (!flowers.retrieve(lowercase_name, flower)) {
        cout << lowercase_name << " isn't found in library" << endl;
    }
    else {
        cout << flower.printFlower() << endl;
    }
}

void FlowerLibrary::addFeature(string name,string feature) {
    Flower flower;
    string lowercase_name = translate(name);

    if (!flowers.retrieve(lowercase_name, flower)) {
        cout << lowercase_name << " isn't found in library" << endl;
    }
    else {
        if (!flower.add(feature)) {
            cout << feature << " already exists in " << lowercase_name << endl;
        }
        else {
            cout << feature << " is added into " << lowercase_name << endl;
        }
    }
}

void FlowerLibrary::removeFeature(string name, string feature) {
    Flower flower;
    string lowercase_name = translate(name);

    if (!flowers.retrieve(lowercase_name, flower)) {
        cout << lowercase_name << " isn't found in library" << endl;
    }
    else {
        if (!flower.remove(feature)) {
            cout << feature << " doesn't exist in " << lowercase_name << endl;
        }
        else {
            cout << feature << " is removed from " << lowercase_name << endl;
        }
    }
}

void FlowerLibrary::findFlowers(string feature) const {

}

string FlowerLibrary::translate(string name) const {
    string name_copy = name;

    for (int i = 0; i < name.length(); i++) {
  		name_copy[i] = tolower(name[i]);
  	}

    return name_copy;
}