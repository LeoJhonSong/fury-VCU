# fury-VCU

## flags

| 名字   | 含义         | 缺省值          | 触发                     |
| ------ | ------------ | --------------- | ------------------------ |
| mcFlag | 电控状态标志 | can2_recieve[5] | 999, if can2WatchDog>100 |


`allFlag = acRealiableFlag*1 + acBrReliableFlag*2 + startFlag*4 + runFlag*8 + driveReadyFlag*16 + SafetyFlag*32 + brFlag*64`

allFlag由高到低为:

| 名字             | 含义             | 缺省值 | 触发                                                     |
| ---------------- | ---------------- | ------ | -------------------------------------------------------- |
| brFlag           | 制动标志         | 0      | 1, 当制动数据大于5                                       |
| SafetyFlag       | 安全回路状态标志 | 0      | 1, 当安全回路正常                                        |
| driveReadyFlag   | 待驶状态         | 0      | 1, 当已启动, 电机输出已使能, 安全回路正常, 电控准备就绪  |
| runFlag          | 电机输出使能标志 | 0      | 1, 当已启动, 油门, 制动可靠, 油门制动都有数据            |
| startFlag        | 启动标志         | 0      | 1, 踩下制动且启动按钮为高                                |
| acBrReliableFlag | 制动数据可靠标志 | 0      | 1, 当启动时油门不大于5, 或行进中油门制动数据不同时大于15 |
| acRealiableFlag  | 油门数据可靠标志 | 0      | 1, 当两路油门相差在10以内                                |
| acAllowed        | 预充允许标志     | 0      | 1, 安全回路正常且按下预充按钮                            |
