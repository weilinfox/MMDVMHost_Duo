/*
 *   Copyright (C) 2016,2017,2018,2020,2021 by Jonathan Naylor G4KLX & Tony Corbett G0WFV
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(HD44780_H)
#define	HD44780_H

#include "Display.h"
#include "Timer.h"

#include <string>
#include <vector>


class CHD44780 : public CDisplay
{
public:
	CHD44780(unsigned int rows, unsigned int cols, const std::string& callsign, unsigned int dmrid, const std::vector<unsigned int>& pins, unsigned int i2cAddress, bool pwm, unsigned int pwmPin, unsigned int pwmBright, unsigned int pwmDim, bool displayClock, bool utc, bool duplex);
	virtual ~CHD44780();

	virtual bool open();

	virtual void close();

protected:
	virtual void setIdleInt();
	virtual void setErrorInt(const char* text);
	virtual void setLockoutInt();
	virtual void setQuitInt();
	virtual void setFMInt();

	virtual void writeDStarInt(const char* my1, const char* my2, const char* your, const char* type, const char* reflector);
	virtual void writeDStarRSSIInt(unsigned char rssi); 
	virtual void clearDStarInt();

	virtual void writeDMRInt(unsigned int slotNo, const std::string& src, bool group, const std::string& dst, const char* type);
	virtual void writeDMRRSSIInt(unsigned int slotNo, unsigned char rssi); 
	virtual void clearDMRInt(unsigned int slotNo);

	virtual void writeFusionInt(const char* source, const char* dest, unsigned char dgid, const char* type, const char* origin);
	virtual void writeFusionRSSIInt(unsigned char rssi); 
	virtual void clearFusionInt();

	virtual void writeP25Int(const char* source, bool group, unsigned int dest, const char* type);
	virtual void writeP25RSSIInt(unsigned char rssi); 
	virtual void clearP25Int();

	virtual void writeNXDNInt(const char* source, bool group, unsigned int dest, const char* type);
	virtual void writeNXDNRSSIInt(unsigned char rssi); 
	virtual void clearNXDNInt();

	virtual void writeM17Int(const char* source, const char* dest, const char* type);
	virtual void writeM17RSSIInt(unsigned char rssi);
	virtual void clearM17Int();

	virtual void writePOCSAGInt(uint32_t ric, const std::string& message);
	virtual void clearPOCSAGInt();

	virtual void writeCWInt();
	virtual void clearCWInt();

	virtual void clockInt(unsigned int ms);

private:
	unsigned int m_rows;
	unsigned int m_cols;
	std::string  m_callsign;
	unsigned int m_dmrid;
	unsigned int m_rb;
	unsigned int m_strb;
	unsigned int m_d0;
	unsigned int m_d1;
	unsigned int m_d2;
	unsigned int m_d3;
	unsigned int m_i2cAddress;
	bool         m_pwm;
	unsigned int m_pwmPin;
	unsigned int m_pwmBright;
	unsigned int m_pwmDim;
	bool         m_displayClock;
	bool         m_utc;
	bool         m_duplex;
	int          m_fd;
	bool         m_dmr;
	CTimer       m_clockDisplayTimer;
	unsigned int m_rssiCount1;
	unsigned int m_rssiCount2;
/*
	CTimer       m_dmrScrollTimer1;
	CTimer       m_dmrScrollTimer2;
	CTimer       m_dstarScrollTimer;
*/

};

#endif
