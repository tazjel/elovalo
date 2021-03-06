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

void effect(void)
{
	clear_buffer();

	// If no custom data, do nothing
	if (custom_data == NULL) return;
	const struct glyph_buf *text = (const struct glyph_buf *)custom_data;

	int16_t pos = ticks >> 3;
	scroll_text(text, true, pos, render_xy);
	scroll_text(text, true, pos-7, render_yz);
}

