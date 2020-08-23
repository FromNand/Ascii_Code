#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//引数の文字が16進数で使用できる文字(0~9, A~F, a~f)であるかどうかを調べて、もし使用できる文字であった場合は対応する値(0~9, 10~15, 10~15)を返す
//それ以外の場合は-1を返す

int ishexdigit(char c){
	if(c >= '0' && c <= '9') return c - 0x30;
	else if(c >= 'A' && c <= 'F') return c - 0x37;
	else if(c >= 'a' && c <= 'f') return c - 0x57;
	return -1;
}

int main(int argc, char **argv){
	int i, length, phase, number, character_count = 0;
	FILE *fp;
	char *buffer, *string, character;

	if(argc != 2){
		printf("プログラムの引数にアスキーコードがテキスト形式で記述されたファイルを指定してください。\n");
		exit(1);
	}

	if(!(fp = fopen(argv[1], "rb"))){
		printf("%s が開けません。\n", argv[1]);
		exit(2);
	}

	if(!(buffer = malloc(1000))){
		printf("読み込みバッファ用のメモリが確保できませんでした。\n");
		exit(3);
	}

	if(!(string = malloc(1000))){
		printf("出力用バッファのメモリが確保できませんでした。\n");
		exit(4);
	}

	while(fgets(buffer, 1000, fp)){
		phase = 0;
		character = 0;
		length = strlen(buffer);
		buffer[length - 1] = '\0';
		for(i = 0; i < length; i++){
			number = ishexdigit(buffer[i]);
			if(number != -1){
				if(phase == 0) {character += number * 16; phase += 1;}
				else if(phase == 1) {character += number; phase += 1;}
				else if(phase == 2) {printf("アスキーテキストに記述する16進数は2桁ずつで区切ってください。\n"); exit(5);}
			}
			else{
				if(phase == 0) continue;
				else if(phase == 1) {printf("アスキーテキストに記述する16進数は2桁ずつで区切ってください。\n"); exit(6);}
				else if(phase == 2) {
					phase = 0;
					string[character_count++] = character;
					character = 0;
				}
			}
		}
	}
	string[character_count] = '\0';

	printf("%s\n", string);

	fclose(fp);
	free(buffer);
	free(string);

	return 0;
}
