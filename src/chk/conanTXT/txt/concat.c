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

	CuAssertTrue(tc, txt1       == 0);
	CuAssertTrue(tc, txt2       == 0);

	conanTXT *txt3 = ConanTXTConcat(txt1, txt2);
	CuAssertTrue(tc, txt3 != 0);
	CuAssertTrue(tc, txt3->lenMax  == 0);
	CuAssertTrue(tc, txt3->lenCurr == 0);
	CuAssertTrue(tc, txt3->null    == 1);
	CuAssertTrue(tc, txt3->tainted == 0);
}

/*****************************************************************************
 */
static void T0001(CuTest* tc) {
	const char  *s = 0;
	conanTXT *txt1 = ConanTXTFromCString(s);
	conanTXT *txt2 = 0;

	CuAssertTrue(tc, txt1       != 0);
	CuAssertTrue(tc, txt1->null == 1);
	CuAssertTrue(tc, txt2       == 0);

	conanTXT *txt3 = ConanTXTConcat(txt1, txt2);
	CuAssertTrue(tc, txt3 != 0);
	CuAssertTrue(tc, txt3->lenMax  == 0);
	CuAssertTrue(tc, txt3->lenCurr == 0);
	CuAssertTrue(tc, txt3->null    == 1);
	CuAssertTrue(tc, txt3->tainted == 0);
	CuAssertTrue(tc, memcmp(txt1, txt3, sizeof(*txt3)) == 0);
}

/*****************************************************************************
 */
static void T0002(CuTest* tc) {
	const char  *s = 0;
	conanTXT *txt1 = 0;
	conanTXT *txt2 = ConanTXTFromCString(s);

	CuAssertTrue(tc, txt1       == 0);
	CuAssertTrue(tc, txt2       != 0);
	CuAssertTrue(tc, txt2->null == 1);

	conanTXT *txt3 = ConanTXTConcat(txt1, txt2);
	CuAssertTrue(tc, txt3 != 0);
	CuAssertTrue(tc, txt3->lenMax  == 0);
	CuAssertTrue(tc, txt3->lenCurr == 0);
	CuAssertTrue(tc, txt3->null    == 1);
	CuAssertTrue(tc, txt3->tainted == 0);
	CuAssertTrue(tc, memcmp(txt2, txt3, sizeof(*txt3)) == 0);
}

/*****************************************************************************
 */
static void T0003(CuTest* tc) {
	const char *s = "T0011 Test";

	conanTXT *txt1 = ConanTXTFromCString(s);
	conanTXT *txt2 = ConanTXTFromCString(0);

	CuAssertTrue(tc, txt1       != 0);
	CuAssertTrue(tc, txt2       != 0);
	CuAssertTrue(tc, txt1->null == 0);
	CuAssertTrue(tc, txt2->null == 1);

	conanTXT *txt3 = ConanTXTConcat(txt1, txt2);
	CuAssertTrue(tc, txt3 != 0);
	CuAssertTrue(tc, txt3->lenMax  == (txt1->lenCurr + txt2->lenCurr));
	CuAssertTrue(tc, txt3->lenCurr == (txt1->lenCurr + txt2->lenCurr));
	CuAssertTrue(tc, txt3->null    == 0);
	CuAssertTrue(tc, txt3->tainted == 0);
	CuAssertTrue(tc, memcmp(txt1, txt3, sizeof(*txt3)) == 0);
	CuAssertTrue(tc, strcmp(txt1->data, txt3->data) == 0);
}

/*****************************************************************************
 */
static void T0004(CuTest* tc) {
	const char *s = "T0012 Test";

	conanTXT *txt1 = ConanTXTFromCString(0);
	conanTXT *txt2 = ConanTXTFromCString(s);

	CuAssertTrue(tc, txt1       != 0);
	CuAssertTrue(tc, txt2       != 0);
	CuAssertTrue(tc, txt1->null == 1);
	CuAssertTrue(tc, txt2->null == 0);

	conanTXT *txt3 = ConanTXTConcat(txt1, txt2);
	CuAssertTrue(tc, txt3 != 0);
	CuAssertTrue(tc, txt3->lenMax  == (txt1->lenCurr + txt2->lenCurr));
	CuAssertTrue(tc, txt3->lenCurr == (txt1->lenCurr + txt2->lenCurr));
	CuAssertTrue(tc, txt3->null    == 0);
	CuAssertTrue(tc, txt3->tainted == 0);
	CuAssertTrue(tc, memcmp(txt2, txt3, sizeof(*txt3)) == 0);
	CuAssertTrue(tc, strcmp(txt2->data, txt3->data) == 0);
}

/*****************************************************************************
 */
static void T0005(CuTest* tc) {
	const char *s = "T0013 Test";

	conanTXT *txt1 = ConanTXTFromCString(s);
	conanTXT *txt2 = ConanTXTFromCString(s);

	CuAssertTrue(tc, txt1       != 0);
	CuAssertTrue(tc, txt2       != 0);
	CuAssertTrue(tc, txt1->null == 0);
	CuAssertTrue(tc, txt2->null == 0);
	CuAssertTrue(tc, memcmp(txt1, txt2, sizeof(*txt1)) == 0);

	conanTXT *txt3 = ConanTXTConcat(txt1, txt2);
	CuAssertTrue(tc, txt3 != 0);
	CuAssertTrue(tc, txt3->lenMax  == (txt1->lenCurr + txt2->lenCurr));
	CuAssertTrue(tc, txt3->lenCurr == (txt1->lenCurr + txt2->lenCurr));
	CuAssertTrue(tc, txt3->null    == 0);
	CuAssertTrue(tc, txt3->tainted == 0);
	CuAssertTrue(tc, strcmp(txt3->data, "T0013 TestT0013 Test") == 0);
}

/*****************************************************************************
 */
CuSuite *GetSuiteTXTConcat(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, T0000);
	SUITE_ADD_TEST(suite, T0001);
	SUITE_ADD_TEST(suite, T0002);
	SUITE_ADD_TEST(suite, T0003);
	SUITE_ADD_TEST(suite, T0004);
	SUITE_ADD_TEST(suite, T0005);

	return suite;
}
