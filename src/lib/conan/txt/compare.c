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
 * return -1 if a <  b  or if a is     null and b is not null
 *         0 if a == b  or if a is     null and b is     null
 *         1 if a  > b  or if a is not null and b is     null
 */
int ConanTXTCompare(conanTXT *a, conanTXT *b) {
	int aIsNull = a ? a->null : 1;
	int bIsNull = b ? b->null : 1;

	int rv;

	if (aIsNull || bIsNull) {
		if (aIsNull && bIsNull) {
			rv = 0;
		} else if (aIsNull) {
			rv = -1;
		} else {
			rv = 1;
		}
	} else {
		rv = strcmp(a->data, b->data);
		if (rv < -1) {
			rv = -1;
		} else if (rv > 1) {
			rv = 1;
		}
	}

	return rv;
}
