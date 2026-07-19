# CipherFlow User Guide

## 🔒 Encrypt File

- Enter the number of files to encrypt

For each file:

- Enter the full file path (drag and drop supported)
- Check if the file exists
  → If not found: you will be prompted to re-enter the path
- Enter the password
- Enter the version (you can reuse the same password for multiple files)

- The file is encrypted if the process completes successfully
- In case of an error:
  → A message is displayed (MessageBox)
  → Sensitive data are cleared
  → The process is ended

## 🔓 Decrypt Files

- Same process as encryption
- Requires the correct password and version
💡 If the provided information is incorrect:
- The file will not be decrypted
- The user can retry using the original encrypted file

## ⏳ Scheduled Encryption

- Set the execution date and time
- Confirm the schedule
- Enter the full file path
- Enter the password and version
**💡 Important:**

- The file does not need to exist at the time of scheduling
At the scheduled time:

- If the file exists → encryption is performed
- Otherwise → "File not found" message is displayed

## ⏳ Scheduled Decryption

- Same behavior as scheduled encryption
At the scheduled time:
- If the file exists → decryption is performed
- Otherwise → "File not found" message is displayed

## File Transfer

CipherFlow System allows users to securely transfer files between two computers over a TCP connection.  
Two transfer modes are available :

- **Send File** - Send a file to another computer.
- **Receive File** - Wait for an incoming file from another computer.

### 📤 Send File

- Enter the receiver's IP address.
- Enter the receiver's listening port.
- Wait until the connection is established.
- Select the file to send.
- Share the reception key with the receiver
- Wait for the transfer to complete.
**Note:** The receiver must already be waiting for an incoming connection before the sender attempts to connect

### 📥 Receive File

- Choose the listening port.
- Share your displayed IP address to the sender.
- Wait for the sender to connect.
- Select the destination folder by selecting a random file in this folder.
- Enter the reception key.
- Confirm the reception of the file
- Wait until the reception is completed.

## 📋 Important information about File Transfer

Before starting a transfer, ensure that:

- Both computers are connected to the same network or can reach each other.
- The receiver must starts the receiving file process and must be in reception mode before sender to connect
- Both sides use the same TCP port.
- The receiver shares the correct IPv4 address with the sender.
- Firewall settings allow CipherFlow to communicate.
