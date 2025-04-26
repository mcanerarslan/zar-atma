# 🎲 Zar Atma Oyunu

Bu proje, C programlama dili kullanılarak geliştirilmiş basit ve eğlenceli bir **Zar Atma Oyunu**dur.  
Kullanıcı ve sistem belirli turlar boyunca zar atarak yarışır, en çok puanı toplayan kazanır!

---

## 📋 Özellikler
- 👤 Kullanıcıdan **isim** alır (boşluklu isim destekli).
- 🎮 1, 3 veya 5 tur seçimi yapılabilir.
- 🎲 Her turda kullanıcı ve sistem için zar atılır.
- 🏆 Turlar sonunda **puanlar** güncellenir.
- 🤝 Skorlar eşitse, **beraberlik kırmak için** ekstra bir zar atışı yapılabilir.
- 🔁 Oyun sonunda kullanıcıya tekrar oynamak isteyip istemediği sorulur.
- 🧹 Yanlış seçim ve karakter giriş hatalarına karşı tam koruma (`getchar()` kullanımı).

---

## 🚀 Kullanılan Dil ve Kütüphaneler
- **C** programlama dili
- `stdio.h`, `stdlib.h`, `time.h`, `unistd.h`, `string.h` kütüphaneleri

---

## 🚀 Nasıl Çalıştırılır?

### 1. Reposu klonlayın:
```bash
git clone https://github.com/mcanerarslan/zar-atma.git
cd zar-atma
```

### 2. Derleyin:
```bash
gcc main.c -o zar-atma
```

### 3. Oyunu çalıştırın:
```bash
./zar-atma
```
