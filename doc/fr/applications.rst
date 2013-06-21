.. _gui_applications:

.. index:: single: application
.. index:: single: illustration

Applications
============
On trouvera ici des exemples d'applications d'adaptation de maillage avec HOMARD.

Quelques illustrations de maillage adapt�s
""""""""""""""""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_3.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_4.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_5.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_6.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_7.png                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+
|                                                               |
| .. image:: ../images/intro_8.gif                              |
|    :align: center                                             |
|                                                               |
+---------------------------------------------------------------+

M�canique non lin�aire
""""""""""""""""""""""

La pi�ce est encastr�e sur sa gauche. On appuie sur le haut de la seconde bosse, avec un chargement variant au cours du temps. Le v�ritable bord de la pi�ce est arrondi. Sur le maillage initial, ce bord est tr�s grossi�rement repr�sent�. Au fil des adaptations, quand le maillage est raffin� sur le bord, on place les nouveaux noeuds sur le v�ritable bord. Ainsi, la g�om�trie est respect�e au plus proche.


Ce calcul est r�alis� avec Code_Aster. La loi utilis�e est Von Mises isotrope. Le transitoire dure 480 s, avec un pas de temps de 3s. Il est d�coup� en 32 calculs. Le calcul num�ro k va de t=0 � t=15*k s. Le maillage est adapt� � l'instant final, t=15*k s. Puis on reprend � partir de 0. Cette strat�gie permet de produire un maillage adapt� � tous les instants du transitoire et de n'avoir aucune interpolation � faire.

.. image:: ../images/appli_01.gif
   :align: center

