# Kalkulator Panas Total dengan Metode Aturan Trapesium

Proyek ini merupakan implementasi metode numerik Aturan Trapesium (Trapezoidal Rule) untuk menyelesaikan studi kasus perhitungan panas total dalam mata kuliah Pemrograman Numerik.

**Nama:** Musyaffa Iman Supriadi  
**NPM:** 2306208464

---

## Deskripsi Program

Program ini dibuat dalam bahasa C untuk menghitung jumlah panas total ($\Delta H$) yang diperlukan untuk menaikkan suhu suatu material dari suhu awal ($T_1$) ke suhu akhir ($T_2$).  Perhitungan ini didasarkan pada kapasitas kalor material, $c(T)$, yang nilainya berubah terhadap suhu dan dimodelkan sebagai fungsi polinomial.

Metode numerik yang digunakan adalah **Aturan Trapesium**, di mana area di bawah kurva fungsi $c(T)$ diaproksimasi dengan menjumlahkan luas dari sejumlah segmen berbentuk trapesium.

### Studi Kasus

- **Massa Material ($m$):** 1000 g
- **Suhu Awal ($T_1$):** -100 °C
- **Suhu Akhir ($T_2$):** 200 °C
- **Fungsi Kapasitas Kalor:**
  \( c(T) = 0.132 + 1.56 \times 10^{-4}T + 2.64 \times 10^{-7}T^2 \)

### Fitur Program

Program ini memiliki beberapa fungsi utama:
1.  **Menghitung Panas Total:** Mengalkulasi nilai $\Delta H$ secara numerik menggunakan Aturan Trapesium.
2.  **Analisis Error:** Membandingkan hasil numerik dengan solusi analitik (eksak) untuk menghitung persentase error.
3.  **Variasi Segmen:** Menampilkan hasil perhitungan untuk berbagai jumlah segmen ($n$) untuk menunjukkan bagaimana akurasi meningkat seiring bertambahnya jumlah segmen.
4.  **Demonstrasi Langkah-demi-Langkah:** Menyajikan rincian proses perhitungan untuk 10 segmen untuk menunjukkan cara kerja algoritma secara transparan.

### Contoh Output
![hasil run 1](https://github.com/user-attachments/assets/dee5390b-93e4-4adf-a40e-68e7297ef061)
![hasil run 2](https://github.com/user-attachments/assets/54030080-0ae0-488a-af8e-a33db95a3c5d)
![hasil run 3](https://github.com/user-attachments/assets/925e3a99-788f-426f-923c-c5fe83ea843d)
