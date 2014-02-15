#ifndef _SERIAL_DRIVER_H_
#define _SERIAL_DRIVER_H_

#include "MySystype.h"

#define BUFF_SIZE    (128)

typedef struct {
	INT iRemain; // バッファ中の残データ数
	INT iRead;   // 読み出し位置
	INT iWrite;  // 書き込み位置
} S_BUFF_INFO;

class CSerialDriver {
  public:
	CSerialDriver(); // コンストラクタ
	VOID vRead();
	VOID vWrite();
	INT iWriteDataTxBuff(UI_8 ucData);
	INT iReadDataRxBuff(UI_8* pData);
	VOID vPutStr(CHAR *pData);
  private:
	UI_8 m_ucRxBuff[BUFF_SIZE];
	UI_8 m_ucTxBuff[BUFF_SIZE];

	S_BUFF_INFO m_sTxBuffInfo;
	S_BUFF_INFO m_sRxBuffInfo;
	BOOL m_isSendState;
	
	VOID vRxBuffClear();
	VOID vTxBuffClear();
	INT iWriteDataRxBuff(UI_8 ucData);
	INT iReadDataTxBuff(UI_8* pData);
};

#endif // _SERIAL_DRIVER_H_
