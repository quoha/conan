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
#ifndef conan_src_bin_conan_local_H
#define conan_src_bin_conan_local_H

/*************************************************************************
 */
typedef struct conanCTX conanCTX;
typedef struct conanENV conanENV;
typedef struct conanTXT conanTXT;

/*************************************************************************
 */
conanCTX *ConanCTX(int argc, char **argv, char **env);
conanENV *ConanENV(void);
conanTXT *ConanGetEnv(conanTXT *name);
conanTXT *ConanSetEnv(conanTXT *name, conanTXT *value);
conanTXT *ConanTXTFromCString(const char *value);

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
	int  lenCurr;
	int  lenMax;
	char data[1];
};

#endif
