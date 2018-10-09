# GitArc

Un projet qui va énerver vos voisins !

Une variante de Guitar Hero avec vos musiques favorites.

#cahier des charges
Le but du projet et de créer un jeu ressemblant a guitare hero en c++ avec le framework Qt. Dans un premier temps, l'application implémenteras une interface simple permettant de jouer a guitare hero sans musique. 
A l'aide des touches du clavier l'utilisateur devra appuyer au bon moment afin de correspondre au bonne note. La partion sera créer a l'avance par nous même. Un menu permettera a l'utilisateur d'intéragir avec le programme.

Dans un second temps, La partition sera généré aléatoirement et de la musique sera ajouté comme simple ambiance sonor. Des sons indiqueront également à l'utilisateur si il a appuyé au bon moment sur la note ou non.
Le menu sera amélioré et permmetera de selectionner différentes options au debut de la partie. Un menu "en-jeu" sera aussi implémenté.

Comme objectif suplémentaire, l'utilisateur pourra selectionner une de ses musiques et l'ajouter au programme. les frequences seront alors decomposés et la partion sera adapté en fonction de la musique.

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
