## 🚀 1. Launch the Program
## 🌐 2. Display Settings
- Select the program language
- Enable / disable animations (ON/OFF)
## 🎛️ 3. Main Menu
Choose an option:
```
[1] Encrypt a file  
[2] Decrypt a file  
[3] Schedule encryption  
[4] Schedule decryption  
[5] Exit
```
🟢 **1. Encrypt Files**
- Enter the number of files to encrypt
```
For each file:
- Enter the full file path (drag and drop supported)
- Check if the file exists
  → If not found: you will be prompted to re-enter the path
- Enter the password
- Enter the version (you can reuse the same password for multiple files)

- The file is encrypted if the process completes successfully
- In case of an error:
  → A message is displayed (MessageBox)
  → Sensitive data is cleared
  → The program is terminated
```
```
📌 **Note:**
- Encrypted files are created with an additional "s" added to their extension.  
- This addition is automatically removed during decryption.
```
🟢 **2. Decrypt Files**
```
- Same process as encryption
- Requires the correct password and version
💡 If the provided information is incorrect:
- The file will not be decrypted
- The user can retry using the original encrypted file
```
🟢 **3. Scheduled Encryption**
```
- Set the execution date and time
- Confirm the schedule
- Enter the full file path
- Enter the password and version

💡 Important:
- The file does not need to exist at the time of scheduling

At the scheduled time:
- If the file exists → encryption is performed
- Otherwise → "File not found" message is displayed
```
🟢 **4. Scheduled Decryption**
```
- Same behavior as scheduled encryption
At the scheduled time:
- If the file exists → decryption is performed
- Otherwise → "File not found" message is displayed
```
