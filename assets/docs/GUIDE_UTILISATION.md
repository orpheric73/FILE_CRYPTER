# Guide d'utilisation CipherFlow

## 🔒 Chiffrer des fichiers

- Saisir le nombre de fichiers à chiffrer

Pour chaque fichier :

- Entrer le chemin complet du fichier (glisser déposer possible)
- Vérification de l’existence du fichier
  → S’il n’existe pas : une nouvelle saisie est demandée
- Entrer le mot de passe
- Entrer la version (possibilité d’utiliser le même mot de passe pour plusieurs fichiers)

- Le fichier est chiffré si le processus se déroule correctement
- En cas d’erreur :
  → Affichage d’un message (MessageBox)
  → Suppression des données sensibles
  → Fermeture du programme

## 🔓 Déchiffrer des fichiers

- Même processus que pour le chiffrement
- Nécessite le bon mot de passe et la bonne version
💡 En cas d’informations incorrectes :
- Le fichier n’est pas déchiffré
- L’utilisateur peut réessayer avec le fichier chiffré d’origine

## ⏳ Planification de chiffrement

- Définir la date et l’heure d’exécution
- Confirmer la planification
- Entrer le chemin complet du fichier
- Entrer le mot de passe et la version
💡 Particularité importante :

- Le fichier peut ne pas exister au moment de la planification
À la date prévue :

- Si le fichier existe → chiffrement
- Sinon → message “Fichier non trouvé”

## ⏳ Planification de déchiffrement

- Même fonctionnement que le chiffrement planifié
À l’heure prévue :
- Si le fichier existe → déchiffrement
- Sinon → message “Fichier non trouvé”

## Transfert de fichier

CipherFlow System permet aux utilisateurs de transferer des fichiers entre deux ordinateur sur une connection TCP.  
Deux mode de transfert sont disponibles :

- **Envoyer un fichier** - Envoyer un fichier a un autre ordinateur.
- **Recevoir un fichier** - Attends un fichier entrant provenant d'un autre ordinateur.

### 📤 Envoyer un fichier

- Entrer l'adresse IP du receveur.
- Entrer le port d'écoute du receveur.
- Attendez jusqu'à ce que la connexion soit établie.
- Sélectionnez le fichier à envoyer.
- Partagez la clé de réception avec le destinataire.
- Attendez la fin du transfert.
**Note :** Le destinataire doit déjà être en attente d'une connexion entrante avant que l'expéditeur n'essaye de se connecter.

### 📥 Recevoir un fichier

- Choisir le port d'écoute.
- Partager votre adresse IP affiché à l'expéditeur.
- Attendez que l'expéditeur ce connecte.
- Sélectionner le dossier de destination en sélectionnant un fichier aléatoire dans ce dossier.
- Entrer la clé de réception.
- Confirmer la réception du fichier.
- Attendez jusqu'à ce que la réception soit terminé.

## 📋 Information importante à propos de File Transfer

Avant de commencé un transfer, assuré vous que:

- Les deux ordinateurs sont connecté au meme réseau ou peuvent interagir entre eux.
- Le récepteur doit lancer le processus de réception de fichier et doit être en mode réception avant que l'expéditeur ne tente de se connecté.
- Les deux cotés utiliseront le meme port TCP.
- Le récepteur doit partagé l'adresse IPv4 correct a l'expéditeur.
- Les paramètre du pare-feu doivent autorisé CipherFlow a se connecté.
