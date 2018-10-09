# GitArc

Un projet qui va énerver vos voisins !

Une variante de Guitar Hero avec vos musiques favorites.

# Cahier des charges
Le but du projet et de créer un jeu ressemblant à guitare hero en c++ avec le framework Qt. Dans un premier temps, l'application implémentera une interface simple permettant de jouer à guitare hero sans musique. 
A l'aide des touches du clavier l'utilisateur devra appuyer au bon moment afin de correspondre aux bonnes notes. La partion sera créée à l'avance par nous-même. Un menu permettera à l'utilisateur d'intéragir avec le programme.

Dans un second temps, La partition sera générée aléatoirement et de la musique sera ajoutée comme ambiance sonore. Des sons indiqueront également à l'utilisateur si il a appuyé au bon moment sur la note ou non.
Le menu sera amélioré et permmetera de sélectionner différentes options au debut de la partie. Un menu "en-jeu" sera aussi implémenté.

Comme objectif suplémentaire, l'utilisateur pourra sélectionner une de ses musiques et l'ajouter au programme. les fréquences seront alors decomposées et la partion sera adaptée en fonction de la musique.

# Fonctionnalités

## Interfaces

### Menu start
* [ ] Bouton jouer
* [ ] Bouton options
* [ ] Bouton quitter

### Menu option (en option)
* [ ] Choix de la difficulté
* [ ] Choix du nombre de notes jouables
    
### Le jeu
* [ ] Background qui change entre les parties
* [ ] Bande des notes (partition)
* [ ] Les notes
    1. Dessinnées selon une partition connue à l'avance
    2. Générées aléatoirement
    3. Générées selon une analyse d'une musique choisie par l'utilisateur
* [ ] Le score
* [ ] Animation (les notes qui explosent)
* [ ] Menu pause

### Menu pause (en jeu)
* [ ] Bouton quitter
* [ ] Bouton reprendre

## Interaction homme-machine
* [ ] Lire les entrées au clavier
    * [ ] Attribuer un score selon la justesse des notes
    * [ ] Emettre un son 
* [ ] Ouvrir le bon menu

# Auteurs
Romain Capocasale, Vincent Moulin, Jonas Freiburghaus
