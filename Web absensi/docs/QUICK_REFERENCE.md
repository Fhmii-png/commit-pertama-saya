# 🔗 QUICK REFERENCE - Command & API Cheat Sheet

Akses cepat untuk commands dan API calls yang paling sering digunakan.

---

## 🚀 Server Commands

### Start Server
```bash
cd backend
npm run dev          # Development mode dengan auto-reload
npm start            # Production mode
```

### Stop Server
```bash
# Press Ctrl+C di terminal
```

### Check Server Status
```bash
curl http://localhost:5000/api/health
```

---

## 🔐 Authentication

### Register User
```bash
curl -X POST http://localhost:5000/api/auth/register \
  -H "Content-Type: application/json" \
  -d '{
    "email": "user@school.com",
    "password": "password123",
    "name": "User Name"
  }'
```

### Login & Get Token
```bash
curl -X POST http://localhost:5000/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{
    "email": "user@school.com",
    "password": "password123"
  }'
```

**Simpan token dari response!**

### Get Profile
```bash
curl http://localhost:5000/api/auth/profile \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### Update Password
```bash
curl -X PUT http://localhost:5000/api/auth/update-password \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer YOUR_TOKEN" \
  -d '{
    "oldPassword": "password123",
    "newPassword": "newpassword456"
  }'
```

---

## 📋 Absensi API

### Submit Absensi (USES STACK ⬇️)
```bash
curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer YOUR_TOKEN" \
  -d '{
    "date": "2024-01-10",
    "status": "Hadir",
    "keterangan": "Masuk tepat waktu"
  }'
```

**Valid Status:** Hadir, Sakit, Izin, Alpa

### Get My Absensi
```bash
curl http://localhost:5000/api/absensi/my-absensi \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### Get Absensi History (FROM STACK - 10 TERBARU)
```bash
curl http://localhost:5000/api/absensi/history \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### Get Absensi Statistics
```bash
curl http://localhost:5000/api/absensi/statistik \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### Get Absensi by Date
```bash
curl "http://localhost:5000/api/absensi/by-date?date=2024-01-10" \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### Get Absensi by Month/Year (Rekap)
```bash
curl "http://localhost:5000/api/absensi/by-month-year?month=1&year=2024" \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### Get All Absensi (ADMIN ONLY)
```bash
curl http://localhost:5000/api/absensi/all \
  -H "Authorization: Bearer ADMIN_TOKEN"
```

### Update Absensi (ADMIN ONLY)
```bash
curl -X PUT http://localhost:5000/api/absensi/ABSENSI_ID \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer ADMIN_TOKEN" \
  -d '{
    "status": "Sakit",
    "keterangan": "Sakit demam"
  }'
```

### Delete Absensi (ADMIN ONLY)
```bash
curl -X DELETE http://localhost:5000/api/absensi/ABSENSI_ID \
  -H "Authorization: Bearer ADMIN_TOKEN"
```

---

## 👥 User/Siswa API (USES LINKED LIST ⬇️)

### Get All Siswa (FROM LINKED LIST - ADMIN ONLY)
```bash
curl http://localhost:5000/api/user/all \
  -H "Authorization: Bearer ADMIN_TOKEN"
```

### Get Siswa by ID
```bash
curl http://localhost:5000/api/user/SISWA_ID \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### Search Siswa (TRAVERSE LINKED LIST)
```bash
curl "http://localhost:5000/api/user/search?keyword=nama" \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### Add Siswa (APPEND TO LINKED LIST - ADMIN ONLY)
```bash
curl -X POST http://localhost:5000/api/user/add \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer ADMIN_TOKEN" \
  -d '{
    "email": "siswa_baru@school.com",
    "password": "password123",
    "name": "Siswa Baru"
  }'
```

### Update Siswa
```bash
curl -X PUT http://localhost:5000/api/user/SISWA_ID \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer YOUR_TOKEN" \
  -d '{
    "name": "Nama Updated",
    "email": "email_baru@school.com"
  }'
```

### Delete Siswa (REMOVE FROM LINKED LIST - ADMIN ONLY)
```bash
curl -X DELETE http://localhost:5000/api/user/SISWA_ID \
  -H "Authorization: Bearer ADMIN_TOKEN"
```

---

## 📊 HTTP Status Codes

| Code | Meaning |
|------|---------|
| 200 | Success |
| 201 | Created |
| 400 | Bad Request (validation error) |
| 403 | Forbidden (not authorized) |
| 404 | Not Found |
| 500 | Server Error |

---

## 🔑 Header Format

### Authorization Header
```
Authorization: Bearer <TOKEN>
```

### Content-Type Header
```
Content-Type: application/json
```

### Full Example
```bash
curl -X GET http://localhost:5000/api/auth/profile \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
```

---

## 🔄 Common Workflows

### Workflow 1: Register → Login → Submit Absensi

```bash
# 1. Register
RESPONSE=$(curl -s -X POST http://localhost:5000/api/auth/register \
  -H "Content-Type: application/json" \
  -d '{"email":"test@school.com","password":"pass123","name":"Test"}')
echo $RESPONSE

# 2. Login & extract token
LOGIN=$(curl -s -X POST http://localhost:5000/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{"email":"test@school.com","password":"pass123"}')
TOKEN=$(echo $LOGIN | grep -o '"token":"[^"]*' | cut -d'"' -f4)
echo "Token: $TOKEN"

# 3. Submit Absensi
curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer $TOKEN" \
  -d '{"date":"2024-01-10","status":"Hadir"}'
```

### Workflow 2: Check History & Statistik

```bash
# Get history (from STACK - 10 terbaru)
curl http://localhost:5000/api/absensi/history \
  -H "Authorization: Bearer $TOKEN"

# Get statistik
curl http://localhost:5000/api/absensi/statistik \
  -H "Authorization: Bearer $TOKEN"
```

### Workflow 3: Admin - Manage Siswa (Linked List)

```bash
# Get all siswa
curl http://localhost:5000/api/user/all \
  -H "Authorization: Bearer $ADMIN_TOKEN"

# Add siswa
curl -X POST http://localhost:5000/api/user/add \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer $ADMIN_TOKEN" \
  -d '{"email":"baru@school.com","password":"pass","name":"Baru"}'

# Search siswa
curl "http://localhost:5000/api/user/search?keyword=baru" \
  -H "Authorization: Bearer $ADMIN_TOKEN"
```

---

## 🧪 Testing Checklist Commands

```bash
# 1. Health Check
curl http://localhost:5000/api/health

# 2. Register
curl -X POST http://localhost:5000/api/auth/register \
  -H "Content-Type: application/json" \
  -d '{"email":"test@school.com","password":"pass123","name":"Test"}'

# 3. Login
curl -X POST http://localhost:5000/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{"email":"test@school.com","password":"pass123"}'
  # Save TOKEN from response

# 4. Submit Absensi
curl -X POST http://localhost:5000/api/absensi/submit \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer TOKEN" \
  -d '{"date":"2024-01-10","status":"Hadir"}'

# 5. Get History (STACK)
curl http://localhost:5000/api/absensi/history \
  -H "Authorization: Bearer TOKEN"

# 6. Get Statistik
curl http://localhost:5000/api/absensi/statistik \
  -H "Authorization: Bearer TOKEN"

# 7. Get All Siswa (LINKED LIST)
curl http://localhost:5000/api/user/all \
  -H "Authorization: Bearer ADMIN_TOKEN"

# 8. Search Siswa
curl "http://localhost:5000/api/user/search?keyword=test" \
  -H "Authorization: Bearer TOKEN"
```

---

## 📝 Notes

### Token Format
```
Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjE2MTQzNDY4MjAwMDAiLCJyb2xlIjoic2lzd2EifQ.xxx
```

### Date Format
```
YYYY-MM-DD
2024-01-10
```

### Status Values
```
Hadir
Sakit
Izin
Alpa
```

### Role Values
```
siswa    (Student)
admin    (Administrator)
```

---

## 🔍 Error Handling

### Invalid Token
```json
{
  "success": false,
  "message": "Failed to authenticate token"
}
```

### Missing Required Field
```json
{
  "success": false,
  "message": "Email dan password diperlukan"
}
```

### Unauthorized Access
```json
{
  "success": false,
  "message": "Hanya admin yang dapat mengakses data ini"
}
```

### Not Found
```json
{
  "success": false,
  "message": "Siswa tidak ditemukan"
}
```

---

## 💻 Environment Variables

File: `.env`

```env
PORT=5000                                          # Server port
JWT_SECRET=your_secret_key_here_change_in_prod   # JWT secret
NODE_ENV=development                              # development/production
```

---

## 📚 Links

- Server: http://localhost:5000
- Health: http://localhost:5000/api/health
- Docs: http://localhost:5000/api/docs
- API Examples: [API_EXAMPLES.md](./API_EXAMPLES.md)
- Full Docs: [README.md](./README.md)
- Setup Guide: [QUICK_START.md](./QUICK_START.md)

---

## ⌨️ Keyboard Shortcuts

```
Ctrl+C              Stop server
Ctrl+Shift+C        Copy (PowerShell)
Ctrl+V              Paste (PowerShell)
```

---

## 🎯 Pro Tips

1. **Save Token ke environment variable**
   ```bash
   export TOKEN="eyJhbGc..."
   curl http://localhost:5000/api/auth/profile -H "Authorization: Bearer $TOKEN"
   ```

2. **Pretty print JSON response**
   ```bash
   curl ... | jq '.'
   ```

3. **Save response to file**
   ```bash
   curl ... > response.json
   ```

4. **Test dengan Postman**
   - Import dari [API_EXAMPLES.md](./API_EXAMPLES.md)
   - Set Authorization token
   - Test semua endpoint

---

**Last Updated:** January 6, 2026  
**Version:** 1.0.0
