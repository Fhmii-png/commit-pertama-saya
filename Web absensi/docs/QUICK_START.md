# 🚀 Quick Start Guide - Web Absensi Backend

## ⚡ 5 Menit Setup

### 1️⃣ Install Dependencies (1 menit)
```bash
cd backend
npm install
```

### 2️⃣ Setup Environment (30 detik)
File `.env` sudah dibuat, pastikan isinya:
```env
PORT=5000
JWT_SECRET=your_secret_key_here_change_in_production
NODE_ENV=development
```

### 3️⃣ Jalankan Server (30 detik)
```bash
npm run dev
```

Tunggu sampai melihat:
```
╔═══════════════════════════════════════════════════════╗
║         WEB ABSENSI - BACKEND SERVER                  ║
║  Server berjalan di: http://localhost:5000           ║
╚═══════════════════════════════════════════════════════╝
```

### 4️⃣ Test Health Check (30 detik)
Buka browser dan kunjungi:
```
http://localhost:5000/api/health
```

**Expected Response:**
```json
{
  "success": true,
  "message": "Server is running",
  "timestamp": "2024-01-06T10:30:00.000Z"
}
```

### 5️⃣ Lihat Dokumentasi API (1 menit)
```
http://localhost:5000/api/docs
```

---

## 📱 Testing Dengan Tools

### Option A: Gunakan Postman
1. Download [Postman](https://www.postman.com/downloads/)
2. Import collection dari file: `API_EXAMPLES.md`
3. Test setiap endpoint

### Option B: Gunakan curl

#### Register Siswa Baru
```bash
curl -X POST http://localhost:5000/api/auth/register \
  -H "Content-Type: application/json" \
  -d '{
    "email": "siswa1@school.com",
    "password": "password123",
    "name": "Siswa 1"
  }'
```

**Response:**
```json
{
  "success": true,
  "message": "Register berhasil",
  "user": {
    "id": "1704562800000",
    "email": "siswa1@school.com",
    "name": "Siswa 1",
    "role": "siswa"
  }
}
```

#### Login
```bash
curl -X POST http://localhost:5000/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{
    "email": "siswa1@school.com",
    "password": "password123"
  }'
```

**Response:**
```json
{
  "success": true,
  "message": "Login berhasil",
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
  "user": {
    "id": "1704562800000",
    "email": "siswa1@school.com",
    "name": "Siswa 1",
    "role": "siswa"
  }
}
```

**SAVE TOKEN INI!** Gunakan di endpoint yang protected.

#### Submit Absensi
```bash
curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer YOUR_TOKEN_HERE" \
  -d '{
    "date": "2024-01-10",
    "status": "Hadir",
    "keterangan": "Masuk tepat waktu"
  }'
```

#### Get Absensi History (Stack)
```bash
curl -X GET http://localhost:5000/api/absensi/history \
  -H "Authorization: Bearer YOUR_TOKEN_HERE"
```

---

## 🔄 Frontend Integration (2 menit)

### 1. Copy API Service
Copy file `src/services/api.js` ke frontend Anda:
```
frontend/src/services/api.js
```

### 2. Import dan Gunakan di Component
```javascript
import { authAPI, absensiAPI, userAPI } from '../../services/api';

// Login
const handleLogin = async (email, password) => {
  try {
    const response = await authAPI.login(email, password);
    localStorage.setItem('token', response.token);
    console.log('Login berhasil!');
  } catch (error) {
    console.error('Login gagal:', error.message);
  }
};

// Submit Absensi
const handleSubmitAbsensi = async (date, status) => {
  try {
    const response = await absensiAPI.submit(date, status, 'Hadir tepat waktu');
    console.log('Absensi berhasil:', response.data);
  } catch (error) {
    console.error('Submit gagal:', error.message);
  }
};

// Get My Absensi
const handleGetMyAbsensi = async () => {
  try {
    const response = await absensiAPI.getMyAbsensi();
    console.log('Absensi saya:', response.data);
  } catch (error) {
    console.error('Gagal load absensi:', error.message);
  }
};
```

---

## 📊 Testing Lengkap (5 menit)

### Langkah-langkah Testing

#### Step 1: Register 2 Siswa
```bash
# Siswa 1
curl -X POST http://localhost:5000/api/auth/register \
  -H "Content-Type: application/json" \
  -d '{"email":"siswa1@school.com","password":"pass123","name":"Siswa 1"}'

# Siswa 2
curl -X POST http://localhost:5000/api/auth/register \
  -H "Content-Type: application/json" \
  -d '{"email":"siswa2@school.com","password":"pass123","name":"Siswa 2"}'
```

#### Step 2: Login Siswa 1 & Dapatkan Token
```bash
curl -X POST http://localhost:5000/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{"email":"siswa1@school.com","password":"pass123"}'
```

**Simpan token dari response!**

#### Step 3: Submit 5 Absensi dengan Token
```bash
# Ganti SISWA1_TOKEN dengan token dari login

curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer SISWA1_TOKEN" \
  -d '{"date":"2024-01-10","status":"Hadir"}'

curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer SISWA1_TOKEN" \
  -d '{"date":"2024-01-11","status":"Sakit","keterangan":"Demam"}'

curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer SISWA1_TOKEN" \
  -d '{"date":"2024-01-12","status":"Hadir"}'

curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer SISWA1_TOKEN" \
  -d '{"date":"2024-01-13","status":"Izin","keterangan":"Ada acara"}'

curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer SISWA1_TOKEN" \
  -d '{"date":"2024-01-14","status":"Hadir"}'
```

#### Step 4: Lihat History (Stack - 10 Terbaru)
```bash
curl -X GET http://localhost:5000/api/absensi/history \
  -H "Authorization: Bearer SISWA1_TOKEN"
```

**Expected:** Array dengan 5 record yang baru saja diinput.

#### Step 5: Lihat Statistik
```bash
curl -X GET http://localhost:5000/api/absensi/statistik \
  -H "Authorization: Bearer SISWA1_TOKEN"
```

**Expected:**
```json
{
  "success": true,
  "message": "Statistik absensi",
  "data": {
    "hadir": 3,
    "sakit": 1,
    "izin": 1,
    "alpa": 0,
    "total": 5
  }
}
```

#### Step 6: Lihat Rekap Bulanan
```bash
curl -X GET "http://localhost:5000/api/absensi/by-month-year?month=1&year=2024" \
  -H "Authorization: Bearer SISWA1_TOKEN"
```

#### Step 7: Lihat Data Siswa (Linked List)
```bash
curl -X GET http://localhost:5000/api/user/all \
  -H "Authorization: Bearer SISWA1_TOKEN"
```

**Note:** Siswa biasa tidak bisa lihat data siswa, hanya admin.

---

## 🐛 Troubleshooting

### Error: "Port already in use"
```bash
# Cari process yang menggunakan port 5000
lsof -i :5000

# Kill process (jika di Mac/Linux)
kill -9 <PID>

# Di Windows, gunakan Task Manager atau:
netstat -ano | findstr :5000
taskkill /PID <PID> /F
```

### Error: "Cannot find module"
```bash
# Pastikan di folder backend
cd backend

# Install ulang
npm install
```

### Error: "CORS error"
Pastikan CORS sudah diaktifkan di server.js:
```javascript
const cors = require('cors');
app.use(cors());  // Ini sudah ada
```

### Token tidak valid
- Pastikan token di copy dengan benar
- Pastikan format header: `Authorization: Bearer TOKEN`
- Token expire setelah 24 jam

---

## 📁 Struktur File Backend

```
backend/
├── src/
│   ├── controllers/
│   │   ├── authController.js      ✅ Login/Register
│   │   ├── absensiController.js   ✅ Absensi logic (Stack)
│   │   └── userController.js      ✅ User/Siswa (Linked List)
│   │
│   ├── dataStructures/
│   │   ├── Stack.js               ✅ Struktur Stack
│   │   └── LinkedList.js          ✅ Struktur Linked List
│   │
│   ├── routes/
│   │   ├── authRoutes.js          ✅ /api/auth/*
│   │   ├── absensiRoutes.js       ✅ /api/absensi/*
│   │   └── userRoutes.js          ✅ /api/user/*
│   │
│   ├── middleware/
│   │   └── auth.js                ✅ JWT verification
│   │
│   ├── database/
│   │   └── db.js                  ✅ JSON file operations
│   │
│   ├── data/
│   │   ├── users.json             ✅ Data pengguna
│   │   └── absensi.json           ✅ Data absensi
│   │
│   ├── services/
│   │   └── api.js                 ✅ Frontend API client
│   │
│   └── server.js                  ✅ Entry point
│
├── .env                           ✅ Environment variables
├── package.json                   ✅ Dependencies
├── README.md                      ✅ Full documentation
├── FRONTEND_INTEGRATION.md        ✅ Integration guide
├── DATA_STRUCTURES_DOCUMENTATION.md ✅ Stack & Linked List
├── API_EXAMPLES.md                ✅ API examples & curl
└── QUICK_START.md                 ✅ This file!
```

---

## ✅ Checklist

- [ ] Backend sudah install dependencies (`npm install`)
- [ ] Server berjalan (`npm run dev`)
- [ ] Health check berhasil (http://localhost:5000/api/health)
- [ ] Bisa register user baru
- [ ] Bisa login dan dapat token
- [ ] Bisa submit absensi
- [ ] Bisa lihat history (Stack)
- [ ] Bisa lihat statistik
- [ ] Bisa lihat data siswa (Linked List)

---

## 🎯 Next Steps

1. **Connect Frontend**: Update components untuk pakai API
2. **Add More Features**: 
   - Foto profil siswa
   - Export report PDF
   - Dashboard analytics
3. **Move to Real Database**:
   - PostgreSQL / MySQL
   - MongoDB
4. **Deploy**:
   - Heroku / Railway
   - AWS / DigitalOcean

---

## 📞 Support

Jika ada masalah:
1. Check error message di console
2. Lihat file: `API_EXAMPLES.md`
3. Lihat file: `README.md`
4. Check: `DATA_STRUCTURES_DOCUMENTATION.md`

---

**Happy Coding! 🚀**

Dibuat: January 6, 2026
