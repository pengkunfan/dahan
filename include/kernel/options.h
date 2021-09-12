/*! ************************************************************************
 *
 * Copyright (C) 2020 luots All rights reserved.
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

/*! ===> Creates on 2021/9/12. <=== */

/*!
 * @author 范特西
 */
#ifndef _KERNEL_OPTIONS_H
#define _KERNEL_OPTIONS_H

#include "database.h"

/**
 * 修改字段名
 *
 * @param table
 * @param name
 * @param newname
 * @param type
 * @param len
 * @param remark
 * @param vdef
 */
void modify_column_info(struct database *base,
                        const char *name,               /* <database name>/<table name> */
                        const char *newname,
                        unsigned char type,
                        unsigned int len,
                        const char *remark,
                        const char *vdef);
/** 修改表名 */
void modify_table_name(struct database *base, const char *oldname, const char *newname);
/** 添加一张表到数据库 */
extern void vacat_add_table(struct database *base, struct table *table);
/** 修改数据库名 */
void modify_database_name(struct database *base, const char *oldname, const char *newname);
/** 获取一张表 */
struct table* vacat_get_table(struct database *base, const char *name);
/** 加载数据库 */
extern bool load_database(struct database *base, const char *name);

#endif /* _KERNEL_OPTIONS_H */