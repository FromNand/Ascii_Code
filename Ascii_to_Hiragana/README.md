【ascii_to_romajiについて】

ascii_to_romajiとは、「48 65 6c 6c 6f 20 57 6f 72 6c 64 21 21 0a」のようなアスキーコードを表現したテキストをローマ字に変換するツール。
入力ファイルには、2桁の16進数を空白やタブ(実は0~9, A~F, a~f以外の文字ならなんでもいい)で区切って記述してください。
アスキーテキストの一行の最大文字数は1000文字。
それ以上は切り捨てられてしまうので、それ以上の文字数が必要な場合は改行してください。

[ascii.txt(入力ファイル)に記述するアスキーテキストの例]

23 69 6e 63 6c 75 64 65 3c 73 74 64 69 6f 2e 68 3e 0a 0a
69 6e 74 20 6d 61 69 6e 28 76 6f 69 64 29 7b 0a 09
69 6e 74 20 69 20 3d 20 30 3b 0a 0a 09
66 6f 72 28 69 20 3d 20 30 3b 20 69 20 3c 20 31 30 3b 20 69 2b 2b 29 7b 0a 09 09
70 72 69 6e 74 66 28 22 48 65 6c 6c 6f 20 57 6f 72 6c 64 21 21 5c 6e 22 29 3b 0a 09
7d 0a 0a 09
72 65 74 75 72 6e 20 30 3b 0a
7d

[出力結果]

#include<stdio.h>

int main(void){
	int i = 0;

	for(i = 0; i < 10; i++){
		printf("Hello World!!\n");
	}

	return 0;
}

【romaji_to_hiraganaについて】

romaji_to_hiraganaとは「boku ha uchuujinnda!!」といったローマ字が記述されたテキストをひらがなに変換するツール。

入力ファイルにはアスキーコードで表現される任意の文字が使用できます。
ただし、空白やタブ、改行を除いた制御文字は無視されることに注意してください。
あと、非常に致命的なのですが、3文字以上のローマ字から生成される日本語には対応できていません。
例えば「りゃ(rya)」や「しゅ(shu)」といったものを入力するとうまくプログラムが動作しませんが、「じゃ(ja)」や「ふぁ(fa)」はうまく動作します。
ちなみに、ローマ字以外の文字は変換されずに結果にファイルにも含まれます。

ローマ字テキストの一行の最大文字数は1000文字。
それ以上は切り捨てられてしまうので、それ以上の文字数が必要な場合は改行してください。

[romaji.txt(入力ファイル)に記述するローマ字テキストの例]

[BOINN + BOINN]

AIUEO
KAKIKUKEKO
SASISUSESO
TATITUTETO
NANINUNENO
HAHIHUHEHO
MAMIMUMEMO
YAYUYO
RARIRURERO
WAWONN

[BOINN + SIINN]

AIUEO
KaKiKuKeKo
SaSiSuSeSo
TaTiTuTeTo
NaNiNuNeNo
HaHiHuHeHo
MaMiMuMeMo
YaYuYo
RaRiRuReRo
WaWoNn

[SIINN + BOINN]

aiueo
kAkIkUkEkO
sAsIsUsEsO
tAtItUtEtO
nAnInUnEnO
hAhIhUhEhO
mAmImUmEmO
yAyUyO
rArIrUrErO
wAwOnN

[SIINN + SIINN]

aiueo
kakikukeko
sasisuseso
tatituteto
naninuneno
hahihuheho
mamimumemo
yayuyo
rarirurero
wawonn

[BOINN + BOINN]

GAGIGUGEGO
ZAZIZUZEZO
DADIDUDEDO
BABIBUBEBO
PAPIPUPEPO
LALILULELO
VU
FAFIFUFEFO
JAJIJUJEJO

[BOINN + SIINN]

GaGiGuGeGo
ZaZiZuZeZo
DaDiDuDeDo
BaBiBuBeBo
PaPiPuPePo
LaLiLuLeLo
Vu
FaFiFuFeFo
JaJiJuJeJo

[SIINN + BOINN]

gAgIgUgEgO
zAzIzUzEzO
dAdIdUdEdO
bAbIbUbEbO
pApIpUpEpO
lAlIlUlElO
vU
fAfIfUfEfO
jAjIjUjEjO

[SIINN + SIINN]

gagigugego
zazizuzezo
dadidudedo
babibubebo
papipupepo
lalilulelo
vu
fafifufefo
jajijujejo

[出力結果]

[ぼいん + ぼいん]

あいうえお
かきくけこ
さしすせそ
たちつてと
なにぬねの
はひふへほ
まみむめも
やゆよ
らりるれろ
わをん

[ぼいん + しいん]

あいうえお
かきくけこ
さしすせそ
たちつてと
なにぬねの
はひふへほ
まみむめも
やゆよ
らりるれろ
わをん

[しいん + ぼいん]

あいうえお
かきくけこ
さしすせそ
たちつてと
なにぬねの
はひふへほ
まみむめも
やゆよ
らりるれろ
わをん

[しいん + しいん]

あいうえお
かきくけこ
さしすせそ
たちつてと
なにぬねの
はひふへほ
まみむめも
やゆよ
らりるれろ
わをん

[ぼいん + ぼいん]

がぎぐげご
ざじずぜぞ
だぢづでど
ばびぶべぼ
ぱぴぷぺぽ
ぁぃぅぇぉ
ゔ
ふぁふぃふふぇふぉ
じぁじじゅじぇじょ

[ぼいん + しいん]

がぎぐげご
ざじずぜぞ
だぢづでど
ばびぶべぼ
ぱぴぷぺぽ
ぁぃぅぇぉ
ゔ
ふぁふぃふふぇふぉ
じぁじじゅじぇじょ

[しいん + ぼいん]

がぎぐげご
ざじずぜぞ
だぢづでど
ばびぶべぼ
ぱぴぷぺぽ
ぁぃぅぇぉ
ゔ
ふぁふぃふふぇふぉ
じぁじじゅじぇじょ

[しいん + しいん]

がぎぐげご
ざじずぜぞ
だぢづでど
ばびぶべぼ
ぱぴぷぺぽ
ぁぃぅぇぉ
ゔ
ふぁふぃふふぇふぉ
じぁじじゅじぇじょ
