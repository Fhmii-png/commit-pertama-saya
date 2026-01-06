/**
 * TEST FILE - API TESTING
 * Gunakan Postman atau curl untuk test endpoints
 */

// ==========================================
// AUTHENTICATION ENDPOINTS
// ==========================================

// 1. REGISTER - POST /api/auth/register
// Request:
{
  "email": "siswa1@school.com",
  "password": "password123",
  "name": "Siswa 1"
}

// Response:
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

// ==========================================

// 2. LOGIN - POST /api/auth/login
// Request:
{
  "email": "siswa1@school.com",
  "password": "password123"
}

// Response:
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

// ==========================================

// 3. GET PROFILE - GET /api/auth/profile
// Headers: Authorization: Bearer <token>
// No request body needed

// Response:
{
  "success": true,
  "user": {
    "id": "1704562800000",
    "email": "siswa1@school.com",
    "name": "Siswa 1",
    "role": "siswa",
    "createdAt": "2024-01-06T10:00:00.000Z"
  }
}

// ==========================================

// 4. UPDATE PASSWORD - PUT /api/auth/update-password
// Headers: Authorization: Bearer <token>
// Request:
{
  "oldPassword": "password123",
  "newPassword": "newpassword456"
}

// Response:
{
  "success": true,
  "message": "Password berhasil diubah",
  "user": {
    "id": "1704562800000",
    "email": "siswa1@school.com",
    "name": "Siswa 1"
  }
}

// ==========================================
// ABSENSI ENDPOINTS
// ==========================================

// 5. SUBMIT ABSENSI - POST /api/absensi/submit
// Headers: Authorization: Bearer <token>
// Request:
{
  "date": "2024-01-10",
  "status": "Hadir",
  "keterangan": "Masuk tepat waktu"
}

// Response:
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

// ==========================================

// 6. GET MY ABSENSI - GET /api/absensi/my-absensi
// Headers: Authorization: Bearer <token>
// No request body needed

// Response:
{
  "success": true,
  "message": "Absensi user berhasil diambil",
  "data": [
    {
      "id": "1704578900000",
      "userId": "1704562800000",
      "date": "2024-01-10",
      "status": "Hadir",
      "keterangan": "Masuk tepat waktu",
      "timestamp": "2024-01-10T10:30:00.000Z"
    }
  ],
  "total": 1
}

// ==========================================

// 7. GET ABSENSI HISTORY (STACK) - GET /api/absensi/history
// Headers: Authorization: Bearer <token>
// Max 10 record terbaru - Menggunakan STACK

// Response:
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

// ==========================================

// 8. GET STATISTIK ABSENSI - GET /api/absensi/statistik
// Headers: Authorization: Bearer <token>

// Response:
{
  "success": true,
  "message": "Statistik absensi",
  "data": {
    "hadir": 8,
    "sakit": 1,
    "izin": 0,
    "alpa": 1,
    "total": 10
  }
}

// ==========================================

// 9. GET ABSENSI BY DATE - GET /api/absensi/by-date?date=2024-01-10
// Headers: Authorization: Bearer <token>

// Response:
{
  "success": true,
  "message": "Absensi tanggal 2024-01-10",
  "data": [
    {
      "id": "1704578900000",
      "userId": "1704562800000",
      "date": "2024-01-10",
      "status": "Hadir",
      "timestamp": "2024-01-10T10:30:00.000Z"
    }
  ],
  "total": 1
}

// ==========================================

// 10. GET ABSENSI BY MONTH/YEAR (REKAP) - GET /api/absensi/by-month-year?month=1&year=2024
// Headers: Authorization: Bearer <token>
// For report/recap functionality

// Response:
{
  "success": true,
  "message": "Rekap absensi 1/2024",
  "data": [
    {
      "id": "1704578900000",
      "userId": "1704562800000",
      "date": "2024-01-10",
      "status": "Hadir",
      "timestamp": "2024-01-10T10:30:00.000Z"
    }
  ],
  "total": 1
}

// ==========================================

// 11. GET ALL ABSENSI (ADMIN) - GET /api/absensi/all
// Headers: Authorization: Bearer <admin_token>
// Only admin can access

// Response:
{
  "success": true,
  "message": "Semua data absensi",
  "data": [
    {
      "id": "1704578900000",
      "userId": "1704562800000",
      "date": "2024-01-10",
      "status": "Hadir",
      "timestamp": "2024-01-10T10:30:00.000Z"
    }
  ],
  "total": 1
}

// ==========================================

// 12. UPDATE ABSENSI (ADMIN) - PUT /api/absensi/:id
// Headers: Authorization: Bearer <admin_token>
// Request:
{
  "status": "Sakit",
  "keterangan": "Sakit demam"
}

// Response:
{
  "success": true,
  "message": "Absensi berhasil diupdate",
  "data": {
    "id": "1704578900000",
    "userId": "1704562800000",
    "date": "2024-01-10",
    "status": "Sakit",
    "keterangan": "Sakit demam",
    "timestamp": "2024-01-10T10:30:00.000Z"
  }
}

// ==========================================

// 13. DELETE ABSENSI (ADMIN) - DELETE /api/absensi/:id
// Headers: Authorization: Bearer <admin_token>

// Response:
{
  "success": true,
  "message": "Absensi berhasil dihapus",
  "data": {
    "id": "1704578900000",
    "userId": "1704562800000",
    "date": "2024-01-10",
    "status": "Sakit",
    "timestamp": "2024-01-10T10:30:00.000Z"
  }
}

// ==========================================
// USER/SISWA ENDPOINTS (LINKED LIST)
// ==========================================

// 14. GET ALL SISWA (ADMIN) - GET /api/user/all
// Headers: Authorization: Bearer <admin_token>
// Data dari LINKED LIST

// Response:
{
  "success": true,
  "message": "Data semua siswa (dari Linked List)",
  "data": [
    {
      "id": "1704562800000",
      "name": "Siswa 1",
      "email": "siswa1@school.com",
      "role": "siswa",
      "createdAt": "2024-01-06T10:00:00.000Z"
    }
  ],
  "total": 1
}

// ==========================================

// 15. GET SISWA BY ID - GET /api/user/:id
// Headers: Authorization: Bearer <token>

// Response:
{
  "success": true,
  "message": "Data siswa berhasil diambil",
  "data": {
    "id": "1704562800000",
    "name": "Siswa 1",
    "email": "siswa1@school.com",
    "role": "siswa",
    "createdAt": "2024-01-06T10:00:00.000Z"
  }
}

// ==========================================

// 16. SEARCH SISWA - GET /api/user/search?keyword=siswa
// Headers: Authorization: Bearer <token>

// Response:
{
  "success": true,
  "message": "Hasil pencarian untuk \"siswa\"",
  "data": [
    {
      "id": "1704562800000",
      "name": "Siswa 1",
      "email": "siswa1@school.com",
      "role": "siswa"
    }
  ],
  "total": 1
}

// ==========================================

// 17. ADD SISWA (ADMIN) - POST /api/user/add
// Headers: Authorization: Bearer <admin_token>
// Request:
{
  "email": "siswa2@school.com",
  "password": "password123",
  "name": "Siswa 2"
}

// Response:
{
  "success": true,
  "message": "Siswa berhasil ditambahkan",
  "data": {
    "id": "1704578900000",
    "name": "Siswa 2",
    "email": "siswa2@school.com",
    "role": "siswa"
  }
}

// ==========================================

// 18. UPDATE SISWA - PUT /api/user/:id
// Headers: Authorization: Bearer <token>
// Request:
{
  "name": "Siswa 1 Updated",
  "email": "siswa1_updated@school.com"
}

// Response:
{
  "success": true,
  "message": "Siswa berhasil diupdate",
  "data": {
    "id": "1704562800000",
    "name": "Siswa 1 Updated",
    "email": "siswa1_updated@school.com",
    "role": "siswa"
  }
}

// ==========================================

// 19. DELETE SISWA (ADMIN) - DELETE /api/user/:id
// Headers: Authorization: Bearer <admin_token>

// Response:
{
  "success": true,
  "message": "Siswa berhasil dihapus",
  "data": {
    "id": "1704562800000",
    "name": "Siswa 1",
    "email": "siswa1@school.com"
  }
}

// ==========================================
// TESTING DENGAN CURL
// ==========================================

// 1. Register
// curl -X POST http://localhost:5000/api/auth/register \
//   -H "Content-Type: application/json" \
//   -d '{"email":"siswa1@school.com","password":"password123","name":"Siswa 1"}'

// 2. Login
// curl -X POST http://localhost:5000/api/auth/login \
//   -H "Content-Type: application/json" \
//   -d '{"email":"siswa1@school.com","password":"password123"}'

// 3. Submit Absensi
// curl -X POST http://localhost:5000/api/absensi/submit \
//   -H "Content-Type: application/json" \
//   -H "Authorization: Bearer YOUR_TOKEN_HERE" \
//   -d '{"date":"2024-01-10","status":"Hadir","keterangan":"Masuk"}'

// 4. Get My Absensi
// curl -X GET http://localhost:5000/api/absensi/my-absensi \
//   -H "Authorization: Bearer YOUR_TOKEN_HERE"

// 5. Get All Siswa (Admin)
// curl -X GET http://localhost:5000/api/user/all \
//   -H "Authorization: Bearer ADMIN_TOKEN_HERE"
