/*
 *  Copyright 2012 Elovalo project group 
 *  
 *  This file is part of Elovalo.
 *  
 *  Elovalo is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  Elovalo is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with Elovalo.  If not, see <http://www.gnu.org/licenses/>.
 */

# pragma FLIP

#include "common.h"

static uint8_t get_amount_of_neighbours(uint8_t x, uint8_t y, uint8_t z);
static void set_leds(uint8_t x, uint8_t y, uint8_t z);

void init(void)
{
	// TODO: might want to use some other seed. using heart for testing
	heart_shape();
}

void effect(void) {
	iterate_xyz(set_leds);
}

void set_leds(uint8_t x, uint8_t y, uint8_t z)
{
	uint8_t neighbours = get_amount_of_neighbours((int8_t)x, (int8_t)y, (int8_t)z);

	if(neighbours >= 9 && neighbours <= 14) set_led(x, y, z, MAX_INTENSITY);
	else set_led(x, y, z, 0);
}

static uint8_t get_amount_of_neighbours(uint8_t x, uint8_t y, uint8_t z) {
	uint8_t ret = 0;

	for(int8_t cx = -1; cx <= 1; cx++)
		for(int8_t cy = -1; cy <= 1; cy++)
			for(int8_t cz = -1; cz <= 1; cz++)
				ret += get_led_wrap(x + cx, y + cy, z + cz) > 0;

	return ret;
}