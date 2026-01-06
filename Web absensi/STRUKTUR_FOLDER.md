# 📁 STRUKTUR FOLDER - WEB ABSENSI

## Organisasi Folder yang Rapi

```
Web absensi/
│
├── 📁 backend/                    ← SERVER API (Node.js + Express)
│   ├── src/
│   │   ├── controllers/           ← Logic bisnis (auth, absensi, user)
│   │   ├── routes/                ← Routing API endpoints
│   │   ├── middleware/            ← JWT verification
│   │   ├── dataStructures/        ← Stack & Linked List
│   │   ├── database/              ← Database functions
│   │   ├── data/                  ← Database files (users.json, absensi.json)
│   │   └── server.js              ← Main server file
│   ├── package.json
│   └── .env
│
├── 📁 SD-TUGAS/form-login/        ← FRONTEND APP (React)
│   ├── src/
│   │   ├── services/              ← API client (api.js)
│   │   ├── pages/                 ← Pages (LoginPage, RegisterPage, etc)
│   │   ├── components/            ← Reusable components
│   │   ├── App.js                 ← Main app component
│   │   └── index.js               ← Entry point
│   ├── public/
│   ├── package.json
│   └── .env
│
├── 📁 docs/                       ← DOKUMENTASI LENGKAP
│   ├── README.md                  ← Start here
│   ├── API_PANDUAN.md             ← Cara pakai API
│   ├── TESTING.md                 ← Testing guide
│   └── ... (file dokumentasi lain)
│
├── 📄 package.json                ← Root config (optional)
├── 📄 README.md                   ← Project overview
└── 📄 .gitignore
```

---

## 📝 Penjelasan Folder

### `backend/` - Server API
**Apa**: Node.js server dengan Express.js
**Port**: 5000
**Tugas**: 
- Mengelola registrasi & login (JWT)
- Mengelola absensi (Stack data structure)
- Mengelola data siswa (Linked List)
- Menyimpan data ke JSON files

**File Penting**:
- `src/server.js` - Mulai dari sini
- `src/controllers/` - Login, absensi, user logic
- `src/routes/` - API endpoints

---

### `SD-TUGAS/form-login/` - Frontend React App
**Apa**: React aplikasi untuk user interface
**Port**: 3000
**Tugas**:
- Tampilkan login & register page
- Komunikasi dengan backend API
- Simpan token di localStorage
- Tampilkan dashboard & absensi

**File Penting**:
- `src/services/api.js` - API client
- `src/pages/LoginPage/` - Login form
- `src/pages/RegisterPage/` - Register form

---

### `docs/` - Dokumentasi
**Apa**: File dokumentasi lengkap
**Isi**:
- Panduan setup
- API examples
- Testing guide
- Architecture overview

---

## 🚀 Cara Menjalankan

### 1. Start Backend
```bash
cd backend
npm install
npm run dev
```
✅ Akan running di `http://localhost:5000`

### 2. Start Frontend
```bash
cd SD-TUGAS/form-login
npm install
npm start
```
✅ Akan running di `http://localhost:3000`

### 3. Buka Browser
```
http://localhost:3000
```

---

## 📚 File Dokumentasi Penting

| File | Apa | Untuk Siapa |
|------|-----|-----------|
| `docs/README.md` | Overview project | Semua orang |
| `docs/API_PANDUAN.md` | Cara pakai 19 API | Developer |
| `docs/TESTING.md` | Testing guide | QA / Tester |
| `docs/SETUP.md` | Setup awal | Semua orang |

---

## ✅ Checklist

- [x] Backend folder rapi
- [x] Frontend folder rapi
- [x] Dokumentasi di folder `docs`
- [x] Struktur mudah dipahami
- [x] Nama folder descriptive

---

**Total**: 
- 1 Backend Server
- 1 Frontend App
- 19 API Endpoints
- 2 Data Structures (Stack, Linked List)
- Dokumentasi Lengkap

Semuanya siap digunakan! 🎉
