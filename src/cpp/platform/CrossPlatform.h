//
// Created by qiuwenchen on 2022/9/15.
//

/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Macro.h"

#pragma mark - errno

#if defined(__linux__) || defined(__ANDROID__)
// Magic number, something unique to avoid being matched
#define EAUTH 0x5c69e1c6
#endif /* defined(__linux__) || defined(__ANDROID__) */

#pragma mark - execinfo

#ifdef __ANDROID__
WCDB_EXTERN_C_BEGIN
int backtrace(void**, int);
char** backtrace_symbols(void* const*, int);
WCDB_EXTERN_C_END
#endif /* __ANDROID__ */

#pragma mark - mman

#if defined(__linux__) || defined(__ANDROID__)
#ifndef MAP_NOEXTEND
// Not exists in Linux, set to 0 to avoid making a difference in OR operation
#define MAP_NOEXTEND 0x0
#endif /* ndef MAP_NOEXTEND */
#endif /* defined(__linux__) || defined(__ANDROID__) */

#if defined(__linux__) || defined(__ANDROID__)

#pragma mark - pthread

#include <pthread.h>

WCDB_EXTERN_C_BEGIN
int pthread_main_np();
int pthread_threadid_np(pthread_t, __uint64_t*);
WCDB_EXTERN_C_END
#define pthread_setname_np(CHAR) pthread_setname_np(pthread_self(), CHAR)

#if defined(__ANDROID__) && __ANDROID_API__ < 26
WCDB_EXTERN_C_BEGIN
int pthread_getname_np(pthread_t, char*, size_t);
WCDB_EXTERN_C_END
#endif /* defined(__ANDROID__) && __ANDROID_API__ < 26 */

#endif /* defined(_linux__) || defined(__ANDROID__) */

#pragma mark - stat

#if defined(__linux__) || defined(__ANDROID__)
#define st_atimespec st_atim
#define st_mtimespec st_mtim
#define st_ctimespec st_ctim
#endif /* __ANDROID__ */

#pragma mark - uinstd

#ifdef __ANDROID__
WCDB_EXTERN_C_BEGIN
int getdtablesize();
WCDB_EXTERN_C_END
#endif /* __ANDROID__ */
