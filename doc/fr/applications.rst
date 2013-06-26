.. _applications:

.. index:: single: application
.. index:: single: illustration

Applications
============
On trouvera ici des exemples d'applications d'adaptation de maillage avec HOMARD.

M�canique non lin�aire
""""""""""""""""""""""

La pi�ce est encastr�e sur sa gauche. On appuie sur le haut de la seconde bosse, avec un chargement variant au cours du temps. Le v�ritable bord de la pi�ce est arrondi. Sur le maillage initial, ce bord est tr�s grossi�rement repr�sent�. Au fil des adaptations, quand le maillage est raffin� sur le bord, on place les nouveaux noeuds sur le v�ritable bord. Ainsi, la g�om�trie est respect�e au plus proche.


Ce calcul est r�alis� avec `Code_Aster <http://www.code-aster.org>`_. La loi utilis�e est Von Mises isotrope. Le transitoire dure 480 s, avec un pas de temps de 3s. Il est d�coup� en 32 calculs. Le calcul num�ro k va de t=0 � t=15*k s. Le maillage est adapt� � l'instant final, t=15*k s. Puis on reprend � partir de 0. Cette strat�gie permet de produire un maillage adapt� � tous les instants du transitoire et de n'avoir aucune interpolation � faire.

.. image:: ../images/appli_01.gif
   :align: center

Des hexa�dres en m�canique
""""""""""""""""""""""""""

La pi�ce repr�sente un piton encastr� dans un mur. On suspend une charge au crochet � droite.
L'adaptation a entra�n� la cr�ation de nouveaux hexa�dres ainsi que des t�tra�dres et des pyramides
dans les zones de transition entre les diff�rents niveaux de raffinement. Ce calcul est r�alis� avec `Code_Aster <http://www.code-aster.org>`_.

Niveau 0 :
----------

.. image:: ../images/appli_02.a.png
   :align: center
   :scale: 50

Niveau 9 :
----------

.. image:: ../images/appli_02.b.png
   :align: center
   :scale: 50

Convection d'un polluant
""""""""""""""""""""""""

Cet exemple simule le passage d'un polluant dans un courant d'eau.
L'�coulement entre dans la structure en bas � gauche, monte pour contourner l'obstacle, puis sort en bas � droite.


On sait que dans ce genre de calculs, la difficult� r�side dans la pr�cision du calcul autour du polluant transport�.
Gr�ce � l'adaptation de maillage avec HOMARD, � chaque instant, le maillage est optimal dans les zones d�licates. On constate en effet que le maillage se raffine en amont de la pr�sence du polluant. Ce maillage reste fin au centre de la zone � forte concentration en polluant, pour am�liorer la pr�cision du calcul dans cette zone. Enfin le maillage est d�raffin� � l'arri�re, une fois que le polluant est pass�.

.. image:: ../images/appli_03.gif
   :align: center

Stratification thermique
""""""""""""""""""""""""

Cet exemple simule une stratification thermique dans un courant d'eau.
L'�coulement entre dans la structure en haut � gauche, descend, puis sort en haut � droite. Par suite de diff�rences de temp�rature, la masse volumique du fluide n'est pas identique partout ; la gravit� cr�e ainsi des strates dans le fluide.

L'adaptation de maillage permet d'affiner le maillage dans les zones de fort gradient thermique.
Sur la figure ci-contre, on peut voir le trac� du maillage colori� par le niveau de temp�rature, jusqu'� l'�tablissement d'un
r�gime permanent.

.. image:: ../images/appli_04.gif
   :align: center

