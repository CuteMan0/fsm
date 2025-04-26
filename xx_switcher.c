#include "xx_switcher.h"

// 状态函数声明
static void *state_off(void *host, const Event *e);
static void *state_on(void *host, const Event *e);

static void *state_off(void *host, const Event *e)
{
    if (*(const LedSwitcherEvent *)e == BUTTON_PRESSED) {
        // 业务逻辑：打开LED
        return state_on;
    }
    return state_off;
}

static void *state_on(void *host, const Event *e)
{
    if (*(const LedSwitcherEvent *)e == BUTTON_PRESSED) {
        // 业务逻辑：关闭LED
        return state_off;
    }
    return state_on;
}

void xx_switcher_init(LedSwitcher *switcher)
{
    state_machine_init(&switcher->fsm, switcher, state_off);
}

void xx_switcher_feed(LedSwitcher *switcher, LedSwitcherEvent event)
{
    state_machine_feed(&switcher->fsm, (Event)event);
}