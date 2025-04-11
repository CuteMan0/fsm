# state_machine

## 这是什么？

这是一个简单的状态机引擎和业务逻辑分离的框架

## 使用说明

### 以灯的控制为例

- 将 state_machine.c/h 和 xx_switcher.c/h 存放到工程路径下。

- 设置 xx_switcher.h 中的逻辑状态，`xxSwitcherEvent`。

- 设置 xx_switcher.c 中的状态函数，`void *state_xx(void *host, const Event \*e)`。

- 在每个状态函数中，根据事件类型，编写相应的业务逻辑。

- 初始化状态切换器`xx_switcher_init`之后，在每次触发事件调用`xx_switcher_feed`。
