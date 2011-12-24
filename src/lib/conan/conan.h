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
#ifndef conan_src_lib_conan_conan_H
#define conan_src_lib_conan_conan_H

/*************************************************************************
 */
typedef struct conanCTX conanCTX;
typedef struct conanENV conanENV;
typedef struct conanTXT conanTXT;

/*************************************************************************
 */
conanCTX *ConanCTX(int argc, char **argv, char **env);
conanENV *ConanENV(const char **env);
conanTXT *ConanGetEnv(conanTXT *name);
conanTXT *ConanSetEnv(conanTXT *name, conanTXT *value);
conanTXT *ConanTXTFromCString(const char *value);
conanTXT *ConanTXTFromString(const char *value, int len);
conanTXT *ConanTXTConcat(conanTXT *a, conanTXT *b);
int       ConanTXTCompare(conanTXT *a, conanTXT *b);

/*************************************************************************
 */
struct conanCTX {
	conanENV *env;
};

/*************************************************************************
 */
struct conanENV {
	conanTXT *authType;
	conanTXT *contentLength;
	conanTXT *contentType;
	conanTXT *gatewayInterface;
	conanTXT *path;
	conanTXT *pathInfo;
	conanTXT *pathTranslated;
	conanTXT *queryString;
	conanTXT *remoteAddr;
	conanTXT *remoteHost;
	conanTXT *remoteIdent;
	conanTXT *remoteUser;
	conanTXT *requestMethod;
	conanTXT *scriptName;
	conanTXT *serverName;
	conanTXT *serverPort;
	conanTXT *serverProtocol;
	conanTXT *serverSoftware;
	conanTXT *name[128];
	conanTXT *value[128];
};

/*************************************************************************
 */
struct conanTXT {
	int  lenCurr;  // bytes of data (not including terminating nil)
	int  lenMax;   // maximum bytes of data (never includes guardian nil)
	int  null;     // 1 if null value, 0 if non-null
	int  tainted;  // 1 if untrusted user data, 1 if not
	char data[1];
};

#endif
