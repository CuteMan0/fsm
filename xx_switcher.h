#ifndef __XX_SWITCHER_H__
#define __XX_SWITCHER_H__

#include "state_machine.h"

// 业务特定事件类型
typedef enum
{
    BUTTON_PRESSED,
    BUTTON_RELEASED
} LedSwitcherEvent;

// LED切换器结构体
typedef struct
{
    StateMachine fsm;
    // 可以添加其他业务特定数据
} LedSwitcher;

// 初始化LED切换器
void xx_switcher_init(LedSwitcher *switcher);

// 处理事件
void xx_switcher_feed(LedSwitcher *switcher, LedSwitcherEvent event);

#endif // __XX_SWITCHER_H__