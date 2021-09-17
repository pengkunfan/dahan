/*! ************************************************************************
 *
 * Copyright (C) 2020 luotiansheng All rights reserved.
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

/*! ===> Creates on 2021/9/16. <=== */

/*!
 * @author tiansheng
 */
#ifndef DAHAN_STDSTORE_H
#define DAHAN_STDSTORE_H

#include "../bytebuf.h"

/** 初始化存储文件，将文件按块初始化 */
static void init_store_file(const char *path);
/** 存储文件 */
static void storebuf(const char *datapath, __bytebuf *buf);

#endif /* DAHAN_STDSTORE_H */