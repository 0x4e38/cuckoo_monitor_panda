/*
Cuckoo Sandbox - Automated Malware Analysis.
Copyright (C) 2010-2015 Cuckoo Foundation.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MONITOR_LOG_H
#define MONITOR_LOG_H

#include <stdint.h>
#include <windows.h>
#include "bson.h"
#include "native.h"

void log_init(const char *pipe_name);

void log_api(uint32_t index, int is_success, uintptr_t return_value,
    uint64_t hash, last_error_t *lasterr, ...);

void log_wstring(bson *b, const char *idx, const wchar_t *str, int length);

void log_anomaly(const char *subcategory,
    const char *funcname, const char *msg);

void log_exception(CONTEXT *ctx, EXCEPTION_RECORD *rec,
    uintptr_t *return_addresses, uint32_t count);

void log_new_process();

void log_debug(const char *fmt, ...);

// Remove log_debug() in release mode altogether.
#if DEBUG == 0
#define log_debug(fmt, ...) (void)0
#endif

// Following are function imports and declarations that are generated as part
// of the automated code generation. However, as we don't want to recompile
// everything every time this code is re-generated, we wrap its data in
// functions which we reference here.

#define FLAG_NONE     0
#define FLAGTYP_NONE  0
#define FLAGTYP_ENUM  1
#define FLAGTYP_VALUE 2

typedef struct _flag_repr_t {
    uint32_t type;
    uint32_t value;
    const char *repr;
} flag_repr_t;

const char *sig_flag_name(uint32_t sigidx, uint32_t flagidx);
uint32_t sig_flag_value(uint32_t sigidx, uint32_t flagidx);
const char *sig_apiname(uint32_t sigidx);
const char *sig_category(uint32_t sigidx);
const char *sig_paramtypes(uint32_t sigidx);
const char *sig_param_name(uint32_t sigidx, uint32_t argidx);
uint32_t sig_count();
const flag_repr_t *flag_value(uint32_t flagidx);

uint32_t sig_index_process();
uint32_t sig_index_anomaly();
uint32_t sig_index_exception();

#endif
