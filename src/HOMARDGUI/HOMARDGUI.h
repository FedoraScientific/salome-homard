// Copyright (C) 2011-2013  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//

//  HOMARDGUI : HOMARD component GUI implemetation
//

#ifndef _HOMARDGUI_H_
#define _HOMARDGUI_H_

#include <SalomeApp_Module.h>
#include "SalomeApp_Study.h"

#include <SALOMEconfig.h>
#include <SALOME_LifeCycleCORBA.hxx>
#include CORBA_CLIENT_HEADER(HOMARD_Gen)
#include CORBA_CLIENT_HEADER(HOMARD_Cas)
#include CORBA_CLIENT_HEADER(HOMARD_Hypothesis)

#include <QtCore/QString>

class SalomeApp_Application;

class HOMARDGUI: public SalomeApp_Module
{
  Q_OBJECT

public:
   HOMARDGUI(const QString&);
  ~HOMARDGUI();



  virtual bool OnGUIEvent (int theCommandID);
  void    initialize( CAM_Application* );
  QString engineIOR() const;
  void    windows( QMap<int, int>& ) const;

  static HOMARD::HOMARD_Gen_var InitHOMARDGen(SalomeApp_Application* );


public slots:
    bool    deactivateModule( SUIT_Study* );
    bool    activateModule( SUIT_Study* );
    static void setOrb();

private slots:
    void OnGUIEvent();
    void EditAsciiFile();
    void LanceCalcul();
    void IterInfo();
    void NextIter();
    void YACS();
    void Edit();
    void Delete();
    void XmGraceFichier();

public:
   virtual void  contextMenuPopup( const QString&, QMenu*, QString& );


private:
   void createHOMARDAction( const int id, const QString& po_id, const QString& icon_id = QString(""),
                            const int key = 0, const bool toggle = false );
   void createActions();
   void createMenus();
   void createPopupMenus();
   _PTR(SObject)  chercheMonObjet();

   virtual void createPreferences();
   HOMARD::HOMARD_Gen_var myComponentHomard;
   SALOMEDS::Study_var       myStudy;

   int anId;
   QString _ObjectName;
};

#endif
