#include "CommandManager.h"
#include "SerialDriver.h"
#include "MyInstance.h"

UI_8 CCommandManager::m_ucCommandDataTable[COMMAND_SIZE][COMMAND_LENGTH] = {
	"on",
	"off"
};

CCommandManager::CCommandManager()
{
	vCommandBufferClear();
}

VOID CCommandManager::vCommandBufferClear()
{
	for (int i = 0;i < COMMAND_LENGTH;i++) {
		m_ucCommandBuff[i] = 0;
	}
}

VOID CCommandManager::vCheckCommand()
{
	UI_8 ucData = 0;
	int iRet = 0;

	for (int i = 0;i < COMMAND_LENGTH;i++) {
		iRet = CMyInstance::GetSerialDriverInstance()->iReadDataRxBuff(&ucData);
		if (iRet == 1) {
			m_ucCommandBuff[i] = ucData;
		} else {
			m_ucCommandBuff[i] = 0;
		}
	}

	if (iRet == 1) {
		do {
			iRet = CMyInstance::GetSerialDriverInstance()->iReadDataRxBuff(&ucData);
		} while (iRet == 1);
	}
	vCommandExecute();
}

VOID CCommandManager::vCommandExecute()
{
	int i;
	for (i = 0;i < COMMAND_LENGTH;i++) {
		if (m_ucCommandBuff[i] == '\r' || m_ucCommandBuff[i] == '\n') {
			m_ucCommandBuff[i] = 0;
		}
	}
	
	for (i = 0;i < COMMAND_SIZE;i++) {
		if (strcmp((const char*)m_ucCommandDataTable[i],(const char*)m_ucCommandBuff) == 0) {
			CHAR *pStr;
			switch (i) {
			case 0:
				pStr = (CHAR*)"ON\n";
				break;
			case 1:
				pStr = (CHAR*)"OFF\n";
			}
			CMyInstance::GetSerialDriverInstance()->vPutStr(pStr);
			break;
		}
	}
}
