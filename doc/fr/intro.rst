.. _intro:

Introduction
############

Pr�sentation g�n�rale
*********************
Le logiciel HOMARD est destin� � adapter les maillages dans le cadre des simulations num�riques par �l�ments ou volumes finis. Ce logiciel, r�alis� par EDF R&D, proc�de par raffinement et d�raffinement des maillages bidimensionnels ou tridimensionnels. Il est con�u pour �tre utilis� ind�pendamment du logiciel auquel il est coupl�.

Raffiner le maillage signifie d�couper des mailles d�sign�es selon des indications fournies par l'utilisateur. D�raffiner le maillage signifie revenir en arri�re sur des d�coupages pr�c�demment r�alis�s : ainsi, en aucun cas HOMARD ne peut simplifier un maillage existant qui aura �t� cr�� trop fin. Le d�raffinement prend toute son importance dans les calculs quand la zone d'int�r�t se d�place au cours du calcul : on ne tiendra plus compte de raffinements pr�c�demment r�alis�s et qui deviennent inutiles. On en trouvera une illustration au bas de cette page.

HOMARD sait traiter des maillages en 2 ou 3 dimensions et comportant les mailles suivantes :
   - mailles-points
   - segments
   - triangles
   - quadrangles
   - t�tra�dres
   - hexa�dres
   - prismes

Ces mailles peuvent �tre pr�sentes simultan�ment. Par exemple, HOMARD saura adapter un maillage comportant des triangles et des quadrangles.
Les noeuds accept�s sont �videmment les noeuds qui sont les sommets des mailles, ce qui correspond � la description classique � en degr� 1 � . Si les �l�ments sont d�crits � en degr� 2 �, les noeuds compl�mentaires sont g�r�s. En revanche, il ne peut pas y avoir cohabitation de mailles d�crites en degr� 1 et d'autres d�crites en degr� 2. Enfin, HOMARD sait prendre en compte des noeuds isol�s, qui n'appartiendraient � aucune d�finition de mailles : ils ressortiront tels quels du processus d'adaptation.

Le cas des pyramides est � part. Pour un maillage comportant des hexa�dres ou des prismes, la mise en conformit� du maillage issu du raffinement cr�e des pyramides pour assurer la liaison entre deux r�gions de niveaux de raffinement diff�rents. Ces pyramides sont g�r�es comme toutes les mailles de transition et ne sont pas red�coup�es par la suite. En revanche, si le maillage initial contient des pyramides, HOMARD ne saura pas l'adapter et �mettra un message d'erreur. Dans certains cas particuliers, on pourra n�anmoins traiter un tel maillage, comme il est d�crit dans la rubrique :ref:`options_avancees` de la cr�ation du cas.

Plusieurs motivations apparaissent pour adapter un maillage :

  - on veut simplifier la r�alisation du maillage d'une g�om�trie complexe : on part d'un maillage grossier et on confie � un processus automatique la charge de le raffiner.
  - on veut s'assurer de la convergence de la solution num�rique : plut�t que de r�aliser � la main des maillages de plus en plus fins, on laisse le logiciel chercher lui-m�me les endroits o� il faudrait affiner le maillage pour augmenter la pr�cision du r�sultat.
  - les conditions du calcul changent au cours de son d�roulement : les zones qui doivent �tre maill�es finement se d�placent. Si on maille fin partout d�s le d�but, le maillage est trop gros. En adaptant au fur et � mesure, le maillage ne sera fin qu'aux endroits n�cessaires : sa taille sera r�duite et la qualit� de la solution sera bonne.

Dans tous les cas, le principe de l'adaptation de maillage reste le m�me. Sur le maillage de d�part, on r�alise le calcul standard. Avec une analyse de la solution num�rique obtenue, on estime l'erreur qui a �t� commise par rapport � la solution r�elle. Cette estimation se repr�sente par une valeur d'indicateur d'erreur dans chaque maille du calcul. A partir de l�, on applique le principe suivant : les mailles o� l'indicateur d'erreur est fort devraient �tre plus petites et, r�ciproquement, les mailles o� l'indicateur d'erreur est faible pourraient �tre plus grandes. Avec cette information, on alimente HOMARD qui va modifier le maillage en cons�quence. Sur le nouveau maillage, on recommencera alors le calcul.

Sch�matiquement, une it�ration d'adaptation de maillage se pr�sente ainsi. Le logiciel calcule la solution num�rique sur le maillage n�k, puis en d�duit les valeurs de l'indicateur d'erreur sur tout le maillage. A partir de la connaissance du maillage n�k et de l'indicateur n�k, HOMARD cr�e le nouveau maillage n�k+1.

.. image:: images/intro_1.png
   :align: center

Au final, la cha�ne compl�te part du maillage initial, puis comprend des maillons successifs (calcul d'indicateur / adaptation). Pour des probl�mes stationnaires en temps, cela �quivaut � une succession de calculs ind�pendants sur diff�rents maillages. Pour des probl�mes transitoires, le calcul est suspendu � un instant donn� ; apr�s adaptation du maillage, le calcul est repris au m�me instant ou � un instant ant�rieur.

.. image:: ../images/intro_2.png
   :align: center

Des variantes de ce sch�ma de base sont possibles. Si aucun calcul d'erreur n'est disponible dans le logiciel coupl�, on peut utiliser un champ pour piloter l'adaptation. Un champ de contraintes en m�caniques peut �tre utilis� : raffiner l� o� les contraintes sont importantes est souvent efficace pour am�liorer la qualit� de la simulation. On peut �galement adapter en fonction du saut d'une variable d'une maille � sa voisine ou dans une zone connue a priori. Gr�ce � ses nombreuses options, HOMARD permet d'envisager de multiples sc�narios d'adaptation de maillage.

.. note::
  Pour une description plus compl�te, voir :download:`Description g�n�rale de HOMARD <../files/HOMARD_0.pdf>`.

.. note::
  Pour une r�f�rence � HOMARD, utiliser :

  G. Nicolas and T. Fouquet, Adaptive Mesh Refinement for Conformal Hexahedral Meshes, "*Finite Elements in Analysis and Design*", Vol. 67, pp. 1-12, 2013, doi:10.1016/j.finel.2012.11.008

  `Accessible en cliquant ici <http://dx.doi.org/10.1016/j.finel.2012.11.008>`_

.. index:: single: YACS

.. note::
  Cet alternance de calculs et d'adaptions est tr�s appropri�e � la mise place de sch�mas :ref:`yacs`.

Mode de d�coupage des mailles
*****************************
.. index:: single: d�coupage
.. index:: single: conformit�

Globalement le processus de maillage adaptatif par d�coupage des mailles se r�sume en deux phases. Dans la premi�re phase, on d�coupe toutes les mailles qui ont �t� d�sign�es par les indications de pilotage. Cela produit un maillage qui n'est pas conforme : des noeuds sont pendants � la jonction entre une zone � raffiner et une zone � garder.
La seconde phase vise � r�gler tous ces probl�mes de conformit�.

A ces deux phases correspondent des modes de d�coupages diff�rents.
Dans la premi�re phase, toutes les mailles sont d�coup�es de la m�me mani�re ; c'est ce que nous appelons le d�coupage standard. Dans la seconde phase, une partie des conflits de conformit� de maillage dans les zones de jonction se r�gle
par les m�mes d�coupages standard de mailles et une autre partie se r�gle par des d�coupages sp�ciaux.

Les modes de d�coupage d�crits ci-dessous ont �t� choisis pour ne pas d�t�riorer la qualit� du maillage au cours des it�rations d'adaptation.


Le d�coupage standard
=====================
Le d�coupage standard des mailles se fait en ayant pour objectif de limiter les cas de figure.
Ainsi, les ar�tes sont-elles scind�es en deux moiti�s �gales.

Pour d�couper un triangle, on d�coupe ses trois ar�tes en deux et on se trouve avec 4 triangles semblables. Ils conservent donc la m�me qualit�.

.. image:: ../images/dec_tria_1.gif
   :align: center
   :alt: D�coupage standard d'un triangle
   :width: 399
   :height: 88

Pour d�couper un quadrangle, on d�coupe ses quatre ar�tes en deux et on se trouve avec 4 quadrangles non semblables au quadrangle p�re et donc de qualit� diff�rente.

.. image:: ../images/dec_quad_1.png
   :align: center
   :alt: D�coupage standard d'un quadrangle
   :width: 399

Le d�coupage des t�tra�dres se fait en huit. Pour commencer, chacune des faces triangulaires est d�coup�e en 4 faces triangulaires semblables.

.. image:: ../images/dec_tetr_1.gif
   :align: center
   :alt: D�coupage standard d'un t�tra�dre - 1
   :width: 328
   :height: 115

Ce d�coupage des faces produit 4 t�tra�dres dans les angles du t�tra�dre initial. On remarque que ces 4 nouveaux t�tra�dres sont homoth�tiques de l'initial. Ils conservent donc la m�me qualit�.

.. image:: ../images/dec_tetr_2.gif
   :align: center
   :alt: D�coupage standard d'un t�tra�dre - 2
   :width: 201
   :height: 159

Il reste au coeur du t�tra�dre, un bloc qui a la forme de deux pyramides accol�es par leur base. On cr�e une ar�te avec l'une des 3 diagonales possibles, puis les 4 faces qui contiennent cette ar�te et deux ar�tes ext�rieures.

.. image:: ../images/dec_tetr_3.gif
   :align: center
   :alt: D�coupage standard d'un t�tra�dre - 3
   :width: 244
   :height: 74

Cela produit 4 nouveaux t�tra�dres. On notera qu'ils sont semblables deux � deux, mais qu'ils ne peuvent jamais �tre semblables au t�tra�dre initial. Ils ne pourront donc jamais avoir la m�me qualit� que lui. Toutefois, selon le choix
de la diagonale qui a servi � la d�coupe du bloc pyramidal interne, le r�sultat
n'est pas le m�me. On montre que le meilleur choix, en terme de qualit�, est celui
de la plus petite des trois diagonales possibles.

.. image:: ../images/dec_tetr_4.gif
   :align: center
   :alt: D�coupage standard d'un t�tra�dre - 4
   :width: 229
   :height: 116

Le d�coupage des hexa�dres se fait en huit. Chacune des faces quadrangulaires est d�coup�e en 4 faces quadrangulaires. 3 faces internes � l'hexa�dre sont cr��es, puis chacune est d�coup�e en 4. Cette construction cr�e 6 points suppl�mentaires au centre de chaque face externe et un point suppl�mentaire � l'int�rieur de l'hexa�dre.

.. image:: ../images/dec_hex.png
   :align: center
   :alt: D�coupage standard d'un hexa�dre
   :scale: 70

Le d�coupage des penta�dres se fait en huit. Chacune des faces quadrangulaires est d�coup�e en 4 faces quadrangulaires de mani�re standard, de m�me pour les faces triangulaires. On construit trois ar�tes internes chacune parall�le � une des faces quadrangulaires au milieu du penat�dre. On construit ensuite 4 faces triangulaires s'appuyant sur ces ar�tes et correspondant au d�coupage standard d'une face triangulaire � l'int�rieur du penta�dre. Six faces quadrangulaires internes sont cr��es deux � deux parall�les � chaque face quadrangulaire du penta�dre.

.. image:: ../images/dec.pent.png
   :align: center
   :alt: D�coupage standard d'un penta�dre
   :scale: 20

Le d�coupage de mise en conformit�
==================================

Le d�coupage de mise en conformit� s'appliquent aux mailles � l'interface entre deux niveaux de raffinement diff�rent.
Ces d�coupages produisent des mailles de qualit� moindre par rapport aux mailles et on voit dans l'algorithme g�n�ral comment cet inconv�nient est pris en compte pour en minimiser les cons�quences.

Etant donn� notre algorithme de maillage adaptatif, seules les quatre situations suivantes peuvent �tre rencontr�es :

Dans le cas d'un triangle, l'une de ses trois ar�tes est coup�e en deux. On joint son milieu au sommet oppos� pour former deux nouveaux triangles.

.. image:: ../images/dec_tria_2.gif
   :align: center
   :alt: D�coupage de conformit� d'un triangle
   :width: 399
   :height: 88

Dans le cas d'un quadrangle, l'une de ses quatre ar�tes est coup�e en deux. On joint son milieu aux deux sommets oppos�s pour former trois triangles. Le maillage adapt� obtenu est donc mixte.

.. image:: ../images/dec_quad_2.png
   :align: center
   :alt: D�coupage de conformit� d'un quadrangle
   :width: 399

Pour un t�tra�dre dont trois des ar�tes sont coup�es : cela n'est possible que si ces ar�tes sont sur la m�me face. Cette face est donc coup�e en quatre. On joint les milieux des ar�tes d�coup�es au sommet oppos�. Cela coupe en deux les trois autres faces et il y a cr�ation de 4 t�tra�dres.

.. image:: ../images/dec_tetr_5.gif
   :align: center
   :alt: D�coupage de conformit� d'un t�tra�dre - 1
   :width: 116
   :height: 116

Pour un t�tra�dre dont deux des ar�tes sont coup�es : cela n'est possible que si ces ar�tes sont oppos�es. On fait toutes les jonctions entre les milieux de ces ar�tes et les autres sommets, ainsi que entre les deux milieux d'ar�tes. Les quatre faces sont coup�es en deux et il y a cr�ation de 4 t�tra�dres.

.. image:: ../images/dec_tetr_6.gif
   :align: center
   :alt: D�coupage de conformit� d'un t�tra�dre - 2
   :width: 116
   :height: 116

Pour un t�tra�dre dont une des ar�tes est coup�e : on joint le milieu de cette ar�te d�coup�e au sommet oppos� et il y a cr�ation de 2 t�tra�dres.

.. image:: ../images/dec_tetr_7.gif
   :align: center
   :alt: D�coupage de conformit� d'un t�tra�dre - 3
   :width: 116
   :height: 116

La conformit� des hexa�dres est assur�e par des combinaisons de t�tra�dres et de pyramides. Les situations d�pendent du nombre de non-conformit�s.

Pour un hexa�dre dont une face est coup�e il y a cr�ation de 4 ar�tes, de 4 t�tra�dres et de 5 pyramides.

.. image:: ../images/hexaface.png
   :align: center
   :alt: D�coupage de conformit� d'un hexa�dre - 1 face
   :width: 384
   :height: 101

Pour un hexa�dre dont une seule ar�te est coup�e il y a cr�ation de deux ar�tes et de 4 pyramides.

.. image:: ../images/hexa1arete.png
   :align: center
   :alt: D�coupage de conformit� d'un hexa�dre - 1 ar�te
   :width: 384
   :height: 101

Pour un hexa�dre dont deux ar�tes sont coup�es il y a cr�ation  d'un point central, de 10 ar�tes, de 12 t�tra�dres et de 2 pyramides.

.. image:: ../images/hexa2aretes.png
   :align: center
   :alt: D�coupage de conformit� d'un hexa�dre - 2 ar�tes
   :width: 384
   :height: 101

Pour un hexa�dre dont trois ar�tes sont coup�es il y a cr�ation  d'un point central, de 11 ar�tes et de 18 t�tra�dres.

.. image:: ../images/hexa3aretes.png
   :align: center
   :alt: D�coupage de conformit� d'un hexa�dre - 3 ar�tes
   :width: 384
   :height: 101



L'algorithme
************
.. index:: single: algorithme

La strat�gie retenue dans les algorithmes d'HOMARD consiste � forcer le d�coupage en quatre pour toutes les faces triangulaires ou quadrangulaires pr�sentant deux points de non conformit�. A la fin, les seuls triangles ou quadrangles pr�sentant des points de non conformit� sont des faces o� une ar�te et une seule est d�coup�e. La mise en conformit� est
alors assur�e par la solution la plus simple possible comme vu ci-avant.
Cette derni�re �tape de mise en conformit� introduit des mailles dont la qualit� peut �tre plus faible que celle
des mailles dont elles sont issues. Cet inconv�nient est contr�l� car nous avons choisi de donner un statut temporaire
� ces mailles de mise en conformit� : elles sont pr�sentes pour produire un maillage acceptable par les logiciels
de calcul, mais disparaissent s'il y a besoin de les d�couper ult�rieurement.
Ainsi, la modification de qualit� ne se propage pas au fil des it�rations d'adaptation de maillage et reste limit�e autant en valeur qu'en nombre de mailles concern�es.

L'algorithme g�n�ral est donc le suivant :

    * Transfert des indications de raffinement ou de d�raffinement des mailles en d�cisions de d�coupage ou de regroupement d'ar�tes, de triangles et de quadrangles.
    * Suppression des mailles temporaires de mise en conformit�.
    * Par examen de tous les triangles et quadrangles du niveau de d�coupage le plus bas vers le niveau le plus haut, r�glement des conflits sur le d�raffinement au moyen des r�gles de base.
    * Par examen de tous les triangles et quadrangles du niveau de d�coupage le plus haut vers le niveau le plus bas, r�glement des conflits sur le raffinement au moyen des r�gles de base.
    * Cr�ation effective du nouveau maillage : d�coupage standard, suivi de mise en conformit�.


Quelques illustrations de maillage adapt�s
******************************************
.. index:: single: illustration

On pourra trouver des exemples d'utilisations de l'adaptation de maillage sur le site de `HOMARD <http://www.code-aster.org/outils/homard/fr/applications.html>`_

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

