# 🔐 CypherFlow System (File Crypter)
## 📖 Overview
CypherFlow System is a console-based file encryption and decryption application written in C.
It allows users to securely encrypt and decrypt files using a password-based transformation algorithm, enhanced by a dynamic versioning system and scheduled execution.
## ⚙️ Features
- 🔒 File Encryption
```
Encrypt one or multiple files using a password and version-based transformation.
```
- 🔓 File Decryption
```
Decrypt previously encrypted files using the correct password and version.
```
- ⏳ Scheduled Encryption
```
Schedule encryption of a file at a future date, even if the file does not yet exist.
```
- ⏳ Scheduled Decryption
```
Schedule decryption safely without deleting the encrypted file.
```
- 🧠 Custom Encryption Algorithm
```
- Password transformation with diffusion
- Version-based modifications
- ASCII character transformation
- Derived numeric encryption key
```
## 🖥️ System Type
- **Application Type**: Console (CLI)
- **Language**: C
## 🚀 How to Use
### ▶️ Launch the Program
Run the executable file. A console interface with ASCII art CypherFlow System will appear.
### 📌 Main Menu Options
**1. Encrypt File(s)**
```
- Enter the number of files to encrypt
- For each file:
- Enter file name and extension
- Program checks if file exists
- If not → prompts again
- Enter password
- Enter version
File is encrypted
```
**2. Decrypt File(s)**
```
- Same process as encryption
- Requires correct password and version
- If incorrect → output remains encrypted (safe retry possible)
```
**3. Scheduled Encryption**
```
- Enter file name and extension
- Enter password and version
- Enter scheduled date/time
- Program confirms scheduling
- 💡 Special Feature:
- File does NOT need to exist yet
- At scheduled time:
  - If file exists → encrypt + delete original
  - If not → “File not found”
```
**4. Scheduled Decryption**
```
- Same process as scheduled encryption
- Encrypted file is NOT deleted after decryption
```
## 💡 Security Advantage:
If password/version is wrong → encrypted file remains encrypted(but not intact)
## 🔐 Encryption Mechanism
CypherFlow uses a custom algorithm based on three main principles:
### 1️⃣ Password Transformation
- Input password is transformed using diffusion
- Each character influences others
### 2️⃣ Dynamic Versioning
- User-defined version modifies transformation behavior
- Produces different encryption outputs for same password
### 3️⃣ Key Derivation
- Final key = numeric sequence derived from password + version
### 4️⃣ ASCII Transformation
- File characters are modified using the derived key
- Output becomes unreadable (encrypted data)
## 📁 Supported Files
All file types readable via file handling
- Exception: Some formats like .docx (ZIP/XML structure) may not open correctly after encryption
## ⚠️ Important Notes
- Correct password + version are required for decryption
- Wrong inputs do NOT destroy encrypted data
- Scheduled encryption can target files not yet created
- Original file is deleted only after successful encryption
## 💡 Example Use Case
- Secure sensitive files with password + version
- Automate encryption at a specific time
- Protect files before sharing or storage
