# 🔐 CIPHER FLOW SYSTEM
## 📝 Description
![Preview](assets/social-preview.jpg)
CIPHER FLOW SYSTEM est un logiciel de gestion sécurisée de fichiers permettant de chiffrer et déchiffrer des fichiers texte, PDF et RTF.
Le programme offre les fonctionnalités suivantes :
- Chiffrement de fichier
```
Chiffre un ou plusieurs fichiers en utilisant un mot de passe unique et une version.
```
- Déchiffrement de fichier
```
Déchiffre les fichiers précédemment chiffrés avec le mot de passe correspondant.
```
- Planification du chiffrement
```
Permet de planifier un chiffrement à une date et heure future.
```
- Planification du déchiffrement
```
Permet de planifier le déchiffrement de fichiers selon une date et heure définie.
```
- Visualisation du niveau de sécurité
```
Affiche la force du mot de passe, allant de “ULTRA-SECURE” à “RISKY”, avec une représentation graphique en ASCII.
```
## 💻 Caractéristiques techniques
- Gestion dynamique de plusieurs fichiers avec allocation mémoire sécurisée
- Vérification et confirmation des entrées utilisateur (mot de passe, version, fichiers)
- Calcul du niveau de sécurité du mot de passe basé sur la répétition des caractères et la complexité
- Planification avec vérification complète de la date et de l’heure système pour déclencher automatiquement les opérations
- La sécurité repose sur le mot de passe et la version, et non sur des standards cryptographiques officiels
## 🎨 Interface console améliorée
- Effets visuels avec type_effect() pour simuler une écriture progressive
- Changement dynamique de couleur pour les étapes importantes (color_change())
- Alertes Windows via MessageBox()
## 🔐 Exemple d’utilisation
Lancer le programme depuis la console :
```
Bash
FILE_CRYPTER.exe
```
Choisir une option :
```
1 → Chiffrement de fichier
2 → Déchiffrement de fichier
3 → Planification du chiffrement
4 → Planification du déchiffrement
5 → Quitter
```
Suivre les instructions pour entrer :
- le nom du fichier
- l’extension
- le mot de passe
- la version
```
Les fichiers chiffrés sont créés avec le suffixe (ENCRYPTED) ou -crypt selon le mode choisi.
```
## 🧠 Objectifs pédagogiques
Ce projet permet de comprendre et pratiquer :
- La gestion de fichiers en C (fopen, fclose, getc, fprintf)
- La manipulation de mémoire dynamique (malloc, calloc, free)
- L’utilisation de structures (struct) pour organiser les données
- Une logique de chiffrement basée sur mot de passe + version
- Les interactions console / Windows pour créer une interface simple mais efficace
## ⚠️ Limitations
- Fonctionne uniquement sous Windows
- Ne supporte pas les chemins contenant des espaces (utiliser _ à la place)
## ⚙️ Technologies
- **Langage** : C
- **Compilateur** : GCC ou tout compilateur C standard
## 🛠️ Build & Compilation
```
Bash
gcc main.c function.c -o FILE_CRYPTER.exe -lwinmm
```
## ▶️ Exécution
```
Bash
./FILE_CRYPTER.exe
```
## 📄 Licence
Ce projet est sous [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE).
