ASCII=ascii.txt
ROMAJI=romaji.txt
JAPANESE=hiragana.txt

SRC1=ascii_to_romaji.c
EXE1=ascii_to_romaji

SRC2=romaji_to_hiragana.c
EXE2=romaji_to_hiragana

all: $(EXE1) $(EXE2) $(JAPANESE)

$(EXE1): $(SRC1)
	gcc $(SRC1) -o $(EXE1)

$(EXE2): $(SRC2)
	gcc $(SRC2) -o $(EXE2)

$(JAPANESE): $(ASCII) $(EXE1) $(EXE2)
	./$(EXE1) $(ASCII) > $(ROMAJI)
	./$(EXE2) $(ROMAJI) > $(JAPANESE)

clean:
	rm -f $(ROMAJI) $(JAPANESE) $(EXE1) $(EXE2)
