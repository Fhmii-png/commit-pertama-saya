# 📊 Dokumentasi Struktur Data - Stack dan Linked List

## Ringkasan Penggunaan Struktur Data dalam Web Absensi

Aplikasi Web Absensi mengimplementasikan dua struktur data utama untuk mengelola data dengan efisien:

---

## 1. 🔲 STACK (Last In First Out - LIFO)

### Lokasi File
`backend/src/dataStructures/Stack.js`

### Tujuan Penggunaan
**Menyimpan History/Riwayat Absensi Terbaru**

### Alasan Menggunakan Stack
1. **LIFO Principle**: Data absensi terbaru diakses terlebih dahulu
2. **Memory Efficient**: Hanya menyimpan 10 record terbaru
3. **Fast Access**: Operasi push/pop O(1) complexity
4. **Real-time Tracking**: Mudah melihat perubahan status terakhir

### Operasi yang Didukung

```javascript
// 1. PUSH - Menambahkan absensi baru ke stack
stack.push({
  id: "1704578900000",
  userId: "1704562800000",
  date: "2024-01-10",
  status: "Hadir",
  timestamp: "2024-01-10T10:30:00.000Z"
});

// 2. POP - Menghapus record teratas (tertua ketika limit tercapai)
const removed = stack.pop();

// 3. PEEK - Melihat record terbaru tanpa menghapus
const latest = stack.peek();

// 4. GET ALL - Mengambil seluruh history
const allHistory = stack.getAll();

// 5. SIZE - Melihat jumlah record
const count = stack.size();

// 6. IS EMPTY - Cek apakah kosong
const empty = stack.isEmpty();

// 7. CLEAR - Mengosongkan stack
stack.clear();
```

### Contoh Penggunaan di Controller

```javascript
// src/controllers/absensiController.js

// Global stack untuk history (max 10 record)
const absensiHistoryStack = new Stack();
const MAX_HISTORY = 10;

const submitAbsensi = (req, res) => {
  // ... validasi ...
  
  const savedAbsensi = db.saveAbsensi(absensiData);
  
  // Tambah ke stack
  absensiHistoryStack.push(savedAbsensi);
  
  // Jika sudah lebih dari 10, buang yang paling lama
  if (absensiHistoryStack.size() > MAX_HISTORY) {
    absensiHistoryStack.pop();
  }
  
  res.status(201).json({ success: true, data: savedAbsensi });
};

const getAbsensiHistory = (req, res) => {
  // Return 10 history terakhir dari stack
  const history = absensiHistoryStack.getAll();
  
  res.status(200).json({
    success: true,
    message: "History absensi (10 terbaru)",
    data: history,
    totalHistory: history.length
  });
};
```

### Use Case Real-World

**Skenario:** Admin melihat aktivitas absensi terbaru
```
Waktu 10:00 - Siswa A: Hadir        ← Paling terbaru (PUSH)
Waktu 09:50 - Siswa B: Sakit        
Waktu 09:40 - Siswa C: Izin         
Waktu 09:30 - Siswa D: Alpa         
...
Waktu 08:00 - Siswa J: Hadir        ← Paling tua

Jika ada record ke-11, record paling tua akan dihapus otomatis.
```

### Kompleksitas Waktu
| Operasi | Kompleksitas |
|---------|-------------|
| Push    | O(1)        |
| Pop     | O(1)        |
| Peek    | O(1)        |
| Size    | O(1)        |
| isEmpty | O(1)        |

---

## 2. 🔗 LINKED LIST (Sequential Data Structure)

### Lokasi File
`backend/src/dataStructures/LinkedList.js`

### Tujuan Penggunaan
**Menyimpan Data Siswa/Murid**

### Alasan Menggunakan Linked List
1. **Dynamic Sizing**: Fleksibel menambah/menghapus siswa
2. **Efficient Insertion/Deletion**: Tidak perlu reallocation seperti array
3. **Search by Property**: Mudah mencari siswa berdasarkan ID atau nama
4. **Sequential Access**: Traverse siswa satu per satu

### Struktur Node

```javascript
class Node {
  constructor(data) {
    this.data = data;      // Data siswa
    this.next = null;      // Pointer ke node berikutnya
  }
}

// Contoh data siswa di node:
{
  id: "1704562800000",
  email: "siswa1@school.com",
  name: "Siswa 1",
  role: "siswa",
  createdAt: "2024-01-06T10:00:00.000Z"
}
```

### Visualisasi Linked List

```
┌─────────────────────┐
│ HEAD                │
└──────────┬──────────┘
           │
           ▼
    ┌─────────────┬────────┐
    │ Siswa 1     │ next ──┼───┐
    │ id: 1       │        │   │
    └─────────────┴────────┘   │
                                │
                     ┌──────────▼─────┬────────┐
                     │ Siswa 2        │ next ──┼───┐
                     │ id: 2          │        │   │
                     └────────────────┴────────┘   │
                                                   │
                                    ┌──────────────▼──┬────────┐
                                    │ Siswa 3         │ next ──┼──► null
                                    │ id: 3           │        │
                                    └─────────────────┴────────┘
```

### Operasi yang Didukung

```javascript
// 1. APPEND - Menambah siswa di akhir
linkedList.append({
  email: "siswa1@school.com",
  name: "Siswa 1",
  role: "siswa"
});

// 2. PREPEND - Menambah siswa di awal
linkedList.prepend({
  email: "siswa2@school.com",
  name: "Siswa 2",
  role: "siswa"
});

// 3. INSERT AT - Menyisipkan di posisi tertentu
linkedList.insertAt(data, 1); // Insert di index 1

// 4. FIND BY - Mencari berdasarkan properti
const siswa = linkedList.findBy('email', 'siswa1@school.com');

// 5. REMOVE - Menghapus berdasarkan data
linkedList.remove(siswa);

// 6. REMOVE AT - Menghapus berdasarkan index
linkedList.removeAt(1);

// 7. GET AT - Mengambil data pada index
const siswa = linkedList.getAt(0);

// 8. TO ARRAY - Konversi ke array
const allSiswa = linkedList.toArray();

// 9. IS EMPTY - Cek apakah kosong
const empty = linkedList.isEmpty();

// 10. SIZE - Jumlah siswa
const count = linkedList.getSize();

// 11. CLEAR - Kosongkan linked list
linkedList.clear();
```

### Contoh Penggunaan di Controller

```javascript
// src/controllers/userController.js

// Global linked list untuk menyimpan siswa
const siswalist = new LinkedList();

// Inisialisasi dari database
const initializeSiswaList = () => {
  const users = db.getAllUsers();
  users.forEach(user => {
    siswalist.append(user);
  });
};

// Get all siswa
const getAllSiswa = (req, res) => {
  const siswaArray = siswalist.toArray();
  const filteredSiswa = siswaArray
    .filter(s => s.role === 'siswa')
    .map(s => ({
      id: s.id,
      name: s.name,
      email: s.email,
      role: s.role,
      createdAt: s.createdAt
    }));

  res.status(200).json({
    success: true,
    message: "Data semua siswa (dari Linked List)",
    data: filteredSiswa,
    total: filteredSiswa.length
  });
};

// Search siswa
const searchSiswa = (req, res) => {
  const { keyword } = req.query;
  const siswaArray = siswalist.toArray();
  
  const results = siswaArray.filter(s =>
    s.role === 'siswa' &&
    (s.name.toLowerCase().includes(keyword.toLowerCase()) ||
     s.email.toLowerCase().includes(keyword.toLowerCase()))
  );

  res.status(200).json({
    success: true,
    message: `Hasil pencarian untuk "${keyword}"`,
    data: results,
    total: results.length
  });
};

// Add siswa
const addSiswa = (req, res) => {
  // ... validasi ...
  
  const newSiswa = db.saveUser({...});
  
  // Tambah ke linked list
  siswalist.append(newSiswa);
  
  res.status(201).json({
    success: true,
    message: 'Siswa berhasil ditambahkan',
    data: newSiswa
  });
};

// Delete siswa
const deleteSiswa = (req, res) => {
  const { id } = req.params;
  
  // Hapus dari database
  const deletedSiswa = db.deleteUser(id);
  
  // Hapus dari linked list
  siswalist.remove(deletedSiswa);
  
  res.status(200).json({
    success: true,
    message: 'Siswa berhasil dihapus',
    data: deletedSiswa
  });
};
```

### Use Case Real-World

**Skenario 1: Tambah Siswa Baru**
```javascript
// Admin menambah siswa baru
const newSiswa = {
  id: "1704562800001",
  email: "siswa_baru@school.com",
  name: "Siswa Baru",
  role: "siswa"
};

// Append ke linked list (O(n) karena harus traverse ke akhir)
siswalist.append(newSiswa);
```

**Skenario 2: Cari Siswa**
```javascript
// Cari siswa berdasarkan email
const siswa = siswalist.findBy('email', 'siswa1@school.com');
// Traverse dari head sampai ketemu → O(n)
```

**Skenario 3: Hapus Siswa**
```javascript
// Hapus siswa dari linked list
siswalist.remove(siswa);
// Traverse sampai ketemu, kemudian update pointer → O(n)
```

### Kompleksitas Waktu
| Operasi | Kompleksitas |
|---------|-------------|
| Append  | O(n)        |
| Prepend | O(1)        |
| Insert  | O(n)        |
| Find    | O(n)        |
| Remove  | O(n)        |
| Get At  | O(n)        |
| Size    | O(1)        |

---

## 3. 📊 Perbandingan Stack vs Linked List

| Aspek | Stack | Linked List |
|-------|-------|------------|
| **Struktur** | LIFO | Sequential |
| **Kegunaan** | History/Recent data | Collection with dynamic size |
| **Insert** | O(1) | O(n) |
| **Delete** | O(1) | O(n) |
| **Search** | O(n) | O(n) |
| **Memory** | Fixed size (10) | Dynamic |

---

## 4. 🔗 Integrasi dalam Aplikasi

### Data Flow

```
┌─────────────────────────────────────────────────────┐
│           FRONTEND (React)                           │
│  Login → Submit Absensi → View History → View Rekap │
└────────────────┬────────────────────────────────────┘
                 │
                 ▼
         ┌───────────────┐
         │  API Requests │
         └────────┬──────┘
                  │
         ┌────────▼─────────┐
         │  EXPRESS BACKEND  │
         ├───────────────────┤
         │ Controllers       │
         │ Routes            │
         │ Middleware        │
         └────────┬──────────┘
                  │
         ┌────────▼────────────────────┐
         │  DATA STRUCTURES            │
         ├────────────────────────────┤
         │ Stack: Absensi History      │ ← 10 record terbaru
         │ Linked List: Siswa Data     │ ← Data siswa dinamis
         └────────┬────────────────────┘
                  │
         ┌────────▼──────────────┐
         │ FILE DATABASE (JSON)  │
         ├──────────────────────┤
         │ users.json           │
         │ absensi.json         │
         └──────────────────────┘
```

### API Endpoint yang Menggunakan Stack
```
GET /api/absensi/history  ← Mengambil dari STACK
```

### API Endpoint yang Menggunakan Linked List
```
GET /api/user/all         ← Mengambil dari LINKED LIST
GET /api/user/search      ← Traverse LINKED LIST
POST /api/user/add        ← Append ke LINKED LIST
DELETE /api/user/:id      ← Remove dari LINKED LIST
```

---

## 5. 💡 Keunggulan Implementasi Ini

1. **Educational Value**: Pembelajaran langsung tentang data structures
2. **Practical Use**: Real-world implementation dalam aplikasi actual
3. **Performance**: Optimized untuk kasus penggunaan spesifik
4. **Scalability**: Mudah dikembangkan ke database real (MongoDB, MySQL)
5. **Maintainability**: Code yang clean dan well-documented

---

## 6. 🚀 Pengembangan Lebih Lanjut

### Improvement Suggestions
1. **Hash Table** untuk pencarian O(1) siswa berdasarkan ID
2. **Queue** untuk antrian approval absensi
3. **Graph** untuk relasi antar siswa/kelas
4. **Binary Search Tree** untuk sorting data absensi

### Migration ke Database Real
```javascript
// Current: File-based (JSON)
users.json
absensi.json

// Future: Database Real
MongoDB / MySQL / PostgreSQL
→ Tetap bisa menggunakan Stack & Linked List untuk in-memory operations
```

---

**Documentation Version:** 1.0  
**Last Updated:** January 6, 2026  
**By:** Development Team
