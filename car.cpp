//Name: Hechenjin Yu 
//Perm#: 8128084
#include "car.hpp"
#include <cstddef>
#include <cstring>

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
Car::Car(){};

/* 
Car(char const* const manufacturerName, char const* const modelName, 
PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign)
    Initialize the member variables with specific values.
*/
Car(char const* const manufacturerName, char const* const modelName, 
PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
    this.manufacturer = manufacturerName;
    this.model = modelName;
    this.zeroToSixtyNs = perf.zeroToSixtyNs;
    this.headonDragCoeff = perf.headonDragCoeff;
    this.horsepower = perf.horsepower;
    this.backseatDoors = backseatDoorDesign;
    this.seatCount = numSeats;
}


/* 
Destructor : ~Car()
    Recycle the memory of variables.
*/
~Car(){
    delete[] manufacturer;
    delete[] model;
}


/*
Car& operator=(Car const& o)
    Overloaded assignment operator =. 
    Set the values of the variables in the current object to be those in o.
*/
Car& Car::operator=(Car const& o) {
    if (this != &o) { // self-assignment check
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
char const* getManufacturer() const{
    return manufacturer;
}

/*
char const* getModel() const
    Get the string of model.
*/
char const* getModel() const{
    return model;
}


/*
PerformanceStats getStats() const
    PerformanceStats is a structure given to you in the head file perf.hpp. 
    It summarizes the three parameters horsepower, zeroToSixtyNs, and headonDragCoeff together. 
    This method gets their values and returns as the structure.
*/
PerformanceStats getStats() const{
    return constexpr PerformanceStats(horsepower, zeroToSixtyNs, headonDragCoeff);
}


/*
uint8_t getSeatCount() const
    Get the number of seats in seatCount.
*/
uint8_t getSeatCount() const{
    return seatCount;
}


/*
DoorKind getBackseatDoors() const
    Get the type of the doors in backseatDoors.
*/
DoorKind getBackseatDoors() const{
    return backseatDoors;
}


/*
void manufacturerChange(char const* const newManufacturer)
    Change the name (string) in manufacturer to the new in newManufacturer. 
    Since the name is of the type string in the memory, 
    please care about the memory management and avoid the memory leak.
*/
void manufacturerChange(char const* const newManufacturer){
    this.manufacturer = newManufacturer;
}


/*
void modelNameChange(char const* const newModelName)
    Change the name (also string) in model to the new in newModelName.
*/
void modelNameChange(char const* const newModelName){
    this.model = newModelName;
}

/*
void reevaluateStats(PerformanceStats newStats)
    Update the values of zeroToSixtyNs, headonDragCoeff and horsepower 
    by using the new parameters in newStats.
*/
void reevaluateStats(PerformanceStats newStats){
    this.zeroToSixtyNs = newStats.zeroToSixtyNs;
    this.headonDragCoeff = newStats.headonDragCoeff;
    this.horsepower = newStats.horsepower;
}


/*
void recountSeats(uint8_t newSeatCount)
    Set the value of seatCount to be newSeatCount.
*/
void recountSeats(uint8_t newSeatCount){
    this.seatCount = newSeatCount;
}


/*
void reexamineDoors(DoorKind newDoorKind)
    Set the kind of the doors in backseatDoors to be newDoorKind.
*/
void reexamineDoors(DoorKind newDoorKind){
    this.backseatDoors = newDoorKind;
}