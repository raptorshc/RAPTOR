#include <SoftwareSerial.h> // This allows it to communicate with the Arduino's Serial Ports

class Openlog()
{
    public:
        Openlog();
        void Read_Disk();
    private:
        void Go_To_CommandMode(void)
        void Setup_OpenLog(void);
}