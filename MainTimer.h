#ifndef _MAIN_TIMER_H_
#define _MAIN_TIMER_H_

#include <Metro.h>
#include "MySystype.h"

class CMainTimer {
  public:
	CMainTimer();
	VOID vLoop();
  private:
	Metro* m_pMetro;
};

#endif // _MAIN_TIMER_H_
