#include <iostream>
using namespace std;

//`virtual` enables runtime polymorphism by allowing a child class to override a function and have the correct version called through a base-class pointer or reference. Adding `= 0` makes that function a pure virtual function, which makes the class abstract and forces concrete child classes to implement it.

class Car{
    public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelarate() = 0;
    virtual void stopEngine() = 0;
    virtual void brake() = 0;
    virtual ~Car(){};
};

class SportsCar: public Car{

    private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    public:

    SportsCar(string brand, string model){
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear) {
        if(!isEngineOn){
            cout<<"First turn on the car"<<endl;
            return;
        }
        currentGear = gear;
        cout<<"Gear shifted to:"<<currentGear<<endl;
    }

    void accelarate(){
        if(!isEngineOn){
            cout<<"First turn on the car"<<endl;
            return;
        }
        currentSpeed += 20;
        cout<<"Car accelarated, speed is:"<<currentSpeed<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout<<"Car has stopped";
    }

    void brake(){
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

};

int main(){
    // A base-class pointer/reference is used to achieve runtime polymorphism, allowing the program to call the overridden version of a virtual function in the actual child object at runtime.
    Car* myCar = new SportsCar("Honda","Civic");
    myCar->startEngine();
    myCar->accelarate();
    myCar->shiftGear(3);
    myCar->accelarate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
}

/*
Abstract class --> 
1. Act as an interface for the outside world to operate the car. 
2. This abstract class tells 'WHAT' all it can do rather then 'HOW' it does that.
3. Since this is an abstract class we cannot directly create Objects of this class. 
4. We need to Inherit it first and then that child class will have the responsibility to 
provide implementation details of all the abstract (virtual) methods in the class.

5. In our real world example of Car, imagine you sitting in the car and able to operate
the car (startEngine, accelerate, brake, turn) just by pressing or moving some
pedals/buttons/ steer the wheel etc. You dont need to know how these things work, and
also they are hidden under the hood. This is known as ABSTRACTION.
6. This Class 'Car' denotes that (pedals/buttons/steering wheel etc). 
*/