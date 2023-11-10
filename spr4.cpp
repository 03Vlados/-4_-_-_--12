#include <iostream>
#include <string>

// Базовий клас
class Vehicle {
protected: 
    std::string brand;
    int year;
    int price;

public:
    Vehicle(const std::string& brand, int year, int price) : brand(brand), year(year), price(price) {}

    virtual ~Vehicle() {}

    virtual void displayInfo() const = 0;
};

// Перший дочірній клас
class Car : public Vehicle {
private:
    int numOfDoors;

public:
    Car(const std::string& brand, int year, int price, int doors) : Vehicle(brand, year, price), numOfDoors(doors) {}

    ~Car() override {}

    void displayInfo() const override {
        std::cout << "Car: " << brand << " (" << year << "), Price: $" << price << ", Doors: " << numOfDoors << "\n";
    }
};

// Другий дочірній клас
class Motorcycle : public Vehicle {
private:
    std::string type;

public:
    Motorcycle(const std::string& brand, int year, int price, const std::string& bikeType)
        : Vehicle(brand, year, price), type(bikeType) {}

    ~Motorcycle() override {}

    void displayInfo() const override {
        std::cout << "Motorcycle: " << brand << " (" << year << "), Price: $" << price << ", Type: " << type << "\n";
    }
};

int main() {
    const int arraySize = 3;
    Vehicle* vehicles[arraySize];

    vehicles[0] = new Car("Toyota", 2022, 25000, 4);
    vehicles[1] = new Motorcycle("Honda", 2021, 12000, "Sport");
    vehicles[2] = new Car("Ford", 2023, 30000, 2);

    for (int i = 0; i < arraySize; ++i) {
        vehicles[i]->displayInfo();
        delete vehicles[i];
    }

    return 0;
}