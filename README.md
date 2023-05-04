# OOP-Elevator

### 问题说明
---

 #### 限定条件：

 1. 每部电梯最大载客量均为K人（自定）
 2. 仿真开始时，各电梯都位于第一层，且都为空梯
 3. 仿真开始后，有N位（0 < N < 1000）乘客在M分钟（0 < M < 10）内随机地到达该国际会展中心，开始电梯活动
 4. 电梯运行的方向由先发出请求者决定，不允许后发出请求者改变电梯的当前运行方向，除非是未被请求的空梯
 5. 当某层有乘客按下乘梯按钮时，优先考虑离该层最近的、满足条件4,能够最快到达目标层的电梯
 6. 不允许电梯超员。超员时应给出提示
 7. 电梯运行速度为S秒/层（自定，1～5之间），没人的话上下时间为T秒/层（自定2～10之间）
---

 #### 第一次上机内容：

 1. 设计实现电梯类、乘客类以及其他必要的类
 2. 设计实现显示仿真信息的界面：
   - ***a、显示每部电梯的状态（空闲或运行中）、运行的方向（上行或下行）、目前停留的楼层；***
   - ***b、电梯内乘客的数量、每位乘客要去往的楼层（例如12-32表示标识为12的乘客要求去往32层）***
   - ***c、当前时间***
 3. 假设10部电梯各自独立运行，均可到达每一层
 4. 随机产生每位乘客所要到达的楼层（假设每位乘客只产生一次乘梯请求），并随机选择一部电梯让其等待
 5. 实现满足该要求的电梯仿真流程，选择将乘客送至其请求的楼层。当所有乘客均到达请求的楼层后，仿真结束
---

 #### 第二次上机内容：

 1. 修改乘客乘梯请求规则
   - ***a、随机产生每位乘客初次所要到达的楼层，并随机选择一部电梯让其等待***
   - ***b、每位乘客乘坐电梯达到指定楼层后，随机地停留10-120秒后，再随机地去往另一楼层，依次类推。当每位乘客乘坐过L次（每人的L值不同，在产生乘客时随机地在1-10之间确定）电梯后，第L+1次为下至底层并结束乘梯行为。到所有乘客结束乘梯行为时，本次仿真结束。***
---

 #### 第三次上级内容：
修改电梯运行规则
1. E0、E1:可到达每层;
2. E2、E3:可到达1、25～40层。
3. E4、E5:可到达1～25层。
4. E6、E7:可到达1、2～40层中的偶数层。
5. E8、E9:可到达1～39层中的奇数层。
6. 按照相同规则运行的两部电梯之间是联动的。
7. 随机产生每位乘客初次所要到达的楼层,选择一部合适的电梯让其等待。