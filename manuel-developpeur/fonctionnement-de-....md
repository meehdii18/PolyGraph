# Choix techniques

## CArc

Nous avons décidé de définir l'origine et la destination de nos arcs en utilisant des chaînes de caractères contenant les identifiants des sommets d'origine et de destination.

La classe est conçue pour que l'utilisateur n'y ait jamais d'accès direct.

## CSommet

Pas de choix de structure particuliers pour CSommet.

La classe est conçue pour que l'utilisateur n'y ait jamais d'accès direct.

## PGraphOrient

Nous avons choisi de définir les graphes orientés sous forme de template de classe avec pour paramètre les classe à utiliser pour les arcs et les sommets du graphe.

La classe est conçue en utilisant les classes d'arc et de sommet de façon à ce que l'utilisateur n'interagisse jamais avec ni l'un ni l'autre directement.

Pour récupérer les données du graphe, des fonctions créent des vecteurs de string afin de ne jamais faire sortir d'accès aux pointeurs en dehors de la classe.

## PGraph

Les graphes sont aussi des templates de classe avec pour paramètre les classe à utiliser pour les arcs et les sommets du graphe, et PGraph hérite de PGraphOrient.

## COperationsSurGraphe

Cette classe est statique car celà n'a pas de sens d'en créer des instances. Elle contient la fonctionnalité pour inverser le sens des arcs du graphe.

## CAffichage

Cette classe est statique car celà n'a pas de sens d'en créer des instances. Elle contient toutes les fonctions qui permettent d'afficher les graphes et leurs données.

## CParseur

Cette classe est statique car celà n'a pas de sens d'en créer des instances. Elle contient toutes kes fonctions qui permettent de parser un fichier.

## CCreateurGraphe

Cette classe est statique car celà n'a pas de sens d'en créer des instances. Elle fait le lien entre le parsage et les graphes.
