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
conanTXT *ConanTXTConcat(conanTXT *a, conanTXT *b) {
	conanTXT *txt = 0;

	if (a && b) {
		txt = ConanTXTNew(a->lenCurr + b->lenCurr);
		if (txt) {
			if (a->null && b->null) {
				txt->null = 1;
			} else {
				txt->null = 0;
			}
			txt->lenCurr = a->lenCurr + b->lenCurr;
			txt->tainted = 0;
			memcpy(txt->data             , a->data, a->lenCurr);
			memcpy(txt->data + a->lenCurr, b->data, b->lenCurr);
		}
	} else if (a && !a->null) {
		txt = ConanTXTFromString(a->data, a->lenCurr);
	} else if (b && !b->null) {
		txt = ConanTXTFromString(b->data, b->lenCurr);
	} else {
		txt = ConanTXTNew(0);
	}

	return txt;
}
