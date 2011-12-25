/*************************************************************************
 * conan - the brute force CGI
 * Copyright (c) 2011 Michael D Henderson
 *
 * This file is part of conan (http://github.com/quoha/conan).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *************************************************************************/

#include "../local.h"
#include <stdlib.h>
#include <string.h>

/*************************************************************************
 */
conanTXT *ConanTXTFromCString(const char *value) {
	return ConanTXTFromString(value, strlen(value ? value : ""));
}

/*************************************************************************
 */
conanTXT *ConanTXTFromString(const char *value, int len) {
	if (len < 0) {
		len = 0;
	}

	conanTXT *txt = ConanTXTNew(len);
	if (txt) {
		txt->lenCurr = len;
		if (value) {
			txt->null = 0;
			memcpy(txt->data, value, len);
		}
	}

	return txt;
}

/*************************************************************************
 */
conanTXT *ConanTXTNew(int len) {
	if (len < 0) {
		len = 0;
	}

	conanTXT *txt = malloc(sizeof(*txt) + len);
	if (txt) {
		txt->lenCurr   = 0;
		txt->lenMax    = len;
		txt->tainted   = 0;
		txt->null      = 1;
		txt->data[0]   = 0;
		txt->data[len] = 0;
	}

	return txt;
}
