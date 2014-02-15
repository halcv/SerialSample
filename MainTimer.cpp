#include "MainTimer.h"
#include "MyInstance.h"

#define METRO_INTERVAL (100)

CMainTimer::CMainTimer()
{
	m_pMetro = new Metro(METRO_INTERVAL);
}

VOID CMainTimer::vLoop()
{
	if (m_pMetro->check() == true) {
		CMyInstance::GetCommandManagerInstance()->vCheckCommand();
	}
}
