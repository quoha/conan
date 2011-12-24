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

/*****************************************************************************
 */
static void T0000(CuTest* tc) {
	conanTXT *txt1 = 0;
	conanTXT *txt2 = 0;
	CuAssertTrue(tc, ConanTXTCompare(txt1, txt2) == 0);
}

/*****************************************************************************
 */
static void T0001(CuTest* tc) {
	conanTXT *txt1 = ConanTXTFromCString("T0001 Test");
	conanTXT *txt2 = 0;
	CuAssertTrue(tc, ConanTXTCompare(txt1, txt2) == 1);
}

/*****************************************************************************
 */
static void T0002(CuTest* tc) {
	conanTXT *txt1 = 0;
	conanTXT *txt2 = ConanTXTFromCString("T0002 Test");
	CuAssertTrue(tc, ConanTXTCompare(txt1, txt2) == -1);
}

/*****************************************************************************
 */
static void T0003(CuTest* tc) {
	conanTXT *txt1 = ConanTXTFromCString("T0003 Test");
	conanTXT *txt2 = ConanTXTFromCString("T0003 Test");
	CuAssertTrue(tc, ConanTXTCompare(txt1, txt2) == 0);
}

/*****************************************************************************
 */
static void T0004(CuTest* tc) {
	conanTXT *txt1 = ConanTXTFromCString("T0004 Test 1");
	conanTXT *txt2 = ConanTXTFromCString("T0004 Test 2");
	CuAssertTrue(tc, ConanTXTCompare(txt1, txt2) == -1);
}

/*****************************************************************************
 */
static void T0005(CuTest* tc) {
	conanTXT *txt1 = ConanTXTFromCString("T0005 Test 1");
	CuAssertTrue(tc, ConanTXTCompare(txt1, txt1) == 0);
}

/*****************************************************************************
 */
static void T0006(CuTest* tc) {
	conanTXT *txt1 = ConanTXTFromCString("T0006 Test 2");
	conanTXT *txt2 = ConanTXTFromCString("T0006 Test 1");
	CuAssertTrue(tc, ConanTXTCompare(txt1, txt2) == 1);
}

/*****************************************************************************
 */
CuSuite *GetSuiteTXTCompare(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, T0000);
	SUITE_ADD_TEST(suite, T0001);
	SUITE_ADD_TEST(suite, T0002);
	SUITE_ADD_TEST(suite, T0003);
	SUITE_ADD_TEST(suite, T0004);
	SUITE_ADD_TEST(suite, T0005);

	return suite;
}
