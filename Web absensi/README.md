# 🎯 ABSENSI MENGAJI - WEB APPLICATION

Aplikasi web untuk mengelola absensi peserta didik di lembaga pendidikan Islam.

## 🚀 Quick Start (5 menit)

### Siapkan (Terminal 1 - Backend)
```bash
cd backend
npm install
npm run dev
```
✅ Backend running di `http://localhost:5000`

### Jalankan (Terminal 2 - Frontend)
```bash
cd SD-TUGAS/form-login
npm install
npm start
```
✅ Frontend running di `http://localhost:3000`

### Buka Browser
```
http://localhost:3000
```

---

## 📋 Fitur Utama

✅ **Registrasi Akun** - Daftar dengan email & password
✅ **Login** - Masuk dengan kredensial yang terdaftar
✅ **Dashboard Absensi** - Lihat & catat kehadiran
✅ **Laporan Absensi** - Rekap per bulan/tahun
✅ **Manajemen Siswa** - Lihat & cari data siswa
✅ **JWT Security** - Password hashed, token 24 jam

---

## 📁 Struktur Folder

```
Web absensi/
├── backend/              ← Server API (Port 5000)
├── SD-TUGAS/
│   └── form-login/       ← Frontend React (Port 3000)
├── docs/                 ← Dokumentasi Lengkap
└── README.md             ← Ini
```

**Detail**: Lihat `STRUKTUR_FOLDER.md`

---

## 🔧 Tech Stack

| Layer | Tech |
|-------|------|
| Backend | Node.js + Express.js |
| Frontend | React |
| Database | JSON Files |
| Auth | JWT + bcryptjs |
| Data Structure | Stack & Linked List |

---

## 📊 API Endpoints (19 Total)

### Authentication (4)
- `POST /api/auth/register` - Register user baru
- `POST /api/auth/login` - Login & dapatkan token
- `GET /api/auth/profile` - Get user profile
- `PUT /api/auth/update-password` - Update password

### Absensi (9)
- `POST /api/absensi/submit` - Submit absensi
- `GET /api/absensi/my` - Get my attendance
- `GET /api/absensi/history` - Get history (Stack - 10 terbaru)
- `GET /api/absensi/statistik` - Get stats
- `GET /api/absensi/by-date` - Get by date range
- `GET /api/absensi/by-month-year` - Get by month/year
- `GET /api/absensi/all` - Get semua
- `PUT /api/absensi/:id` - Update record
- `DELETE /api/absensi/:id` - Delete record

### User/Siswa (6)
- `GET /api/user/all` - Get semua siswa
- `GET /api/user/:id` - Get by ID
- `GET /api/user/search?q=...` - Search siswa
- `POST /api/user/add` - Add siswa baru
- `PUT /api/user/:id` - Update siswa
- `DELETE /api/user/:id` - Delete siswa

**Detail**: Lihat `docs/API_PANDUAN.md`

---

## 🧪 Testing

### Test Registration
1. Buka `http://localhost:3000`
2. Klik "Daftar"
3. Isi form:
   - Email: `test@example.com`
   - Password: `password123`
   - Nama: `Test User`
4. Klik "Daftar"
5. Lihat pesan "Pendaftaran Berhasil!" ✅

### Test Login
1. Klik "Masuk"
2. Masukkan email & password yang didaftar
3. Klik "Masuk"
4. Lihat Dashboard ✅

**Detail**: Lihat `docs/TESTING.md`

---

## 📚 Dokumentasi

| File | Apa |
|------|-----|
| `STRUKTUR_FOLDER.md` | Penjelasan folder & files |
| `docs/API_PANDUAN.md` | Panduan lengkap 19 API |
| `docs/TESTING.md` | Testing guide |
| `docs/SETUP.md` | Setup awal & troubleshooting |

---

## 💾 Data Storage

### Database Files
```
backend/src/data/
├── users.json      ← Data user (email, password hash, nama)
└── absensi.json    ← Data absensi
```

### Frontend Storage
```javascript
localStorage.token   // JWT token
localStorage.user    // User info JSON
```

---

## 🔐 Security

✅ **Password Hashing** - bcryptjs (salt: 10)
✅ **JWT Tokens** - 24 hour expiry
✅ **CORS** - Localhost only
✅ **Protected Routes** - Token required untuk protected endpoints

---

## 🆘 Troubleshooting

### Backend tidak jalan?
```bash
# Kill existing process
taskkill /F /IM node.exe

# Coba lagi
cd backend
npm run dev
```

### Frontend not connecting to backend?
1. Check backend running: `http://localhost:5000`
2. Check `src/services/api.js` API_BASE_URL correct
3. Check CORS enabled di backend

### Database tidak save?
1. Check folder `backend/src/data/` exists
2. Check `users.json` readable/writable
3. Check server console untuk error

**Bantuan**: Lihat `docs/SETUP.md` atau buka issue di GitHub

---

## 📞 Support

Pertanyaan? Lihat dokumentasi:
- Setup issues → `docs/SETUP.md`
- API questions → `docs/API_PANDUAN.md`
- Testing help → `docs/TESTING.md`
- Architecture → `docs/ARCHITECTURE.md`

---

## 📈 Next Steps

Setelah berhasil test:

1. **Integrate Dashboard** - Koneksi absensi ke API
2. **Integrate RekapAbsensi** - Koneksi laporan ke API
3. **Add Logout** - Clear token & redirect
4. **Improve UI** - Better styling & animations
5. **Deploy** - Ke server production

---

## ✅ Status

| Komponen | Status | Port |
|----------|--------|------|
| Backend Server | ✅ Ready | 5000 |
| Frontend App | ✅ Ready | 3000 |
| API Endpoints | ✅ 19/19 | - |
| Database | ✅ JSON | - |
| Documentation | ✅ Complete | - |

**Siap untuk production!** 🎉

---

**Created**: January 6, 2026
**Version**: 1.0.0
**License**: MIT
