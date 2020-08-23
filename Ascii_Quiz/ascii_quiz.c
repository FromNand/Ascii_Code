#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define QUESTION_NUM 190

//文字列の中の空白を取り除く関数

char* erase_space(char *s){
	int i, j, length = strlen(s);

	for(i = 0; i < length; ){
		if(s[i] == ' '){
			for(j = i; j < length - 1; j++){
				s[j] = s[j + 1];
			}
			length -= 1;
		}
		else i++;
	}
	s[length] = '\0';

	return s;
}

//引数の文字列が10進数や16進数の文字列かどうかを判定する関数
//引数の文字列を判定した結果が10進数や16進数だった場合は0を、それ以外の場合は1を返す

int number_string(char *s){
	int i, digit, base_number;

	digit = strlen(s);
	if(!digit) return 1;
	else if(digit > 10) return 1;

	if(strncmp(s, "0x", 2)) base_number = 10;
	else base_number = 16;
	if(base_number == 16 && digit == 2) return 1;

	if(base_number == 10){
		for(i = 0; i < digit; i++){
			if(s[i] < '0' || s[i] > '9') return 1;
		}
	}
	else if(base_number == 16){
		for(i = 2; i < digit; i++){
			if(s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'F' && s[i] < 'a') || s[i] > 'f') return 1;
		}
	}

	return 0;
}

//10進数や16進数の文字列を整数に変換する関数
//引数に取る文字列は完全無欠であることを前提としているので、そうでない場合は動作は未定義
//文字列の先頭に0xを指定した場合は16進数として計算し、それ以外の場合は10進数として計算する

int hatoi(char *s){
	int i, j, digit, base_number, tmp = 1, value = 0;

	digit = strlen(s);
	if(strncmp(s, "0x", 2)) base_number = 10;
	else base_number = 16;

	for(i = ((base_number == 16) ? 2 : 0) ; i < digit; i++){
		tmp = 1;
		for(j = digit - 1 - i; j > 0; j--){
			tmp *= base_number;
		}
		if(s[i] >= '1' && s[i] <= '9') value += (s[i] - 0x30) * tmp;
		else if(s[i] >= 'A' && s[i] <= 'F') value += (s[i] - 0x37) * tmp;
		else if(s[i] >= 'a' && s[i] <= 'f') value += (s[i] - 0x57) * tmp;
	}

	return value;
}

//実際のゲームプログラム

int main(void){
	int i, rand1, rand2, tmp, question[QUESTION_NUM], question_total, character_code, correct_count = 0, wrong_count, wrong_total, wrong_question[QUESTION_NUM];
	char user_input[100];

	printf("\nさあ、ASCIIクイズを始めよう！\n");
	printf("問題は最大%d問あり、そのすべてがランダムに出題されます。\n", QUESTION_NUM);
	printf("問題の形式は２つあり、左側に文字が書かれている場合と16進数が書かれている場合があります。\n");
	printf("文字が書かれている場合はその文字に対応する10進数か16進数を入力してください(先頭に0xをつけた場合は16進数、それ以外は10進数と判断されます)\n");
	printf("16進数が書かれている場合は対応する文字を入力してください。\n");
	printf("途中でやめたい場合はctrl+Cを使用してください。\n\n");

	srand((unsigned int)time(NULL));

	for(i = 0; i < QUESTION_NUM; i++) question[i] = i + 0x20;
	for(i = 0; i < QUESTION_NUM * 10; i++){
		rand1 = rand() % QUESTION_NUM;
		rand2 = rand() % QUESTION_NUM;
		tmp = question[rand1];
		question[rand1] = question[rand2];
		question[rand2] = tmp;
	}

	while(1){
		printf("挑戦したい問題数を入力してください(最大%d問です) -> ", QUESTION_NUM);
		fgets(user_input, 100, stdin);
		user_input[strlen(user_input) - 1] = '\0';
		erase_space(user_input);
		if(!number_string(user_input)) {
			question_total = hatoi(user_input);
			if(question_total >= 1 && question_total <= QUESTION_NUM) break;
			else printf("1から%dまでの数値を入力してください。\n", QUESTION_NUM);
		}
		else printf("入力した文字列は数字列でないか、桁数が正常ではありません。もう一度入力してください。\n");
	}
	printf("question_total = %d\n\n", question_total);

	for(i = 0; i < question_total; i++){
		printf("##### 第%d問 #####\n", i);
		if(question[i] < 0x7f){
			character_code = question[i];
			printf(" '%c' -> ", character_code);
number_again:
			fgets(user_input, 100, stdin);
			user_input[strlen(user_input) - 1] = '\0';
			erase_space(user_input);
			if(number_string(user_input)){
				printf("入力した文字列は数値列ではないか、桁数が正常ではありません。もう一度入力してください。 -> ");
				goto number_again;
			}
			if(character_code == hatoi(user_input)){
				printf("正解です！！\n");
				correct_count += 1;
			}
			else{
				printf("不正解です！！あなたの入力した値は %d(0x%x) でしたが、正解は %d(0x%x) でした！！\n", hatoi(user_input), hatoi(user_input), character_code, character_code);
				wrong_question[wrong_count] = character_code;
				wrong_count += 1;
			}
		}
		else{
			character_code = question[i] - 0x5f;
			printf("0x%02x -> ", character_code);
character_again:
			fgets(user_input, 100, stdin);
			user_input[strlen(user_input) - 1] = '\0';
			if(strlen(user_input) != 1){
				printf("文字を入力しなかったか、文字列を入力しました。一文字だけを入力してください。 -> ");
				goto character_again;
			}
			if(character_code == user_input[0]){
				printf("正解です！！\n");
				correct_count += 1;
			}
			else{
				printf("不正解です！！あなたの入力した文字は %c(0x%x) でしたが、正解は %c でした！！\n", user_input[0], user_input[0], character_code);
				wrong_question[wrong_count] = character_code + 0x80;
				wrong_count += 1;
			}
		}
		printf("\n");
	}

	while(wrong_count){
		printf("***** 最終結果 *****\n");
		printf("あなたは%d問のクイズのうち%d問正解しました。\n", question_total, correct_count);
		printf("あなたのクイズの正答率は%.2f%%です。\n\n", ((double)correct_count / question_total) * 100);

		while(1){
			printf("間違えた問題にもう一度チャレンジしますか？(y or n) -> ");
			fgets(user_input, 100, stdin);
			user_input[strlen(user_input) - 1] = '\0';
			if(strcmp("y", user_input) == 0 || strcmp("n", user_input) == 0) break;
			else printf("yかnで答えてください。\n");
		}
		printf("\n");

		if(user_input[0] == 'y'){
			wrong_total = wrong_count;
			wrong_count = 0;
			for(i = 0; i < wrong_total; i++){
				printf("##### 第%d問目 #####\n", i);
				if(wrong_question[i] < 0x80){
					character_code = wrong_question[i];
					printf(" '%c' -> ", character_code);
number_again2:
					fgets(user_input, 100, stdin);
					user_input[strlen(user_input) - 1] = '\0';
					erase_space(user_input);
					if(number_string(user_input)){
						printf("入力した文字列は数値列ではないか、桁数が正常ではありません。もう一度入力してください。 -> ");
						goto number_again2;
					}
					if(character_code == hatoi(user_input)){
						printf("正解です！！\n");
						correct_count += 1;
					}
					else{
						printf("不正解です！！あなたの入力した値は %d(0x%x) でしたが、正解は %d(0x%x) でした！！\n", hatoi(user_input), hatoi(user_input), character_code, character_code);
						wrong_question[wrong_count] = character_code;
						wrong_count += 1;
					}
				}
				else{
					character_code = wrong_question[i] - 0x80;
					printf("0x%02x -> ", character_code);
character_again2:
					fgets(user_input, 100, stdin);
					user_input[strlen(user_input) - 1] = '\0';
					if(strlen(user_input) != 1){
						printf("文字を入力しなかったか、文字列を入力しました。一文字だけを入力してください。 -> ");
						goto character_again2;
					}
					if(character_code == user_input[0]){
						printf("正解です！！\n");
						correct_count += 1;
					}
					else{
						printf("不正解です！！あなたの入力した文字は %c(0x%x) でしたが、正解は %c でした！！\n", user_input[0], user_input[0], character_code);
						wrong_question[wrong_count] = character_code + 0x80;
						wrong_count += 1;
					}
				}
				printf("\n");
			}
		}
		else break;
	}
	if(correct_count == question_total) printf("あなたはすべての問題に正解しました！！\n\n");

	return 0;
}
