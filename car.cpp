//Name: Hechenjin Yu 
//Perm#: 8128084
#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

/*
private:
    char* manufacturer;
    char* model;
    uint32_t zeroToSixtyNs;
    float headonDragCoeff;
    uint16_t horsepower;
    DoorKind backseatDoors;
    uint8_t seatCount;
*/

/* 
Car()
    Initialize the pointer type variables with NULL and the numerical variables with 0. 
    DoorKind variable is also initialized with None.
*/
Car::Car():
    zeroToSixtyNs(0), 
    headonDragCoeff(0.0f), 
    horsepower(0), 
    backseatDoors(None), 
    seatCount(0) 
    
{
    manufacturer = new char[strlen("Unknown") + 1];
    strcpy(manufacturer, "Unknown");

    model = new char[strlen("Unknown") + 1];
    strcpy(model, "Unknown");
};

Car::Car(const Car& other) {
    manufacturer = new char[strlen(other.manufacturer) + 1];
    strcpy(manufacturer, other.manufacturer);

    model = new char[strlen(other.model) + 1];
    strcpy(model, other.model);

    zeroToSixtyNs = other.zeroToSixtyNs;
    headonDragCoeff = other.headonDragCoeff;
    horsepower = other.horsepower;
    backseatDoors = other.backseatDoors;
    seatCount = other.seatCount;
}

/* 
Car(char const* const manufacturerName, char const* const modelName, 
PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign)
    Initialize the member variables with specific values.
*/
Car::Car(char const* const manufacturerName, char const* const modelName, 
PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
    manufacturer = new char[strlen(manufacturerName) + 1];
strcpy(manufacturer, manufacturerName);
    model = new char[strlen(modelName) + 1];
strcpy(model, modelName);
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    backseatDoors = backseatDoorDesign;
    seatCount = numSeats;
}


/* 
Destructor : ~Car()
    Recycle the memory of variables.
*/
Car::~Car(){
    delete[] manufacturer;
    delete[] model;
}

/*
Car& operator=(Car const& o)
    Overloaded assignment operator =. 
    Set the values of the variables in the current object to be those in o.
*/
Car& Car::operator=(Car const& o) {
    if (this != &o) { 
        delete[] manufacturer;
        delete[] model;
        
        manufacturer = new char[strlen(o.manufacturer) + 1];
        strcpy(manufacturer, o.manufacturer);

        model = new char[strlen(o.model) + 1];
        strcpy(model, o.model);

        zeroToSixtyNs = o.zeroToSixtyNs;
        headonDragCoeff = o.headonDragCoeff;
        horsepower = o.horsepower;
        backseatDoors = o.backseatDoors;
        seatCount = o.seatCount;
    }
    return *this;
}

/*
char const* getManufacturer() const
    Get the string of manufacturer.*/
char const* Car::getManufacturer() const{
    return manufacturer ? manufacturer : "Unknown";
}

/*
char const* getModel() const
    Get the string of model.
*/
char const* Car::getModel() const{
    return model ? model : "Unknown";
}


/*
PerformanceStats getStats() const
    PerformanceStats is a structure given to you in the head file perf.hpp. 
    It summarizes the three parameters horsepower, zeroToSixtyNs, and headonDragCoeff together. 
    This method gets their values and returns as the structure.
*/
PerformanceStats Car::getStats() const{
    return PerformanceStats{horsepower, zeroToSixtyNs, headonDragCoeff};
}


/*
uint8_t getSeatCount() const
    Get the number of seats in seatCount.
*/
uint8_t Car:: getSeatCount() const{
    return seatCount;
}


/*
DoorKind getBackseatDoors() const
    Get the type of the doors in backseatDoors.
*/
DoorKind Car:: getBackseatDoors() const{
    return backseatDoors;
}


/*
void manufacturerChange(char const* const newManufacturer)
    Change the name (string) in manufacturer to the new in newManufacturer. 
    Since the name is of the type string in the memory, 
    please care about the memory management and avoid the memory leak.
*/
void Car::manufacturerChange(char const* const newManufacturer) {
    delete[] manufacturer;
    manufacturer = new char[strlen(newManufacturer) + 1];
    strcpy(manufacturer, newManufacturer);
}


/*
void modelNameChange(char const* const newModelName)
    Change the name (also string) in model to the new in newModelName.
*/
void Car::modelNameChange(char const* const newModelName) {
    delete[] model;
    model = new char[strlen(newModelName) + 1];
    strcpy(model, newModelName);
}

/*
void reevaluateStats(PerformanceStats newStats)
    Update the values of zeroToSixtyNs, headonDragCoeff and horsepower 
    by using the new parameters in newStats.
*/
void Car:: reevaluateStats(PerformanceStats newStats){
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
    horsepower = newStats.horsepower;
}


/*
void recountSeats(uint8_t newSeatCount)
    Set the value of seatCount to be newSeatCount.
*/
void Car:: recountSeats(uint8_t newSeatCount){
    seatCount = newSeatCount;
}


/*
void reexamineDoors(DoorKind newDoorKind)
    Set the kind of the doors in backseatDoors to be newDoorKind.
*/
void Car::reexamineDoors(DoorKind doorKind) {
    backseatDoors = doorKind;
}
