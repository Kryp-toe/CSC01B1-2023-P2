#include "libIIoT.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//default constuctor
IIoTMonitor::IIoTMonitor() : IIoTMonitor(DEFAULT_ROWS, DEFAULT_COLS)
{/*No work needs to be done */}

//constructor
IIoTMonitor::IIoTMonitor(int introws, int intcols)
{
    //where the dimensions of the area being monitored and a default value for all the sensors are specified
    _rows = introws;
    _cols = intcols;
    
    _sensor = new scIIoTSensor*[_rows];
    for(int r=0; r<_rows; r++)
    {
        _sensor[r] = new scIIoTSensor[_cols];
        
        for(int c=0; c<_cols; c++)
        {
            _sensor[r][c] = DEFAULT_SENSOR;
        }
    }
    setSensorData();
}

//Copy constructor
IIoTMonitor::IIoTMonitor(const IIoTMonitor& objOriginal) : IIoTMonitor(objOriginal._rows, objOriginal._cols)
{
    for(int r=0; r<_rows; r++)
    {
        for(int c=0; c<_cols; c++)
        {
            _sensor[r][c] = objOriginal._sensor[r][c];
        }
    }
}

//Destructor
IIoTMonitor::~IIoTMonitor()
{
    for(int r=0; r<_rows; r++)
    {
        delete[] _sensor[r];
    }
    delete[] _sensor;
    _sensor = nullptr;
}

/*
* By placing 'const' at the end of a function's header,
* we ensure that the function cannot modify the state of
* the object.
*/

//Accessor member functions
int IIoTMonitor::getRows() const
{
    return _rows;
}

int IIoTMonitor::getCols() const
{
    return _cols;
}

double getrand(int high, int low)
{
    int range = high - low + 1;
    return rand() % range + low;
}

void IIoTMonitor::setSensorData() //generates random sensor data for each of the IIoTSensor using the range of valid values. This function must be called in the constructor that does the initialisation
{
    for(int r=0; r<_rows; r++)
    {
        for(int c=0; c<_cols; c++)
        {
            _sensor[r][c].SensorID = r*c; 
            _sensor[r][c].Temperature = getrand(50,0);
            _sensor[r][c].Humidity = getrand(40,0);
            _sensor[r][c].Pressure = getrand(40,0);
            _sensor[r][c].LightIntensity = getrand(200000,0);
        }
    }
}

string IIoTMonitor::toString(int r) const
{
    stringstream ss;
    
    for(int c=0; c<_cols; c++)
    {
        int count = 0;
        char temp = '.';
        
        if(_sensor[r][c].Temperature <= 0  || _sensor[r][c].Temperature>40)
        {
            temp = 'T';
            count ++;
        }
        else if(_sensor[r][c].Humidity <= 0  || _sensor[r][c].Humidity>30)
        {
            temp = 'H';
            count ++;
        }
        else if(_sensor[r][c].Pressure <= 0  || _sensor[r][c].Pressure>30.2)
        {
            temp = 'P';
            count ++;
        }
        else if(_sensor[r][c].LightIntensity < 0  || _sensor[r][c].LightIntensity>100000)
        {
            temp = 'L';
            count ++;
        }
        
        if(count = 0)
        {
            temp = '.';
        }
        else if(count > 1)
        {
            temp = 'M';
        }
        
        ss << temp << " ";
    }
    ss << endl;
    return ss.str();
}



