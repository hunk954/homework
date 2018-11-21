## 机器语言编程

#### 任务1 
（2）1.PC（Program counter）程序计数器，用来计数的，指示指令存储的存放位置    
IR（Instuction Register）指令寄存器：是临时放置从内存里面取得的程序指令的寄存器，用于存放当前从主存储器读出的正在执行的一条指令    

2.ACC（Accumulator）累加器。专门用来存放操作数或运算结果。  


3.I.Fetch Instruction 从主存中取指令“LOD #3”，得到机器码“00000100 00000011”
II.Decode Instuction 指令译码, 根据指令格式分析指令作用 “将值3载入累加器ACC中”
III. 无需从寄存器中取值
IV. 在ALU算术逻辑运算单元中进行运算操作
V. ALU运算结果返回寄存器ACC中
VI.在PC+4处执行下一条指令  



4.I.Fetch Instruction 从主存中取指令，得到机器码“00000000 W的地址”
II.Decode Instuction 指令译码, 根据指令格式分析指令作用“将W中的值与累加器ACC中的值相加”
III. 从寄存器W、ACC中取值  
IV. 在ALU算术逻辑运算单元中进行加法操作 
V. ALU运算结果返回累加器ACC中
VI.在PC+4处执行下一条指令  


5.LOD #3只需访问RAM一次,而ADD W需要访问RAM两次


（3）  
1.00010100 00000111  其中前八位为指令码 后八位为数值。其中前八位的第四位是寻址模式（1表示后八位操作数为数值） 前八位的后四位是操作码指示不同的命令 


2.Read Only Memory,里面只是暂时存储数据和相关指令，如果电源断开，下次启动时数据和指令将丢失  


3.16位  


4.int w = 3; int x = 7; int z = x + w;

#### 任务2
（1）  
1.x从10倒数至0  

2.int x = 10;  
while(x >= 0) x--;  

（2）  
1.int x = 10;   
int sum = 0;  
while(x > 0) {  
  sum += x;  
} 

2.
0000000 00010100 00001010  
0000010 00000101 10000001  
0000100 00010001 00000001  
0000110 00000101 10000000  
0001000 00000000 10000001  
0001010 00000101 10000000  
0001100 00000100 10000000  
0001110 00001101 00010010  
0010000 00001100 00000100  
0010010 00000101 10000010  
0010100 00001111 00000000  
0010110 00001110 00000000  
1000000 00000000   
1000001 00000000   
1000010 00000000  
 
3.区别：高级语言更加易懂、易于编写。而机器语言是一串二进制代码，主要目的是让机器能读懂。  
联系：高级语言不能直接被计算器所执行，但可以通过汇编可以形成汇编语言，再通过翻译可以变成机器语言，进而让机器运行。  
