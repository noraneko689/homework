#include <iostream>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
public:
    Car() : brand(""), model(""), year(0) {}
    Car(const string& brand, const string& model, int year)
        : brand(""), model(""), year(0)
    {
        setBrand(brand);
        setModel(model);
        setYear(year);
    }
    Car(const Car& other)
        : brand(other.brand), model(other.model), year(other.year) {}

    string getBrand() const {
        return brand;
    }
    string getModel() const {
        return model;
    }
    int getYear() const {
        return year;
    }
    void setBrand(const string& brand) {
        if (brand.empty()) {
            cout << "Warning: brand cannot be empty. Value not changed." << endl;
            return;
        }
        this->brand = brand;
    }

    void setModel(const string& model) {
        if (model.empty()) {
            cout << "Warning: model cannot be empty. Value not changed." << endl;
            return;
        }
        this->model = model;
    }
    void setYear(int year) {
        if (year < 1886 || year > 2025) {
            cout << "Warning: year must be between 1886 and 2025. Value not changed." << endl;
            return;
        }
        this->year = year;
    }
    virtual void displayInfo() const {
        cout << "Car Info:" << endl;
        cout << " Brand: " << brand << endl;
        cout << " Model: " << model << endl;
        cout << " Year: " << year << endl;
    }
};
class Truck :public Car
{
private:
    double loadCapacity;
public:
    Truck() : Car(), loadCapacity(0.0) {}
    Truck(const string& brand, const string& model, int year, double loadCapacity) : Car(brand, model, year)

    {
        setLoadCapacity(loadCapacity);
    }
    Truck(const Truck& other) :
        Car(other), loadCapacity(other.loadCapacity) {}
    double getLoadCapacity() const {
        return loadCapacity;
    }
    void setLoadCapacity(double loadCapacity) {
        if (loadCapacity < 0) {
            cout << "Warning. Cant be lower 0." << endl;
            return;
        }
        this->loadCapacity = loadCapacity;
    }
    void displayInfo() const override {
        Car::displayInfo();
        cout << " Load Capacity: " << loadCapacity << endl;
    }
};
int main() {
    const int size = 4;
    Car* vehicles[size];
    vehicles[0] = new Car("Car1", "Model1", 2015);
    vehicles[1] = new Truck("Truck1", "Model2", 2020, 25.0);
    vehicles[2] = new Car("Car2", "Model3", 2018);
    vehicles[3] = new Truck("Truck2", "Model4", 2019, 18.5);

    for (int i = 0; i < size; ++i) {
        cout << "Vehicle #" << i + 1 << ":" << endl;
        vehicles[i]->displayInfo();
        cout << endl;
    }

    for (int i = 0; i < size; ++i) {
        delete vehicles[i];
    }

    return 0;

}