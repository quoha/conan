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
	conanTXT *txt = 0;
	CuAssertTrue(tc, txt == 0);
}

/*****************************************************************************
 */
static void T0001(CuTest* tc) {
	const char *s = 0;
	conanTXT *txt = ConanTXTFromCString(s);
	CuAssertTrue(tc, txt != 0);
	CuAssertTrue(tc, txt->lenCurr == 0);
	CuAssertTrue(tc, txt->lenMax  == 0);
	CuAssertTrue(tc, txt->null    == 1);
	CuAssertTrue(tc, txt->tainted == 0);
	CuAssertTrue(tc, txt->data[0] == 0);
}

/*****************************************************************************
 */
static void T0002(CuTest* tc) {
	const char *s = "";
	conanTXT *txt = ConanTXTFromCString(s);
	CuAssertTrue(tc, txt != 0);
	CuAssertTrue(tc, txt->lenCurr == 0);
	CuAssertTrue(tc, txt->lenMax  == 0);
	CuAssertTrue(tc, txt->null    == 0);
	CuAssertTrue(tc, txt->tainted == 0);
	CuAssertTrue(tc, txt->data[0] == 0);
}

/*****************************************************************************
 */
static void T0003(CuTest* tc) {
	const char *s = "T0003 Test";
	conanTXT *txt = ConanTXTFromCString(s);
	CuAssertTrue(tc, txt != 0);
	CuAssertTrue(tc, txt->lenMax  == strlen(s));
	CuAssertTrue(tc, txt->lenCurr == strlen(s));
	CuAssertTrue(tc, txt->null    == 0);
	CuAssertTrue(tc, txt->tainted == 0);
	CuAssertTrue(tc, txt->data[0] == *s);
	CuAssertTrue(tc, strcmp(s, txt->data) == 0);
}

/*****************************************************************************
 */
static void T0004(CuTest* tc) {
	const char *s = 0;
	conanTXT *txt = ConanTXTFromString(s, 0);
	CuAssertTrue(tc, txt != 0);
	CuAssertTrue(tc, txt->lenCurr == 0);
	CuAssertTrue(tc, txt->lenMax  == 0);
	CuAssertTrue(tc, txt->null    == 1);
	CuAssertTrue(tc, txt->tainted == 0);
	CuAssertTrue(tc, txt->data[0] == 0);
}

/*****************************************************************************
 */
static void T0005(CuTest* tc) {
	const char *s = "";
	conanTXT *txt = ConanTXTFromString(s, 0);
	CuAssertTrue(tc, txt != 0);
	CuAssertTrue(tc, txt->lenCurr == 0);
	CuAssertTrue(tc, txt->lenMax  == 0);
	CuAssertTrue(tc, txt->null    == 0);
	CuAssertTrue(tc, txt->tainted == 0);
	CuAssertTrue(tc, txt->data[0] == 0);
}

/*****************************************************************************
 */
static void T0006(CuTest* tc) {
	const char *s = "T0006 Test";
	conanTXT *txt = ConanTXTFromString(s, strlen(s));
	CuAssertTrue(tc, txt != 0);
	CuAssertTrue(tc, txt->lenMax  == strlen(s));
	CuAssertTrue(tc, txt->lenCurr == strlen(s));
	CuAssertTrue(tc, txt->null    == 0);
	CuAssertTrue(tc, txt->tainted == 0);
	CuAssertTrue(tc, txt->data[0] == *s);
	CuAssertTrue(tc, strcmp(s, txt->data) == 0);
}

/*****************************************************************************
 */
static void T0007(CuTest* tc) {
	const char *s = "T0007 Test";
	conanTXT *txt = ConanTXTFromString(s, 5);
	CuAssertTrue(tc, txt != 0);
	CuAssertTrue(tc, txt->lenMax  == 5);
	CuAssertTrue(tc, txt->lenCurr == 5);
	CuAssertTrue(tc, txt->null    == 0);
	CuAssertTrue(tc, txt->tainted == 0);
	CuAssertTrue(tc, txt->data[0] == *s);
	CuAssertTrue(tc, strcmp(s, txt->data) != 0);
	CuAssertTrue(tc, strcmp(txt->data, "T0007") == 0);
}

/*****************************************************************************
 */
static void T0008(CuTest* tc) {
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
static void T0009(CuTest* tc) {
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
static void T0010(CuTest* tc) {
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
static void T0011(CuTest* tc) {
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
static void T0012(CuTest* tc) {
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
static void T0013(CuTest* tc) {
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
CuSuite *GetSuiteTXT(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, T0000);
	SUITE_ADD_TEST(suite, T0001);
	SUITE_ADD_TEST(suite, T0002);
	SUITE_ADD_TEST(suite, T0003);
	SUITE_ADD_TEST(suite, T0004);
	SUITE_ADD_TEST(suite, T0005);
	SUITE_ADD_TEST(suite, T0006);
	SUITE_ADD_TEST(suite, T0007);
	SUITE_ADD_TEST(suite, T0008);
	SUITE_ADD_TEST(suite, T0009);
	SUITE_ADD_TEST(suite, T0010);
	SUITE_ADD_TEST(suite, T0011);
	SUITE_ADD_TEST(suite, T0012);
	SUITE_ADD_TEST(suite, T0013);

	return suite;
}
