#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_lower_vowel(char c){
	if(c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') return 1;
	return 0;
}

int is_alphabet(char c){
	if(c >= 'A' && c <= 'Z') return 1;
	else if(c >= 'a' && c <= 'z') return 2;
	return 0;
}

int one_character(char *s1, char *s2){
	s2[0] = 0xe3;
	s2[1] = 0x81;
	if(*s1 == 'A'){s2[2] = 0x82; return 3;}
	else if(*s1 == 'I'){s2[2] = 0x84; return 3;}
	else if(*s1 == 'U'){s2[2] = 0x86; return 3;}
	else if(*s1 == 'E'){s2[2] = 0x88; return 3;}
	else if(*s1 == 'O'){s2[2] = 0x8a; return 3;}
	return 0;
}

int two_character(char *s1, char *s2){
	s2[0] = 0xe3;
	if(s1[0] == 'K'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0x8b; return 3;}
		if(s1[1] == 'I'){s2[2] = 0x8d; return 3;}
		if(s1[1] == 'U'){s2[2] = 0x8f; return 3;}
		if(s1[1] == 'E'){s2[2] = 0x91; return 3;}
		if(s1[1] == 'O'){s2[2] = 0x93; return 3;}
	}
	else if(s1[0] == 'Z'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0x96; return 3;}
		if(s1[1] == 'I'){s2[2] = 0x98; return 3;}
		if(s1[1] == 'U'){s2[2] = 0x9a; return 3;}
		if(s1[1] == 'E'){s2[2] = 0x9c; return 3;}
		if(s1[1] == 'O'){s2[2] = 0x9e; return 3;}
	}
	else if(s1[0] == 'G'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0x8c; return 3;}
		if(s1[1] == 'I'){s2[2] = 0x8e; return 3;}
		if(s1[1] == 'U'){s2[2] = 0x90; return 3;}
		if(s1[1] == 'E'){s2[2] = 0x92; return 3;}
		if(s1[1] == 'O'){s2[2] = 0x94; return 3;}
	}
	else if(s1[0] == 'S'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0x95; return 3;}
		if(s1[1] == 'I'){s2[2] = 0x97; return 3;}
		if(s1[1] == 'U'){s2[2] = 0x99; return 3;}
		if(s1[1] == 'E'){s2[2] = 0x9b; return 3;}
		if(s1[1] == 'O'){s2[2] = 0x9d; return 3;}
	}
	else if(s1[0] == 'T'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0x9f; return 3;}
		if(s1[1] == 'I'){s2[2] = 0xa1; return 3;}
		if(s1[1] == 'U'){s2[2] = 0xa4; return 3;}
		if(s1[1] == 'E'){s2[2] = 0xa6; return 3;}
		if(s1[1] == 'O'){s2[2] = 0xa8; return 3;}
	}
	else if(s1[0] == 'D'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0xa0; return 3;}
		if(s1[1] == 'I'){s2[2] = 0xa2; return 3;}
		if(s1[1] == 'U'){s2[2] = 0xa5; return 3;}
		if(s1[1] == 'E'){s2[2] = 0xa7; return 3;}
		if(s1[1] == 'O'){s2[2] = 0xa9; return 3;}
	}
	else if(s1[0] == 'N'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0xaa; return 3;}
		if(s1[1] == 'I'){s2[2] = 0xab; return 3;}
		if(s1[1] == 'U'){s2[2] = 0xac; return 3;}
		if(s1[1] == 'E'){s2[2] = 0xad; return 3;}
		if(s1[1] == 'O'){s2[2] = 0xae; return 3;}
		if(s1[1] == 'N'){s2[1] = 0x82; s2[2] = 0x93; return 3;}
	}
	else if(s1[0] == 'H'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0xaf; return 3;}
		if(s1[1] == 'I'){s2[2] = 0xb2; return 3;}
		if(s1[1] == 'U'){s2[2] = 0xb5; return 3;}
		if(s1[1] == 'E'){s2[2] = 0xb8; return 3;}
		if(s1[1] == 'O'){s2[2] = 0xbb; return 3;}
	}
	else if(s1[0] == 'B'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0xb0; return 3;}
		if(s1[1] == 'I'){s2[2] = 0xb3; return 3;}
		if(s1[1] == 'U'){s2[2] = 0xb6; return 3;}
		if(s1[1] == 'E'){s2[2] = 0xb9; return 3;}
		if(s1[1] == 'O'){s2[2] = 0xbc; return 3;}
	}
	else if(s1[0] == 'P'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0xb1; return 3;}
		if(s1[1] == 'I'){s2[2] = 0xb4; return 3;}
		if(s1[1] == 'U'){s2[2] = 0xb7; return 3;}
		if(s1[1] == 'E'){s2[2] = 0xba; return 3;}
		if(s1[1] == 'O'){s2[2] = 0xbd; return 3;}
	}
	else if(s1[0] == 'M'){
		if(s1[1] == 'A'){s2[1] = 0x81; s2[2] = 0xbe; return 3;}
		if(s1[1] == 'I'){s2[1] = 0x81; s2[2] = 0xbf; return 3;}
		if(s1[1] == 'U'){s2[1] = 0x82; s2[2] = 0x80; return 3;}
		if(s1[1] == 'E'){s2[1] = 0x82; s2[2] = 0x81; return 3;}
		if(s1[1] == 'O'){s2[1] = 0x82; s2[2] = 0x82; return 3;}
	}
	else if(s1[0] == 'Y'){
		s2[1] = 0x82;
		if(s1[1] == 'A'){s2[2] = 0x84; return 3;}
		if(s1[1] == 'U'){s2[2] = 0x86; return 3;}
		if(s1[1] == 'O'){s2[2] = 0x88; return 3;}
	}
	else if(s1[0] == 'R'){
		s2[1] = 0x82;
		if(s1[1] == 'A'){s2[2] = 0x89; return 3;}
		if(s1[1] == 'I'){s2[2] = 0x8a; return 3;}
		if(s1[1] == 'U'){s2[2] = 0x8b; return 3;}
		if(s1[1] == 'E'){s2[2] = 0x8c; return 3;}
		if(s1[1] == 'O'){s2[2] = 0x8d; return 3;}
	}
	else if(s1[0] == 'W'){
		s2[1] = 0x82;
		if(s1[1] == 'A'){s2[2] = 0x8f; return 3;}
		if(s1[1] == 'O'){s2[2] = 0x92; return 3;}
	}
	else if(s1[0] == 'V' && s1[1] == 'U'){
		s2[1] = 0x82;
		s2[2] = 0x94;
		return 3;
	}
	else if(s1[0] == 'L'){
		s2[1] = 0x81;
		if(s1[1] == 'A'){s2[2] = 0x81; return 3;}
		if(s1[1] == 'I'){s2[2] = 0x83; return 3;}
		if(s1[1] == 'U'){s2[2] = 0x85; return 3;}
		if(s1[1] == 'E'){s2[2] = 0x87; return 3;}
		if(s1[1] == 'O'){s2[2] = 0x89; return 3;}
	}
	else if(s1[0] == 'F'){
		s2[1] = 0x81;
		s2[2] = 0xb5;
		s2[3] = 0xe3;
		s2[4] = 0x81;
		if(s1[1] == 'A'){s2[5] = 0x81; return 6;}
		if(s1[1] == 'I'){s2[5] = 0x83; return 6;}
		if(s1[1] == 'U'){s2[2] = 0xb5; return 3;}
		if(s1[1] == 'E'){s2[5] = 0x87; return 6;}
		if(s1[1] == 'O'){s2[5] = 0x89; return 6;}
	}
	else if(s1[0] == 'J'){
		s2[1] = 0x81;
		s2[2] = 0x98;
		s2[3] = 0xe3;
		s2[4] = 0x82;
		if(s1[1] == 'A'){s2[4] = 0x81; s2[5] = 0x81; return 6;}
		if(s1[1] == 'I'){s2[2] = 0x98; return 3;}
		if(s1[1] == 'U'){s2[5] = 0x85; return 6;}
		if(s1[1] == 'E'){s2[4] = 0x81; s2[5] = 0x87; return 6;}
		if(s1[1] == 'O'){s2[5] = 0x87; return 6;}
	}
	return 0;
}

int main(int argc, char **argv){
	char *buffer, *string, *string_top;
	FILE *fp;
	int i, length, character_size;

	if(argc != 2){
		printf("引数に変換したいローマ字テキストを指定してください。\n");
		exit(1);
	}

	if(!(buffer = malloc(1000))){
		printf("読み込みバッファ用のメモリが確保できませんでした。\n");
		exit(2);
	}

	if(!(string = malloc(6000))){
		printf("出力用バッファのメモリが確保できませんでした。\n");
		exit(3);
	}
	string_top = string;

	if(!(fp = fopen(argv[1], "rb"))){
		printf("%s が開けませんでした。\n", argv[1]);
		exit(4);
	}

	while(fgets(buffer, 1000, fp)){
		length = strlen(buffer);
		for(i = 0; i < length; ){
			//そもそもアルファベットでない文字はそのまま出力する
			if(is_alphabet(buffer[i]) == 0){
				*string++ = buffer[i];
				i += 1;
				continue;
			}

			//考えうる状況を少なくするため、小文字のアルファベットは大文字のアルファベットに変換する
			if(is_alphabet(buffer[i]) == 2) buffer[i] -= 0x20;
			//もし一文字目が母音ならば即ひらがな(カタカナ)に変換する
			if(is_lower_vowel(buffer[i])){
				if(character_size = one_character(buffer + i, string)) string += character_size;
				else{printf("ローマ字の一文字変換に失敗しました。\n"); exit(5);}
				i += 1;
				continue;
			}

			//考えうる状況を少なくするため、小文字のアルファベットは大文字のアルファベットに変換する
			if(is_alphabet(buffer[i+1]) == 2) buffer[i+1] -= 0x20;
			//もし二文字目が母音ならば一文字目との組み合わせでひらがな(カタカナ)に変換する
			//ん(NN)は例外なので、or条件を使用して処理する
			if(is_lower_vowel(buffer[i+1]) || !strncmp(buffer + i, "NN", 2)){
				if(character_size = two_character(buffer + i, string)) string += character_size;
				else{printf("ローマ字の二文字変換に失敗しました。\n"); exit(6);}
				i += 2;
				continue;
			}

			//ここまでくるということは「りゃ」や「しゃ」といった実装されていない文字を書いたか、子音を単体で書いているなどの入力ミスということになる
			printf("実装されていない文字を入力したか、入力した文字がおかしいです。\n");
			exit(7);
		}
	}
	string[-1] = '\0';

	printf("%s\n", string_top);
			
	free(buffer);
	free(string_top);
	fclose(fp);	

	return 0;
}
