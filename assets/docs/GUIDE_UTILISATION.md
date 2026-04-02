# 🔐 CypherFlow System (File Crypter)
## 📖 Présentation
CypherFlow System est une application console développée en langage C permettant le chiffrement et le déchiffrement de fichiers.
Le système repose sur un algorithme personnalisé basé sur un mot de passe, combiné à un mécanisme de version dynamique et à une exécution planifiée.
## ⚙️ Fonctionnalités
- 🔒 Chiffrement de fichiers
```
Chiffre un ou plusieurs fichiers à l’aide d’un mot de passe et d’une version.
```
- 🔓 Déchiffrement de fichiers
```
Déchiffre les fichiers précédemment chiffrés avec les bons paramètres.
```
- ⏳ Chiffrement planifié
```
Permet de programmer le chiffrement d’un fichier à une date future.
```
- ⏳ Déchiffrement planifié
```
Permet de programmer le déchiffrement sans supprimer le fichier chiffré.
```
- 🧠 Algorithme de chiffrement personnalisé
```
  - Transformation du mot de passe
  - Diffusion des caractères
  - Modification basée sur une version
  - Transformation ASCII des données
```
## 🖥️ Type de système
- **Type** : Application console (CLI)
- **Langage** : C
## 🚀 Utilisation
### ▶️ Lancement du programme
Exécute le programme. Une interface console avec un ASCII art “CypherFlow System” apparaît.
### 📌 Menu principal
**1. Chiffrer des fichiers (Encrypt File)**
```
- Saisir le nombre de fichiers à chiffrer
Pour chaque fichier :
- Entrer le nom et l’extension
- Vérification de l’existence du fichier
Si inexistant → nouvelle saisie demandée
- Entrer le mot de passe
- Entrer la version
Le fichier est ensuite chiffré
```
**2. Déchiffrer des fichiers (Decrypt File)**
```
- Même processus que le chiffrement
- Nécessite le bon mot de passe et la bonne version
- 💡 Si les informations sont incorrectes :
  - Le fichier reste chiffré (aucune perte de données)
  - L’utilisateur peut réessayer
```
**3. Chiffrement planifié (Scheduled Encryption)**
```
- Définir la date et l'heure d'exécution
- Confirmation de la planification 
- Entrer le nom et l’extension du fichier
- Entrer le mot de passe et la version
- 💡 Particularité importante :
  - Le fichier peut ne pas exister au moment de la programmation
  - À l’heure prévue :
Si le fichier existe → chiffrement + suppression du fichier original
Sinon → message “File not found”
```
**4. Déchiffrement planifié (Scheduled Decryption)**
```
- Même fonctionnement que le chiffrement planifié
- 💡 Sécurité renforcée :
  - Le fichier chiffré n’est pas supprimé après déchiffrement
  - Permet de réessayer en cas d’erreur de mot de passe/version
```
## 🔐 Mécanisme de chiffrement
Le système repose sur un algorithme personnalisé composé de plusieurs étapes :
### 1️⃣ Transformation du mot de passe
- Le mot de passe utilisateur subit une diffusion
- Chaque caractère influence les autres
### 2️⃣ Version dynamique
- Une version définie par l’utilisateur modifie le comportement de l’algorithme
- Permet d’obtenir des résultats différents avec le même mot de passe
### 3️⃣ Dérivation de clé
- Le mot de passe transformé devient une clé numérique
- Cette clé est utilisée pour le chiffrement
### 4️⃣ Transformation ASCII
- Les caractères du fichier sont modifiés via leur valeur ASCII
- Le contenu devient illisible (chiffré)
## 📁 Types de fichiers supportés
Tous les fichiers lisibles via les fonctions de lecture de fichiers
- Limitation actuelle :
Certains formats comme .docx (structure ZIP/XML) peuvent ne pas être exploitables après chiffrement
## ⚠️ Remarques importantes
- Le mot de passe et la version doivent être exacts pour le déchiffrement
- Une erreur n’endommage pas les données chiffrées
- Le chiffrement planifié fonctionne même pour des fichiers futurs
- Le fichier original est supprimé uniquement après chiffrement réussi
## 🔥 Améliorations possibles (future work)
- Support complet de tous les formats de fichiers
- Interface graphique
- Amélioration de l’algorithme de chiffrement
- Ajout de logs et monitoring
