#include <Metro.h>
#include "MySystype.h"
#include "MyInstance.h"

VOID setup()
{
	CMyInstance::vCreateInstance();
}

VOID loop()
{
	CMyInstance::GetMainTimerInstance()->vLoop();
	CMyInstance::GetSerialDriverInstance()->vRead();
	CMyInstance::GetSerialDriverInstance()->vWrite();
}
