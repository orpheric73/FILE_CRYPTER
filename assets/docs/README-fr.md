# 🔐 CipherFlow System

## 📝 Description

![CipherFlow Preview](../social-preview.jpg)
CipherFlow System est une application console Windows développée en langage C permettant le chiffrement, le déchiffrement de fichiers, la planification d’exécution de ces opérations ainsi que le transfert sécurisé des fichiers par TCP.  
Le système repose sur un algorithme personnalisé utilisant un mot de passe, combiné à un mécanisme de version dynamique, une permutation non linéaire des données et un protocole fiable de transfert de fichiers construit avec Winsock.

---

## 📦 Fonctionnalités

- 🔒 Chiffrement de fichiers  
Chiffre un ou plusieurs fichiers en utilisant un mot de passe unique et une version.
- 🔓 Déchiffrement de fichiers  
Déchiffre les fichiers chiffrés en utilisant le mot de passe et la version correct.
- ⏳ Chiffrement planifié  
Permet de programmer le chiffrement d’un fichier à une date et une heure spécifié.
- ⏳ Déchiffrement planifié  
Permet de programmer le déchiffrement d’un fichier à une date et une heure spécifié.
- 📤 Transfert de fichier (New in v1.3)  
Envoie sécurisé de fichier a un autre appareil par TCP.
- 📥 Réception de fichier (New in v1.3)  
Réception de fichier d'un autre appareil en utilisant le protocole de transfert intégré à CipherFlow.
- 🌐 Multilingue  
Support dynamique des langues : français / anglais
- 🛡️ Protection  
Protection contre la suppression ou les erreurs critiques pendant l’exécution.

---

## 💻 Caractéristiques techniques

- Gestion dynamique de plusieurs fichiers avec allocation mémoire sécurisée
- Vérification des entrées utilisateur (mot de passe, version, Adresse IP, Port, et chemins de fichiers)
- Système de planification basé sur la date et l’heure du système
- Analyse du niveau de sécurité du mot de passe (basé sur la répétition des caractères)
- Transfert fiable de fichiers par TCP utilisant Winsock
- Transmission de données garanti avec send_all() et recv_all()
- Affichage automatique de la progression du transfert
- Interface bilingue (FR / EN)

---

## 🔐 Mécanisme de chiffrement

Le système repose sur un algorithme personnalisé en plusieurs étapes :

- 1️⃣ Génération de la clé à partir du mot de passe et de la version
- 2️⃣ Transformation des données à partir de cette clé et de la version
- 3️⃣ Permutation non linéaire des données basée sur la clé ajustée par la version

---

## 🌐 Protocol de transfert de fichiers

CipherFlow v1.3 introduit un système de transfert de fichiers intégré par TCP.

Fonctionnalités incluses :

- Communication TCP fiable
- Connection automatique expéditeur/receveur
- Transmission garanti de toutes les données du fichier
- Affichage de la progression du transfert
- Prise en charge des fichiers de pratiquement toutes les tailles
- Gestion des erreurs réseau
- Reconstruction automatique du fichier reçu

---

## 🎨 Interface console

- Effets d’écriture progressive
- Effets visuels type “Matrix” et de couleurs
- Alertes système via MessageBox()
- Interface de connexion réseau dédiée
- Progression du transfert en temps réel
- Interface de console améliorée

---

## 🧠 Objectifs pédagogiques

Ce projet permet de comprendre et pratiquer :

- La gestion de fichiers en C (fopen, fclose, getc, fprintf)
- La manipulation de mémoire dynamique (malloc, calloc, free)
- L’utilisation de structures (struct)
- La création d’interfaces console interactives
- L’intégration d’alertes système Windows
- Programmation socket TCP avec Winsock
- Architecture Client/Server
- Implementation d'un protocole fiable de transfert de fichier

---

## ⚙️ Technologies

- **Type** : Application console (CLI)
- **Langage** : C
- **Compilateur** : GCC (MSYS2/MinGW-w64)
- **Système d'exploitation:** Windows
- **Réseautage:** Winsock (TCP)
- **API Windows:** User32, Shell32
- **Système de ressource:** Windows Resource Compiler (.rc)

---

## 🛠️ Build & Compilation

```Bash
Bash
windres resource.rc -O coff -o CipherFlow.res

gcc main.c function.c CipherFlow.res -o FILE_CRYPTER.exe -luser32 -lws2_32 -lshell32
```

---

## ▶️ Exécution

```Bash
Bash
./FILE_CRYPTER.exe
```

---

## 📋 Prérequis

- Windows 10 ou plus récent
- MSYS2 (pour la compilation)
- GCC (MinGW-w64)
- Windows SDK (Compilateur de ressource)

---

## ⭐ Cas d’utilisation

**1️⃣ Protection des données personnelles :**

- Chiffrement de documents sensibles (mots de passe, fichiers privés, données confidentielles)
- Sécurisation avant stockage ou partage

**2️⃣ Automatisation des tâches de sécurité :**

- Planification automatique des opérations de chiffrement et déchiffrement
- Réduction des actions manuelles

**3️⃣ Prévention des pertes et fuites de données :**

- Protection contre les accès non autorisés
- Sécurisation des fichiers avant transfert

**4️⃣ Transfert sécurisé de fichiers :**

- Envoyer des fichier de manière sécurisé entre des appareils Windows
- Transferer des fichiers chiffré sur un réseau local
- Partager de grand fichiers  a travers le protocole intégré de CipherFlow

---

## 📁 Types de fichiers supportés

```md
Tous les fichiers lisibles via les fonctions de lecture de fichiers
```

---

## ⚠️ Remarques importantes

- Fonctionne uniquement sous Windows
- Le mot de passe et la version doivent être exacts pour le déchiffrement
- Le chiffrement planifié peut fonctionner même si le fichier n’existe pas encore au moment de la planification
- L'expéditeur et le receveur doivent utilisé le meme port TCP.
- Le processus de transfert de fichiers requiert une connexion réseau entre les appareils.
- Les fichiers chiffrés utilisent l'extension .cflow.

---

## 🔥 Améliorations possibles

- Authentification du transfert
- Communication chiffré de bout en bout
- Prise en charge de poursuite de transfert
- Transfert de multiples fichiers
- Interface graphique (GUI)
- Système de logs et de monitoring

---

## 📚 Documentation

Pour une explication détaillée de l’utilisation:

👉 [Voir le guide utilisateur](GUIDE_UTILISATION.md)

## 📄 Licence

Ce projet est sous [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../../LICENSE).
