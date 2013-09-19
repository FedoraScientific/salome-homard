Exemples
========
.. index:: single: exemple
.. index:: single: python

On trouvera ici les instructions python pour quelques configurations caract�ristiques. Les fichiers de donn�es associ�s sont t�l�chargeables. Il faut penser � adapter la valeur de la variable ``data_dir`` : c'est le r�pertoire dans lequel les fichiers med auront �t� enregistr�s.
C'est dans le r�pertoire ``dircase`` que seront �crits les fichiers r�sultant des adaptations successives. Ce r�pertoire est cr�� par d�faut dans ``/tmp``.

Chargement du module HOMARD
"""""""""""""""""""""""""""
.. index:: single: yacs

Le chargement du module HOMARD se fait de mani�re analogue aux autres modules.

 ::

  import HOMARD
  homard = salome.lcc.FindOrLoadComponent('FactoryServer','HOMARD')
  homard.SetCurrentStudy(salome.myStudy)

Pour utiliser le module HOMARD au sein d'un sch�ma YACS distribu�, le chargement se fait ainsi :

 ::

  import HOMARD
  my_container.load_component_Library('HOMARD')
  homard = my_container.create_component_instance('HOMARD',0)
  homard.SetCurrentStudy(salome.myStudy)

Raffinement uniforme
""""""""""""""""""""
.. index:: single: raffinement;uniforme

On fera ici trois raffinements uniformes successifs du maillage contenu dans le fichier ``tutorial_1.00.med``. Quelques remarques :
  * la m�me hypoth�se est utilis�e � chaque it�ration
  * le maillage produit porte toujours le m�me nom. Cela ne pose pas de probl�me car il est stock� dans des fichiers diff�rents.

.. literalinclude:: ../files/tutorial_1.py
   :lines: 57-89

.. note::
  T�l�chargement des fichiers

  * :download:`maillage initial<../files/tutorial_1.00.med.gz>`
  * :download:`commandes python<../files/tutorial_1.py>`


Raffinement par des zones
"""""""""""""""""""""""""
.. index:: single: zone

On proc�de ici au raffinement selon des zones. Pour passer du maillage initial au maillage 'M_1', on utilise une bo�te encadrant le plan z=1 et une sph�re centr�e sur l'origine de rayon 1.05. Puis pour passer du maillage 'M_1' au maillage 'M_2', on remplace la sph�re par une bo�te encadrant le cube de c�t� 0.5, pointant sur l'origine. On notera que le type de raffinement n'a pas �t� pr�cis� ; par d�faut, il sera donc conforme.

.. literalinclude:: ../files/tutorial_2.py
   :lines: 57-101

.. note::
  T�l�chargement des fichiers

  * :download:`maillage initial<../files/tutorial_2.00.med.gz>`
  * :download:`commandes python<../files/tutorial_2.py>`


Raffinement selon un champ
""""""""""""""""""""""""""
.. index:: single: champ

On proc�de ici au raffinement selon un champ. Les hypoth�ses servent � d�finir le nom du champ et les seuils de raffinement/d�raffinement. La donn�e du fichier et des instants est faite dans l'it�ration. Des champs sur les noeuds ou sur les mailles sont interpol�s.
Pour adapter le maillage H_1 issu de l'it�ration Iter_1, deux variantes sont appliqu�es. Dans la premi�re, Iter_2, le champ est un champ scalaire d'indicateurs d'erreur et on d�coupe les 1.5% de mailles o� l'erreur est la plus grande. Dans la seconde variante, Iter_2_bis, on se base sur un champ vectoriel et on examine le saut de ce vecteur entre une maille et ses voisines : on d�coupera l� o� la norme infinie de ce saut est sup�rieure au seuil absolu de 0.0001.

.. literalinclude:: ../files/tutorial_3.py
   :lines: 57-131

.. note::
  T�l�chargement des fichiers

  * :download:`maillage et champ �tape 0<../files/tutorial_3.00.med.gz>`
  * :download:`maillage et champ �tape 1<../files/tutorial_3.01.med.gz>`
  * :download:`commandes python<../files/tutorial_3.py>`


Suivi de fronti�res courbes
"""""""""""""""""""""""""""
.. index:: single: champ
.. index:: single: yacs

On teste ici le suivi des fronti�res courbes : des fronti�res analytiques pour d�crire les diff�rentes surfaces des tuyaux et une fronti�re discr�te pour d�crire les lignes d'intersection des deux tuyaux. Le pilotage du raffinement est le suivant : raffinement uniforme de toutes les mailles contenues dans des groupes d�sign�s. On commence par raffiner les faces internes aux tuyaux ; ensuite, on raffine deux fois de suite les faces externes aux tuyaux.
Le sch�ma YACS r�alisant cette adaptation est t�l�chargeable.

.. literalinclude:: ../files/tutorial_4.py
   :lines: 57-115

.. note::
  T�l�chargement des fichiers

  * :download:`maillage initial<../files/tutorial_4.00.med.gz>`
  * :download:`maillage de la fronti�re discr�te<../files/tutorial_4.fr.med.gz>`
  * :download:`commandes python<../files/tutorial_4.py>`
  * :download:`sch�ma YACS<../files/tutorial_4.xml>`


Instructions sp�cifiques au 2D
""""""""""""""""""""""""""""""
.. index:: single: 2D

Les instructions pour adapter un maillage 2D sont exactement identiques � celles n�cessaires � l'adaptation d'un maillage 3D. La seule exception concerne le raffinement selon des zones g�om�triques : des fonctions diff�rentes sont utilis�es pour pouvoir d�finir des zones 2D. On donne alors les coordonn�es 2D des zones, en pr�cisant l'orientation du plan du maillage.
Dans le cas pr�sent� ici, on raffine une premi�re fois toutes les mailles contenues dans un disque perc�, puis dans une seconde it�ration, toutes les mailles contenues dans un rectangle. On notera l'utilisation du suivi des fronti�res circulaires du domaine.

.. literalinclude:: ../files/tutorial_5.py
   :lines: 57-101

.. note::
  T�l�chargement des fichiers

  * :download:`maillage initial<../files/tutorial_5.00.med.gz>`
  * :download:`maillage de la fronti�re discr�te<../files/tutorial_5.fr.med.gz>`
  * :download:`commandes python<../files/tutorial_5.py>`


.. toctree::
   :maxdepth: 2
