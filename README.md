# CIPHER FLOW SYSTEM
## 📝 Description
![Social Preview](assets/social-preview.jpg)
CipherFlow System is a console application written in C that allows file encryption, decryption, and task scheduling.
The system is based on a custom algorithm using a password, combined with a dynamic versioning mechanism and a non-linear permutation process. 
## 📦 Features
- 🔒 File Encryption
Encrypts one or multiple files using a password and a version, with internal data permutation.
- 🔓 File Decryption
Decrypts encrypted files using the correct password and version.
- ⏳ Scheduled Encryption
Allows scheduling file encryption at a specific date and time.
- ⏳ Scheduled Decryption
Allows scheduling file decryption at a specific date and time.
- 🌐 Multilingual Support
Dynamic language switching (French / English)
- 🛡️ Safety Protection
Prevents accidental file overwriting or deletion.
## 💻 Technical Features
- Dynamic handling of multiple files with secure memory allocation
- Input validation (password, version, file paths)
- Scheduling system based on system date and time
- Password strength estimation based on character repetition
- Dual-language display (EN / FR)
## 🔐 Encryption Mechanism
The system relies on a custom algorithm composed of several steps:
- Key generation from password and version
- Data transformation based on the generated key
- Non-linear permutation using version-adjusted key values
##🎨 Console Interface
- Progressive text rendering
- Color effects and “Matrix-style” animations
- Windows alerts using MessageBox() 
##🧠 Learning Objectives
This project helps practice:
- File handling in C (fopen, fclose, getc, fprintf)
- Dynamic memory management (malloc, calloc, free)
- Use of struct for data organization
- Console UI + Windows popups integration
## ⚙️ Technologies 
- **Language:** C
- **Compiler:** GCC or any standard C compiler.
## 🛠️ Build & Compilation
```
gcc main.c function.c -o FILE_CRYPTER.exe -luser32 
```
## ▶️ Execution
```
Bash
./FILE_CRYPTER.exe
```
## ⭐ Use Cases
**1️⃣ Personal Data Protection**
```
- Secure sensitive files (passwords, private documents, confidential data)
- Encrypt data before storage or sharing
```
**2️⃣ Security Automation**
```
- Schedule encryption/decryption tasks
- Reduce manual intervention
```
**3️⃣ Data Loss & Leak Prevention**
```
- Protect files from unauthorized access
- Secure files before transfer
```
## 📁 Supported File Types
All file types supported by file reading functions.
## ⚠️ Important Notes
- Works on Windows only
- Correct password and version are required for decryption
- Scheduled encryption works even if the file does not exist yet
## 🔥 Future Improvements
- Graphical User Interface (GUI)
- Logging and monitoring system
## ## 📚 Documentation

For a detailed explanation on how to use:

- 👉 [View Full User Guide](assets/docs/USER_GUIDE.md)
## 📄 License
This project is licensed under the [![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
## 🌍 FRENCH VERSION

[![Français](https://img.shields.io/badge/Langue-Français-blue.svg)](assets/docs/README-fr.md)