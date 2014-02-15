#include "SerialDriver.h"

CSerialDriver::CSerialDriver()
{
	Serial.begin(9600);
	vRxBuffClear();
	vTxBuffClear();
	m_isSendState = false;
}

VOID CSerialDriver::vRxBuffClear()
{
	m_sRxBuffInfo.iRemain = 0;
	m_sRxBuffInfo.iRead = 0;
	m_sRxBuffInfo.iWrite = 0;
}

VOID CSerialDriver::vTxBuffClear()
{
	m_sTxBuffInfo.iRemain = 0;
	m_sTxBuffInfo.iRead = 0;
	m_sTxBuffInfo.iWrite = 0;
}

VOID CSerialDriver::vRead()
{
	if (Serial.available() > 0) {
		UI_8 ucData = Serial.read();
		iWriteDataRxBuff(ucData);
	}
}

VOID CSerialDriver::vWrite()
{
	UI_8 ucData;
	if (iReadDataTxBuff(&ucData)) {
		Serial.write(ucData);
	}
}

INT CSerialDriver::iWriteDataRxBuff(UI_8 ucData)
{
	int iRet = 0;
	if (m_sRxBuffInfo.iRemain < BUFF_SIZE) {
		iRet = 1;
		m_ucRxBuff[m_sRxBuffInfo.iWrite] = ucData;
		m_sRxBuffInfo.iRemain++;
		m_sRxBuffInfo.iWrite++;
		if (m_sRxBuffInfo.iWrite >= BUFF_SIZE) {
			m_sRxBuffInfo.iWrite = 0;
		}
	}

	return iRet;
}

INT CSerialDriver::iReadDataRxBuff(UI_8* pData)
{
	INT iRet = 0;
	if (m_sRxBuffInfo.iRemain > 0) {
		iRet = 1;
		*pData = m_ucRxBuff[m_sRxBuffInfo.iRead];
		m_sRxBuffInfo.iRemain--;
		m_sRxBuffInfo.iRead++;
		if (m_sRxBuffInfo.iRead >= BUFF_SIZE) {
			m_sRxBuffInfo.iRead = 0;
		}
	}
	
	return iRet;
}

INT CSerialDriver::iWriteDataTxBuff(UI_8 ucData)
{
	INT iRet = 0;
	if (m_sTxBuffInfo.iRemain < BUFF_SIZE) {
		iRet = 1;
		m_ucTxBuff[m_sTxBuffInfo.iWrite] = ucData;
		m_sTxBuffInfo.iRemain++;
		m_sTxBuffInfo.iWrite++;
		if (m_sTxBuffInfo.iWrite >= BUFF_SIZE) {
			m_sTxBuffInfo.iWrite = 0;
		}
	}
	return iRet;
}

INT CSerialDriver::iReadDataTxBuff(UI_8* pData)
{
	INT iRet = 0;
	if (m_sTxBuffInfo.iRemain > 0) {
		iRet = 1;
		*pData = m_ucTxBuff[m_sTxBuffInfo.iRead];
		m_sTxBuffInfo.iRemain--;
		m_sTxBuffInfo.iRead++;
		if (m_sTxBuffInfo.iRead >= BUFF_SIZE) {
			m_sTxBuffInfo.iRead = 0;
		}
	}

	return iRet;
}

VOID CSerialDriver::vPutStr(CHAR* pData)
{
	while(*pData != 0) {
		iWriteDataTxBuff(*pData);
		pData++;
	}
}
