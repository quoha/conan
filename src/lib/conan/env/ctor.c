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

conanENV *ConanENV(const char **env) {
	conanENV *ce = malloc(sizeof(*ce));
	if (!ce) {
		return 0;
	}
	memset(ce, 0, sizeof(*ce));

	if (env == 0) {
		extern char **environ;
		env = (const char **)environ;
	}

	int idx;	
	for (idx = 0; env[idx]; ++idx) {
		const char *name  = env[idx];
		const char *value = name;
		while (*value && *value != '=') {
			++value;
		}
		if (*value) {
			++value;
		}
		int len = value - name;
		
		if (strncmp(name, "AUTH_TYPE=", len) == 0) {
			ce->authType = ConanTXTFromCString(value);
		} else if (strncmp(name, "CONTENT_LENGTH=", len) == 0) {
			ce->contentLength = ConanTXTFromCString(value);
		} else if (strncmp(name, "CONTENT_TYPE=", len) == 0) {
			ce->contentType = ConanTXTFromCString(value);
		} else if (strncmp(name, "GATEWAY_INTERFACE=", len) == 0) {
			ce->gatewayInterface = ConanTXTFromCString(value);
		} else if (strncmp(name, "PATH=", len) == 0) {
			ce->path = ConanTXTFromCString(value);
		} else if (strncmp(name, "PATH_INFO=", len) == 0) {
			ce->pathInfo = ConanTXTFromCString(value);
		} else if (strncmp(name, "PATH_TRANSLATED=", len) == 0) {
			ce->pathTranslated = ConanTXTFromCString(value);
		} else if (strncmp(name, "QUERY_STRING=", len) == 0) {
			ce->queryString = ConanTXTFromCString(value);
		} else if (strncmp(name, "REMOTE_ADDR=", len) == 0) {
			ce->remoteAddr = ConanTXTFromCString(value);
		} else if (strncmp(name, "REMOTE_HOST=", len) == 0) {
			ce->remoteHost = ConanTXTFromCString(value);
		} else if (strncmp(name, "REMOTE_IDENT=", len) == 0) {
			ce->remoteIdent = ConanTXTFromCString(value);
		} else if (strncmp(name, "REMOTE_USER=", len) == 0) {
			ce->remoteUser = ConanTXTFromCString(value);
		} else if (strncmp(name, "REQUEST_METHOD=", len) == 0) {
			ce->requestMethod = ConanTXTFromCString(value);
		} else if (strncmp(name, "SCRIPT_NAME=", len) == 0) {
			ce->scriptName = ConanTXTFromCString(value);
		} else if (strncmp(name, "SERVER_NAME=", len) == 0) {
			ce->serverName = ConanTXTFromCString(value);
		} else if (strncmp(name, "SERVER_PORT=", len) == 0) {
			ce->serverPort = ConanTXTFromCString(value);
		} else if (strncmp(name, "SERVER_PROTOCOL=", len) == 0) {
			ce->serverProtocol = ConanTXTFromCString(value);
		} else if (strncmp(name, "SERVER_SOFTWARE=", len) == 0) {
			ce->serverSoftware = ConanTXTFromCString(value);
		} else { // add to name/value pair
			int idy;
			for (idy = 0; idy < 127; ++idy) {
				if (!ce->name[idy]) {
					ce->name[idy]  = ConanTXTFromString(name, len);
					ce->value[idy] = ConanTXTFromCString(value);
					break;
				}
			}
		}
	}

	return ce;
}
