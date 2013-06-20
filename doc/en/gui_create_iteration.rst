.. _gui_create_iteration:

The iteration
=============
.. index:: single: iteration

La d�finition d'une iteration se fait par la donn�e des informations suivantes :

  - L'iteration pr�c�dente
  - Le nom du maillage r�sultat
  - L'hypothesis utilis�e
  - Eventuellement, le fichier du champ d'indicateurs d'erreur

.. image:: images/create_iteration_1.png
   :align: center

Name of the iteration
"""""""""""""""""""""
Un nom de cas est propos� automatiquement : Iter_1, Iter_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir �t� utilis� pour une iteration pr�c�dente.

The previous iteration
""""""""""""""""""""""
L'iteration pr�c�dente est choisie dans l'arbre d'�tude. Le nom du maillage correspondant sera affich�.

.. index:: single: mesh;result

The name of the resulting mesh
""""""""""""""""""""""""""""""
L'iteration en cours de cr�ation produira un maillage. Ce maillage sera connu sous un nom. Ce nom est fourni en le tapant dans la zone de texte. Par d�faut, on propose un nom identique � celui de l'iteration pr�c�dente.

.. index:: single: field
.. index:: single: MED

The field
"""""""""
Pour cr�er ou utiliser une hypothesis d'adaptation bas�e sur un champ exprim� sur le maillage, on doit fournir le fichier o� se trouve le champ. C'est �galement le cas si on veut interpoler des champs du maillage n au maillage n+1. Ce fichier est au format MED. Classiquement, il aura �t� produit par le logiciel de calcul avec lequel on travaille. Le nom du fichier peut �tre fourni, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.


.. image:: images/create_iteration_2.png
   :align: center

Dans le cas o� des pas de temps ont �t� d�finis, une solution simple consiste � traiter les champs au dernier pas de temps enregistr� dans le fichier. Si on veut d�finir un autre pas de temps, on coche le bouton "*Pas de temps choisi*". Les valeurs de 'Pas de temps' et de 'Num�ro d'ordre' sont celles correspondant � la convention MED (time step / rank). Ces valeurs d�pendent de la logique qui a �t� retenue par le logiciel qui a �crit le fichier. Souvent ces deux valeurs sont identiques mais il arrive que l'on disjoigne les pas de temps et les intervalles d'archivage.

.. image:: images/create_iteration_3.png
   :align: center

.. index:: single: hypothesis

The hypothesis
""""""""""""""
L'iteration en cours pilotera l'adaptation par HOMARD selon un sc�nario d�fini dans une hypothesis. Celle-ci est choisie dans la liste des hypothesiss existantes.

Au d�marrage, il faut cr�er une premi�re hypothesis par activation du bouton "*Nouveau*" (voir :ref:`gui_create_hypothese`) :

.. image:: images/create_iteration_4.png
   :align: center

Ensuite, si une hypothesis pr�c�demment d�finie convient, il suffit de la s�lectionner dans la liste propos�e. Sinon, il faut cr�er une nouvelle hypothesis par activation du bouton "*Nouveau*", puis la s�lectionner dans la liste propos�e :

.. image:: images/create_iteration_5.png
   :align: center


.. note::
  Si on envisage une adaptation selon les valeurs d'un champ sur le maillage, il faut avoir renseign� les informations sur ce champ avant de cr�er une nouvelle hypothesis.

.. index:: single: object browser

Object browser
""""""""""""""
A l'issue de cette cr�ation d'iteration, l'arbre d'�tudes a �t� enrichi. On y trouve l'iteration initiale, identifi�e par le nom du maillage qui a �t� lu dans le fichier fourni, l'iteration courante, identifi�e par son nom. On trouve aussi l'hypothesis qui lui est attach�e. L'ic�ne en regard de l'iteration permet de diff�rencier les iterations calcul�es ou non.

.. image:: images/create_iteration_6.png
   :align: center

Quand plusieurs iterations s'encha�nent, leur hypothesis est visible dans l'arbre d'�tude. On remarquera dans la figure ci-apr�s que deux iterations peuvent partager la m�me hypothesis.

.. image:: images/create_iteration_7.png
   :align: center

Corresponding python functions
""""""""""""""""""""""""""""""
Look :ref:`tui_create_iteration`
