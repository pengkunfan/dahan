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

/*! ===> Creates on 2021/9/9. <=== */

/*!
 * 指令集
 * @author 范特西
 */
#ifndef VAP_INST_H
#define VAP_INST_H

struct directive {
        unsigned char code;        /* 指令码 */
        char name[8];              /* 助记符号 */
        char command[200];         /* 备注 */
        char param[30];            /* 参数，使用逗号分割 */
};

#define __such(code, name, cm) \
struct directive name = { code, #name,  cm}

__such(0x01, vap, "创建一个对象");
__such(0x02, aoc, "给对象分配数据");
__such(0x03, beg, "代码块开始标记");
__such(0x04, end, "代码块结束标记");
__such(0x05, mov, "将数据根据offset移动到对应的内存区域");
__such(0x06, add, "将一个表添加到数据库或者将字段添加到表中");
__such(0x07, get, "从指针中获取表或者字段，根据指针类型而定");
__such(0x08, mod, "修改数据");

#endif /* VAP_INST_H */