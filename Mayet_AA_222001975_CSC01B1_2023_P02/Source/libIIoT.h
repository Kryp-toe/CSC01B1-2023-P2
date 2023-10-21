#ifndef IIOT_H
#define IIOT_H

#include <string>

using namespace std;

struct scIIoTSensor
{
    int SensorID;
    double Temperature;  //0 - 50
    int Humidity;  //0 - 40
    double Pressure;  //0 - 40
    double LightIntensity;   //0 - 200000
};

class IIoTMonitor
{
public:
    //default constuctor
    IIoTMonitor();
    
    //constructor
    IIoTMonitor(int introws, int intcols);  //where the dimensions of the area being monitored and a default value for all the sensors are specified
    
    //Copy constructor
    IIoTMonitor(const IIoTMonitor& objOriginal);
    
    //Destructor
    ~IIoTMonitor();
    
    /*
     * By placing 'const' at the end of a function's header,
     * we ensure that the function cannot modify the state of
     * the object.
    */
    
    //Accessor member functions
    int getRows() const;
    int getCols() const;
    void setSensorData(); //generates random sensor data for each of the IIoTSensor using the range of valid values. This function must be called in the constructor that does the initialisation
    
    string toString(int r) const;
    /*
    //represents sensors states. A malfunctioning or faulty sensor is defined as follows: 
    ▪ Temperature (value <= 0 OR value > 40) 
    ▪ Humidity (value <= 0 OR value > 30) 
    ▪ Pressure (value <= 0 OR value > 30.2) 
    ▪ Light Intensity (value < 0 OR value > 100000)
    
    o The toString function should return the following characters:
    ▪ M if more than one sensor in the IIoTSensor is malfunctioning
    ▪ T if only the temperature sensor is malfunctioning
    ▪ H if only the humidity sensor is malfunctioning
    ▪ P if only the pressure sensor is malfunctioning
    ▪ L if only the light intensity sensor is malfunctioning
    ▪ . if no sensor is malfunctioning
    */
    
    //Class constants
    static const int DEFAULT_ROWS = 5;
    static const int DEFAULT_COLS = 5;
    static constexpr scIIoTSensor DEFAULT_SENSOR = {0,-1,-1,-1,-1};
    
private:
    // Member variables (state).
    int _rows;
    int _cols;
    scIIoTSensor** _sensor;
};
#endif