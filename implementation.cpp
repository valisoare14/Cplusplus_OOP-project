#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

// The "Operators" template class
template<typename T>
class Operators {
private:
    int vectorSize;
    T* vect;
public:
    //getters
    int getVectorSize() {
        return this->vectorSize;
    }
    T getVect() {
        if (this->vect != nullptr)
            return this->vect;
        else
            throw new exception("Null vector");
    }
    //setters
    void setVectorSize(int vectorSize) {
        if (vectorSize > 0) {
            if (vectorSize < this->vectorSize) {
                T* newElements;
                newElements = new T[this->vectorSize];
                for (int i = 0; i < this->vectorSize; i++) {
                    newElements[i] = this->vect[i];
                }
                delete[] this->vect;
                this->vectorSize = vectorSize;
                this->vect = new T[vectorSize];
                for (int i = 0; i < vectorSize; i++) {
                    this->vect[i] = newElements[i];
                }
                delete[] newElements;
            }
            else if (vectorSize > this->vectorSize) {
                T* newElements;
                newElements = new T[this->vectorSize];
                for (int i = 0; i < this->vectorSize; i++) {
                    newElements[i] = this->vect[i];
                }
                delete[] this->vect;
                this->vect = new T[vectorSize];
                for (int i = 0; i < this->vectorSize; i++) {
                    this->vect[i] = newElements[i];
                }
                this->vectorSize = vectorSize;
                delete[] newElements;
            }
            else
                throw new exception("The vector already has this size!");
        }
        else
            throw new exception("Please enter a positive size!");
    }
    void setVect(T* vect) {
        if (vect != nullptr)
            this->vect = vect;
        else
            throw new exception("Please provide a non-null pointer!");
    }
    Operators() {
        vect = nullptr;
        vectorSize = 0;
    }
    Operators(int vectorSize, T* vect) {
        if (vectorSize <= 0)
            throw new exception("Please enter a positive size!");
        if (vect == nullptr)
            throw new exception("Please provide a non-null pointer!");
        this->vectorSize = vectorSize;
        this->vect = new T[vectorSize];
        for (int i = 0; i < this->vectorSize; i++) {
            this->vect[i] = vect[i];
        }
    }
    Operators(const Operators& operators) {
        this->vectorSize = operators.vectorSize;
        this->vect = new T[operators.vectorSize];
        for (int i = 0; i < this->vectorSize; i++) {
            this->vect[i] = operators.vect[i];
        }
    }
    friend ostream& operator<<(ostream& out, const Operators& operators) {
        out << "Vector size : " << operators.vectorSize << endl;
        for (int i = 0; i < operators.vectorSize; i++) {
            out << operators.vect[i];
        }
        return out;
    }
    friend istream& operator>>(istream& in, Operators& operators) {
        cout << "Enter vector size : ";
        in >> operators.vectorSize;
        for (int i = 0; i < operators.vectorSize; i++) {
            cout << "Enter element " << i << " of the vector:" << endl;
            in >> operators.vect[i];
        }
        return in;
    }
    Operators operator=(const Operators& operators) {
        this->vectorSize = operators.vectorSize;
        if (this->vect != nullptr)
            delete[] this->vect;
        this->vect = new T[this->vectorSize];
        for (int i = 0; i < this->vectorSize; i++) {
            this->vect[i] = operators.vect[i];
        }
        return *this;
    }
    Operators operator+(const Operators& operators) {
        if (this->vectorSize >= operators.vectorSize) {
            Operators o = *this;
            for (int i = 0; i < operators.vectorSize; i++) {
                o.vect[i] = this->vect[i] + operators.vect[i];
            }
            return o;
        }
        else if (this->vectorSize < operators.vectorSize) {
            Operators o = operators;
            for (int i = 0; i < this->vectorSize; i++) {
                o.vect[i] = operators.vect[i] + this->vect[i];
            }
            return o;
        }
    }
    Operators operator-(const Operators& operators) {
        if (this->vectorSize >= operators.vectorSize) {
            Operators o = *this;
            for (int i = 0; i < operators.vectorSize; i++) {
                o.vect[i] = this->vect[i] - operators.vect[i];
            }
            return o;
        }
        else if (this->vectorSize < operators.vectorSize) {
            Operators o = operators;
            for (int i = 0; i < this->vectorSize; i++) {
                o.vect[i] = operators.vect[i] - this->vect[i];
            }
            return o;
        }
    }
    Operators operator/(const Operators& operators) {
        if (this->vectorSize >= operators.vectorSize) {
            Operators o = *this;
            for (int i = 0; i < operators.vectorSize; i++) {
                o.vect[i] = this->vect[i] / operators.vect[i];
            }
            return o;
        }
        else if (this->vectorSize < operators.vectorSize) {
            Operators o = operators;
            for (int i = 0; i < this->vectorSize; i++) {
                o.vect[i] = operators.vect[i] / this->vect[i];
            }
            return o;
        }
    }
    Operators operator++(int) {
        Operators operators = *this;
        for (int i = 0; i < this->vectorSize; i++) {
            this->vect[i]++;
        }
        return operators;
    }
    Operators operator++() {
        for (int i = 0; i < this->vectorSize; i++) {
            this->vect[i]++;
        }
        return *this;
    }
};

// "Device" class
class Device {
private:
    int manufacturingYear;
    float price;
public:
    //getters
    int getManufacturingYear() {
        return this->manufacturingYear;
    }
    float getPrice() {
        return this->price;
    }
    //setters
    void setManufacturingYear(int manufacturingYear) {
        if (manufacturingYear > 0)
            this->manufacturingYear = manufacturingYear;
        else
            throw new exception("You have entered a negative manufacturing year!");
    }
    void setPrice(float price) {
        if (price > 0)
            this->price = price;
        else
            throw new exception("You have entered a negative price!");
    }
    //DEFAULT constructor
    Device() {
        this->manufacturingYear = 0;
        this->price = 0;
    }
    //copy constructor
    Device(const Device& device) {
        this->manufacturingYear = device.manufacturingYear;
        this->price = device.price;
    }
    //constructor with parameters
    Device(int manufacturingYear, float price) {
        if (manufacturingYear <= 0)
            throw new exception("You have entered a negative manufacturing year!");
        if (price <= 0)
            throw new exception("You have entered a negative price!");
        this->manufacturingYear = manufacturingYear;
        this->price = price;
    }
    //constructor with the parameter manufacturingYear
    Device(int manufacturingYear) {
        if (manufacturingYear <= 0)
            throw new exception("You have entered a negative manufacturing year!");
        this->manufacturingYear = manufacturingYear;
    }
    //constructor with the parameter price
    Device(float price) {
        if (price <= 0)
            throw new exception("You have entered a negative price!");
        this->price = price;
    }
    //VIRTUAL FUNCTION
    virtual string emittedSound() = 0;
    //operator<< overload
    friend ostream& operator<<(ostream& out, const Device& device) {
        out << endl << "Manufacturing year: " << device.manufacturingYear << " --- Price: " << device.price;
        return out;
    }
    //operator>> overload
    friend istream& operator>>(istream& in, Device& device) {
        cout << "Enter manufacturing year: ";
        in >> device.manufacturingYear;
        cout << "Enter price: ";
        in >> device.price;
        return in;
    }
    // ifstream >> overload
    friend ifstream& operator>>(ifstream& in, Device& device) {
        in >> device.manufacturingYear;
        in >> device.price;
        return in;
    }
    //operator= overload
    Device& operator=(const Device& device) {
        this->manufacturingYear = device.manufacturingYear;
        this->price = device.price;
        return *this;
    }
    //operator+= overload
    Device& operator+=(const Device& device) {
        this->price += device.price;
        return *this;
    }
    //operator-= overload
    Device& operator-=(const Device& device) {
        if (this->price > device.price)
            this->price -= device.price;
        else
            this->price = device.price - this->price;
        return *this;
    }
    //operator/= overload
    Device& operator/=(const Device& device) {
        this->price /= device.price;
        return *this;
    }
    //operator* overload
    Device& operator*(const Device& device) {
        Device* d = this;
        d->price = this->price * device.price;
        return *d;
    }
    //operator*= overload
    Device& operator*=(const Device& device) {
        this->price *= device.price;
        return *this;
    }
    //DESTRUCTOR
    ~Device() {}
};

class Profile {
private:
    string category;
    int warranty;
    bool waterproof;
    string networkType;
public:
    //DEFAULT constructor
    Profile() {
        this->category = "unknown";
        this->warranty = 0;
        this->waterproof = 0;
        this->networkType = "unknown";
    }
    //copy constructor
    Profile(const Profile& profile) {
        this->category = profile.category;
        this->warranty = profile.warranty;
        this->waterproof = profile.waterproof;
        this->networkType = profile.networkType;
    }
    //constructor with parameters
    Profile(const string& category, int warranty, bool waterproof, const string& networkType) {
        if (category.length() <= 0)
            throw new exception("Please enter an existing string");
        if (warranty <= 0)
            throw new exception("You have entered a negative warranty!");
        if (networkType.length() <= 0)
            throw new exception("Please enter an existing string");
        this->category = category;
        this->warranty = warranty;
        this->waterproof = waterproof;
        this->networkType = networkType;
    }
    //getters
    string getCategory() {
        return this->category;
    }
    char getCategory(int index) {
        return this->category[index];
    }
    char getNetworkType(int index) {
        return this->networkType[index];
    }
    int getWarranty() {
        return this->warranty;
    }
    bool getWaterproof() {
        return this->waterproof;
    }
    string getNetworkType() {
        return this->networkType;
    }
    //setters
    void setCategory(const string& category) {
        if (category.length() > 0)
            this->category = category;
        else
            throw new exception("Please enter an existing string");
    }
    void setWarranty(int warranty) {
        if (warranty > 0)
            this->warranty = warranty;
        else
            throw new exception("You have entered a negative warranty!");
    }
    void setWaterproof(bool waterproof) {
        this->waterproof = waterproof;
    }
    void setNetworkType(const string& networkType) {
        if (networkType.length() > 0)
            this->networkType = networkType;
        else
            throw new exception("Please enter an existing string");
    }
    //operator= overload
    Profile operator=(const Profile& profile) {
        this->category = profile.category;
        this->warranty = profile.warranty;
        this->waterproof = profile.waterproof;
        this->networkType = profile.networkType;
        return *this;
    }
    //operator+ overload
    Profile operator+(const Profile& profile) {
        Profile p = *this;
        p.warranty = this->warranty + profile.warranty;
        return p;
    }
    //operator- overload
    Profile operator-(const Profile& profile) {
        Profile p = *this;
        if (this->warranty > profile.warranty)
            p.warranty = this->warranty - profile.warranty;
        else
            p.warranty = profile.warranty - this->warranty;
        return p;
    }
    //operator/ overload
    Profile operator/(const Profile& profile) {
        Profile p = *this;
        p.warranty = this->warranty / profile.warranty;
        return p;
    }
    //operator++ - post overload
    Profile operator++(int) {
        Profile p = *this;
        this->warranty++;
        return p;
    }
    //operator++ - pre overload
    Profile operator++() {
        this->warranty++;
        return *this;
    }
    //operator<< overload
    friend ostream& operator<<(ostream& out, const Profile& profile) {
        out << endl << "Category:" << profile.category << "---Warranty:" << profile.warranty << " years--- Waterproof:" << profile.waterproof << "--- Network type:" << profile.networkType << endl;
        return out;
    }
    //operator>> overload
    friend istream& operator>>(istream& in, Profile& profile) {
        cout << "Category:"; in >> profile.category;
        cout << "Warranty:"; in >> profile.warranty;
        cout << "Waterproof:"; in >> profile.waterproof;
        cout << "Network typeL"; in >> profile.networkType;
        return in;
    }
    //ofstream& operator<< overload
    friend ofstream& operator<<(ofstream& out, const Profile& profile) {
        out << endl << "Category:" << profile.category << "---Warranty:" << profile.warranty << " years--- Waterproof:" << profile.waterproof << "--- Network type:" << profile.networkType << endl << endl;
        return out;
    }
    //DESTRUCTOR
    ~Profile() {}
};

// The "Sensor" class inherits from "Device"
class Sensor : public Device {
private:
    const int id;
    bool s_a_c;
    static int counter;
    int interactionCount = 0;
    int resetCount = 0;
    int lifespan = 0;
    int* dataHistory = nullptr;
    int dataHistorySize = 0;
    char* positioning = nullptr;
    float distanceToNextSensor = 0;
    float responseTime = 0;
    bool remoteConnection = 0;
    string criticalSituation = "";
    bool interconnectionWithOtherSensors = 0;
    Profile profile;
public:
    friend class SmartHome;
    //DEFAULT constructor
    Sensor() :id(counter++), s_a_c(0), Device() {
        this->positioning = new char[strlen("No name") + 1];
        strcpy_s(this->positioning, strlen("No name") + 1, "No name");
    }
    //copy constructor
    Sensor(const Sensor& sensor) :id(counter++), s_a_c(0), Device(sensor) {
        this->interactionCount = sensor.interactionCount;
        this->resetCount = sensor.resetCount;
        this->lifespan = sensor.lifespan;
        this->dataHistorySize = sensor.dataHistorySize;
        if (this->dataHistory != nullptr)
            delete[] this->dataHistory;
        this->dataHistory = new int[sensor.dataHistorySize];
        for (int i = 0; i < this->dataHistorySize; i++) {
            this->dataHistory[i] = sensor.dataHistory[i];
        }
        if (this->positioning != nullptr)
            delete[] this->positioning;
        this->positioning = new char[strlen(sensor.positioning) + 1];
        strcpy_s(this->positioning, strlen(sensor.positioning) + 1, sensor.positioning);
        this->distanceToNextSensor = sensor.distanceToNextSensor;
        this->responseTime = sensor.responseTime;
        this->remoteConnection = sensor.remoteConnection;
        this->criticalSituation = sensor.criticalSituation;
        this->interconnectionWithOtherSensors = sensor.interconnectionWithOtherSensors;
        this->profile = sensor.profile;
    }
    //constructor with parameters
    Sensor(int interactionCount, int resetCount, int lifespan, int* dataHistory, int dataHistorySize, char* positioning, float distanceToNextSensor, float responseTime, bool remoteConnection, string criticalSituation, bool interconnectionWithOtherSensors, int manufacturingYear, float price) :id(counter++), s_a_c(0), Device(manufacturingYear, price) {
        if (interactionCount <= 0)
            throw new exception("You have entered a negative number of interactions");
        if (resetCount <= 0)
            throw new exception("You have entered a negative number of resets");
        if (lifespan <= 0)
            throw new exception("You have entered a negative lifespan");
        if (dataHistory == nullptr)
            throw new exception("Assign a non-null pointer");
        if (dataHistorySize <= 0)
            throw new exception("You have entered a negative size");
        if (positioning == nullptr)
            throw new exception("Assign a non-null pointer");
        if (distanceToNextSensor <= 0)
            throw new exception("You have entered a negative distance to the next sensor");
        if (responseTime <= 0)
            throw new exception("You have entered a negative response time");
        if (criticalSituation.length() <= 0)
            throw new exception("Please enter an existing string");
        this->interactionCount = interactionCount;
        this->resetCount = resetCount;
        this->lifespan = lifespan;
        this->dataHistorySize = dataHistorySize;
        this->dataHistory = new int[dataHistorySize];
        for (int i = 0; i < dataHistorySize; i++) {
            this->dataHistory[i] = dataHistory[i];
        }
        this->positioning = new char[strlen(positioning) + 1];
        strcpy_s(this->positioning, strlen(positioning) + 1, positioning);
        this->distanceToNextSensor = distanceToNextSensor;
        this->responseTime = responseTime;
        this->remoteConnection = remoteConnection;
        this->criticalSituation = criticalSituation;
        this->interconnectionWithOtherSensors = interconnectionWithOtherSensors;
        Profile p;
        this->profile = p;
    }

    //operator= overload
    Sensor operator=(const Sensor& sensor) {
        Device::operator=(sensor);
        this->profile = sensor.profile;
        this->interactionCount = sensor.interactionCount;
        this->resetCount = sensor.resetCount;
        this->lifespan = sensor.lifespan;
        this->dataHistorySize = sensor.dataHistorySize;
        if (this->dataHistory != nullptr)
            delete[] this->dataHistory;
        this->dataHistory = new int[sensor.dataHistorySize];
        for (int i = 0; i < this->dataHistorySize; i++) {
            this->dataHistory[i] = sensor.dataHistory[i];
        }
        if (this->positioning != nullptr)
            delete[] this->positioning;
        this->positioning = new char[strlen(sensor.positioning) + 1];
        strcpy_s(this->positioning, strlen(sensor.positioning) + 1, sensor.positioning);
        this->distanceToNextSensor = sensor.distanceToNextSensor;
        this->responseTime = sensor.responseTime;
        this->remoteConnection = sensor.remoteConnection;
        this->criticalSituation = sensor.criticalSituation;
        this->interconnectionWithOtherSensors = sensor.interconnectionWithOtherSensors;
        return *this;
    }
    //operator<< overload
    friend ostream& operator<<(ostream& out, const Sensor& sensor) {
        out << "ID: " << sensor.id << " ; number of interactions: " << sensor.interactionCount << "; number of resets: " << sensor.resetCount << "; lifespan:" << sensor.lifespan << "; data history size:" << sensor.dataHistorySize << "; distance to the next sensor:" << sensor.distanceToNextSensor << "; response time: " << sensor.responseTime << "; remote connection: " << sensor.remoteConnection << "; critical situation:" << sensor.criticalSituation << "; interconnection with other sensors: " << sensor.interconnectionWithOtherSensors << endl;
        out << "Data history : ";
        if (sensor.dataHistorySize != 0) {
            for (int i = 0; i < sensor.dataHistorySize; i++) {
                out << sensor.dataHistory[i];
            }
        }
        else
            out << "We do not have data history";
        out << endl << "Sensor positioning : ";
        if (sensor.positioning != nullptr) {
            for (int i = 0; i < strlen(sensor.positioning); i++) {
                out << sensor.positioning[i];
            }
        }
        else
            out << "We do not have positioning";
        out << (Device&)sensor;
        out << sensor.profile << endl << endl;
        return out;
    }
    //operator>> overload
    friend istream& operator>>(istream& in, Sensor& sensor) {
        cout << "number of interactions: ";
        in >> sensor.interactionCount;
        cout << "number of resets: ";
        in >> sensor.resetCount;
        cout << "lifespan:";
        in >> sensor.lifespan;
        cout << "data history size:";
        in >> sensor.dataHistorySize;
        cout << "distance to the next sensor:";
        in >> sensor.distanceToNextSensor;
        cout << "response time : ";
        in >> sensor.responseTime;
        cout << "remote connection : ";
        in >> sensor.remoteConnection;
        cout << "critical situation : ";
        in >> sensor.criticalSituation;
        cout << "interconnection with other sensors : ";
        in >> sensor.interconnectionWithOtherSensors;
        if (sensor.dataHistory != nullptr)
            delete[] sensor.dataHistory;
        sensor.dataHistory = new int[sensor.dataHistorySize];
        for (int i = 0; i < sensor.dataHistorySize; i++) {
            cout << "Enter code " << i << ": ";
            in >> sensor.dataHistory[i];
        }
        int positioningSize;
        cout << "Enter the size of the positioning array : ";
        cin >> positioningSize;
        if (sensor.positioning != nullptr)
            delete[] sensor.positioning;
        sensor.positioning = new char[positioningSize + 1];
        for (int i = 0; i < positioningSize; i++) {
            cout << "Enter position " << i << "/" << positioningSize;
            in >> sensor.positioning[i];
        }
        sensor.positioning[positioningSize] = '\0';
        in >> (Device&)sensor;
        return in;
    }
    //ifstream& operator>> overload
    friend ifstream& operator>>(ifstream& in, Sensor& sensor) {
        in >> sensor.interactionCount;
        in >> sensor.resetCount;
        in >> sensor.lifespan;
        in >> sensor.dataHistorySize;
        in >> sensor.distanceToNextSensor;
        in >> sensor.responseTime;
        in >> sensor.remoteConnection;
        in >> sensor.criticalSituation;
        in >> sensor.interconnectionWithOtherSensors;
        if (sensor.dataHistory != nullptr)
            delete[] sensor.dataHistory;
        sensor.dataHistory = new int[sensor.dataHistorySize];
        for (int i = 0; i < sensor.dataHistorySize; i++) {
            in >> sensor.dataHistory[i];
        }
        int positioningSize;
        in >> positioningSize;
        if (sensor.positioning != nullptr)
            delete[] sensor.positioning;
        sensor.positioning = new char[positioningSize + 1];
        for (int i = 0; i < positioningSize; i++) {
            in >> sensor.positioning[i];
        }
        sensor.positioning[positioningSize] = '\0';
        in >> (Device&)sensor;
        return in;
    }
    //operator+ overload
    Sensor operator+(const Sensor& sensor) {
        Sensor s = *this;
        s.lifespan = this->lifespan + sensor.lifespan;
        return s;
    }
    //operator- overload
    Sensor operator-(const Sensor& sensor) {
        Sensor s = *this;
        if (sensor.lifespan > this->lifespan)
            s.lifespan = sensor.lifespan - this->lifespan;
        else
            s.lifespan = this->lifespan - sensor.lifespan;
        return s;
    }
    //operator/ overload
    Sensor operator/(const Sensor& sensor) {
        Sensor s = *this;
        s.distanceToNextSensor = this->distanceToNextSensor / sensor.distanceToNextSensor;
        return s;
    }
    //operator++ - post overload
    Sensor operator++(int) {
        Sensor temp = *this;
        this->lifespan++;
        return temp;
    }
    //operator++ - pre overload
    Sensor operator++() {
        this->lifespan++;
        return *this;
    }

    //DESTRUCTOR
    ~Sensor() {
        if (this->positioning != nullptr)
            delete[] this->positioning;
        if (this->dataHistory != nullptr)
            delete[] this->dataHistory;
    }
    //getters
    int getDataHistorySize() {
        return this->dataHistorySize;
    }
    int getId() {
        return this->id;
    }
    bool getS_a_c() {
        return this->s_a_c;
    }
    int* getDataHistory() {
        if (this->dataHistory != nullptr)
            return this->dataHistory;
        else
            throw new exception("Null pointer");
    }
    int getInteractionCount() {
        return this->interactionCount;
    }
    int getResetCount() {
        return this->resetCount;
    }
    int getLifespan() {
        return this->lifespan;
    }
    char* getPositioning() {
        return this->positioning;
    }
    char getPositioning(int index) {
        if (this->positioning != nullptr)
            return this->positioning[index];
        else {
            throw "We do not have positioning!";
        }
    }
    float getDistanceToNextSensor() {
        return this->distanceToNextSensor;
    }
    float getResponseTime() {
        return this->responseTime;
    }
    bool getRemoteConnection() {
        return this->remoteConnection;
    }
    string getCriticalSituation() {
        return this->criticalSituation;
    }
    bool getInterconnectionWithOtherSensors() {
        return this->interconnectionWithOtherSensors;
    }
    Profile getProfile() {
        return this->profile;
    }
    //setters
    void setDataHistory(int* dataHistory) {
        if (dataHistory != nullptr)
            this->dataHistory = dataHistory;
        else
            throw new exception("Assign a non-null pointer");
    }
    void setDataHistorySize(int dataHistorySize) {
        if (dataHistorySize > 0)
            this->dataHistorySize = dataHistorySize;
        else
            throw new exception("You have entered a negative size");
    }
    void setInteractionCount(int interactionCount) {
        if (interactionCount > 0)
            this->interactionCount = interactionCount;
        else
            throw new exception("You have entered a negative number of interactions");
    }
    void setResetCount(int resetCount) {
        if (resetCount > 0)
            this->resetCount = resetCount;
        else
            throw new exception("You have entered a negative number of resets");
    }
    void setLifespan(int lifespan) {
        if (lifespan > 0)
            this->lifespan = lifespan;
        else
            throw new exception("You have entered a negative lifespan");
    }
    void setPositioning(char* positioning) {
        if (strlen(positioning) > 0)
            this->positioning = positioning;
        else
            throw new exception("Assign a non-null pointer");
    }
    void setDistanceToNextSensor(float distanceToNextSensor) {
        if (distanceToNextSensor > 0)
            this->distanceToNextSensor = distanceToNextSensor;
        else
            throw new exception("You have entered a negative distance to the next sensor");
    }
    void setResponseTime(float responseTime) {
        if (responseTime > 0)
            this->responseTime = responseTime;
        else
            throw new exception("You have entered a negative response time");
    }
    void setRemoteConnection(bool remoteConnection) {
        this->remoteConnection = remoteConnection;
    }
    void setCriticalSituation(const string& criticalSituation) {
        if (criticalSituation.length() > 0)
            this->criticalSituation = criticalSituation;
        else
            throw new exception("Please enter an existing string");
    }
    void setInterconnectionWithOtherSensors(bool interconnectionWithOtherSensors) {
        this->interconnectionWithOtherSensors = interconnectionWithOtherSensors;
    }
    void setProfile(const Profile& profile) {
        this->profile = profile;
    }
    string emittedSound() {
        return "bipbip";
    }
};

class SmartHome {
private:
    int sensorCount;
    Sensor** allSensors;
    float Rating = 0;
public:
    static void correctS_a_c(Sensor** s, int size) {
        if (s != nullptr) {
            for (int i = 0; i < size; i++) {
                if (s[i] != nullptr) {
                    s[i]->s_a_c = 1;
                }
                else
                    throw new exception("The array contains a null sensor");
            }
        }
        else
            throw new exception("The array does not contain sensors!");
    }
    //getters
    float getRating() {
        return this->Rating;
    }
    int getSensorCount() {
        return this->sensorCount;
    }
    Sensor** getAllSensors() {
        if (this->allSensors != nullptr)
            return this->allSensors;
        else
            throw new exception("The smart home does not contain sensors!");
    }
    //setters
    void setRating(float Rating) {
        if (Rating > 0)
            this->Rating = Rating;
        else
            throw new exception("You have entered a negative rating");
    }
    void setSensorCount(int sensorCount) {
        if (sensorCount > 0) {
            if (sensorCount < this->sensorCount) {
                Sensor** newSensors;
                newSensors = new Sensor * [this->sensorCount];
                for (int i = 0; i < this->sensorCount; i++) {
                    newSensors[i] = this->allSensors[i];
                }
                delete[] this->allSensors;
                int a = this->sensorCount;
                this->sensorCount = sensorCount;
                this->allSensors = new Sensor * [sensorCount];
                for (int i = 0; i < this->sensorCount; i++) {
                    this->allSensors[i] = newSensors[i];
                }
                delete[] newSensors;
            }
            else if (sensorCount > this->sensorCount) {
                Sensor** newSensors;
                newSensors = new Sensor * [this->sensorCount];
                for (int i = 0; i < this->sensorCount; i++) {
                    newSensors[i] = this->allSensors[i];
                }
                delete[] this->allSensors;
                int a = this->sensorCount;
                this->sensorCount = sensorCount;
                this->allSensors = new Sensor * [sensorCount];
                for (int i = 0; i < this->sensorCount; i++) {
                    this->allSensors[i] = new Sensor();
                }
                for (int i = 0; i < a; i++) {
                    this->allSensors[i] = newSensors[i];
                }
                delete[] newSensors;
            }
            else
                throw new exception("The array already has this size!");
        }
        else
            throw new exception("You have entered a negative number of sensors");
    }
    void setAllSensors(Sensor** sensors) {
        if (sensors != nullptr)
            this->allSensors = sensors;
        else
            throw new exception("Please provide a non-null pointer");
    }
    //DEFAULT constructor
    SmartHome() {
        this->sensorCount = 0;
        this->allSensors = nullptr;
    }
    //constructor with parameters
    SmartHome(int sensorCount, Sensor** allSensors) {
        if (sensorCount <= 0)
            throw new exception("You have entered a negative number of sensors");
        if (allSensors == nullptr)
            throw new exception("Please provide a non-null pointer");
        this->sensorCount = sensorCount;
        this->allSensors = new Sensor*[sensorCount];
        for (int i = 0; i < sensorCount; i++) {
            this->allSensors[i] = allSensors[i];
        }
        // s_a_c change
        for (int i = 0; i < sensorCount; i++) {
            this->allSensors[i]->s_a_c = 1;
        }
    }
    //copy constructor
    SmartHome(const SmartHome& smartHome) {
        this->sensorCount = smartHome.sensorCount;
        this->allSensors = new Sensor*[smartHome.sensorCount];
        for (int i = 0; i < this->sensorCount; i++) {
            this->allSensors[i] = new Sensor();
        }
        for (int i = 0; i < smartHome.sensorCount; i++) {
            *this->allSensors[i] = *smartHome.allSensors[i];
        }
        // s_a_c change
        for (int i = 0; i < sensorCount; i++) {
            this->allSensors[i]->s_a_c = 1;
        }
        this->Rating = smartHome.Rating;
    }
    //operator= overload
    SmartHome operator=(const SmartHome& smartHome) {
        if (this->allSensors != nullptr) {
            delete[] this->allSensors;
        }
        this->sensorCount = smartHome.sensorCount;
        this->allSensors = new Sensor*[smartHome.sensorCount];
        for (int i = 0; i < this->sensorCount; i++) {
            this->allSensors[i] = new Sensor();
        }
        for (int i = 0; i < smartHome.sensorCount; i++) {
            *this->allSensors[i] = *smartHome.allSensors[i];
        }
        // s_a_c change
        for (int i = 0; i < sensorCount; i++) {
            this->allSensors[i]->s_a_c = 1;
        }
        this->Rating = smartHome.Rating;
        return *this;
    }
    //operator<< overload
    friend ostream& operator<<(ostream& out, const SmartHome& smartHome) {
        out << "Number of sensors in the smart home : " << smartHome.sensorCount << endl;
        for (int i = 0; i < smartHome.sensorCount; i++) {
            out << "Sensor " << i + 1 << " :" << endl;
            out << *smartHome.allSensors[i];
        }
        out << endl << "Smart Home Rating: " << smartHome.Rating << endl;
        return out;
    }
    //operator>> overload
    friend istream& operator>>(istream& in, SmartHome& smartHome) {
        cout << "Enter number of sensors : ";
        in >> smartHome.sensorCount;
        if (smartHome.allSensors != nullptr) {
            delete[] smartHome.allSensors;
        }
        smartHome.allSensors = new Sensor*[smartHome.sensorCount];
        for (int i = 0; i < smartHome.sensorCount; i++) {
            smartHome.allSensors[i] = new Sensor();
        }
        for (int i = 0; i < smartHome.sensorCount; i++) {
            cout << "Enter sensor " << i << " :" << endl;
            in >> *smartHome.allSensors[i];
        }
        correctS_a_c(smartHome.allSensors, smartHome.sensorCount);
        return in;
    }
    //ifstream& operator>> overload
    friend ifstream& operator>>(ifstream& in, SmartHome& smartHome) {
        in >> smartHome.sensorCount;
        if (smartHome.allSensors != nullptr) {
            delete[] smartHome.allSensors;
        }
        smartHome.allSensors = new Sensor*[smartHome.sensorCount];
        for (int i = 0; i < smartHome.sensorCount; i++) {
            smartHome.allSensors[i] = new Sensor();
        }
        for (int i = 0; i < smartHome.sensorCount; i++) {
            in >> *smartHome.allSensors[i];
        }
        correctS_a_c(smartHome.allSensors, smartHome.sensorCount);
        return in;
    }
    //operator++ - post overload
    SmartHome operator++(int) {
        SmartHome temp = *this;
        for (int i = 0; i < this->sensorCount; i++) {
            (*this->allSensors[i])++;
        }
        return temp;
    }
    //operator++ - pre overload
    SmartHome operator++() {
        for (int i = 0; i < this->sensorCount; i++) {
            (*this->allSensors[i])++;
        }
        return *this;
    }
    //operator+ overload
    SmartHome operator+(const SmartHome& smartHome) {
        if (this->sensorCount >= smartHome.sensorCount) {
            SmartHome home = *this;
            for (int i = 0; i < smartHome.sensorCount; i++) {
                *home.allSensors[i] = *this->allSensors[i] + *smartHome.allSensors[i];
            }
            return home;
        }
        else if (this->sensorCount < smartHome.sensorCount) {
            SmartHome home = smartHome;
            for (int i = 0; i < this->sensorCount; i++) {
                *home.allSensors[i] = *this->allSensors[i] + *smartHome.allSensors[i];
            }
            return home;
        }
    }
    //operator- overload
    SmartHome operator-(const SmartHome& smartHome) {
        if (this->sensorCount >= smartHome.sensorCount) {
            SmartHome home = *this;
            for (int i = 0; i < smartHome.sensorCount; i++) {
                *home.allSensors[i] = *this->allSensors[i] - *smartHome.allSensors[i];
            }
            return home;
        }
        else if (this->sensorCount < smartHome.sensorCount) {
            SmartHome home = smartHome;
            for (int i = 0; i < this->sensorCount; i++) {
                *home.allSensors[i] = *smartHome.allSensors[i] - *this->allSensors[i];
            }
            return home;
        }
    }
    //operator/ overload
    SmartHome operator/(const SmartHome& smartHome) {
        if (this->sensorCount >= smartHome.sensorCount) {
            SmartHome home = *this;
            for (int i = 0; i < smartHome.sensorCount; i++) {
                *home.allSensors[i] = *this->allSensors[i] / *smartHome.allSensors[i];
            }
            return home;
        }
        else if (this->sensorCount < smartHome.sensorCount) {
            SmartHome home = smartHome;
            for (int i = 0; i < this->sensorCount; i++) {
                *home.allSensors[i] = *smartHome.allSensors[i] / *this->allSensors[i];
            }
            return home;
        }
    }
    ~SmartHome() {
        if (this->allSensors != nullptr) {
            for (int i = 0; i < this->sensorCount; i++){
                if (this->allSensors[i] != nullptr) {
                    delete this->allSensors[i];
                }
            }
            delete[] this->allSensors;
        }
    }
};

int  Sensor::counter = 1;

// Writes the profile of the smart home sensors to the file path entered from the keyboard
void writeSmartHomeProfileToFilePath(SmartHome& smartHome) {
    string filePath;
    cout << "Enter the file path : " << endl; cin >> filePath;
    ofstream file(filePath, ios::out);
    if (!file.is_open()) {
        cout << endl << "The file does not exist at path : " << filePath;
    }
    else {
        Sensor** sensors = new Sensor*[smartHome.getSensorCount()];
        for (int i = 0; i < smartHome.getSensorCount(); i++) {
            sensors[i] = smartHome.getAllSensors()[i];
        }
        Profile* profile = new Profile[smartHome.getSensorCount()];
        for (int i = 0; i < smartHome.getSensorCount(); i++) {
            profile[i] = sensors[i]->getProfile();
        }
        file << "Number of Sensors : " << smartHome.getSensorCount() << endl << endl << endl;
        for (int i = 0; i < smartHome.getSensorCount(); i++) {
            file << "Sensor Profile " << i << " : ";
            file << profile[i];
        }
        file << endl;
        file << "Smart Home Rating : " << smartHome.getRating();
        delete[] sensors;
        delete[] profile;
        file.close();
    }
}

// Throws an exception if the sensor does not belong to the IoT system
void exceptionIfSensorNotInIoTSystem(Sensor* sensor) {
    if (sensor->getS_a_c() == 0)
        throw new exception("The sensor is not part of the IoT system!");
}

// Establishes an intermediate rating for a sensor
float establishSensorIntermediateRating(Sensor& sensor) {
    Profile profile = sensor.getProfile();
    float intermediateRating = 0;
    if (profile.getNetworkType(0) == 's' && profile.getCategory(0) == 'm' && profile.getWarranty() > 20 && profile.getWaterproof() == 1)
        intermediateRating = 10;
    else if (profile.getNetworkType(0) == 's' && profile.getCategory(0) == 'm' && profile.getWarranty() > 20 && profile.getWaterproof() == 0)
        intermediateRating = 9.8;
    else if (profile.getNetworkType(0) == 's' && profile.getCategory(0) == 'm' && profile.getWarranty() < 20 && profile.getWaterproof() == 1)
        intermediateRating = 9.6;
    else if (profile.getNetworkType(0) == 's' && profile.getCategory(0) == 's' && profile.getWarranty() > 20 && profile.getWaterproof() == 1)
        intermediateRating = 9.4;
    else if (profile.getNetworkType(0) == 's' && profile.getCategory(0) == 'm' && profile.getWarranty() < 20 && profile.getWaterproof() == 0)
        intermediateRating = 9.2;
    else if (profile.getNetworkType(0) == 's' && profile.getCategory(0) == 's' && profile.getWarranty() > 20 && profile.getWaterproof() == 0)
        intermediateRating = 9;
    else if (profile.getNetworkType(0) == 's' && profile.getCategory(0) == 's' && profile.getWarranty() < 20 && profile.getWaterproof() == 1)
        intermediateRating = 8.8;
    else if (profile.getNetworkType(0) == 's' && profile.getCategory(0) == 's' && profile.getWarranty() < 20 && profile.getWaterproof() == 0)
        intermediateRating = 8.6;
    else if (profile.getNetworkType(0) == 'a' && profile.getCategory(0) == 'm' && profile.getWarranty() > 20 && profile.getWaterproof() == 1)
        intermediateRating = 8.4;
    else if (profile.getNetworkType(0) == 'a' && profile.getCategory(0) == 'm' && profile.getWarranty() > 20 && profile.getWaterproof() == 0)
        intermediateRating = 8.2;
    else if (profile.getNetworkType(0) == 'a' && profile.getCategory(0) == 'm' && profile.getWarranty() < 20 && profile.getWaterproof() == 1)
        intermediateRating = 8;
    else if (profile.getNetworkType(0) == 'a' && profile.getCategory(0) == 's' && profile.getWarranty() > 20 && profile.getWaterproof() == 1)
        intermediateRating = 7.8;
    else if (profile.getNetworkType(0) == 'a' && profile.getCategory(0) == 'm' && profile.getWarranty() < 20 && profile.getWaterproof() == 0)
        intermediateRating = 7.6;
    else if (profile.getNetworkType(0) == 'a' && profile.getCategory(0) == 's' && profile.getWarranty() > 20 && profile.getWaterproof() == 0)
        intermediateRating = 7.4;
    else if (profile.getNetworkType(0) == 'a' && profile.getCategory(0) == 's' && profile.getWarranty() < 20 && profile.getWaterproof() == 1)
        intermediateRating = 7.2;
    else if (profile.getNetworkType(0) == 'a' && profile.getCategory(0) == 's' && profile.getWarranty() < 20 && profile.getWaterproof() == 0)
        intermediateRating = 7;
    else if (profile.getNetworkType(0) == 'p' && profile.getCategory(0) == 'm' && profile.getWarranty() > 20 && profile.getWaterproof() == 1)
        intermediateRating = 6.8;
    else if (profile.getNetworkType(0) == 'p' && profile.getCategory(0) == 'm' && profile.getWarranty() > 20 && profile.getWaterproof() == 0)
        intermediateRating = 6.6;
    else if (profile.getNetworkType(0) == 'p' && profile.getCategory(0) == 'm' && profile.getWarranty() < 20 && profile.getWaterproof() == 1)
        intermediateRating = 6.4;
    else if (profile.getNetworkType(0) == 'p' && profile.getCategory(0) == 's' && profile.getWarranty() > 20 && profile.getWaterproof() == 1)
        intermediateRating = 6.2;
    else if (profile.getNetworkType(0) == 'p' && profile.getCategory(0) == 'm' && profile.getWarranty() < 20 && profile.getWaterproof() == 0)
        intermediateRating = 6;
    else if (profile.getNetworkType(0) == 'p' && profile.getCategory(0) == 's' && profile.getWarranty() > 20 && profile.getWaterproof() == 0)
        intermediateRating = 5.8;
    else if (profile.getNetworkType(0) == 'p' && profile.getCategory(0) == 's' && profile.getWarranty() < 20 && profile.getWaterproof() == 1)
        intermediateRating = 5.6;
    else if (profile.getNetworkType(0) == 'p' && profile.getCategory(0) == 's' && profile.getWarranty() < 20 && profile.getWaterproof() == 0)
        intermediateRating = 5.4;
    else if (profile.getNetworkType(0) == 'c' && profile.getCategory(0) == 'm' && profile.getWarranty() > 20 && profile.getWaterproof() == 1)
        intermediateRating = 5.2;
    else if (profile.getNetworkType(0) == 'c' && profile.getCategory(0) == 'm' && profile.getWarranty() > 20 && profile.getWaterproof() == 0)
        intermediateRating = 5;
    else if (profile.getNetworkType(0) == 'c' && profile.getCategory(0) == 'm' && profile.getWarranty() < 20 && profile.getWaterproof() == 1)
        intermediateRating = 4.8;
    else if (profile.getNetworkType(0) == 'c' && profile.getCategory(0) == 's' && profile.getWarranty() > 20 && profile.getWaterproof() == 1)
        intermediateRating = 4.6;
    else if (profile.getNetworkType(0) == 'c' && profile.getCategory(0) == 'm' && profile.getWarranty() < 20 && profile.getWaterproof() == 0)
        intermediateRating = 4.4;
    else if (profile.getNetworkType(0) == 'c' && profile.getCategory(0) == 's' && profile.getWarranty() > 20 && profile.getWaterproof() == 0)
        intermediateRating = 4.2;
    else if (profile.getNetworkType(0) == 'c' && profile.getCategory(0) == 's' && profile.getWarranty() < 20 && profile.getWaterproof() == 1)
        intermediateRating = 4;
    else if (profile.getNetworkType(0) == 'c' && profile.getCategory(0) == 's' && profile.getWarranty() < 20 && profile.getWaterproof() == 0)
        intermediateRating = 3.8;
    else
        intermediateRating = 0;
    return intermediateRating;
}

// Establishes the rating of the smart home
void establishSmartHomeRating(SmartHome& smartHome) {
    float sum = 0;
    for (int i = 0; i < smartHome.getSensorCount(); i++) {
        sum += establishSensorIntermediateRating(*smartHome.getAllSensors()[i]) / smartHome.getSensorCount();
    }
    if (sum == 0)
        throw new exception("The sensors of the smart home do not have completed profiles!");
    smartHome.setRating(sum);
}

// Establishes the profile of a sensor
void establishSensorProfile(Sensor& sensor) {
    Profile profile;
    if (sensor.getInterconnectionWithOtherSensors() == true)
        profile.setCategory("monitoring");
    else
        profile.setCategory("surveillance");
    float formula;
    formula = (sensor.getLifespan() + sensor.getResetCount()) / 2 + sensor.getInteractionCount() / 4;
    profile.setWarranty(formula);
    if (sensor.getPositioning(0) == 'b')
        profile.setWaterproof(1);
    else if (sensor.getPositioning(0) == 'B')
        profile.setWaterproof(1);
    else
        profile.setWaterproof(0);
    if (sensor.getRemoteConnection() && sensor.getResponseTime() < 1)
        profile.setNetworkType("satellite");
    else if (sensor.getRemoteConnection() && sensor.getResponseTime() >= 1)
        profile.setNetworkType("antenna");
    else if (!sensor.getRemoteConnection() && sensor.getResponseTime() < 1)
        profile.setNetworkType("peertopeer");
    else
        profile.setNetworkType("cable");
    sensor.setProfile(profile);
}

// Establishes the profile for all sensors of the smart home
void establishProfilesForSmartHomeSensors(SmartHome& smartHome) {
    if (smartHome.getAllSensors() != nullptr) {
        for (int i = 0; i < smartHome.getSensorCount(); i++) {
            establishSensorProfile(*smartHome.getAllSensors()[i]);
        }
    }
    else
        throw new exception("The smart home does not contain sensors!");
}

// Reads the smart home from the "SENZORI.txt" file
void readSmartHomeFromFile(SmartHome& smartHome) {
    ifstream file("SENZORI.txt", ios::in);
    if (!file.is_open())
        cout << endl << "The file named : senzori.txt does not exist";
    else {
        file >> smartHome;
        file.close();
    }
}

// Shows how the virtual function is used
void exampleOfVirtualFunctionUsage(Sensor& sensor) {
    Device& device = (Device&)sensor;
    cout << sensor.emittedSound() << endl;
    cout << device.emittedSound();
}

void main() {
    try {
        int a = 2;
        Sensor** s = new Sensor * [a];
        s[0] = new Sensor(30, 40, 40, new int[3]{ 1,2,3 }, 3, new char[10]{ 'b','u','c','a','t','a','r','i','e' }, 0.2, 0.2, true, "nosignal", true, 2022, 160.5);
        s[1] = new Sensor(4, 4, 4, new int[4]{ 6 , 9 , 7 , 5 }, 4, new char[4]{ 'h' , 'o' , 'l' }, 4.3, 18.9, true, "nobattery", false, 2005, 80.3);
        //exceptionIfSensorNotInIoTSystem(s[0]);
        SmartHome smartHome(2, s);
        //readSmartHomeFromFile(smartHome);
        cin >> smartHome;
        cout << smartHome;
        establishProfilesForSmartHomeSensors(smartHome);
        establishSmartHomeRating(smartHome);
        writeSmartHomeProfileToFilePath(smartHome);
        //exceptionIfSensorNotInIoTSystem(s[0]);
        //exampleOfVirtualFunctionUsage(*s[0]);

        //Operators<Sensor> op(2, new Sensor[2]{ *s[0], *s[1] });
        if (s != nullptr) {
            delete[] s;
        }
    }
    catch (exception* ex) {
        cout << ex->what();
    }
    catch (...) {
        cout << "An unknown problem occurred";
    }
}
