# 🧪 TESTING GUIDE - Registration & Login

## ⚡ Quick Test (2 minutes)

### Prerequisites
- Backend running: `npm run dev` (port 5000)
- Frontend running: `npm start` (port 3000)
- Both should be running before testing

### Test Steps

#### 1️⃣ Test Registration
```
1. Open http://localhost:3000 in browser
2. On login page, click "Daftar" button
3. Fill the registration form:
   - Nama Lengkap: "John Doe"
   - Email: "john@example.com"
   - No. Handphone: "08123456789"
   - Daftar sebagai: "Orang Tua"
   - Password: "password123"
   - Konfirmasi Password: "password123"
4. Click "Daftar" button
5. Should see: ✅ "Pendaftaran Berhasil! Silahkan login menggunakan akun Anda."
6. After 1.5 seconds, should auto-redirect to login page
```

#### 2️⃣ Test Login with Registered Account
```
1. On login page, enter:
   - Email: "john@example.com"
   - Password: "password123"
2. Click "Masuk" button
3. Should see: ✅ Dashboard/Home page loads
4. Should be logged in successfully
```

#### 3️⃣ Verify Data Saved
```
1. Open backend folder: c:\Users\ASUS\Desktop\Web absensi\backend\src\data
2. Open users.json file
3. Should see new user account with:
   - email: "john@example.com"
   - name: "John Doe"
   - password: (bcryptjs hashed - looks like: $2a$10$...)
   - createdAt: (timestamp)
```

---

## 🔍 Troubleshooting

### Issue: Register button doesn't work
**Solution**:
1. Open browser developer console (F12)
2. Check Console tab for errors
3. Check Network tab to see if API request is being made
4. Verify backend is running on http://localhost:5000

### Issue: "Pendaftaran gagal" error appears
**Solutions**:
1. Email already exists - use different email
2. Backend not running - start with `npm run dev`
3. Check backend console for error messages
4. Verify network connectivity

### Issue: Login doesn't work with registered account
**Solutions**:
1. Double-check email and password spelling
2. Verify user exists in users.json
3. Check if token is being stored in localStorage:
   - F12 → Application → localStorage
   - Should have 'token' and 'user' keys
4. Verify backend is running

### Issue: "API Error" appears
**Solutions**:
1. Verify backend running on port 5000
2. Check CORS is enabled in backend
3. Check API_BASE_URL in `src/services/api.js` is correct
4. Check network connectivity

---

## 📊 Validation Rules

### Password
- Minimum 6 characters
- Must match confirmation password

### Email
- Must be valid email format
- Must not already exist in database

### All fields are required:
- Nama Lengkap (Name)
- Email
- No. Handphone (Phone)
- Daftar sebagai (Role)
- Password
- Konfirmasi Password (Confirm Password)

---

## 💾 Data Storage

### Frontend (localStorage)
After successful login:
```javascript
localStorage.token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
localStorage.user = '{"id":"123","email":"john@example.com","name":"John Doe","role":"orang_tua"}'
```

### Backend (users.json)
```json
{
  "id": "12345",
  "email": "john@example.com",
  "password": "$2a$10$hashedpassword...",
  "name": "John Doe",
  "role": "orang_tua",
  "createdAt": "2025-01-13T10:30:00.000Z"
}
```

---

## 🔐 Security Features

✅ Passwords hashed with bcryptjs (salt rounds: 10)
✅ JWT tokens with 24-hour expiry
✅ CORS enabled only for localhost
✅ Token auto-injected in Authorization header
✅ Protected API endpoints require valid token
✅ Tokens stored in localStorage (not cookies for this version)

---

## 📝 Example Successful Response

### Register Success
```json
{
  "success": true,
  "message": "Pendaftaran berhasil",
  "user": {
    "id": "12345",
    "email": "john@example.com",
    "name": "John Doe",
    "role": "orang_tua"
  },
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
}
```

### Login Success
```json
{
  "success": true,
  "message": "Login berhasil",
  "user": {
    "id": "12345",
    "email": "john@example.com",
    "name": "John Doe",
    "role": "orang_tua"
  },
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
}
```

---

## 🛠️ Commands to Start

### Terminal 1 - Backend
```bash
cd "c:\Users\ASUS\Desktop\Web absensi\backend"
npm run dev
```

### Terminal 2 - Frontend
```bash
cd "c:\Users\ASUS\Desktop\Web absensi\SD-TUGAS\form-login"
npm start
```

---

**Status**: ✅ Ready to test!

If you see any errors, please:
1. Check backend console for error logs
2. Open browser F12 console for frontend errors
3. Verify both servers are running (Ctrl+L in each terminal to check)
4. Check users.json to verify data being saved
