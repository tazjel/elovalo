/* -*- mode: c; c-file-style: "linux" -*-
 *  vi: set shiftwidth=8 tabstop=8 noexpandtab:
 *
 *  Copyright 2012 Elovalo project group 
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

# pragma FLIP

#include "common.h"

XY(effect)
{
	const float scaler = (float)MAX_2D_PLOT_INTENSITY/2;
	const float time = (float)ticks/100;
	const float x_ = x*cos(time)-y*sin(time);
	const float y_ = x*sin(time)+y*cos(time);
	uint16_t i = scaler*(1+sin(0.8*(x_+y_+time)));

	set_z(x, y, i);
}
