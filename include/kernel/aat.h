/*! ************************************************************************
 *
 * Copyright (C) 2020 LuoTianSheng All rights reserved.
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

/*! ===> Creates on 2021/9/25. <=== */

/*!
 * 区域分配表
 * @author TianSheng
 */
#ifndef _AAT_H
#define _AAT_H

#include "column.h"

struct aatcol {
        size_t areaid;
        const char *colname;
};

/* 数据区域分配表 */
struct aat {
        uint *idle;
        size_t arrsize;
        struct aatcol *areas;
};

/* 创建一个区域分配表 */
struct aat *aat_init();
/* 销毁一个区域分配表 */
void aat_destroy(struct aat *aat);
/* 添加一个字段所对应的区域 */
void aat_bound(struct aat *aat, const char *colname);
/* 获取字段对应的区域id */
size_t aat_get(struct aat *aat, const char *colname);

#endif /* _AAT_H */
