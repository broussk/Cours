# Projet de C++ (SET)
## Déclaration pour projet **set**

| Binôme | DUPONT Corentin, LACROIX Owen
| ---|---
| Groupe | S4F3-B

Remplir les tableaux et sections ci-dessous en fonction de ce que vous
avez réalisé.

**Attention:** toute déclaration incorrecte retire des points à votre note
finale.

## Base fonctionnelle

Pour la base des arbres c'est à dire les noeuds, étant donné que nous les avons vus en Info0401 en C nous nous sommes basés sur ça.


## Explications

Pour commencer nous avons pris ce sujet qui certes est plus difficile que le deque, mais nous n'avons vraiment pas compris le principe de celui-ci, et on voulait tout de même essayer de rendre quelque chose certes pas fonctionnel. Ce qui nous a donc conduits au choix du SET.

Donc une fois les nœuds réalisés, nous avons fait une classe AVLTree pour gérer les arbres équilibrés. Nous avons passé déjà pas mal de temps sur ça, car nous les avions jamais vus. Pour tester le fonctionnement de cette classe un main a été créé à cette occasion : main_avltree.cpp

Une fois, cela fait, nous nous sommes attaqués à la classe Set sauf que nous n'avons pas réussi à utiliser la classe AVLTree créée précédemment. On a quand même essayé de développer les méthodes contenant dans la classe Set avec les itérateurs, mais lors de leur définition dans leurs deux classes respectives, nous n'avons pas réussi.

On aimerait aussi rajouter que la difficulté du langage n'a pas facilité l'aboutissement de ce projet.

Toutes les méthodes non développées, on été mis en commentaire pour vous facilitez la lecture de celui-ci.

 **Temps passé** : ~15-20h

## Fonctionnalités générales

Les déclarations possibles sont les suivantes:
+ *fait* = réalisé ET testé.
+ *partiel* = réalisé mais ne fonctionne pas dans certains cas identifié (à préciser).
+ *bogué* = réalisé mais fonctionne pas dans des cas non identifié.
+ *non fonctionnel* = écrit mais ne fonctionne pas.
+ déclaration vide = non réalisé.

### ----------------------------------------------------------------------------

### Classe Node

| version réalisée | Déclaration |
| ---|---|
| int |-|
| template |*fait*|

| constructeur/destructeur | Déclaration |
| ---|---|
|Node() |*fait*|
|Node(T value)|*fait*|
|Node(T value, Node *parent)|*fait*|
|Node(T value, Node *parent, Node *left, Node *right)|*fait*|
|explicit Node(const Node* node) |*fait*|

| méthodes | Déclaration |
| ---|---|
|void insert(const T& value) |*fait*|
|static Node* goNextUpNode(Node* &current)|*fait*|
|static Node* goNextLeftNode(Node* &current)|*fait*|
|static Node* goNextRightNode(Node* &current) |*fait*|
|static bool hasNext(Node<T>* &current, Node<T>* &last) |*fait*|


| getters/setters | Déclaration |
| ---|---|
|T& getValue()) |*fait*|
|void setValue(T value)|*fait*|
|Node* getParent()|*fait*|
|void setParent(Node *parent) |*fait*|
|Node* getLeft() |*fait*|
|void setLeft(Node *left) |*fait*|
|Node* getRight() |*fait*|
|void setRight(Node *right) |*fait*|

### ----------------------------------------------------------------------------

### Classe AVLTree

| version réalisée | Déclaration |
| ---|---|
| int |-|
| template |*fait*|


| constructeur/destructeur | Déclaration |
| ---|---|
|AVLTree()|*fait*|
|AVLTree(const AVLTree<T> &copy)|*fait*|
|~AVLTree()|*fait*|


| méthodes (private) | Déclaration |
| ---|---|
|int getHeight(Node<T> *tree)|*fait*|
|int getBalance(Node<T> *tree)|*fait*|
|Node<T> *doubleRightRotation(Node<T> *node)|*fait*|
|Node<T> *doubleLeftRotation(Node<T> *node)|*fait*|
|Node<T> *leftRightRotation(Node<T> *node)|*fait*|
|Node<T> *rightLeftRotation(Node<T> *node)|*fait*|
|Node<T> *balance(Node<T> *tree)|*fait*|
|Node<T> *insertNode(Node<T> *tree, const T& value)|*fait*|
|void preorder(Node<T> *tree)|*fait*|
|void inorder(Node<T> *tree)|*fait*|
|void postorder(Node<T> *tree)|*fait*|
|void printTree(Node<T> *tree, int minHeight, int maxHeight)|*fait*|



| méthodes (public) | Déclaration |
| ---|---|
|void insert(const T& value) |*fait*|
|bool isBalanced() |*fait*|
|bool isEmpty()|*fait*|
|void preorder() |*fait*|
|void inorder()|*fait*|
|void postorder()|*fait*|
|void print()|*fait*|



| getters/setters | Déclaration |
| ---|---|
|Node<T> *getRoot() |*fait*|
|void setRoot(Node<T> *root)|*fait*|



### ----------------------------------------------------------------------------

### Classe Set

| version réalisée | Déclaration |
| ---|---|
| int |-|
| template | *non fonctionnel* |

| constructeur/destructeur | Déclaration |
| ---|---|
|set()|*fait*|
|set( const Compare& comp )|-|
|template< class InputIt > set( InputIt first, InputIt last, const Compare& comp = Compare())|-|
|set( const set& other )|*fait*|
|set( set&& other )|*fait*|
|set( std::initializer_list<T> init, const Compare& comp = Compare())|-|
|~set()|*bogué*|

| assignation | Déclaration
| ---|---
|set& operator=( const set& other )|*bogué*|
|set& operator=( set&& other )|*bogué*|
|set& operator=( std::initializer_list<T> ilist )|-|

| accès aux éléments | Déclaration
| ---|---
| iterator find( const T& value ) |*non fonctionnel*|
| std::pair<iterator,iterator> equal_range( const T& value ) const |-|
| iterator lower_bound( const T& value ) const |-|
| iterator upper_bound( const T& value ) const |-|

| ajout/suppression d'éléments | Déclaration
| ---|---
| std::pair<iterator,bool> insertNode( const T& value ) |*non fonctionnel*|
| std::pair<iterator,bool> insertNode( T&& value ) |-|
| template< class InputIt > void insertNode( InputIt first, InputIt last ) |-|
| void insertNode( std::initializer_list<T> ilist ) |-|
| template< class... Args > std::pair<iterator,bool> emplace( Args&&... args ) |-|
| iterator erase( const_iterator pos ) |-|
| void erase( const_iterator first, const_iterator last ) |-|
| size_t erase( const T& value ) |-|

| modification | Déclaration
| ---|---
| void clear() |*bogué*|
| void swap( set& other ) |*non fonctionnel*|
| swap (version externe) |-|

| tests | Déclaration
| ---|---
| bool operator== |*bogué*|
| bool operator!= |*bogué*|
| bool operator< |*bogué*|
| bool operator<= |*bogué*|
| bool operator> |*bogué*|
| bool operator>= |*bogué*|
| bool empty() const { return true; } |*fait*|
| bool contains( const T& value ) const |*non fonctionnel*|
| size_t size() const |*non fonctionnel*|
| size_t count( const T& value ) const |*non fonctionnel*|

| itérateurs | Déclaration |
| ---|---
| bidirectionnel | *non fonctionnel* |
| constant | *non fonctionnel* |
| inverse |-|
| inverse constant |-|

## Tests unitaires

Il n'y a aucun test unitaire, car notre SET est non fonctionnel.
