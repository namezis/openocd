/***************************************************************************
 *   Copyright (C) 2007 by Dominic Rath                                    *
 *   Dominic.Rath@gmx.de                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef ETB_H
#define ETB_H

/* ETB registers */
enum
{
	ETB_ID = 0x00,
	ETB_RAM_DEPTH = 0x01,
	ETB_RAM_WIDTH = 0x02,
	ETB_STATUS = 0x03,
	ETB_RAM_DATA = 0x04,
	ETB_RAM_READ_POINTER = 0x05,
	ETB_RAM_WRITE_POINTER = 0x06,
	ETB_TRIGGER_COUNTER = 0x07,
	ETB_CTRL = 0x08,
};

struct etb
{
	etm_context_t *etm_ctx;
	struct jtag_tap *tap;
	uint32_t cur_scan_chain;
	struct reg_cache *reg_cache;

	/* ETB parameters */
	uint32_t ram_depth;
	uint32_t ram_width;
};

struct etb_reg
{
	uint32_t addr;
	struct etb *etb;
};

extern struct etm_capture_driver etb_capture_driver;

struct reg_cache* etb_build_reg_cache(struct etb *etb);

#endif /* ETB_H */
