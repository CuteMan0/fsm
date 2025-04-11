#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include <stdint.h>

// 事件类型，由用户定义
typedef uint32_t Event;

// 状态函数类型
typedef void *(*StateFn)(void *host, const Event *e);

// 状态机结构体
typedef struct
{
    void *host;            // 指向宿主结构
    StateFn current_state; // 当前状态函数
} StateMachine;

// 初始化状态机
void state_machine_init(StateMachine *sm, void *host, StateFn initial_state);

// 处理事件
void state_machine_feed(StateMachine *sm, Event e);

#endif // __STATE_MACHINE_H__