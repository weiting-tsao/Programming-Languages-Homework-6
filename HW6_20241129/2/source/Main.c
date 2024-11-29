#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 定義Card結構 */
struct card {
    const char* face; /* 定義指標face */
    const char* suit; /* 定義指標suit */
}; /* 結構結束 */

typedef struct card Card; /* 定義新類型名稱 */

/* 函數原型 */
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal(const Card* const wDeck);

int main(void) {
    Card deck[52]; /* 定義一副牌的陣列 */

    /* 初始化點數的指標陣列 */
    const char* face[] = {
        "Ace", "Deuce", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Jack", "Queen", "King"
    };

    /* 初始化花色的指標陣列 */
    const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    srand(time(NULL)); /* 設定隨機數生成器的種子 */

    fillDeck(deck, face, suit); /* 填充牌組 */
    shuffle(deck);             /* 洗牌 */
    deal(deck);                /* 發牌 */

    return 0; /* 表示程式順利結束 */
}

/* 將字串放入Card結構中 */
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]) {
    for (int i = 0; i < 52; i++) {
        wDeck[i].face = wFace[i % 13];
        wDeck[i].suit = wSuit[i / 13];
    }
}

/* 洗牌函數 */
void shuffle(Card* const wDeck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52; /* 生成0到51之間的隨機數 */
        Card temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

/* 發牌函數 */
void deal(const Card* const wDeck) {
    for (int i = 0; i < 52; i++) {
        printf("%5s of %-8s%s",
            wDeck[i].face,
            wDeck[i].suit,
            (i + 1) % 4 ? " " : "\n");
    }
}