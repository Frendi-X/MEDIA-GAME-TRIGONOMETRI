# 📐 Media Game Trigonometri Interaktif - Arduino Project


![alt text](https://github.com/Frendi-X/MEDIA-GAME-TRIGONOMETRI/blob/main/png/MEDIA%20GAME%20TRIGONOMETRI.png)

Proyek ini merupakan media pembelajaran interaktif berbasis Arduino yang digunakan untuk menguji pemahaman konsep trigonometri siswa melalui game fisik berbentuk kuis. Program ini menggunakan tombol sebagai input jawaban, LED sebagai indikator, DFPlayer Mini untuk audio instruksi dan feedback, serta servo motor sebagai efek mekanis saat jawaban salah. [SKRIPSI - Pendidikan Matematika UMPO]

## 🎮 Fitur Utama

- 🔘 **Tombol Soal dan Jawaban**  
  Terdapat 14 tombol soal trigonometri dan 14 tombol jawaban yang mewakili nilai-nilai fungsi trigonometri.

- 💡 **Indikator LED**  
  Setiap jawaban memiliki LED-nya sendiri. Terdapat juga LED indikator `BENAR` dan `SALAH`.

- 🔊 **DFPlayer Mini**  
  Digunakan untuk memutar instruksi audio soal dan feedback jawaban (benar/salah).

- ⚙️ **Servo Motor**  
  Servo akan bergerak ketika jawaban salah sebagai bentuk punishment visual dan kembali ke posisi awal saat jawaban benar ditekan.

---

## 🔧 Komponen yang Digunakan

- Arduino (Board yang kompatibel)
- DFPlayer Mini + speaker
- Tombol pushbutton (28 buah)
- LED (16 buah)
- Servo motor
- Resistor (untuk pull-up jika diperlukan)
- Breadboard, kabel jumper
- Power supply eksternal (opsional)

---

## 📂 Struktur Pin

### 🔢 Tombol Soal Trigonometri (Input)
| Fungsi Trigonometri | Pin |
|---------------------|-----|
| sin(0)              | 34  |
| sin(30)             | 33  |
| sin(45)             | 30  |
| cos(360)            | 29  |
| tan(120)            | 32  |
| sec(180)            | 31  |
| cosec(60)           | 28  |
| sec(120)            | 27  |
| sec(45)             | 26  |
| cot(60)             | 25  |
| cos(120)            | 24  |
| cos(30)             | 21  |
| tan(90)             | 22  |
| cosec(30)           | 23  |

### 🔘 Tombol Jawaban
| Nilai               | Pin |
|---------------------|-----|
| 0                   | 40  |
| 1/2                 | 39  |
| -√3                 | 38  |
| -1                  | 37  |
| -1/2                | 36  |
| Tak hingga (∞)      | 35  |
| √2/2                | 46  |
| 1/√3                | 45  |
| 2                   | 44  |
| √3/2                | 43  |
| √2                  | 42  |
| -2                  | 41  |
| 1                   | 48  |
| 2/√3                | 47  |

### 💡 LED Jawaban
Pin LED mengikuti urutan tombol jawaban pada pin analog (A0 - A15 dan A5 - A12).

### ✅ LED Indikator
- `LED_BENAR` → A14  
- `LED_SALAH` → A13  

### 🔁 Servo Motor
- Servo dikontrol melalui pin digital `5`.

---

## 🔊 Audio (DFPlayer Mini)

- File MP3 disimpan dalam urutan tertentu.
- Suara soal disesuaikan dengan nomor urut soal.
- File feedback benar (misal: `Benar.mp3`) = index 29  
- File feedback salah (misal: `Salah.mp3`) = index 30

---

## 🔁 Alur Program

1. **Tombol soal ditekan** → Memicu audio soal dan menunggu input.
2. **Menunggu jawaban**:
   - Jika **benar**:
     - LED jawaban dan LED benar menyala.
     - Audio feedback benar diputar.
   - Jika **salah**:
     - LED jawaban salah menyala.
     - LED salah menyala.
     - Servo bergerak ke 90° sebagai petunjuk.
     - Sistem menunggu hingga tombol jawaban **benar** ditekan untuk mengembalikan servo ke posisi semula.
3. **Semua LED dimatikan**, siap menerima soal berikutnya.

---

## 🧠 Tujuan Pembelajaran

Proyek ini bertujuan membantu siswa memahami nilai fungsi trigonometri dalam bentuk interaktif yang menyenangkan dan berbasis audio-visual-kinestetik.

---

## 📌 Catatan Teknis

- Gunakan library:
  - `DFPlayer_Mini_Mp3.h`
  - `SoftwareSerial.h`
  - `Servo.h`
- Pastikan file audio diberi nama sesuai urutan DFPlayer dan di-copy ke SD Card FAT32.

---

## 🛠️ Pengembangan Selanjutnya

- Tambahkan **LCD** untuk petunjuk visual.
- Tambahkan **skoring otomatis**.
- Gunakan **ESP32** atau **I2C expander** jika jumlah pin tidak mencukupi.

---

## Contacs us : 
* [Frendi RoboTech](https://www.instagram.com/frendi.co/)
* [Whatsapp : +6287888227410](https://wa.me/+6287888227410)
* [Email    : frendirobotech@gmail.com](https://mail.google.com/mail/u/0/?view=cm&tf=1&fs=1&to=frendirobotech@gmail.com) atau [Email    : frendix45@gmail.com](https://mail.google.com/mail/u/0/?view=cm&tf=1&fs=1&to=frendix45@gmail.com)

---

## 👨‍💻 Author
Dikembangkan oleh: [Reog Robotic & Robotech Electronics]  
Untuk: Media Pembelajaran Interaktif Trigonometri
