#include <iostream>
using namespace std;
#include "FlowerLibrary.h"


int main(){
    FlowerLibrary L;
    //L.listFlowers();

    // Testing add flower
    cout << "Testing add flower" << endl;
    cout << endl;

    L.addFlower("Magnolia");
    L.addFlower("SCARLET PIMPERNEL");
    L.addFlower("verbascum");
    cout << endl;

    L.addFlower("Magnolia");
    L.addFlower("magnolia");
    cout << endl;

    /*
    L.listFlowers();
    cout << endl;

    // Testing remove flower
    cout << endl;
    cout << "Testing remove flower" << endl;
    cout << endl;

    L.removeFlower("Magnolia");
    L.removeFlower("lantana");
    cout << endl;

    L.removeFlower("LANTANA");
    L.removeFlower("VERBASCUM");
    L.removeFlower("oleander");
    cout << endl;

    L.addFlower("verbascum");
    cout << endl;

    L.listFlowers();
    cout << endl;

    // Testing add feature
    cout << endl;
    cout << "Testing add feature" << endl;
    cout << endl;

    L.addFlower("calla lilly");
    cout << endl;

    L.listFeatures("magnolia");
    cout << endl;

    L.addFeature("verbascum", "yellow");
    L.addFeature("verbascum", "biennial");
    L.addFeature("verbascum", "Perennial");
    L.addFeature("calla lilly", "ornamental");
    cout << endl;

    L.addFeature("calla lilly", "ornamental");
    L.addFeature("Magnolia", "ornamental");
    cout << endl;

    L.addFlower("magnolia");
    L.addFeature("Magnolia", "ornamental");
    L.addFeature("Magnolia", "citronella scented");

    L.listFeatures("magnolia");
    cout << endl;
    */
}