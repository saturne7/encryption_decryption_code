# Mini Projet C

Barrières Mathieu / Devienne-Ousmer Julien

L'objectif de l'application que nous avons développée est de lire un message entré par
l'utilisateur de celle-ci, crypter ce message avec un algorithme de chiffrement
(pour nous c'est celui de César), et déchiffrer ensuite ce message. 
Le code que nous avons écrit ne chiffre pas les accents, mais il est capable de crypter
lettres majuscules et minuscules, ponctuation et chiffres.

Les fonctions et leur documentation :


1/	
La fonction dont la signature est : void crypt(char * message, int key, char * messageCode);
a comme paramètres d'entrées un tableau de caractère pour le message entré par l'utilisateur,
un entier qui désigne la clé de chiffrement, et un tableau de caractère pour le message codé.
Elle permet de lire le message entré par l'utilisateur, le mettre dans un tableau de caractère et coder ce
tableau de caractère à l'aide de la clé de chiffrement.

Cas d'erreur n°1: Lorsque l'on met un seul caractere dans la fonction d'affichage main
affiche de nouveaux caractères apparaissent sur un nouvelle ligne.

Cas d'erreur n°2: Lorsque l'on crypte un message, il se peut que quelque fois le message
d'erreur "Segmentation fault (core dumped)" apparaisse mais crypte quand même le message.


2/
La fonction dont la signature est : void decrypt(char * messageCode, int key, char * messageOriginel);
a comme paramètres en entrées un tableau de caractère pour le message codé, un entier qui désigne la clé de chiffrement,
et un tableau de caractère pour le message décodé.
Elle permet de décrypter le message codé à l'inverse de la fonction "crypt".

3/
La fonction dont la signature est : int verifierMessage(char * message);
a comme paramètre d'entrée un tableau de caractère avec le message d'origine
et comme paramètre de sortie un entier égal à 0 ou un chiffre > 1 (pas un booléen car sa valeur doit être stockée et non seulement renvoyée).
Elle permet de vérifier que tous les caractères entrés par l'utilisateur sont bien chiffrables.


URL du GIT utilisé pour le projet :

https://framagit.org/JulienDevienne-Ousmer/mini-projet-c






















