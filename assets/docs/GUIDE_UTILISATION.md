##🚀 1. Lancer le programme
##🌐 2. Choix de l’affichage
- Sélection de la langue du programme
- Activation / désactivation des animations (ON/OFF)
##🎛️ 3. Menu principal
Choisissez une option :
```
[1] Chiffrer un fichier  
[2] Déchiffrer un fichier  
[3] Planifier un chiffrement  
[4] Planifier un déchiffrement  
[5] Quitter
```
🟢 **1. Chiffrer des fichiers**
- Saisir le nombre de fichiers à chiffrer
```
Pour chaque fichier :
- Entrer le chemin complet du fichier (glisser-déposer possible)
- Vérification de l’existence du fichier
  → S’il n’existe pas : une nouvelle saisie est demandée
- Entrer le mot de passe
- Entrer la version (possibilité d’utiliser le même mot de passe pour plusieurs fichiers)

- Le fichier est chiffré si le processus se déroule correctement
- En cas d’erreur :
  → Affichage d’un message (MessageBox)
  → Suppression des données sensibles
  → Fermeture du programme
```
```
📌 **Remarque :**
- Les fichiers chiffrés sont créés avec un ajout de "s" à leur extension.
- Cet ajout est automatiquement supprimé lors du déchiffrement.
```
🟢 **2. Déchiffrer des fichiers**
```
- Même processus que pour le chiffrement
- Nécessite le bon mot de passe et la bonne version
💡 En cas d’informations incorrectes :
- Le fichier n’est pas déchiffré
- L’utilisateur peut réessayer avec le fichier chiffré d’origine
```
🟢 **3. Chiffrement planifié**
```
- Définir la date et l’heure d’exécution
- Confirmer la planification
- Entrer le chemin complet du fichier
- Entrer le mot de passe et la version

💡 Particularité importante :
- Le fichier peut ne pas exister au moment de la planification

À la date prévue :
- Si le fichier existe → chiffrement
- Sinon → message “File not found”
```
🟢 **4. Déchiffrement planifié**
```
- Même fonctionnement que le chiffrement planifié
À l’heure prévue :
- Si le fichier existe → déchiffrement
- Sinon → message “File not found”
```