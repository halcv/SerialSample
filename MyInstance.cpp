#include "MyInstance.h"

CSerialDriver* CMyInstance::m_pSerialDriver = NULL;
CMainTimer* CMyInstance::m_pMainTimer = NULL;
CCommandManager* CMyInstance::m_pCommandManager = NULL;

VOID CMyInstance::vCreateInstance()
{
	m_pMainTimer = new CMainTimer();
	m_pSerialDriver = new CSerialDriver();
	m_pCommandManager = new CCommandManager();
}

CSerialDriver* CMyInstance::GetSerialDriverInstance()
{
	return m_pSerialDriver;
}

CMainTimer* CMyInstance::GetMainTimerInstance()
{
	return m_pMainTimer;
}

CCommandManager* CMyInstance::GetCommandManagerInstance()
{
	return m_pCommandManager;
}
