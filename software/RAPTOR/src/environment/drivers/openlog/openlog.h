#include <SoftwareSerial.h> // This allows it to communicate with the Arduino's Serial Ports

class Openlog()
{
    public:
        Openlog();
        void readDisk();
    private:
        void goToCommandMode(void)
        void setupOpenLog(void);
}