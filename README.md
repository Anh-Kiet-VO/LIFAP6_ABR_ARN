# LIFAP6 - TP SUR LES ABR et ARN - SERVEZ-VOUS

## Auteur :
VO Anh-Kiet p1907921

-----------------

    Dépôt contenant le code du TP7 et du TP8 de LIFAP6 en C++, réalisé dans le cadre du cours "Algorithmique, Programmation et Complexité" de la L3 Informatique de l'Université Lyon 1.

-----------------

ORGANISATION DES FICHIERS/REPERTOIRES :

    - bin : contient les fichiers exécutables compilés

    - obj : contient les compilations intermédiaires (fichiers objets .o)

    - data : les graphes des performances

    - src : contient les fichiers sources .cpp et les fichiers headers .h

    - Performance : contient, après exécution de bin/mainPerformance, les résultats des tests de performance de l'ABR et de l'ARN

    - Makefile : permet de compiler et nettoyer

    - README : ce readme.
    
-----------------

RÔLE DE CHAQUE EXECUTABLE :

    - bin/main : teste les fonctionnalités du module Arbre et du module ARN (exécute main.cpp) ;

    - bin/mainPerformance : réalise un test de performance du module Arbre et du module ARN (exécute mainPerformance) ;

-----------------

PLACEZ-VOUS A LA RACINE DU PROJET DEPUIS UN TERMINAL DE COMMANDE LINUX, PUIS :

    - POUR COMPILER : Exécutez la commande make.

    - POUR EXECUTER : Exécutez la commande make runmain (ou son équivalent bin/main) ou make runperf (ou son équivalent bin/mainPerformance), selon le programme que vous voulez exécuter.

    - POUR NETTOYER : Pour vider le dossier obj, exécutez la commande make clean.

-----------------

COMMENT FAIRE UN GRAPHIQUE VIA GNUPLOT SUR LE CMD :
gnuplot
set terminal png
set output "ARN_Performance.png"
set title "Performance de l'ARN"
plot "Performance/ARN_Performance.txt with lines, "Performance/ABR_Performance.txt" with lines
