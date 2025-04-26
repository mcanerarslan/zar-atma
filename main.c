#include <stdio.h>
#include <time.h>    // srand, time gibi rastgelelik ve zaman fonksiyonları için gerekli
#include <stdlib.h>  // rand, srand gibi rastgele sayı üretimi için gerekli
#include <unistd.h>  // sleep fonksiyonu ile zaman gecikmesi eklemek için gerekli
#include <string.h>  // fgets ile metin alma ve strcspn gibi string işlemleri için gerekli

int main(int argc, const char * argv[]) {
    
    char name[50];
    char blank[] = "────────────────────────────────────\n";
    char playAgain; // Kullanıcı oyunu tekrar oynamak ister mi

    srand(time(NULL));  // Her seferinde farklı rastgele sayı üretmek için gerekli
    
    printf("%s🎲 Zar Atma Oyununa Hoşgeldin! 🎲\n%s", blank, blank);
    printf("📝 Lütfen ismini gir: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    
    do { // Bir daha oynamak isterse diye do while içine koyuyoruz
        int gameModeInput, gameRound, pointOfUser = 0, pointOfBot = 0;

        printf("%s👋 Merhaba tekrar, %s!\n", blank, name);
        printf("%s🎲 Zar Atış Modu Seçimi:\n", blank);
        printf("   1️⃣ 1 tur\n");
        printf("   3️⃣ 3 tur\n");
        printf("   5️⃣ 5 tur\n");

        do {
            printf("👉 Seçimin:\t");
            scanf("%d", &gameModeInput);
            
            if (gameModeInput == 1 || gameModeInput == 3 || gameModeInput == 5) {
                switch(gameModeInput) {
                    case 1:
                        gameRound = 1;
                        printf("%s\t✅ 1 Tur seçildi. Başarılar!\n%s", blank, blank);
                        break;
                    case 3:
                        gameRound = 3;
                        printf("%s\t✅ 3 Tur seçildi. Başarılar!\n%s", blank, blank);
                        break;
                    case 5:
                        gameRound = 5;
                        printf("%s\t✅ 5 Tur seçildi. Başarılar!\n%s", blank, blank);
                        break;
                }
                break; // Doğru seçim yaptıysa döngüden çık
            } else {
                printf("%s!!! HATA - Yanlış seçim yaptınız.\nLütfen 1, 3 veya 5 seçiniz.\n%s", blank, blank);
            }
        } while(1);
        
        printf("🎲 \t Sistem\t\t vs %9s\n%s", name, blank);

        while (gameRound > 0) {
            int numberOfUser = rand() % 6 + 1;
            int numberOfBot = rand() % 6 + 1;
            
            printf("›\t\t%-10d|%9d\n", numberOfBot, numberOfUser);
            gameRound--;
            sleep(1);
            
            if (numberOfUser > numberOfBot) {
                pointOfUser++;
            } else if (numberOfBot > numberOfUser) {
                pointOfBot++;
            }
        }
        printf("%s", blank);
        
        if (pointOfUser > pointOfBot) {
            printf("🏆 Tebrikler, kazandın!\t📈 Skor: %d - %d\n", pointOfUser, pointOfBot);
        } else if (pointOfBot > pointOfUser) {
            printf("😔 Üzgünüm, kaybettin.\t📈 Skor: %d - %d\n", pointOfUser, pointOfBot);
        } else if (pointOfBot == pointOfUser) {
            printf("🤝 Berabere! Gerçekten sıkı bir mücadeleydi!\n");

            getchar(); // Buffer temizle
            char decision;
            printf("🎲 Beraberlik bozulması için son bir zar atışı yapalım mı? (E/H): ");
            scanf("%c", &decision);

            if (decision == 'E' || decision == 'e') {
                int numberOfUser = rand() % 6 + 1;
                int numberOfBot = rand() % 6 + 1;
                
                printf("🎲 \t Sistem\t\t vs %9s\n%s", name, blank);
                printf("›\t\t%-10d|%9d\n", numberOfBot, numberOfUser);
                
                if (numberOfUser > numberOfBot) {
                    printf("🏆 Son anda kazandın! Tebrikler!\n");
                } else if (numberOfBot > numberOfUser) {
                    printf("😔 Maalesef son zarla kaybettin.\n");
                } else {
                    printf("🤝 Yine berabere! Gerçekten inanılmaz bir mücadele!\n");
                }
            } else {
                printf("🤝 Oyun berabere bitti! Güzel mücadeleydi!\n");
            }
        }

        getchar(); // Buffer temizle
        printf("\n🎮 Tekrar oynamak ister misin? (E/H): ");
        scanf("%c", &playAgain);

    } while (playAgain == 'E' || playAgain == 'e'); // Evet derse oyun başa sarar

    printf("\n👋 Oyun bitti, tekrar görüşmek üzere!\n");
    
    return 0;
}
