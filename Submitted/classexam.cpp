#include <iostream>
using namespace std;

struct Registration {
    string id;

    Registration(string id) : id(id) {}
};

class Vehicle {
protected:
    string name;
    int topSpeed;
    Registration* reg;
public:
    Vehicle(string name, int topSpeed, Registration* reg) : name(name), topSpeed(topSpeed), reg(reg) {}

    virtual void info() {
        cout << "Name: " << name << endl;
        cout << "Top Speed: " << topSpeed << endl;
        cout << "Registration: " << reg->id << endl;
    }

    void changeTopSpeed(int val) {
        topSpeed = val;
    }

    void changeRegistration(Registration* newReg) {
        delete reg;
        reg = newReg;
    }

    ~Vehicle() {
        delete reg;
    }
};

class Car : public Vehicle {
protected:
    int seats;
    friend class Person;
public:
    Car(string name, int topSpeed, Registration* reg, int seats) : Vehicle(name, topSpeed, reg), seats(seats) {}

    virtual void info() {
        Vehicle::info();
        cout << "Seats: " << seats << endl;
    }
};

class Boat : public Vehicle {
protected:
    int bounancy;
    int seats;
public:
    Boat(string name, int topSpeed, Registration* reg, int bounacy, int seats)
        : Vehicle(name, topSpeed, reg), bounancy(bounacy), seats(seats) {}

    void info() {
        Vehicle::info();
        cout << "Bounacy: " << bounancy << endl;
        cout << "Seats: " << seats << endl;
    }

    void changeBounancy(int val) {
        bounancy = val;
    }
};

class Person{
    string name;
public:
    Person(string name) : name(name) {}

    int getSeats(Car& c) {
        return c.seats;
    }

    string getName() {
        return name;
    }
};

int main()
{
    Vehicle* v1 = new Vehicle("Abstract Moving Object", 10, new Registration("ABCD"));
    v1->info();
    cout << endl;
    v1->changeTopSpeed(15);
    v1->changeRegistration(new Registration("DCBA"));
    v1->info();
    delete v1;

    cout << endl << endl;

    Car* c1 = new Car("Ferrari", 200, new Registration("1234"), 2);
    Person p1("Adam");
    c1->info();
    cout << "My name is " << p1.getName() << " and I want to sit down... this car has " << p1.getSeats(*c1) << " seats" << endl;
    delete c1;

    cout << endl << endl;

    Boat* b1 = new Boat("Awesomeboat", 50, new Registration("4321"), 100, 4);
    b1->info();
    cout << endl;
    b1->changeBounancy(10);
    b1->info();
    delete b1;
}