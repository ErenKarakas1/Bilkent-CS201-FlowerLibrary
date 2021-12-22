using namespace std;
/*
Eren KARAKAS
22002722
*/


class Flower{
public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower& aFlower);
    ~Flower();
    bool isEmpty() const;

    // getters
    int getLength() const ;
    string getName() const;

    // other necessary methods
    bool add(string feature);
    bool remove(string feature);
    
    string printFlower() const;
    bool featureExists(string feaure) const;
    Flower& operator=( Flower& aFlower);

private:
    struct FeatureNode{
        string feature;
        FeatureNode* next;
    };
    int size;
    string flowerName;
    FeatureNode* head;
    FeatureNode* findFeature(string feature) const;

//the features are stored in a sorted singly linear linked list
// ...
//you may define additional member functions and data members, if necessary
};