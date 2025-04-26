#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> //sleep için

int main(int argc, const char * argv[]) {
    
    char name[15];
    char blank[] = "─────────────────────────────────\n";
    
    int gameModeInput,gameRound,pointOfUser=0, pointOfBot=0;;
    srand(time(NULL));
    
    printf("%s🎲 Hoşgeldin, Zar Atma Oyununa! 🎲\n%s", blank, blank);
    printf("📝 Lütfen ismini gir: ");
    scanf("%s", name);
    printf("%s👋 Merhaba tekrar, %s!\n", blank, name);
    printf("%s🎲 Zar Atış Modu Seçimi:\n", blank);
    printf("   1️⃣ 1 tur\n");
    printf("   3️⃣ 3 tur\n");
    printf("   5️⃣ 5 tur\n");
    printf("👉 Seçimin:\t");
    scanf("%d", &gameModeInput);
    
    switch(gameModeInput){
        case 1:
            gameRound =1;
            printf("✅ 1 Tur seçildi. Başarılar!\n");
            break;
        case 3:
            gameRound =3;
            printf("✅ 3 Tur seçildi. Başarılar!\n");
            break;
        case 5:
            gameRound=5;
            printf("✅ 5 Tur seçildi. Başarılar!\n");
            break;
        default:
            printf("%s!!! HATA - Yanlış seçim yaptınız.\nLütfen tekrar deneyiniz.\n%s",blank,blank);
            return 0;
    }
    
    
    
    printf("Kullanıcı\t vs\t\tSistem\n%s", blank);
    while(gameRound>0){
        
        
        int numberOfUser = rand() % 6 + 1;
        int numberOfBot = rand() % 6 + 1;
        
        printf("%6d\t\t |%10d\n",numberOfUser,numberOfBot);
        gameRound--;
        sleep(1);
        
        if(numberOfUser>numberOfBot){
            pointOfUser++;
        }else if(numberOfBot>numberOfUser){
            pointOfBot++;
        }
    }
    printf("%s",blank);
    
    if(pointOfUser>pointOfBot){
        printf("🏆 Tebrikler, kazandın! Harika iş çıkardın!\n");
    }else if(pointOfBot>pointOfUser){
        printf("😔 Üzgünüm, kaybettin. Bir dahaki sefere şansın açık olsun!\n");
    }else if(pointOfBot==pointOfUser){
        printf("🤝 Berabere! Gerçekten sıkı bir mücadeleydi!\n");
    }
    
    return 0;
}
