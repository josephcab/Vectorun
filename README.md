# Vectorun
 
Le jeu développé pour les 24h du Code 2025

## Présentation du jeu



## Configuration des dépendances

### Installation de stechec2

1. nstallez les prérequis.

```
apt-get install build-essential libzmq3-dev libzmqpp-dev python3-yaml \
    python3-jinja2 libgtest-dev libgflags-dev gcovr pkg-config
```

2. Récupérez le projet git stechec2 :

```
git clone https://github.com/prologin/stechec2
cd stechec2
```

3. Pour configurer et installer stechec2, il suffit d'exécuter les commandes suivantes.
```
./waf.py configure build --prefix=/usr --libdir=/usr/libdir
./waf.py install
```

### Installation des dépendances de programmation

Étape nécesaire pour permettre la génération des codes de bases dans différents langages.

```
apt-get install php-cli php-dev libphp-embed ocaml mono-devel ghc \
                openjdk-11-jdk rustc python3-dev
```

## Créer le jeu

### Configurer les fonctions et constantes

cf. stechec2.readthedocs.io

### Générer les fichiers de code

Pour ce faire, il suffit d'exécuter les commandes suivantes, et de traiter les éventuels messages d'erreur !

```
stechec2-generator rules ./vectorun.yml
mv gen/src src
```

### Compiler les règles

dans le dossier racine de stechec2, avecles règles de jeu installées dans le dossier games :

```
./waf.py configure --with-games=vectorun
./waf.py build
```


