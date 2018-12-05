void snakeMove(int dx, int dy){
	//Ԥ��ͷ���Ƿ���ײ��ǽ�ڻ��߳Ե��Լ� 
	int head = snakeLength-1;
	char ch_head = map[snakeY[head]+dy][snakeX[head]+dx];
	if(ch_head == WALL_CELL || ch_head == SNAKE_BODY) 
		flag_over = 1;
	if(ch_head == SNAKE_FOOD){
		snakeEat();
		flag_eat = 1;
	} 
	
	//���ԭ������ 
	for(int i = 0; i < snakeLength; i++)
		if(map[snakeY[i]][snakeX[i]] != WALL_CELL)  map[snakeY[i]][snakeX[i]] = BLANK_CELL;
		
	//������������ 
	for(int i = 0; i < snakeLength-1; i++){
		snakeX[i] = snakeX[i+1];
		snakeY[i] = snakeY[i+1];
	}
	head = snakeLength - 1;
	snakeX[head] = snakeX[head] + dx;
	snakeY[head] = snakeY[head] + dy;

	//��λ������ַ� 
	map[snakeY[head]][snakeX[head]] = SNAKE_HEAD;
	for(int i = 0; i < snakeLength-1; i++)
		map[snakeY[i]][snakeX[i]] = SNAKE_BODY;
}
