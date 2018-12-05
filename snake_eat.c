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
