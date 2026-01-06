# Web Absensi - Backend Server

Backend server untuk aplikasi Web Absensi yang dibangun dengan **Node.js + Express.js** dan mengimplementasikan struktur data **Stack** dan **Linked List**.

## 📊 Struktur Data yang Digunakan

### 1. **Stack (LIFO - Last In First Out)**
**Lokasi:** `src/dataStructures/Stack.js`

**Kegunaan:** Menyimpan history/riwayat absensi terbaru (max 10 record)
- Ketika absensi baru ditambahkan, otomatis masuk ke stack
- Record terlama otomatis keluar ketika stack penuh
- Berguna untuk tracking perubahan status absensi terkini
- Efisien untuk akses data terbaru dengan cepat

**Operasi:**
- `push(element)` - Menambahkan absensi baru
- `pop()` - Menghapus record tertua
- `peek()` - Melihat record terbaru
- `getAll()` - Mengambil seluruh history

### 2. **Linked List (Sequential Data Structure)**
**Lokasi:** `src/dataStructures/LinkedList.js`

**Kegunaan:** Menyimpan data siswa/murid dengan operasi insert, delete, dan search yang fleksibel
- Setiap node berisi data siswa + pointer ke node berikutnya
- Memudahkan penambahan/penghapusan siswa tanpa reallocation
- Efisien untuk pencarian berdasarkan properti tertentu

**Operasi:**
- `append(data)` - Menambah siswa di akhir
- `prepend(data)` - Menambah siswa di awal
- `findBy(property, value)` - Mencari siswa berdasarkan properti
- `toArray()` - Konversi ke array untuk response API
- `remove(data)` - Menghapus siswa dari list

## 🗂️ Struktur Folder

```
backend/
├── src/
│   ├── controllers/
│   │   ├── authController.js      # Login, Register, Auth
│   │   ├── absensiController.js   # Submit & manage absensi
│   │   └── userController.js      # Manage data siswa
│   ├── dataStructures/
│   │   ├── Stack.js               # Struktur Stack
│   │   └── LinkedList.js          # Struktur Linked List
│   ├── database/
│   │   └── db.js                  # File-based database operations
│   ├── middleware/
│   │   └── auth.js                # JWT verification middleware
│   ├── routes/
│   │   ├── authRoutes.js          # Auth endpoints
│   │   ├── absensiRoutes.js       # Absensi endpoints
│   │   └── userRoutes.js          # User endpoints
│   ├── data/                       # Folder untuk file database
│   │   ├── users.json
│   │   └── absensi.json
│   └── server.js                   # Entry point
├── .env                            # Environment variables
├── package.json
└── README.md                       # Documentation
```

## 🚀 Instalasi & Menjalankan

### 1. Install Dependencies
```bash
cd backend
npm install
```

### 2. Konfigurasi Environment
Edit file `.env`:
```env
PORT=5000
JWT_SECRET=your_secret_key_here_change_in_production
NODE_ENV=development
```

### 3. Jalankan Server
```bash
# Development mode (dengan auto-reload)
npm run dev

# Production mode
npm start
```

Server akan berjalan di `http://localhost:5000`

## 📡 API Endpoints

### Autentikasi
```
POST   /api/auth/register           # Register user baru
POST   /api/auth/login              # Login & dapatkan JWT token
GET    /api/auth/profile            # Dapatkan profil user (protected)
PUT    /api/auth/update-password    # Update password (protected)
```

### Absensi
```
POST   /api/absensi/submit          # Submit absensi baru
GET    /api/absensi/my-absensi      # Dapatkan absensi user
GET    /api/absensi/history         # Dapatkan history (dari Stack)
GET    /api/absensi/statistik       # Dapatkan statistik absensi
GET    /api/absensi/by-date         # Absensi berdasarkan tanggal
GET    /api/absensi/by-month-year   # Rekap absensi bulanan
GET    /api/absensi/all             # Semua absensi (admin)
PUT    /api/absensi/:id             # Update absensi (admin)
DELETE /api/absensi/:id             # Hapus absensi (admin)
```

### User/Siswa
```
GET    /api/user/all                # Semua siswa dari Linked List (admin)
GET    /api/user/search             # Cari siswa berdasarkan nama
GET    /api/user/:id                # Dapatkan data siswa
POST   /api/user/add                # Tambah siswa baru (admin)
PUT    /api/user/:id                # Update data siswa
DELETE /api/user/:id                # Hapus siswa (admin)
```

## 📝 Contoh Request/Response

### Register
```bash
POST /api/auth/register
Content-Type: application/json

{
  "email": "siswa@school.com",
  "password": "password123",
  "name": "Nama Siswa"
}
```

**Response:**
```json
{
  "success": true,
  "message": "Register berhasil",
  "user": {
    "id": "1704562800000",
    "email": "siswa@school.com",
    "name": "Nama Siswa",
    "role": "siswa"
  }
}
```

### Login
```bash
POST /api/auth/login
Content-Type: application/json

{
  "email": "siswa@school.com",
  "password": "password123"
}
```

**Response:**
```json
{
  "success": true,
  "message": "Login berhasil",
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
  "user": {
    "id": "1704562800000",
    "email": "siswa@school.com",
    "name": "Nama Siswa",
    "role": "siswa"
  }
}
```

### Submit Absensi
```bash
POST /api/absensi/submit
Authorization: Bearer <token>
Content-Type: application/json

{
  "date": "2024-01-10",
  "status": "Hadir",
  "keterangan": "Masuk tepat waktu"
}
```

**Response:**
```json
{
  "success": true,
  "message": "Absensi berhasil disimpan",
  "data": {
    "id": "1704578900000",
    "userId": "1704562800000",
    "date": "2024-01-10",
    "status": "Hadir",
    "keterangan": "Masuk tepat waktu",
    "timestamp": "2024-01-10T10:30:00.000Z"
  }
}
```

### Get Absensi History (Stack)
```bash
GET /api/absensi/history
Authorization: Bearer <token>
```

**Response:**
```json
{
  "success": true,
  "message": "History absensi (10 terbaru)",
  "data": [
    {
      "id": "1704578900000",
      "userId": "1704562800000",
      "date": "2024-01-10",
      "status": "Hadir",
      "timestamp": "2024-01-10T10:30:00.000Z"
    }
  ],
  "totalHistory": 1
}
```

### Get All Siswa (Linked List)
```bash
GET /api/user/all
Authorization: Bearer <admin_token>
```

**Response:**
```json
{
  "success": true,
  "message": "Data semua siswa (dari Linked List)",
  "data": [
    {
      "id": "1704562800000",
      "name": "Nama Siswa",
      "email": "siswa@school.com",
      "role": "siswa",
      "createdAt": "2024-01-06T10:00:00.000Z"
    }
  ],
  "total": 1
}
```

## 🔐 Autentikasi

Semua endpoint protected menggunakan JWT Token. Cara penggunaan:

1. Login untuk mendapatkan token
2. Tambahkan header `Authorization: Bearer <token>` di setiap request protected

## 📊 Data Validation

### Status Absensi Valid
- `Hadir` - Siswa hadir
- `Sakit` - Siswa sakit
- `Izin` - Siswa izin
- `Alpa` - Siswa tidak ada keterangan

### User Roles
- `admin` - Administrator
- `siswa` - Siswa/User biasa

## 🗄️ Database Storage

Database menggunakan file JSON:
- `src/data/users.json` - Menyimpan data user
- `src/data/absensi.json` - Menyimpan data absensi

## 📌 Catatan Penting

1. **Stack untuk History:** Otomatis limit 10 record terbaru
2. **Linked List untuk Siswa:** Diinisialisasi saat server start
3. **JWT Secret:** Ubah di file `.env` untuk production
4. **Database:** Menggunakan file JSON (bisa diganti ke database nyata nanti)

## 🔗 Integrasi dengan Frontend

Update file frontend Anda untuk menggunakan API ini. Contoh dengan fetch:

```javascript
// Login
const login = async (email, password) => {
  const response = await fetch('http://localhost:5000/api/auth/login', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ email, password })
  });
  const data = await response.json();
  localStorage.setItem('token', data.token);
  return data;
};

// Submit Absensi
const submitAbsensi = async (date, status) => {
  const token = localStorage.getItem('token');
  const response = await fetch('http://localhost:5000/api/absensi/submit', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Authorization': `Bearer ${token}`
    },
    body: JSON.stringify({ date, status })
  });
  return await response.json();
};
```

## 💡 Tips Pengembangan

- Update `.env` dan ganti `JWT_SECRET` dengan nilai yang aman
- Untuk production, gunakan database nyata (MySQL, MongoDB, dll)
- Implementasi rate limiting untuk keamanan
- Tambahkan logging yang lebih detail
- Setup HTTPS/SSL untuk production

---

**Version:** 1.0.0  
**Last Updated:** January 6, 2026
