# Projet info0402

Il s'agit d'écrire une classe de conteneur similaire à celle de la STL (voir chapitre 8) avec l'ensemble des fonctionnalités indiquées, et de tester cette classe de manière intensive.

L'ensemble des conteneurs devront au minimum respecter les spécifications des conteneurs de la STL, fournir des itérateurs permettant aux maximums d'algorithmes possibles de fonctionner sur le conteneur.

  * Sujet 1: deque
  * Sujet 2: set
  * Sujet 3: map

Ces sujets sont ordonnés par difficulté. La note tiendra compte cette difficulté.

Vous devez choisir parmi l'un des sujets 1 à 3.

## Travail à réaliser:

### Implémentation d'un conteneur

En se basant sur la documentation du conteneur équivalent de la STL, implémenter le conteneur qui vous a été attribué tel que:
  1. Il soit écrit en version générique (template),
  2. Il n'utilise pas d'allocateur spécifique (contrairement à la version de la STL),
  3. Les fonctionnalités à implémenter sont dans le fichier d'entête fourni, voir [deque.h](deque/deque.h) pour deque, [set.h](set/set.h) pour set et [map.h](map/map.h) pour map. Un version non template (avec des entiers et aussi disponible si vous avez, pour commencer, des problèmes avec les templates).
  4. Il définit les mêmes types d'itérateurs (on pourra ne pas implémenter les versions const). Voir le TD correspondant et [](http://www.cs.northwestern.edu/%7Eriesbeck/programming/c++/stl-iterator-define.html).

Ce projet s'intéresse à la construction d'un boite C++ implémentant ce type de stockage de données, et non aux problèmes algorithmiques associés.

Obligatoirement, la structure interne du conteneur:
* pour **deque** , devra être un tableau 2D (un tableau de pointeurs pointant sur des tableaux ayant tous exactement la même taille).
* pour **set** et **map** , devra être un arbre binaire équilibré.
Si cette contrainte n'est pas respectée, la note sera de 0.

Si vous le souhaitez, vous pouvez utiliser une code de base en langage C implémentant déjà le type de structure de données interne associé à votre conteneur. Dans ce cas, le code source duquel vous êtes parti sera fourni avec le projet. L'utilisation d'un code de base en C++ est interdite (note = 0 sinon).

Toutes les fonctions d'allocation devront obligatoirement utiliser les fonctions d'allocation du C++ (à savoir new et delete). Donc, malloc et free ne seront jamais, et à aucun endroit, utilisés dans le code rendu (y compris dans l'adaptation de la base en C que vous utilisez).

### Tests

L'ensemble des méthodes implémentées devront être testées avec des types concrets (au minimum int, classe A du TP N°7).

On utilisera le différentiel des compteurs de la classe A pour vérifier que la méthode fonctionne bien comme supposé (en particulier lors des copies, déplacements, ajout d'éléments, ...).

Alternativement, on pourra également faire des tests unitaires avec catch (voir répertoire catch qui donne un exemple de tests unitaires sur vector).

En cas de doute, le fonctionnement de votre conteneur pourra être comparé à celui de la bibliothèque standard.

### Rapport

Le rapport sera rédigée dans une page html contenant une déclaration de toutes les méthodes implémentées et testées.  
Un table de déclaration du travail réalisé y sera intégrée (à savoir pour toutes les méthodes et itérateurs définis dans le fichier d'entête fourni, ce qui a été fait, ce qui fonctionne ou pas, ...).  

### Réalisation, évaluation et soutenance

Les trois dernières séances de TP devront être consacrés à ce projet. Il requiert évidemment plus que ce temps pour être réalisé. Il est conseillé de commencer le projet pendant les vacances d'hivers.

Le projet doit être réalisé en binôme. Pour tout code partagé, les binômes concernés verront leurs notes divisés par le nombre de binômes avec lequel il a été partagé.

### Remise des sources et soutenance

La soutenance aura lieu lors de la semaine des examens. Un planning de soutenance sera mis en place environ une dizaine de jours avant. Le code et le rapport devront être placés 24h avant la soutenance. dans un dépot qui sera créé à cet effet sur [cours.univ-reims.fr](https://cours.univ-reims.fr/course/view.php?id=1664).  

Lors de la soutenance, vous serez questionné sur le code remis. Aussi, si vous rendez un code qui n'est pas le votre, il vous sera impossible de répondre aux questions qui seront posées, ce qui conduira nécessairement à la note de 0.

Également, si vous utilisez des extraits de code donnés en TP, vous devez donc absolument comprendre leurs sens.

Année universitaire 2020-2021 : version du 22 février 2021.
