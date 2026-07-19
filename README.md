# CipherFlow System

## 📝 Description

![CipherFlow Preview](assets/social-preview.jpg)
CipherFlow System is a Windows console application written in C that provides file encryption, file decryption, task scheduling, and secure TCP file transfer.  
The system is based on a custom password-driven algorithm combining with a dynamic versioning mechanism, a non-linear permutation process, and a reliable file transfer protocol built with Winsock.

---

## 📦 Features

- 🔒 File Encryption  
Encrypts one or multiple files using a password and a version.
- 🔓 File Decryption  
Decrypts encrypted files using the correct password and version.
- ⏳ Scheduled Encryption  
Schedule file encryption at a specific date and time.
- ⏳ Scheduled Decryption  
Schedule file decryption at a specific date and time.
- 📤 File Transfer (New in v1.3)  
Securely send files to another computer over TCP.
- 📥 File Reception (New in v1.3)  
Receive files from another computer through CipherFlow's built-in transfer protocol.
- 🌐 Multilingual Support  
Dynamic language switching (French / English)
- 🛡️ Safety Protection  
Prevents accidental file overwriting or deletion.

---

## 💻 Technical Features

- Dynamic handling of multiple files with secure memory allocation
- Input validation (password, version, IP address, Port, and file paths)
- Scheduling system based on system date and time
- Password strength estimation based on character repetition
- Reliable TCP file transfer using Winsock
- Guaranteed data transmission with send_all() and recv_all()
- Automatic transfer progress display
- Dual-language display (EN / FR)

---

## 🔐 Encryption Mechanism

The system relies on a custom algorithm composed of several steps:

- Key generation from password and version
- Data transformation based on the generated key
- Non-linear permutation using version-adjusted key values

---

## 🌐 File Transfer Protocol

CipherFlow v1.3 introduces a built-in TCP file transfer system.

Features include :

- Reliable TCP communication
- Automatic sender/receiver connection
- Guaranteed transmission of all file data
- Transfer progress monitoring
- Support for files of virtually any size
- Network error handling
- Automatic reconstruction of the received file

---

## 🎨 Console Interface

- Progressive text rendering
- Color effects and “Matrix-style” animations
- Windows alerts using MessageBox()
- Dedicated network connection interface
- Real-time transfer progress
- Improved console layout

---

## 🧠 Learning Objectives

This project helps practice:

- File handling in C (fopen, fclose, getc, fprintf)
- Dynamic memory management (malloc, calloc, free)
- Use of struct for data organization
- Console UI + Windows popups integration
- TCP socket programming with Winsock
- Client/Server architecture
- Reliable file transfer protocol implementation

---

## ⚙️ Technologies

- **App** : Console application (CLI)
- **Language:** C
- **Compiler:** GCC (MSYS2/MinGW-w64)
- **Operating System:** Windows
- **Networking:** Winsock (TCP)
- **Windows API:** User32, Shell32
- **Resource System:** Windows Resource Compiler (.rc)

---

## 🛠️ Build & Compilation

```Bash
Bash
windres resource.rc -O coff -o CipherFlow.res

gcc main.c function.c CipherFlow.res -o FILE_CRYPTER.exe -luser32 -lws2_32 -lshell32
```

---

## ▶️ Execution

```Bash
Bash
./FILE_CRYPTER.exe
```

---

## 📋 Requirements

- Windows 10 or later
- MSYS2 (for compilation)
- GCC (MinGW-w64)
- Windows SDK (Resource Compiler)

---

## ⭐ Use Cases

**1️⃣ Personal Data Protection :**

- Secure sensitive files (passwords, private documents, confidential data)
- Encrypt data before storage or sharing

**2️⃣ Security Automation :**

- Schedule encryption/decryption tasks
- Reduce manual intervention

**3️⃣ Data Loss & Leak Prevention :**

- Protect files from unauthorized access
- Secure files before transfer

**4️⃣ Secure File Transfer :**

- Send files securely between Windows computers
- Transfer encrypted files over a local network
- Share large files through CipherFlow's built-in protocol

---

## 📁 Supported File Types

```md
All file types are supported, including binary and text files.
```

---

## ⚠️ Important Notes

- Works on Windows only.
- Correct password and version are required for decryption.
- Scheduled encryption works even if the file does not exist yet.
- Sender and receiver must use the same TCP port.
- File transfer requires an network connection between the device.
- Encrypted files use the .cflow extension.

---

## 🔥 Future Improvements

- Transfer authentication
- End-to-end encrypted communication
- Transfer resume support
- Multi-file transfer
- Graphical User Interface (GUI)
- Logging and monitoring system

---

## 📚 Documentation

For a detailed explanation on how to use:

- 👉 [View Full User Guide](assets/docs/USER_GUIDE.md)

## 📄 License

This project is licensed under the [![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

## 🌍 FRENCH VERSION

[![Français](https://img.shields.io/badge/Langue-Français-blue.svg)](assets/docs/README-fr.md)
