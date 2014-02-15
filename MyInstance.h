#ifndef _MY_INSTANCE_H_
#define _MY_INSTANCE_H_

#include "MySystype.h"
#include "SerialDriver.h"
#include "MainTimer.h"
#include "CommandManager.h"

class CMyInstance {
  public:
	static VOID vCreateInstance();
	static CSerialDriver* GetSerialDriverInstance();
	static CMainTimer* GetMainTimerInstance();
	static CCommandManager* GetCommandManagerInstance();
	
  private:
	static CSerialDriver* m_pSerialDriver;
	static CMainTimer* m_pMainTimer;
	static CCommandManager* m_pCommandManager;
};

#endif // _MY_INSTANCE_H_
