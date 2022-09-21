#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Parkinglot
{
    vector<Floor> floors;
    vector<Entry> entries;
    vector<Exit> exits;
    string name;
    Address address;

    public :
    bool isSpotAvailable(Vehicle vehicle);
    void updateSpotStatus(Vehicle vechicle, int gateID);
};

class Floor
{
    int floorNumber;
    bool isFull;
    vector<ParkingSpace> parkingSpaces;
    DisplayForStatus displays;
};

class Gate
{
    int gateID;
    ParkingAttendent parkingAttendent;
};

class Entry : public Gate
{
    public :
    ParkingTicket getTkt(Vehicle vehicle);
};

class Exit : public Gate
{
    public :
    ParkingTicket getBillForPark(Vehicle vehicle, Parkingticket tkt);
};

class Address
{
    int pin;
    string city;
    string state;
    string country;
};

class ParkingSpace
{
    bool isAvailable;
    float chargesPerHour;
    Vehicle vehicle;
    TypeOfSpace space;
};

class DisplayForStatus
{
    map<TypeOfSpace, int> freeSpotsAvailability;
    public : 
    void updateSpots(TypeOfSpaces space);
};

class Account
{
    int id;
    string name;
    string email;
    string password;
    Address address;
};

class ParkingAttendent : public Account
{
    Payment payment;
    public : 
    bool processVehicleEntyr(Vehicle vehicle);
    PaymentInfo generateTkt(Vehicle typeOfVehicle);
};

class Vehicle
{
    string licence;
    Vehicletype type;
    ParkingTicket tktInfo;
    PaymentInfo payInfo;
};

