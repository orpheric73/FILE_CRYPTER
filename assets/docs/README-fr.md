# 🔐 CIPHER FLOW SYSTEM
## 📝 Description
![Preview](../social-preview.jpg)
CipherFlow System est une application console développée en langage C permettant le chiffrement, le déchiffrement de fichiers ainsi que la planification d’exécution de ces opérations.
Le système repose sur un algorithme personnalisé utilisant un mot de passe, combiné à un mécanisme de version dynamique et une permutation non linéaire des données.
## 📦 Fonctionnalités
- 🔒 Chiffrement de fichiers
Chiffre un ou plusieurs fichiers en utilisant un mot de passe unique et une version avec permutation interne des données.
- 🔓 Déchiffrement de fichiers
Déchiffre les fichiers précédemment chiffrés à l’aide des paramètres corrects (mot de passe et version).
- ⏳ Chiffrement planifié
Permet de programmer le chiffrement d’un fichier à une date et une heure futures.
- ⏳ Déchiffrement planifié
Permet de programmer le déchiffrement d’un fichier à une date et une heure futures.
- 🌐 Multilingue
Support dynamique des langues : français / anglais
- 🛡️ Protection
Protection contre la suppression ou les erreurs critiques pendant l’exécution.
## 💻 Caractéristiques techniques
- Gestion dynamique de plusieurs fichiers avec allocation mémoire sécurisée
- Vérification des entrées utilisateur (mot de passe, version, chemins de fichiers)
- Système de planification basé sur la date et l’heure du système
- Analyse du niveau de sécurité du mot de passe (basé sur la répétition des caractères)
- Interface bilingue (FR / EN)
## 🔐 Mécanisme de chiffrement
Le système repose sur un algorithme personnalisé en plusieurs étapes :
- 1️⃣ Génération de la clé à partir du mot de passe et de la version
- 2️⃣ Transformation des données à partir de cette clé et de la version
- 3️⃣ Permutation non linéaire des données basée sur la clé ajustée par la version
## 🎨 Interface console
- Effets d’écriture progressive
- Effets visuels type “Matrix”
- Changement de couleurs dans la console
- Alertes système via MessageBox()
## 🧠 Objectifs pédagogiques
Ce projet permet de comprendre et pratiquer :
- La gestion de fichiers en C (fopen, fclose, getc, fprintf)
- La manipulation de mémoire dynamique (malloc, calloc, free)
- L’utilisation de structures (struct) 
- La création d’interfaces console interactives
- L’intégration d’alertes système Windows
## ⚙️ Technologies
- **Type** : Application console (CLI)
- **Langage** : C
- **Compilateur** : GCC ou tout compilateur C standard
## 🛠️ Build & Compilation
Windows (MinGW)
```
Bash
gcc main.c function.c -o FILE_CRYPTER.exe -luser32
```
## ▶️ Exécution
```
Bash
./FILE_CRYPTER.exe
```
## ⭐ Cas d’utilisation
**1️⃣ Protection des données personnelles**
```
- Chiffrement de documents sensibles (mots de passe, fichiers privés, données confidentielles)
- Sécurisation avant stockage ou partage
```
**2️⃣ Automatisation des tâches de sécurité**
```
- Planification automatique des opérations de chiffrement et déchiffrement
- Réduction des actions manuelles
```
**3️⃣ Prévention des pertes et fuites de données**
```
- Protection contre les accès non autorisés
- Sécurisation des fichiers avant transfert
```
## 📁 Types de fichiers supportés
Tous les fichiers lisibles via les fonctions de lecture de fichiers
## ⚠️ Remarques importantes
- Fonctionne uniquement sous Windows
- Le mot de passe et la version doivent être exacts pour le déchiffrement
- Le chiffrement planifié peut fonctionner même si le fichier n’existe pas encore au moment de la planification
## 🔥 Améliorations possibles (future work)
- Interface graphique (GUI)
- Système de logs et de monitoring
## 📚 Documentation

Pour une explication détaillée de l’utilisation:

👉 [Voir le guide utilisateur](GUIDE_UTILISATION.md)
## 📄 Licence
Ce projet est sous [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../../LICENSE). 
