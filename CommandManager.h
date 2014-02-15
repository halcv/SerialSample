#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_

#include "MySystype.h"

#define COMMAND_SIZE   (2)
#define COMMAND_LENGTH (10)

class CCommandManager {
  public:
	CCommandManager();
	VOID vCheckCommand();
	
  private:
	UI_8 m_ucCommandBuff[COMMAND_LENGTH];
	static UI_8 m_ucCommandDataTable[COMMAND_SIZE][COMMAND_LENGTH];
	VOID vCommandBufferClear();
	VOID vCommandExecute();
};

#endif // _COMMAND_MANAGER_H_
