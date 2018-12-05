## 字符游戏-贪吃蛇实验报告
### 一、实验目的
1. 了解字符游戏的表示
2. 体验自顶向下的设计方法实现问题求解
3. 使用伪代码表示算法
4. 使用函数抽象过程

### 二、游戏玩法与表示
1. 玩法  
通过"WASD"控制蛇的走向，在有限的范围内，通过吃蛇食物使蛇变长。注意不要吃到自己的身体也不要撞到墙边。  
2. 游戏表示  
给定一个10 * 10的字符矩阵表示蛇的生存空间,其中有一条长度5的蛇(HXXXX), “H”表示蛇头,“X”表示蛇身体。空间中可能有食物（“$”表示）和障碍物（“*”表示）  
你可以使用“ADWS”按键分别控制蛇的前进方向“左右上下”, 当蛇头碰到自己的身体或走出边界,游戏结束,否则蛇按你指定方向前进一步。  

### 三、编程实现
#### 1. 程序头部  
##### 定义常量以及相关函数
```
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H' 
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$' 
#define WALL_CELL '*'

//snake step: dx = -1(left) / 1(right), dy = -1(up) / 1(down); 
void snakeMove(int, int);
//snake eat food
void snakeEat(void);
//put a food randomized on a blank cell
void put_money(void);
//out cells of the grid
void output(void);
//outs when gameover
void gameover(void);

char map[13][13]= 
		{"************",
		"*XXXXH     *",
		"*          *",
		"*          *",
		"*          *",
		"*          *",
		"*          *",
		"*          *",
		"*          *",
		"*          *",
		"*          *",
		"************"}; 

//define vars for snake
int snakeX[SNAKE_MAX_LENGTH] = {1, 2, 3, 4, 5}; //蛇身和蛇头的坐标
int snakeY[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int snakeLength = 5;
//判断移动后蛇是否撞墙或者吃到自己 
int flag_over = 0;
//判断蛇是否吃到食物 
int flag_eat = 0;
```

#### 2. main函数
##### 伪代码
```
输出字符矩阵
	WHILE not 游戏结束 DO
		ch＝等待输入
		CASE ch DO
		‘A’:左前进一步，break 
		‘D’:右前进一步，break    
		‘W’:上前进一步，break    
		‘S’:下前进一步，break    
		END CASE
		输出字符矩阵
	END WHILE
	输出 Game Over!!! 
```
##### 具体C语言实现
```
int main(){
	put_money();
	//output the matrix
	output();
	char ch;
	while(true){
		ch = getch();
		if(ch >= 'a' &&  ch <= 'z')
			ch = ch - 'a' + 'A';
		switch(ch){
			case 'A': snakeMove(-1, 0); break;
			case 'D': snakeMove(1, 0); break;
			case 'W': snakeMove(0, -1); break;
			case 'S': snakeMove(0, 1); break;
		}
		if(flag_eat == 1){
			flag_eat = 0;
			put_money();
		} 
		output();
		if(flag_over) gameover();
	}	
}
```
#### 3.具体功能函数
##### snake_move.c
```
void snakeMove(int dx, int dy){
	//预判头部是否碰撞到墙壁或者吃到自己 
	int head = snakeLength-1;
	char ch_head = map[snakeY[head]+dy][snakeX[head]+dx];
	if(ch_head == WALL_CELL || ch_head == SNAKE_BODY) 
		flag_over = 1;
	if(ch_head == SNAKE_FOOD){
		snakeEat();
		flag_eat = 1;
	} 
	
	//清空原来蛇身 
	for(int i = 0; i < snakeLength; i++)
		if(map[snakeY[i]][snakeX[i]] != WALL_CELL)  map[snakeY[i]][snakeX[i]] = BLANK_CELL;
		
	//更新蛇身坐标 
	for(int i = 0; i < snakeLength-1; i++){
		snakeX[i] = snakeX[i+1];
		snakeY[i] = snakeY[i+1];
	}
	head = snakeLength - 1;
	snakeX[head] = snakeX[head] + dx;
	snakeY[head] = snakeY[head] + dy;

	//定位坐标改字符 
	map[snakeY[head]][snakeX[head]] = SNAKE_HEAD;
	for(int i = 0; i < snakeLength-1; i++)
		map[snakeY[i]][snakeX[i]] = SNAKE_BODY;
}
```

##### snake_eat.c
```
void snakeEat(){
	int dx = snakeX[1] - snakeX[0];
	int dy = snakeY[1] - snakeY[0];
	for(int i = snakeLength; i > 0; i--){
		snakeX[i] = snakeX[i-1];
		snakeY[i] = snakeY[i-1];
	}
	snakeX[0] = snakeX[1] - dx;
	snakeY[0] = snakeY[1] - dy;
	snakeLength++;
	if(snakeLength > 20){
		printf("The length of snake reach the maximum. You win!\n");
		exit(0);
	}
}
```

