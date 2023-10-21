#include <iostream>
#include "libIIoT.h"

using namespace std;

int main(int argc, char** argv)
{
    
    srand(time(0));
    
    if(argc != 3)
    {
        cerr << "Invalid number of arguments <intRows> <intCols>" << endl;
        exit(0);
    }
    
    int intRows = stoi(argv[1]);
    int intCols = stoi(argv[2]);
    
    //Create object
    IIoTMonitor objIIoTMonitor(intRows, intCols);
    
    for(int r=0; r<intRows; r++)
    {
        cout << objIIoTMonitor.toString(r) << endl;
    }
    
    
    return 0;
}




