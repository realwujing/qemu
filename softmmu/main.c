/*
 * QEMU System Emulator
 *
 * Copyright (c) 2003-2020 Fabrice Bellard
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"                                      // QEMU 系统仿真器
#include "qemu-main.h"                                      // QEMU 主程序
#include "sysemu/sysemu.h"                                   // QEMU 系统仿真

#ifdef CONFIG_SDL
#include <SDL.h>                                             // 简单直接媒体层（Simple DirectMedia Layer，SDL）库
#endif

int qemu_default_main(void)
{
    int status;

    status = qemu_main_loop();                                // 执行 QEMU 主循环
    qemu_cleanup();                                            // 清理 QEMU 资源

    return status;
}

int (*qemu_main)(void) = qemu_default_main;                   // 指向 QEMU 主函数的指针

int main(int argc, char **argv)
{
    qemu_init(argc, argv);                                     // 初始化 QEMU
    return qemu_main();                                       // 执行 QEMU 主函数
}
