/*! ************************************************************************
 *
 * Copyright (C) 2020 netforklabs All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/07/22. <=== */

/*!
 * 统一类型命名
 *
 * @author 范特西
 */
#pragma once

#define log_info(va, ...)  printf(va, __VA_ARGS__)
#define log_error(va, ...) printf(va, __VA_ARGS__)
#define log_debug(va, ...) printf(va, __VA_ARGS__)
#define log_warn(va, ...)  printf(va, __VA_ARGS__)

#ifdef WIN32
#   define __api_import__ __declspec(dllimport)
#   define __api_export__ __declspec(dllexport)
#else
#   define __api_export__
#   define __api_import__
#endif /* defined(WIN) || defined(WIN32) */

#ifdef TAICHU_BUILD_DLL
#   define __glibc_api__ __api_export__
#else
#   define __glibc_api__ __api_import__
#endif /* TAICHU_BUILD_DLL */
