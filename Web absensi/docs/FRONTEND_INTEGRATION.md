# Panduan Koneksi Backend-Frontend

Dokumentasi ini menjelaskan bagaimana mengkoneksikan frontend React dengan backend Node.js.

## 🔧 Setup API Service (Frontend)

Buat file baru di `src/services/api.js`:

```javascript
const API_BASE_URL = 'http://localhost:5000/api';

// Helper untuk fetch dengan error handling
const fetchAPI = async (endpoint, options = {}) => {
  const token = localStorage.getItem('token');
  
  const headers = {
    'Content-Type': 'application/json',
    ...options.headers
  };

  if (token) {
    headers['Authorization'] = `Bearer ${token}`;
  }

  const response = await fetch(`${API_BASE_URL}${endpoint}`, {
    ...options,
    headers
  });

  const data = await response.json();

  if (!response.ok) {
    throw new Error(data.message || 'API Error');
  }

  return data;
};

// AUTH ENDPOINTS
export const authAPI = {
  register: (email, password, name) =>
    fetchAPI('/auth/register', {
      method: 'POST',
      body: JSON.stringify({ email, password, name })
    }),

  login: (email, password) =>
    fetchAPI('/auth/login', {
      method: 'POST',
      body: JSON.stringify({ email, password })
    }),

  getProfile: () =>
    fetchAPI('/auth/profile'),

  updatePassword: (oldPassword, newPassword) =>
    fetchAPI('/auth/update-password', {
      method: 'PUT',
      body: JSON.stringify({ oldPassword, newPassword })
    })
};

// ABSENSI ENDPOINTS
export const absensiAPI = {
  submit: (date, status, keterangan = '') =>
    fetchAPI('/absensi/submit', {
      method: 'POST',
      body: JSON.stringify({ date, status, keterangan })
    }),

  getMyAbsensi: () =>
    fetchAPI('/absensi/my-absensi'),

  getHistory: () =>
    fetchAPI('/absensi/history'),

  getStatistik: () =>
    fetchAPI('/absensi/statistik'),

  getByDate: (date) =>
    fetchAPI(`/absensi/by-date?date=${date}`),

  getByMonthYear: (month, year) =>
    fetchAPI(`/absensi/by-month-year?month=${month}&year=${year}`),

  getAll: () =>
    fetchAPI('/absensi/all'),

  update: (id, status, keterangan) =>
    fetchAPI(`/absensi/${id}`, {
      method: 'PUT',
      body: JSON.stringify({ status, keterangan })
    }),

  delete: (id) =>
    fetchAPI(`/absensi/${id}`, { method: 'DELETE' })
};

// USER ENDPOINTS
export const userAPI = {
  getAllSiswa: () =>
    fetchAPI('/user/all'),

  getSiswaById: (id) =>
    fetchAPI(`/user/${id}`),

  searchSiswa: (keyword) =>
    fetchAPI(`/user/search?keyword=${keyword}`),

  addSiswa: (email, password, name) =>
    fetchAPI('/user/add', {
      method: 'POST',
      body: JSON.stringify({ email, password, name })
    }),

  updateSiswa: (id, name, email) =>
    fetchAPI(`/user/${id}`, {
      method: 'PUT',
      body: JSON.stringify({ name, email })
    }),

  deleteSiswa: (id) =>
    fetchAPI(`/user/${id}`, { method: 'DELETE' })
};

export default fetchAPI;
```

## 🔐 Update Login Component

Update file `src/pages/LoginPage/LoginPage.jsx`:

```javascript
import React, { useState } from 'react';
import { authAPI } from '../../services/api';
import './Login.css';

const LoginPage = ({ onLoginSuccess }) => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState('');

  const handleLogin = async (e) => {
    e.preventDefault();
    setLoading(true);
    setError('');

    try {
      const response = await authAPI.login(email, password);
      
      // Simpan token dan user data
      localStorage.setItem('token', response.token);
      localStorage.setItem('user', JSON.stringify(response.user));
      
      // Panggil callback untuk pindah halaman
      onLoginSuccess();
    } catch (err) {
      setError(err.message || 'Login gagal');
    } finally {
      setLoading(false);
    }
  };

  return (
    <div className="login-container">
      <form onSubmit={handleLogin}>
        <h2>Login</h2>
        
        {error && <div className="error-message">{error}</div>}
        
        <input
          type="email"
          placeholder="Email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
          disabled={loading}
          required
        />
        
        <input
          type="password"
          placeholder="Password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
          disabled={loading}
          required
        />
        
        <button type="submit" disabled={loading}>
          {loading ? 'Loading...' : 'Login'}
        </button>
      </form>
    </div>
  );
};

export default LoginPage;
```

## 📝 Update Register Component

Update file `src/pages/RegisterPage/RegisterPage.jsx`:

```javascript
import React, { useState } from 'react';
import { authAPI } from '../../services/api';
import './Register.css';

const RegisterPage = ({ onRegisterSuccess }) => {
  const [name, setName] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState('');
  const [success, setSuccess] = useState('');

  const handleRegister = async (e) => {
    e.preventDefault();
    setLoading(true);
    setError('');
    setSuccess('');

    try {
      const response = await authAPI.register(email, password, name);
      setSuccess('Register berhasil! Silakan login.');
      setName('');
      setEmail('');
      setPassword('');
      
      setTimeout(onRegisterSuccess, 2000);
    } catch (err) {
      setError(err.message || 'Register gagal');
    } finally {
      setLoading(false);
    }
  };

  return (
    <div className="register-container">
      <form onSubmit={handleRegister}>
        <h2>Register</h2>
        
        {error && <div className="error-message">{error}</div>}
        {success && <div className="success-message">{success}</div>}
        
        <input
          type="text"
          placeholder="Nama Lengkap"
          value={name}
          onChange={(e) => setName(e.target.value)}
          disabled={loading}
          required
        />
        
        <input
          type="email"
          placeholder="Email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
          disabled={loading}
          required
        />
        
        <input
          type="password"
          placeholder="Password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
          disabled={loading}
          required
        />
        
        <button type="submit" disabled={loading}>
          {loading ? 'Loading...' : 'Register'}
        </button>
      </form>
    </div>
  );
};

export default RegisterPage;
```

## ✅ Update Submit Absensi Component

Update file `src/pages/Mengisiabsensi/SubmitButton.jsx`:

```javascript
import React, { useState } from 'react';
import { absensiAPI } from '../../services/api';

const SubmitButton = ({ date, status, keterangan, onSuccess }) => {
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState('');

  const handleSubmit = async () => {
    if (!date || !status) {
      setError('Tanggal dan status harus dipilih');
      return;
    }

    setLoading(true);
    setError('');

    try {
      const response = await absensiAPI.submit(date, status, keterangan);
      console.log('Absensi submitted:', response);
      
      if (onSuccess) {
        onSuccess();
      }
      alert('Absensi berhasil disimpan');
    } catch (err) {
      setError(err.message || 'Gagal menyimpan absensi');
    } finally {
      setLoading(false);
    }
  };

  return (
    <div>
      {error && <p style={{ color: 'red' }}>{error}</p>}
      <button 
        onClick={handleSubmit} 
        disabled={loading}
        className="submit-button"
      >
        {loading ? 'Loading...' : 'Submit Absensi'}
      </button>
    </div>
  );
};

export default SubmitButton;
```

## 📊 Update Dashboard untuk Rekap

Update file `src/pages/RekapAbsensi/RekapAbsensi.jsx`:

```javascript
import React, { useState, useEffect } from 'react';
import { absensiAPI } from '../../services/api';

const RekapAbsensi = ({ setDashboardPage }) => {
  const [month, setMonth] = useState(new Date().getMonth() + 1);
  const [year, setYear] = useState(new Date().getFullYear());
  const [absensi, setAbsensi] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState('');

  const loadAbsensi = async () => {
    setLoading(true);
    setError('');
    
    try {
      const response = await absensiAPI.getByMonthYear(month, year);
      setAbsensi(response.data);
    } catch (err) {
      setError(err.message || 'Gagal memuat data');
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    loadAbsensi();
  }, [month, year]);

  return (
    <div className="rekap-container">
      <h2>Rekap Absensi</h2>
      
      <div className="filter-section">
        <label>
          Bulan:
          <input
            type="number"
            min="1"
            max="12"
            value={month}
            onChange={(e) => setMonth(parseInt(e.target.value))}
          />
        </label>
        
        <label>
          Tahun:
          <input
            type="number"
            value={year}
            onChange={(e) => setYear(parseInt(e.target.value))}
          />
        </label>
      </div>

      {error && <p style={{ color: 'red' }}>{error}</p>}
      
      {loading ? (
        <p>Loading...</p>
      ) : (
        <table>
          <thead>
            <tr>
              <th>Tanggal</th>
              <th>Status</th>
              <th>Keterangan</th>
            </tr>
          </thead>
          <tbody>
            {absensi.map((item) => (
              <tr key={item.id}>
                <td>{item.date}</td>
                <td>{item.status}</td>
                <td>{item.keterangan}</td>
              </tr>
            ))}
          </tbody>
        </table>
      )}

      <button onClick={() => setDashboardPage('mengisi')}>
        Kembali
      </button>
    </div>
  );
};

export default RekapAbsensi;
```

## 🛠️ Update App.js

Update `src/App.js` untuk menggunakan backend:

```javascript
import React, { useState, useEffect } from "react";
import LoginForm from "./pages/LoginPage/LoginPage.jsx";
import RegisterForm from "./pages/RegisterPage/RegisterPage.jsx";
import Dashboard from "./pages/Mengisiabsensi/Dashboard.jsx";
import Navbar from "./pages/Mengisiabsensi/Navbar.jsx";

const VIEW_LOGIN = "login";
const VIEW_REGISTER = "register";

function App() {
  const [view, setView] = useState(VIEW_LOGIN);
  const [dashboardPage, setDashboardPage] = useState("mengisi");
  const [user, setUser] = useState(null);

  // Check if user sudah login (dari localStorage)
  useEffect(() => {
    const savedUser = localStorage.getItem('user');
    if (savedUser) {
      setUser(JSON.parse(savedUser));
      setView('dashboard');
    }
  }, []);

  const handleLoginSuccess = () => {
    const savedUser = localStorage.getItem('user');
    setUser(JSON.parse(savedUser));
    setView("dashboard");
  };

  const handleLogout = () => {
    localStorage.removeItem('token');
    localStorage.removeItem('user');
    setUser(null);
    setView(VIEW_LOGIN);
  };

  return (
    <div className="App">
      {view === "dashboard" ? (
        <div className="dashboard-layout1">
          <Navbar
            onLogout={handleLogout}
            setDashboardPage={setDashboardPage}
            dashboardPage={dashboardPage}
            user={user}
          />
          <div className="dashboard-content1">
            {dashboardPage === "mengisi" && <Dashboard />}
            {/* Komponen lainnya */}
          </div>
        </div>
      ) : view === "register" ? (
        <RegisterForm onRegisterSuccess={() => setView(VIEW_LOGIN)} />
      ) : (
        <LoginForm onLoginSuccess={handleLoginSuccess} />
      )}
    </div>
  );
}

export default App;
```

## 📦 Install Dependencies Frontend

Jalankan di folder frontend:
```bash
npm install
```

Tidak perlu install package tambahan karena menggunakan fetch API bawaan browser.

## ✅ Testing

1. Start backend:
   ```bash
   cd backend
   npm run dev
   ```

2. Start frontend:
   ```bash
   cd SD-TUGAS/form-login
   npm start
   ```

3. Test register dan login di browser
4. Cek localStorage untuk melihat token yang disimpan

---

**Selesai! Backend dan Frontend sudah terkoneksi.**
