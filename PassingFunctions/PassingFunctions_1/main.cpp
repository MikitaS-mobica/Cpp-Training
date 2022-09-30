#include "Bridge.h"
#include "ArchBridge.h"
#include "TiedArchBridge.h"


void testCopyBridge(Bridge obj)
{
    obj.cross();
    
    return;
}


void testTheBridge(Bridge &obj)
{
    obj.cross();
    
    return;
}


int main()
{
    TiedArchBridge newBridge;

    newBridge.cross();
    newBridge.passUnder();
    newBridge.takePhoto();

    Bridge &testBridge = newBridge;

    testBridge.cross();

    testCopyBridge(newBridge);
    testTheBridge(newBridge);

    return 0;
}
