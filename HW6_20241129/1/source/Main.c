#include <stdio.h>

// 定義結構 card
struct card {
    char* face; // 定義點數
    char* suit; // 定義花色
};

int main(void) {
    struct card aCard;       // 宣告一個 struct card 變數
    struct card* cardPtr;    // 宣告一個指向 struct card 的指標

    aCard.face = "Ace";
    aCard.suit = "Spades";

    cardPtr = &aCard; // 將 aCard 的地址賦值給 cardPtr

    // 使用結構成員運算子和指標運算子輸出結果
    printf("%s%s%s\n%s%s%s\n%s%s%s\n", aCard.face, " of ", aCard.suit,  // 使用結構變數直接訪問
       cardPtr->face, " of ", cardPtr->suit, // 使用指標訪問
       (*cardPtr).face, " of ", (*cardPtr).suit); // 另一種指標訪問方式

    return 0;
}