.. _regles:

R�gles
######

Quel que soit le mode d'utilisation retenu, des r�gles g�n�rales sont � suivre dans la constitution des donn�es. Elles sont d�taill�es ici.

Le maillage initial
*******************
.. index:: single: maillage;initial

Le maillage comporte des noeuds, des mailles-points, des segments, des triangles, des quadrangles, des t�tra�dres, des hexa�dres et/ou des penta�dres. Il peut �tre de degr� 1 ou 2. Il peut �tre en plusieurs morceaux, non connexe.
On peut tout � fait traiter des maillages qui m�lent des zones maill�es en volume, et des zones maill�es en surfaces. Ces zones peuvent �tre adjacentes ou non.
Au cours du processus de raffinement, il n'y a pas de r�gularisation du maillage. Il faut donc veiller � ce que le maillage initial soit le plus r�gulier possible. Un mauvais maillage initial produira de mauvais maillages d�coup�s. En revanche, ce maillage initial peut �tre grossier. Il suffit qu'il respecte a minima les conditions initiales.
Enfin, il est souhaitable de poss�der d�s le d�part une bonne repr�sentation des fronti�res courbes. Le d�coupage des mailles de bord se faisant sur l'approximation de la fronti�re par le maillage initial, il n'y aura pas toujours un suivi tr�s fin de courbes accentu�es. N�anmoins, pour rem�dier � cela, un module sp�cifique de suivi de fronti�res 1D ou 2D est disponible.

Les conditions aux limites et les sources
*****************************************
.. index:: single: conditions aux limites

La d�finition des endroits o� s'appliquent des conditions aux limites ou des termes source doit �tre faite sur des entit�s de m�me dimension que le ph�nom�ne repr�sent�. En clair, cela signifie qu'un chargement ponctuel sera d�fini sur un noeud. Dans un calcul 2D, la d�finition des comportements sur les bords se fera par des caract�risations des segments de bord et non pas par les noeuds de bords. De m�me en 3D, les comportements sur les parois externes du domaine � mod�liser sont �tablis sur les triangles ou les quadrangles qui constituent ce bord. En proc�dant ainsi, on est s�r de propager correctement ces d�finitions au fil des raffinements de maillage.

Il ne faut surtout pas d�finir les conditions aux limites par les noeuds, sinon il est impossible de repr�senter correctement les fronti�res apr�s adaptation. Cela va �tre d�montr� sur l'exemple suivant.

.. image:: ../images/cl_0.gif
   :align: center
   :width: 201
   :height: 110

On veut mod�liser ici un cas de m�canique des fluides pour lequel un �coulement entre puis sort d'une cavit�. Le mod�le est bidimensionnel et, classiquement, on d�finit les conditions aux limites par des caract�risation des noeuds. Sur le zoom dessin� ci-dessous, on a les noeuds rouges pour la paroi et les noeuds bleus pour l'entr�e, les noeuds noirs �tant des noeuds libres.

.. image:: ../images/cl_1.gif
   :align: center
   :width: 372
   :height: 119

S'il s'av�re que le maillage a besoin de d�coupage autour de la zone d'entr�e, il va y avoir cr�ation de nouveaux noeuds. Tout le probl�me va consister � savoir � quelle cat�gorie appartient un nouveau noeud situ� entre un noeud de paroi ou un noeud d'entr�e. Si, comme sur le sch�ma de gauche, on privil�gie la paroi, tout va bien. En revanche si, comme sur le sch�ma de droite, on privil�gie l'entr�e, il y a un probl�me : cela revient � agrandir artificiellement l'entr�e ... et donc � fausser le calcul !

|cl_2| Paroi ------------------------------ Entr�e |cl_3|

.. |cl_2| image:: ../images/cl_2.gif
   :align: middle
   :width: 244
   :height: 129


.. |cl_3| image:: ../images/cl_3.gif
   :align: middle
   :width: 244
   :height: 128

G�rer les priorit�s entre les informations devient tr�s rapidement impossible : il faudrait �tablir des conventions uniques pour tous les logiciels de calcul associ�s � HOMARD et traiter une combinaison importante de possibilit�s. Qui plus est, en 3D, cette technique de gestion de priorit�s aboutit � des impasses. Essayez d'imaginer la mise � jour des caract�risations des noeuds issus du d�coupage des t�tra�dres dans l'angle de ce domaine. Tr�s rapidement, il devient impossible de trancher entre le bleu, le rouge ou le vert.

.. image:: ../images/cl_4.gif
   :align: center
   :width: 470
   :height: 201

La seule solution viable consiste � d�finir les conditions aux limites sur les mailles de bord. Pour reprendre notre exemple 2D en m�canique des fluides, on donne les caract�ristiques paroi ou entr�e aux ar�tes de bord. Dans le logiciel de calcul, le programme saura transf�rer tr�s facilement des ar�tes vers les sommets frontaliers.

.. image:: ../images/cl_5.gif
   :align: center
   :width: 372
   :height: 119

Si le raffinement du maillage a lieu comme pr�c�demment, les nouvelles ar�tes prennent la m�me caract�risation que celles dont elles sont issues : une ar�te de paroi d�coup�e donne naissance � deux ar�tes de paroi et une ar�te d'entr�e d�coup�e donne naissance � deux ar�tes d'entr�e. De ce fait, le logiciel de calcul n'a aucune difficult� � �tablir les bonnes informations sur les noeuds frontaliers.

.. image:: ../images/cl_6.gif
   :align: center
   :width: 244
   :height: 129

La strat�gie d'adaptation
*************************

On a le choix entre plusieurs types de raffinement et de d�raffinement :

    * en filtrant les indications d'erreur par des seuils pr�d�finis : toutes les mailles qui portent une erreur sup�rieure � un seuil haut sont d�coup�es et toutes celles pour lesquelles l'erreur est inf�rieure � un seuil bas sont d�raffin�es. Ensuite, d'autres d�coupages interviennent jusqu'� ce que le maillage soit conforme.
    * en filtrant les indications d'erreur par des seuils d�pendant de la r�partition de l'erreur : toutes les mailles qui portent une erreur sup�rieure � un d�calage par rapport � la moyenne sont raffin�es. Ensuite, d'autres d�coupages interviennent jusqu'� ce que le maillage soit conforme.
    * en filtrant avec des pourcentages de mailles : on d�coupe les x% de mailles � la plus forte erreur et on d�raffine les y% � la plus faible erreur.
    * en n'utilisant que la fonction de raffinement, avec filtrage par rapport � un seuil haut.
    * inversement, en n'utilisant que la fonction de d�raffinement, avec filtrage par rapport � un seuil bas.
    * raffinement uniforme ; on ne tient compte d'aucun indicateur d'erreur et le maillage est d�coup� int�gralement : chaque triangle est d�coup� en 4, chaque quadrangle est d�coup� en 4, chaque t�tra�dre est d�coup� en 8, chaque penta�dre est d�coup� en 8 et chaque hexa�dre est d�coup� en 8. Attention, le volume du maillage r�sultat peut �tre �norme ...

L'indicateur d'erreur
*********************
.. index:: single: indicateur d'erreur

La plupart du temps, l'indicateur d'erreur est un champ de valeurs r�elles d�finis par maille. C'est un des r�sultats du logiciel de calcul. La s�lection des mailles � d�couper se fait par comparaison de la valeur de l'indicateur et d'un seuil donn�.
Par rapport � ce standard, HOMARD accepte deux extensions : un indicateur d'erreur exprim� par noeud et/ou un indicateur d'erreur sous forme enti�re. Quand l'indicateur est fourni par noeud, HOMARD attribue � chaque maille la plus grande valeur d'erreur trouv�e sur les noeuds de la maille. Quand l'indicateur est sous forme enti�re, la convention retenue est que 1 correspond � une demande de raffinement, -1 correspond � une demande de d�raffinement et 0 correspond � ne rien faire.
On n'est pas oblig� de fournir une valeur sur chaque maille : si des mailles ne sont associ�es � aucune valeur, HOMARD leur attribuera une d�cision par d�faut selon les pr�f�rences retenues.

L'interpolation des champs
**************************
.. index:: single: interpolation
.. index:: single: champ

HOMARD sait mettre � jour des champs exprim�s sur le maillage. Deux cas de figure sont possibles :

    * Si le champ se pr�sente sous la forme d'un champ aux noeuds, HOMARD produira un nouveau champ aux noeuds avec la m�thode suivante. Pour un noeud pr�sent dans les deux maillages, avant et apr�s adaptation, la valeur du champ est gard�e telle quelle. Pour un nouveau noeud, la valeur du champ est obtenue par interpolation P1 ou P2 selon le degr� du maillage en fonction des valeurs sur les noeuds les plus proches.
    * Si le champ se pr�sente sous la forme d'un champ constant par maille, HOMARD produira un nouveau champ constant par maille, avec la m�thode suivante. Pour une maille pr�sente dans les deux maillages, avant et apr�s adaptation, la valeur du champ est gard�e telle quelle. Pour une maille issue d'un d�coupage, la valeur du champ est celle du champ sur la maille m�re. Pour une maille issue d'un regroupement apr�s d�raffinement, la valeur du champ est la moyenne des valeurs du champ sur les anciennes mailles filles.

Ces techniques de mise � jour sont bas�es sur des champs scalaires. Si un champ vectoriel est transmis � HOMARD par les fichiers MED, chaque composante sera trait�e comme un scalaire ind�pendant. Ensuite, le nouveau vecteur est reconstruit en rassemblant toutes ses composantes.





