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
#include "kernel/options.h"
#include "serialize/serialize.c"

#define CHK_TABLE_NOT_FOUND(__ptr, name)           \
if(__ptr == NULL) {                                \
        kerror("【%s】表不存在\n", name);             \
        return;                                    \
}

#define CHK_COLUMN_NOT_FOUND(__ptr, name)          \
if(__ptr == NULL) {                                \
        kerror("【%s】字段不存在\n", name);           \
        return;                                    \
}

static __always_inline void getname(const char *path, char *tabname, char *colname)
{
        char cpypath[_PATH_MAX];
        strncpy(cpypath, path, _PATH_MAX);

        char *word;
        word = strtok(cpypath, "/");

        unsigned char count = 0;
        while (word != NULL) {
                switch (count) {
                        case 0: {
                                if (tabname != NULL)
                                        strncpy(tabname, word, _NAME_MAX);
                                break;
                        }
                        case 1: {
                                if (colname != NULL)
                                        strncpy(colname, word, _NAME_MAX);
                                break;
                        }
                }
                word = strtok(NULL, "/");
                count++;
        }
}

void modify_column_info(struct database *base,
                        const char *name,
                        const char *newname,
                        unsigned char type,
                        unsigned int len,
                        const char *remark,
                        const char *vdef)
{
        char tabname[_NAME_MAX];
        char colname[_NAME_MAX];
        getname(name, tabname, colname);

#ifdef __vacat_debug
        DEBUG("############## 调试开始【修改字段信息】 ##############\n");
        DEBUG("路径: %s\n", name);
        DEBUG("表名: %s\n", tabname);
        DEBUG("字段名: %s\n", colname);
        DEBUG("############## 调试结束【修改字段信息】 ##############\n");
#endif

        // 获取表结构体
        struct table *table = vacat_get_table(base, tabname);
        CHK_TABLE_NOT_FOUND(table, tabname)

        // 获取字段结构体
        struct column *column = table_get_column(table, colname);
        CHK_COLUMN_NOT_FOUND(column, colname)

        if(newname != NULL && strlen(newname) != 0) {
                memset(column->name, 0, _NAME_MAX);
                strncpy(column->name, newname, _NAME_MAX);
        }

        if(remark != NULL && strlen(remark) != 0) {
                memset(column->remark, 0, _REMARK_MAX);
                strncpy(column->remark, remark, _REMARK_MAX);
        }

        if(vdef != NULL && strlen(vdef) != 0) {
                memset(column->vdef, 0, _VDEF_MAX);
                strncpy(column->vdef, vdef, _VDEF_MAX);
        }

        // TODO 需要检测当前字段的数据中类型是否符合条件
        if(type > 0)
                column->type = type;

        // TODO 需要检测当前字段的数据中长度是否符合条件
        if(len > 0)
                column->len = len;

}

/** 序列化表结构，将表结构序列化成文件持久化存放到文件中。 */
void _vacat_serialze_table(struct database *base, struct table *table)
{
        char tablepath[_PATH_MAX];
        /* 结果类似： /home/root/<数据库名>/<表名> */
        xsnprintf(tablepath, _PATH_MAX, "%s/%s", base->pathname, table->name);

        if (!file_exist(tablepath))
                vacat_mkdirs(tablepath);

        // 将表结构信息写入文件
        _write_table(tablepath, table);
        _write_columns(tablepath, table->columns, table->colnum);
}

void modify_table_name(struct database *base, const char *oldname, const char *newname)
{
        struct table *table;
        table = vacat_get_table(base, oldname);

        CHK_TABLE_NOT_FOUND(table, oldname)

        char oldpath[_PATH_MAX];
        char newpath[_PATH_MAX];

        xsnprintf(oldpath, _PATH_MAX, "%s/%s", base->pathname, table->name);
        xsnprintf(newpath, _PATH_MAX, "%s/%s", base->pathname, newname);

        memset(table->name, 0, _NAME_MAX);
        strncpy(table->name, newname, _NAME_MAX);

#ifdef __vacat_debug
        DEBUG("############## 调试开始【修改表名】 ##############\n");
        DEBUG("原路径: %s\n", oldpath);
        DEBUG("新路径: %s\n", newpath);
        DEBUG("############## 调试结束【修改表名】 ##############\n");
#endif

        rename(oldpath, newpath);
}

extern void vacat_add_table(struct database *bp, struct table *tp)
{
        if (bp->tabnum == (bp->arrsize - 1))
        _ARRAY_RESIZE(bp, TABLE_ARRAY_SIZE, tables,
                      sizeof(struct table));

        // 检测字段名是否重复
        if (kcheck_table_name_dup(bp->tables, bp->tabnum, tp->name)) {
                puts("表名重复");
                return;
        }

        bp->tables[bp->tabnum] = (*tp);
        ++bp->tabnum;

        // 序列化
        _vacat_serialze_table(bp, tp);
}

struct table *vacat_get_table(struct database *base, const char *name)
{
        struct table *tab;

        size_t i;
        for (i = 0; i < base->tabnum; i++) {
                tab = (base->tables + i);
                if (strcmp(tab->name, name) == 0)
                        return tab;
        }

        return NULL;
}

void modify_database_name(struct database *base, const char *oldname, const char *newname)
{
        char newpathname[_PATH_MAX];
        char oldpathname[_PATH_MAX];
        xsnprintf(newpathname, _PATH_MAX, "%s/%s", kconf_data_dir(), newname);
        xsnprintf(oldpathname, _PATH_MAX, "%s/%s", kconf_data_dir(), oldname);

        rename(oldpathname, newpathname);
        strncpy(base->pathname, newpathname, _PATH_MAX);
}