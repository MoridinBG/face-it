#ifndef __NETWORK_INTERFACE_H
#define __NETWORK_INTERFACE_H

class NetworkInterface
{
public:
    NetworkInterface() {}
    virtual ~NetworkInterface() {}


private:
    NetworkInterface( const NetworkInterface& source );
    void operator = ( const NetworkInterface& source );
};


#endif // __NETWORK_INTERFACE_H
