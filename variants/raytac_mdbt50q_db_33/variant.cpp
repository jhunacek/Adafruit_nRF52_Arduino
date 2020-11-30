/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

// There are lots of invalid pins here, but it is easier to keep it
// straight this way since there aren't D0/1/etc labels on this board.
const uint32_t g_ADigitalPinMap[] =
{
	0, // D0 P0.00
	1, // D1 P0.01
	2, // D2 P0.02
	3, // D3 P0.03
	4, // D4 P0.04
	5, // D5 P0.05
	6, // D6 P0.06
	7, // D7 P0.07
	8, // D8 P0.08
	9, // D9 P0.09
	10, // D10 P0.10
	11, // D11 P0.11
	12, // D12 P0.12
	13, // D13 P0.13
	14, // D14 P0.14
	15, // D15 P0.15
	16, // D16 P0.16
	17, // D17 P0.17
	18, // D18 P0.18
	19, // D19 P0.19
	20, // D20 P0.20
	21, // D21 P0.21
	22, // D22 P0.22
	23, // D23 P0.23
	24, // D24 P0.24
	25, // D25 P0.25
	26, // D26 P0.26
	27, // D27 P0.27
	28, // D28 P0.28
	29, // D29 P0.29
	30, // D30 P0.30
	31, // D31 P0.31

	32, // D32 P1.00
	33, // D33 P1.01
	34, // D34 P1.02
	35, // D35 P1.03
	36, // D36 P1.04
	37, // D37 P1.05
	38, // D38 P1.06
	39, // D39 P1.07
	40, // D40 P1.08
	41, // D41 P1.09
	42, // D42 P1.10
	43, // D43 P1.11
	44, // D44 P1.12
	45, // D45 P1.13
	46, // D46 P1.14
	47, // D47 P1.15
	48, // D48 P1.16
	49, // D49 P1.17
	50, // D50 P1.18
	51, // D51 P1.19
	52, // D52 P1.20
	53, // D53 P1.21
	54, // D54 P1.22
	55, // D55 P1.23
	56, // D56 P1.24
	57, // D57 P1.25
	58, // D58 P1.26
	59, // D59 P1.27
	60, // D60 P1.28
	61, // D61 P1.29
	62, // D62 P1.30
	63, // D63 P1.31
};

void initVariant()
{
  // LED1 & LED2
  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

  pinMode(PIN_LED2, OUTPUT);
  ledOff(PIN_LED2);
}

