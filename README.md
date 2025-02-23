# IoT Application
A C++ console application that manages sensor profiles in an IoT (Internet of Things) system.

## Technologies Used:
- C++ language
- OOP (Object-Oriented Programming)

## Implemented Classes:
- **class Operators** – Represents a TEMPLATE class.
- **class Device** – Represents an abstract class, serving as the parent class of the ‘Sensor’ class.
- **class Profile** – Represents sensor profile classes, consisting of four key attributes.
- **class Sensor** – Represents a class containing all the measured attributes needed to establish the profile.
- **class SmartHome** – Represents our IoT system, containing a vector of sensors and an attribute called ‘Rating,’ which is calculated based on the sensor profiles within the respective Smart Home, as explained below.

### Algorithm for Determining Sensor Profiles and Assessing the Intelligence Level of the IoT System:
The profile of a sensor consists of establishing the four attributes from the **Profile** class:
- `string category;`
- `int warranty;`
- `bool waterproof;`
- `string networkType;`
