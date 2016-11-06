LibFT
======

Réimplémentation d'un sous-ensemble de la libc, avec 
quelques structures de données en plus.

Sommaire
---------
- [std](#documentation)
 - [algorithm](#algorithm)
 - [io](#io)
 - [list](#list)
 - [memory](#memory)
 - [string](#string)
- [parser](#parser)
 - [Fonctionnement](#fonctionnement)

##Notes

### Build System

Le system de build est make, le Makefile de base est completement générique,
en vue d'être utilisé dans d'autres projets, et d'intégrer plus facilement les 
projets entre eux.

Les projets doivent disposer à leur racine un dossier `config`, avec un fichier
`build_cfg.mk` qui doit contenir au moins les clés suivantes:

| Nom   | Description                                                                 |
| ----- | --------------------------------------------------------------------------- |
|NAME|Le nom du projet. Utilisé par le build system pour repérer les dépendances |
|TYPE|Le type du projet. Peut prendre pour valeur "prog" ou "lib", utilisé par le build system pour savoir comment linker le projet. |
|MODULE|Liste des modules du projet. Par défaut, tout les fichiers .c présents sousles répertoires du même nom à la racine seront compilé pour le projet.|
|OUTPUT|Nom du fichier de sortie|

En plus de ces variables **obligatoires**, les variables suivantes facultatives
sont supportées:

| Nom   | Description                                                                 |
| ----- | --------------------------------------------------------------------------- |
|INCLUDE_DIRS|Liste des répertoires à ajouter au chemin de recherche de fichiers|
|CFLAGS|Liste des flags à utiliser lors de la compilation|
|LFLAGS|Liste des flags à utiliser lors du link|
|SFLAGS|Liste des flags à utiliser commun aux deux étapes de compilation.|
|(C/L/S)FLAGS_{SYSTEM}|Liste des flags à utiliser en fonction du systeme hôte. Par exemple, CFLAGS_Darwin permet de spécifier des flags de compilation propre à une compilation sous OSX|
|{MODULE}_CC|Commande de compilation pour le module MODULE. Doit obligatoirement générer un fichier objet pour linker.|
|{MODULE}_EXT|Extension des fichiers à traiter pour le module MODULE|
|{MODULE}_INPUTPREFIX|Valeur du flag indiquant le traitement à effectuer pour le fichier d'entrée|

# Documentation

Seul les modules `std` et `parser`, compilé par défaut, sont documentés.

## std

Bibliothèque standard plus bonus.

Les fonctions sont regroupées par thèmes: `algorithm`, `io`, `list`, `memory` et
 `string`.
Sauf si explicitement écrit, toutes les fonctions exhibent un comportement indéfini
si un pointeur nul est passé en paramètre.

### algorithm

```
int ft_atoi(const char *str);
```

Prend en paramètre un pointeur vers une chaîne de caractères
représentant un nombre entier entre INT\_MIN et INT\_MAX
correspondante à la regex suivante.

`/^\s*(+|-)?[0-9]+\s*/`

Le comportement est indéfini pour toute autre type de chaîne.

***

```
char *ft_itoa(int n);
```

Prend en paramètre un entier compris entre INT\_MIN et INT\_MAX, et
renvois un pointeur vers une chaîne de caractères représentant ce
nombre.

Le pointeur devrat être passé à `free()` lorsqu'il n'est plus utilisé.

***

```
char *ft_lsitoa(long n, char *base)
```

Prend en paramètre un entier compris entre LONG\_MIN et LONG\_MAX, un
pointeur vers une chaîne qui sert de base de référence, et renvois un
pointeur vers une chaîne de caractères représentant ce nombre dans la
base donnée.

Le pointeur devrat être passé à `free()` lorsqu'il n'est plus utilisé.

Le comportement est indéfini si la base fait moins de deux caractères
de long.

***

```
char *ft_luitoa(unsigned long n, char *base)
```

Prend en paramètre un entier compris entre 0 et ULONG\_MAX, un
pointeur vers une chaîne qui sert de base de référence, et renvois un
pointeur vers une chaîne de caractères représentant ce nombre dans la
base donnée.

Le pointeur devrat être passé à `free()` lorsqu'il n'est plus utilisé.

Le comportement est indéfini si la base fait moins de deux caractères
de long.

***

```
void ft_swap_any(void *a, void *b, size_t size)
```

Échange le contenu de deux zones mémoires.

Le comportement est indéfini si `size` est grand.
Le comportement est indéfini si les zones pointés par `a` et `b` se
chevauchent et que `a != b`.

### io

Toutes les fonctions documentées dans cette section ont un équivalent 
sans le suffixe `_fd`, qui écrivent sur la sortie standard.

***

```
void ft_putchar_fd(char c, int fd)
```

Écrit un octet `c` dans le fichier décrit par `fd`.

***

```
void	ft_putendl_fd(char const *s, int fd)
```

Écrit une suite d'octets terminée par un octet nul, pointée par `s`, dans
le fichier décrit par `fd`, suivit de l'octet représentant le retour à la ligne
en code ASCII.

***

```
void	ft_putstr_fd(char const *s, int fd)
```

Écrit une suite d'octets terminée par un octet nul, pointée par `s`, dans
le fichier décrit par `fd`.

***

```
void	ft_putnbr_fd(int n, int fd)
```

Écrit une représentation du paramètre `n` dans le fichier décrit par `fd`.

### list

Cette section concerne une structure de donnée, une liste chainée.

Toutes les fonctions préfixées par `ft_` manipulent une liste
simplement chaînée.  Ces fonctions sont obsolètes et présentes que par
un soucis de compatibilité.

Les fonctions préfixées par `ftext_` manipulent une liste circulaire
doublement chainée.  C'est avec ce type que sont développé les projets
plus récents. Cette structure de donnée permet d'implementer certaines
opérations de manière plus efficace.

Toute les fonctions `ft_*` ont un équivalent `ftext_*`

***

```
void	ft_lstadd(t_list **alst, t_list *new)
```

Ajoute un élément `new` en début de la liste `alst`.

`*alst` est permis d'être nul.

***

```
void t_destructor(void *, size_t);
void ft_lstdel(t_list **alst, t_destructor del);
```

Supprime une liste. La totalité des ressources associées à la liste
sont détruites.  Prend en paramètre un pointeur vers un pointeur de
liste, qui sera affécté à 0 après déstruction pour mitiger les
problèmes de dangling pointers.  Chaque élément est passé en paramètre
à la fonction pointée par `del`, qui doit s'assurer de libérer la
totalitée des ressources associées au contenu d'un maillon de la
liste.

***

```
void				ft_lstdelone(t_list **alst, t_destructor del);
```

Supprime un élément d'une liste. La liste n'est pas réparée en cas de bris.

***

```
int t_keep(t_list *);
int t_keepup(t_list *, void *);

t_list *ft_lstfilter(t_list *lst, t_keep f);
t_list *ft_lstfilterup(t_list *lst, t_keepup f, void *up);
```

Renvois une nouvelle liste composée d'une copie superficielle (aka,
seulement les pointeurs vers les éléments sont copié, par les élements
eux-même), des éléments qui satisfont le prédicat `f`.

La version suffixé de `up` prends en paramètre un pointeur utilisateur
passé au prédicat.

Si `f` est satisfaite, alors elle renverra une valeur différente de 0.

Le comportement est indéfini si le prédicat modifie la structure de la liste,
ou modifie des éléments en dehors de celui qui lui est passé.

***

```
int t_iter(t_list *);
int t_iterup(t_list *, void *);
void ft_lstiter(t_list *lst, t_iter f);
void ft_lstiterup(t_list *lst, t_iterup f, void *up);
```

Applique un prédicat à tout les élément de la liste passé en paramètre.

La version suffixé de `up` prends en paramètre un pointeur utilisateur
passé au prédicat.

Le comportement est indéfini si le prédicat modifie la structure de la liste,
ou modifie des éléments en dehors de celui qui lui est passé.

***

```
t_list *t_gen(t_list *);
t_list *t_genup(t_list *, void *);

t_list *ft_lstmap(t_list *lst, t_gen f);
t_list *ft_lstmapup(t_list *l, t_genup f, void *up);
```

Génere une liste dont les éléments sont des transformations par `f`
des éléments de la liste passé en paramètre.

La version suffixé de `up` prends en paramètre un pointeur utilisateur
passé au prédicat.

Le comportement est indéfini si le prédicat modifie la structure de la
liste, ou modifie des éléments en dehors de celui qui lui est passé.

***

```
t_list	*ft_lstnew(void const *content, size_t content_size)
```

Crée un maillon de liste, le maillon est responsable d'une copie des données passé en paramètre.

***
```
t_list	*ft_lstnewown(void const *content, size_t content_size)
```

Crée un maillon de liste, le maillon est responsable des données passé en paramètre.

***
```
void		ft_lstpush(t_list **lst, t_list *to_add)
```

Ajoute un élément en fin de liste.

***
```
void t_af(t_list *, const t_list *);
void t_afup(t_list *, const t_list *, void*);

t_list *ft_lstreduce(t_clist *l, t_clist *init, t_af f);
t_list *ft_lstreduceup(t_clist *l, t_clist *i, t_afup f, void *u);
```

Crée un élément dont la valeur est obtenu par plis associatif-gauche (foldl).
`init` est la valeur initiale.

La version suffixé de `up` prends en paramètre un pointeur utilisateur
passé au prédicat.

Le comportement est indéfini si le prédicat modifie la structure de la
liste, ou modifie des éléments en dehors de celui qui lui est passé.

***

```
int t_lstcmp(const t_list *, const t_list *)
int t_lstcmpup(const t_list *, const t_list *, void *)

void			ft_lstsort(t_list **head, t_lstcmp cmp)
void			ft_lstsortup(t_list **head, t_lstcmpup cmp, void *u)
```

Applique un merge-sort sur la liste passée en paramètre, 
selon le prédicat de tri `cmp`.

`cmp` doit se baser sur le même concept de relation que pour le callback de la fonction standard qsort.

La version suffixé de `up` prends en paramètre un pointeur utilisateur
passé au prédicat.

Le comportement est indéfini si le prédicat modifie la structure de la
liste, ou modifie des éléments en dehors de celui qui lui est passé.

***

```
void ftext_lstsplice(t_dlist *first, t_dlist *last, t_dlist *pos);
```

Déplace une partie d'une liste délimitée par `first` et `last` et la
place avant `pos`, maillon d'une autre liste.

### memory

Les fonctions qui ne sont pas documentées ici ont des équivalents dans la bibliothèque standard.

***
```
void *ft_memalloc(size_t size);
```

Équivalent à `calloc(1, size)`

***
```
void	ft_memdel(void **ap);
```

Appelle `free()` sur le pointeur pointé par `ap`, puis lui affecte 0.
Sert principalement à mitiger les problèmes de dangling pointers.


### string

Les fonctions qui ne sont pas documentées ici ont des équivalents dans la bibliothèque standard.

***
```
void	ft_strclr(char *s)
```

Équivalent à `memset(s, 0, strlen(s))`

***
```
void	ft_strdel(char **ap)
```

Équivalent à `ft_memdel(ap)`

***
```
int	ft_strequ(char const *s1, char const *s2)
int	ft_strnequ(char const *s1, char const *s2)
```

Équivalent à `strcmp(s1, s2) == 0` et `strcmp(s1, s2) != 0`, respectivement.

***
```
int	ft_strindexof(const char *str, char c)
```

Renvoi l'indice de la première occurence de `c` dans `s`.

-1 si non-trouvé.

***

```
void	ft_striter(char *s, void (*f)(char *))
void	ft_striteri(char *s, void (*f)(unsigned, char *))
```

Applique le prédicat `f` pour chaque caractère de s.
Un pointeur est passé à `f` pour effectuer une transformation en place.

La variante suffixé de `i` passe l'indice du caractère en premier paramètre au prédicat.

***
```
char *ft_strjoin(char const *s1, char const *s2)
```

Crée une nouvelle chaîne de caractères résultante de la concaténation de s1 et s2.

Le pointeur devrat être passé à `free()` lorsqu'il n'est plus utilisé.

***
```
char *ft_strmap(char const *s, char (*f)(char))
char *ft_strmapi(char const *s, char (*f)(unsigned char))
```

Crée une nouvelle chaine issue de la transformation par-caractère de `s` par le prédicat `f`.
Le pointeur devrat être passé à `free()` lorsqu'il n'est plus utilisé.
La variante suffixé de `i` passe l'indice du caractère en premier paramètre au prédicat.

***
```
char *ft_strnew(size_t size)
```

Équivalent à `calloc(1, size)`

***
```
char	*ft_strrev(char *str)
```

Inverse une chaine en-place.

***

```
char		**ft_strsplit(char const *str, char c)
char		**ft_strsplitv(char const *str, int (*f)(int))
```

Renvoi un tableau des chaine delimitiée par le caractère `c` dans `str`.
La variante suffixée de `v` utilise le prédicat `f` pour déterminer ce qui constitue un délimiteur.

***

```
char *ft_strsub(char const *s, unsigned int start, size_t len)
```

Renvoie une copie de la sous-chaine designée par `start` et `len`.

Le comportement est non-spécifié si `start + len > strlen(s)`

***

```
char		**ft_strtok(const char *str, char c)
```

Comme `ft_strsplit` mais conserve les séparateurs successifs dans le
tableau retourné en tant qu'éléments séparés.

***

```
char		*ft_strtrim(char const *s)
```

Renvoie une copie de `s` sans les caractères d'espacement en début et fin.

## parser

Seul le fonctionnement global de cette partie de la bibliothèque, et
quelques fonctions de haut-niveau seront documentées ici.

### Fonctionnement

`parser` est un combinateur de parser, appliquant une lecture de
gauche à droite avec dérivation de gauche, parsant des languages sans
contexte.  Vous pouvez voir un parseur comme une machine qui vérifie
une entrée.

On a des combinateurs, qui prennent un ou plusieurs parser, et qui
effectuent un traitement particulier aux parseurs donnés.

Par exemple, une combinateur logique `ET` prend un ensemble de
parseurs, et les applique séquentiellement, et considere que l'entrée
est correcte si tout les parseurs qu'elle aggrege valident
l'entrée. De par ce comportement exhibé, on peut utiliser un
combinateur comme un parseur. Il y a aussi des "applicateurs", qui,
pour une entrée validée par un parseur donnée, transforme l'entrée
valide en un autre objet et le renvoie. Cela permet notemment de
construire des arbres de syntaxe, voir même d'autre parser. C'est
d'ailleurs comme ca que sont construit le parser de regex et le parser
de langue.


### Documentation

```
int		run_parser(t_parser *p, char *s, void **res)
```

Éxecute un parser `p` sur l'entrée `s`. `res` est modifié pour pointer
vers un résultat, dépendant du type parsé par le parseur.  La valeur
de retour indique un succès ou un échec. Dans le cas d'échec, `res`
pointe vers un objet d'erreur qui peut être utilisé pour obtenir un
diagnostic.

***

```
void	print_error(t_error *e, const char *i)
```

Affiche l'erreur associée à l'entrée `i`, sur la sortie standard.

***

```
t_parser	*get_parser(t_symtable *sy, char *sn)
```

Permet de récuperer un parseur qui renvois un arbre de syntaxe pour un objet nommé `sn` dans la table `sy`

***

t_langparser est synonyme de t_symtable.

```
t_langparser	*lang_parser(char *il)
```

Renvoie une table de parseur pour le langage spécifié par `il`.

La grammaire à respecter pour spécifier le langage est la suivante:

```
lang        := <statement>*;
statement   := <c_ident> ":=" <grammar> ';';
grammar     := <term> (| <grammar>)?;
term        := <factor>+;
factor      := <base> (<quantifier> | '');
quantifier  := '*' | '+' | '?';
base        := <literal> | ('(' <grammar> ')');
literal     := ('\'' . '\'') | ('"' /.*/ '"' ) | ('/' /.*/ '/');
```

c_ident est un parser d'identificateur type C.

La grammaire ci-dessus est spécifiée en utilisant la grammaire qu'elle est capable de parser. Sympa, non?

Entre autres:

- Le ET logique est spécifié en écrivant plusieurs termes successifs.
- Le OU logique utilise le caractère `|`
- Un caractère litéral est représenté entre `'`
- Une chaine caractère litérale est représenté entre `"`
- Un regex litéral est représenté entre `/`
