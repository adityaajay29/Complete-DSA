#include <iostream>
#include <vector>
using namespace std;

class Hotel
{
    string name;
    int id;
    Location address;
    vector<Room> rooms;
};

class Location
{
    int pin;
    string city;
    string country;
};

class Room
{
    int roomNo;
    RoomType roomType;
    RoomStatus roomStatus;
    vector<RoomKeys> roomKeys;
};

enum RoomType{Suite, Satndard, Delux};

enum RoomStatus{Available, Booked, Unavailable};

class RoomKeys
{
    int keyId;
    bool isActive;
    bool isMaster;
};

class Person
{
    public :
    virtual void fun() = 0;
    string name;
    int accountNumber;
    int phone;
};

class Guest : public Person
{
    Book book;
    Cancel cancel;
    Search search;
    public : 
    void bookRoom(Room newRoom);
    void cancelRoom(Room newRoom);
};

class Receptionist : public Person
{
    Book book;
    Cancel cancel;
    Search search;
    public :
    void checkIn(Guest guest);
    void CheckOut(Guest guest);
};

class Book
{
    public : 
    void createRoomBooking(Room room);
};

class Cancel
{
    public : 
    void CancelRoomBooking(Room room);
};

class Search
{
    public : 
    void SearchRoom(Room room);
};
