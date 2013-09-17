// #Copyright (C) 2011-2013  CEA/DEN, EDF R&D
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

using namespace std;

#include "MonCreateBoundaryAn.h"
#include "MonCreateCase.h"

#include <QFileDialog>
#include <QMessageBox>

#include "SalomeApp_Tools.h"
#include "HOMARDGUI_Utils.h"
#include "HomardQtCommun.h"
#include <utilities.h>

#include <SUIT_Desktop.h>
#include <SUIT_MessageBox.h>
#include <SUIT_ResourceMgr.h>
#include <SUIT_Session.h>
#include <SUIT_ViewManager.h>

#include "math.h"
#define PI 3.141592653589793
// ------------------------------------------------------------------------------------------------------------------------
MonCreateBoundaryAn::MonCreateBoundaryAn(MonCreateCase* parent, bool modal,
                             HOMARD::HOMARD_Gen_var myHomardGen,
                             QString caseName) :
// ------------------------------------------------------------------------------------------------------------------------------
/* Constructs a MonCreateBoundaryAn
   appele pour une vraie creation
   initialise un cylindre et non une sphere
*/
    QDialog(0), Ui_CreateBoundaryAn(),
    _parent(parent),
    _aName (""),
    _aCaseName(caseName),
    _Xmin(0), _Xmax(0), _Xincr(0), _Ymin(0), _Ymax(0), _Yincr(0), _Zmin(0), _Zmax(0), _Zincr(0), _DMax(0),
    _Type(1),
    _BoundaryAnXcentre(0), _BoundaryAnYcentre(0), _BoundaryAnZcentre(0), _BoundaryAnRayon(0),
    _BoundaryAnXaxis(0), _BoundaryAnYaxis(0), _BoundaryAnZaxis(0),
    _Xcentre(0), _Ycentre(0), _Zcentre(0), _Rayon(0),
    _BoundaryAnXcone1(0), _BoundaryAnYcone1(0), _BoundaryAnZcone1(0), _BoundaryAnRayon1(0),
    _BoundaryAnXcone2(0), _BoundaryAnYcone2(0), _BoundaryAnZcone2(0), _BoundaryAnRayon2(0),
    _BoundaryAnXaxisCone(0), _BoundaryAnYaxisCone(0), _BoundaryAnZaxisCone(0),
    _BoundaryAngle(0),
    Chgt (false)
    {
      MESSAGE("Constructeur") ;
      myHomardGen=HOMARD::HOMARD_Gen::_duplicate(myHomardGen);
      setupUi(this);
      setModal(modal);

    //  Gestion des icones
      SUIT_ResourceMgr* resMgr = SUIT_Session::session()->resourceMgr();
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "spherepoint.png" );
      QIcon IS=QIcon(pix);
      RBSphere->setIcon(IS);
      QPixmap pix2 = resMgr->loadPixmap( "HOMARD", "cylinderpointvector.png" );
      QIcon IS2=QIcon(pix2);
      RBCylindre->setIcon(IS2);
      QPixmap pix3 = resMgr->loadPixmap( "HOMARD", "cone.png" );
      QIcon IS3=QIcon(pix3);
      RBCone->setIcon(IS3);
      QPixmap pix4 = resMgr->loadPixmap( "HOMARD", "conepointvector.png" );
      QIcon IS4=QIcon(pix4);
      RB_Def_angle->setIcon(IS4);
      QPixmap pix5 = resMgr->loadPixmap( "HOMARD", "conedxyz.png" );
      QIcon IS5=QIcon(pix5);
      RB_Def_radius->setIcon(IS5);

      InitConnect( );

      SetNewName() ;
      InitValBoundaryAn();          // Cherche les valeurs de la boite englobante le maillage
      InitMinMax();                 // Initialise les bornes des boutons
      SetCylinder();                // Propose un cylindre en premier choix
    }
// --------------------------------------------------------------------------------------------------------------
MonCreateBoundaryAn::MonCreateBoundaryAn(MonCreateCase* parent,
                             HOMARD::HOMARD_Gen_var myHomardGen,
                             QString caseName):
// --------------------------------------------------------------------------------------------------------------
// Constructeur appele par MonEditBoundaryAn
//
    QDialog(0), Ui_CreateBoundaryAn(),
     myHomardGen(myHomardGen),
    _parent(parent),
    _aName (""),
    _aCaseName(caseName),
    _Type(1),
    _BoundaryAnXcentre(0), _BoundaryAnYcentre(0), _BoundaryAnZcentre(0), _BoundaryAnRayon(0),
    _BoundaryAnXaxis(0), _BoundaryAnYaxis(0), _BoundaryAnZaxis(0),
    // Pour affichage lors de l edition d une BoundaryAn sans nom de Cas
    _Xcentre(0), _Ycentre(0), _Zcentre(0), _Rayon(0),
    _Xmin(1), _Xmax(1), _Xincr(1), _Ymin(1), _Ymax(1), _Yincr(1), _Zmin(1), _Zmax(1), _Zincr(1), _DMax(1),
    Chgt (false)
    {
  //  MESSAGE("Debut de  MonCreateBoundaryAn")
      setupUi(this);
      SUIT_ResourceMgr* resMgr = SUIT_Session::session()->resourceMgr();
      QPixmap pix = resMgr->loadPixmap( "HOMARD", "spherepoint.png" );
      QIcon IS=QIcon(pix);
      RBSphere->setIcon(IS);
      QPixmap pix2 = resMgr->loadPixmap( "HOMARD", "cylinderpointvector.png" );
      QIcon IS2=QIcon(pix2);
      RBCylindre->setIcon(IS2);
      QPixmap pix3 = resMgr->loadPixmap( "HOMARD", "cone.png" );
      QIcon IS3=QIcon(pix3);
      RBCone->setIcon(IS3);
      QPixmap pix4 = resMgr->loadPixmap( "HOMARD", "conepointvector.png" );
      QIcon IS4=QIcon(pix4);
      RB_Def_angle->setIcon(IS4);
      QPixmap pix5 = resMgr->loadPixmap( "HOMARD", "conedxyz.png" );
      QIcon IS5=QIcon(pix5);
      RB_Def_radius->setIcon(IS5);
      setModal(true);
      InitConnect();
    }

// ------------------------------------------------------------------------
MonCreateBoundaryAn::~MonCreateBoundaryAn()
// ------------------------------------------------------------------------
{
    // no need to delete child widgets, Qt does it all for us
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::InitConnect()
// ------------------------------------------------------------------------
{
    connect( RBCylindre,    SIGNAL(clicked()) , this, SLOT(SetCylinder()) ) ;
    connect( RBSphere,      SIGNAL(clicked()) , this, SLOT(SetSphere()) ) ;
    connect( RBCone,        SIGNAL(clicked()) , this, SLOT(SetCone()) ) ;
    connect( RB_Def_radius, SIGNAL(clicked()) , this, SLOT(SetConeR()) );
    connect( RB_Def_angle,  SIGNAL(clicked()) , this, SLOT(SetConeA()) );
    connect( buttonOk,     SIGNAL( pressed() ), this, SLOT( PushOnOK() ) );
    connect( buttonApply,  SIGNAL( pressed() ), this, SLOT( PushOnApply() ) );
    connect( buttonCancel, SIGNAL( pressed() ), this, SLOT( close() ) );
    connect( buttonHelp,   SIGNAL( pressed() ), this, SLOT( PushOnHelp() ) );
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::InitValBoundaryAn()
// ------------------------------------------------------------------------
{
//
//  1. Les coordonnees extremes du maillage
//
    if (_aCaseName == QString("")) { return; }

    HOMARD::HOMARD_Cas_var aCas = myHomardGen->GetCase(_aCaseName.toStdString().c_str());
    HOMARD::extrema_var  MesExtremes = aCas->GetBoundingBox();
    int num = MesExtremes->length() ;
    ASSERT(num == 10);
    _Xmin=MesExtremes[0]; _Xmax=MesExtremes[1]; _Xincr=MesExtremes[2];
    _Ymin=MesExtremes[3]; _Ymax=MesExtremes[4]; _Yincr=MesExtremes[5];
    _Zmin=MesExtremes[6]; _Zmax=MesExtremes[7]; _Zincr=MesExtremes[8];
    _DMax=MesExtremes[9];
     MESSAGE ("_Xmin : " << _Xmin << " _Xmax : " << _Xmax << " _Xincr : " << _Xincr ) ;
     MESSAGE ("_Ymin : " << _Ymin << " _Ymax : " << _Ymax << " _Yincr : " << _Yincr ) ;
     MESSAGE ("_Zmin : " << _Zmin << " _Zmax : " << _Zmax << " _Zincr : " << _Zincr) ;
     MESSAGE ("_DMax : " << _DMax);

//  2. Caracteristiques des frontieres
// en X
    _Xcentre=(_Xmin + _Xmax)/2.;
// en Y
    _Ycentre=(_Ymin + _Ymax)/2.;
// en Z
    _Zcentre=(_Zmin + _Zmax)/2.;
// Rayon
    _Rayon= _DMax/4.;
}

// ------------------------------------------------------------------------
void MonCreateBoundaryAn::InitMinMax()
// ------------------------------------------------------------------------
{
  // Cylindre
  // . X du centre
  SpinBox_Xcent->setValue(_Xcentre);
  SpinBox_Xcent->setSingleStep(_Xincr);
  // . Y du centre
  SpinBox_Ycent->setValue(_Ycentre);
  SpinBox_Ycent->setSingleStep(_Yincr);
  // . Z du centre
  SpinBox_Zcent->setValue(_Zcentre);
  SpinBox_Zcent->setSingleStep(_Zincr);
  // . X de l'axe
  SpinBox_Xaxis->setValue(0.);
  SpinBox_Xaxis->setSingleStep(0.1);
  // . Y de l'axe
  SpinBox_Yaxis->setValue(0.);
  SpinBox_Yaxis->setSingleStep(0.1);
  // . Z de l'axe
  SpinBox_Zaxis->setValue(1.);
  SpinBox_Zaxis->setSingleStep(0.1);
  // . Rayon
  SpinBox_Radius->setValue(_Rayon);
  SpinBox_Radius->setSingleStep(_Rayon/10.);
  SpinBox_Radius->setMinimum(0.);

  // Sphere
  // . X du centre
  SpinBox_Xcentre->setValue(_Xcentre);
  SpinBox_Xcentre->setSingleStep(_Xincr);
  // . Y du centre
  SpinBox_Ycentre->setValue(_Ycentre);
  SpinBox_Ycentre->setSingleStep(_Yincr);
  // . Z du centre
  SpinBox_Zcentre->setValue(_Zcentre);
  SpinBox_Zcentre->setSingleStep(_Zincr);
  // . Rayon
  SpinBox_Rayon->setValue(_Rayon);
  SpinBox_Rayon->setSingleStep(_Rayon/10.);
  SpinBox_Rayon->setMinimum(0.);

  // Cone en rayons
  // . X des centres
  _BoundaryAnXcone1 = _Xcentre ;
  SpinBox_Cone_X1->setSingleStep(_Xincr);
  _BoundaryAnXcone2 = _Xcentre ;
  SpinBox_Cone_X2->setSingleStep(_Xincr);
  // . Y des centres
  _BoundaryAnYcone1 = _Ycentre ;
  SpinBox_Cone_Y1->setSingleStep(_Yincr);
  _BoundaryAnYcone2 = _Ycentre ;
  SpinBox_Cone_Y2->setSingleStep(_Yincr);
  // . Z des centres
  _BoundaryAnZcone1 = _Zmin ;
  SpinBox_Cone_Z1->setSingleStep(_Zincr);
  _BoundaryAnZcone2 = _Zmax ;
  SpinBox_Cone_Z2->setSingleStep(_Zincr);
  // . Rayons/Angles
  _BoundaryAnRayon1 = 0. ;
  SpinBox_Cone_V1->setMinimum(0.);
  _BoundaryAnRayon2 = _Rayon ;
  SpinBox_Cone_V2->setSingleStep(_Rayon/10.);
  SpinBox_Cone_V2->setMinimum(0.);

  // Cone en angle
  convertRayonAngle(1) ;
  SpinBox_Cone_X1->setValue(_BoundaryAnXaxisCone);
  SpinBox_Cone_Y1->setValue(_BoundaryAnYaxisCone);
  SpinBox_Cone_Z1->setValue(_BoundaryAnZaxisCone);
  SpinBox_Cone_V1->setValue(_BoundaryAngle);
  SpinBox_Cone_X2->setValue(_BoundaryAnXorigCone);
  SpinBox_Cone_Y2->setValue(_BoundaryAnYorigCone);
  SpinBox_Cone_Z2->setValue(_BoundaryAnZorigCone);
}
// ------------------------------------------------------------------------
bool MonCreateBoundaryAn::PushOnApply()
// ------------------------------------------------------------------------
// Appele lorsque l'un des boutons Ok ou Apply est presse
//
{
  if (LEName->text().trimmed()=="")
  {
    QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                              QObject::tr("HOM_BOUN_NAME") );
    return false;
  }

  switch (_Type)
  {
      case 1 : // il s agit d un cylindre
      {
        if ((_BoundaryAnXcentre != SpinBox_Xcent->value())  or
            (_BoundaryAnYcentre != SpinBox_Ycent->value())  or
            (_BoundaryAnZcentre != SpinBox_Zcent->value())  or
            (_BoundaryAnRayon   != SpinBox_Radius->value()) or
            (_BoundaryAnXaxis   != SpinBox_Xaxis->value()) or
            (_BoundaryAnYaxis   != SpinBox_Yaxis->value()) or
            (_BoundaryAnZaxis   != SpinBox_Zaxis->value()) )
        {
          Chgt = true;
          _BoundaryAnXaxis= SpinBox_Xaxis->value();
          _BoundaryAnYaxis= SpinBox_Yaxis->value();
          _BoundaryAnZaxis= SpinBox_Zaxis->value();
          _BoundaryAnXcentre=SpinBox_Xcent->value();
          _BoundaryAnYcentre=SpinBox_Ycent->value();
          _BoundaryAnZcentre=SpinBox_Zcent->value();
          _BoundaryAnRayon=SpinBox_Radius->value();
        }
        break;
      }

      case 2 : // il s agit d une sphere
      {
        if ((_BoundaryAnXcentre != SpinBox_Xcentre->value()) or
            (_BoundaryAnYcentre != SpinBox_Ycentre->value()) or
            (_BoundaryAnZcentre != SpinBox_Zcentre->value()) or
            (_BoundaryAnRayon   != SpinBox_Rayon->value())  )
        {
           Chgt = true;
          _BoundaryAnXcentre=SpinBox_Xcentre->value();
          _BoundaryAnYcentre=SpinBox_Ycentre->value();
          _BoundaryAnZcentre=SpinBox_Zcentre->value();
          _BoundaryAnRayon=SpinBox_Rayon->value();
        }
        break;
      }

      case 3 : // il s agit d un cone defini par un axe et un angle
      {
        if ((_BoundaryAnXaxisCone != SpinBox_Cone_X1->value())  or
            (_BoundaryAnYaxisCone != SpinBox_Cone_Y1->value())  or
            (_BoundaryAnZaxisCone != SpinBox_Cone_Z1->value())  or
            (_BoundaryAnXorigCone != SpinBox_Cone_X2->value())  or
            (_BoundaryAnYorigCone != SpinBox_Cone_Y2->value())  or
            (_BoundaryAnZorigCone != SpinBox_Cone_Z2->value())  or
            (_BoundaryAngle       != SpinBox_Cone_V1->value()) )
        {
           Chgt = true;
          _BoundaryAnXaxisCone = SpinBox_Cone_X1->value() ;
          _BoundaryAnYaxisCone = SpinBox_Cone_Y1->value() ;
          _BoundaryAnZaxisCone = SpinBox_Cone_Z1->value() ;
          _BoundaryAnXorigCone = SpinBox_Cone_X2->value() ;
          _BoundaryAnYorigCone = SpinBox_Cone_Y2->value() ;
          _BoundaryAnZorigCone = SpinBox_Cone_Z2->value() ;
          _BoundaryAngle       = SpinBox_Cone_V1->value() ;
        }
        break;
      }

      case 4 : // il s agit d un cone defini par les 2 rayons
      {
        if ((_BoundaryAnXcone1 != SpinBox_Cone_X1->value())  or
            (_BoundaryAnYcone1 != SpinBox_Cone_Y1->value())  or
            (_BoundaryAnZcone1 != SpinBox_Cone_Z1->value())  or
            (_BoundaryAnRayon1 != SpinBox_Cone_V1->value())  or
            (_BoundaryAnXcone2 != SpinBox_Cone_X2->value())  or
            (_BoundaryAnYcone2 != SpinBox_Cone_Y2->value())  or
            (_BoundaryAnZcone2 != SpinBox_Cone_Z2->value())  or
            (_BoundaryAnRayon2 != SpinBox_Cone_V2->value()) )
        {
           Chgt = true;
          _BoundaryAnXcone1 = SpinBox_Cone_X1->value() ;
          _BoundaryAnYcone1 = SpinBox_Cone_Y1->value() ;
          _BoundaryAnZcone1 = SpinBox_Cone_Z1->value() ;
          _BoundaryAnRayon1 = SpinBox_Cone_V1->value() ;
          _BoundaryAnXcone2 = SpinBox_Cone_X2->value() ;
          _BoundaryAnYcone2 = SpinBox_Cone_Y2->value() ;
          _BoundaryAnZcone2 = SpinBox_Cone_Z2->value() ;
          _BoundaryAnRayon2 = SpinBox_Cone_V2->value() ;
        }
        break;
      }
 }

  bool bOK = CreateOrUpdateBoundaryAn();

  if ( bOK ) { HOMARD_UTILS::updateObjBrowser() ; }

  return bOK;

}
// ---------------------------------------------------
bool MonCreateBoundaryAn:: CreateOrUpdateBoundaryAn()
//----------------------------------------------------
//  Creation de l'objet boundary
{
  _aName = LEName->text().trimmed();
  switch (_Type)
  {
    case 1 : // il s agit d un cylindre
    {
      try
      {
        aBoundaryAn = myHomardGen->CreateBoundaryCylinder(CORBA::string_dup(_aName.toStdString().c_str()), \
        _BoundaryAnXcentre, _BoundaryAnYcentre, _BoundaryAnZcentre, _BoundaryAnXaxis, _BoundaryAnYaxis, _BoundaryAnZaxis, _BoundaryAnRayon );
      }
      catch( SALOME::SALOME_Exception& S_ex )
      {
        QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                  QObject::tr(CORBA::string_dup(S_ex.details.text)) );
        return false ;
      }
      break;
    }
    case 2 : // il s agit d une sphere
    {
      try
      {
        aBoundaryAn = myHomardGen->CreateBoundarySphere(CORBA::string_dup(_aName.toStdString().c_str()), \
        _BoundaryAnXcentre, _BoundaryAnYcentre, _BoundaryAnZcentre, _BoundaryAnRayon);
      }
      catch( SALOME::SALOME_Exception& S_ex )
      {
        QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                  QObject::tr(CORBA::string_dup(S_ex.details.text)) );
        return false ;
      }
      break;
    }
    case 3 : // il s agit d un cone defini par un axe et un angle
    {
      try
      {
        aBoundaryAn = myHomardGen->CreateBoundaryConeA(CORBA::string_dup(_aName.toStdString().c_str()), \
        _BoundaryAnXaxisCone, _BoundaryAnYaxisCone, _BoundaryAnZaxisCone, _BoundaryAngle, \
        _BoundaryAnXorigCone, _BoundaryAnYorigCone, _BoundaryAnYorigCone);
      }
      catch( SALOME::SALOME_Exception& S_ex )
      {
        QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                  QObject::tr(CORBA::string_dup(S_ex.details.text)) );
        return false ;
      }
      break;
    }
    case 4 : // il s agit d un cone defini par les 2 rayons
    {
      try
      {
        aBoundaryAn = myHomardGen->CreateBoundaryConeR(CORBA::string_dup(_aName.toStdString().c_str()), \
        _BoundaryAnXcone1, _BoundaryAnYcone1, _BoundaryAnZcone1, _BoundaryAnRayon1, \
        _BoundaryAnXcone2, _BoundaryAnYcone2, _BoundaryAnZcone2, _BoundaryAnRayon2);
      }
      catch( SALOME::SALOME_Exception& S_ex )
      {
        QMessageBox::critical( 0, QObject::tr("HOM_ERROR"),
                                  QObject::tr(CORBA::string_dup(S_ex.details.text)) );
        return false ;
      }
      break;
    }
  }
  _parent->AddBoundaryAn(_aName);

  return true;
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::PushOnOK()
// ------------------------------------------------------------------------
{
     if (PushOnApply()) this->close();
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::PushOnHelp()
// ------------------------------------------------------------------------
{
  HOMARD_UTILS::PushOnHelp(QString("gui_create_boundary.html"), QString("un-cylindre") ) ;
}

// -----------------------------------
void MonCreateBoundaryAn::SetNewName()
// -----------------------------------
{
// Recherche d'un nom par defaut qui n'existe pas encore

  HOMARD::listeBoundarys_var MyObjects = myHomardGen->GetAllBoundarysName();
  int num = 0; QString aName="";
  while (aName=="" )
  {
    aName.setNum(num+1) ;
    aName.insert(0, QString("Boun_")) ;
    for ( int i=0; i<MyObjects->length(); i++)
    {
      if ( aName ==  QString(MyObjects[i]))
      {
          num=num+1;
          aName="";
          break;
      }
   }
  }
  LEName->setText(aName);
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::SetCylinder()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetCylinder")
  gBCylindre->setVisible(1);
  gBSphere->setVisible(0);
  gBCone->setVisible(0);
  adjustSize();
  _Type=1;
//   MESSAGE("Fin de SetCylinder")
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::SetSphere()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetSphere")
  gBCylindre->setVisible(0);
  gBSphere->setVisible(1);
  gBCone->setVisible(0);
  adjustSize();
  _Type=2;
//   MESSAGE("Fin de SetSphere")
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::SetConeR()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetConeR")
//
// Stockage et conversion des valeurs si elles ont change
  if ((_BoundaryAnXaxisCone != SpinBox_Cone_X1->value())  or
      (_BoundaryAnYaxisCone != SpinBox_Cone_Y1->value())  or
      (_BoundaryAnZaxisCone != SpinBox_Cone_Z1->value())  or
      (_BoundaryAnXorigCone != SpinBox_Cone_X2->value())  or
      (_BoundaryAnYorigCone != SpinBox_Cone_Y2->value())  or
      (_BoundaryAnZorigCone != SpinBox_Cone_Z2->value())  or
      (_BoundaryAngle       != SpinBox_Cone_V1->value()) )
  {
    MESSAGE("Stockage et conversion")
    _BoundaryAnXaxisCone = SpinBox_Cone_X1->value() ;
    _BoundaryAnYaxisCone = SpinBox_Cone_Y1->value() ;
    _BoundaryAnZaxisCone = SpinBox_Cone_Z1->value() ;
    _BoundaryAnXorigCone = SpinBox_Cone_X2->value() ;
    _BoundaryAnYorigCone = SpinBox_Cone_Y2->value() ;
    _BoundaryAnZorigCone = SpinBox_Cone_Z2->value() ;
    _BoundaryAngle       = SpinBox_Cone_V1->value() ;
    convertRayonAngle(-1) ;
  }
//
  _Type=4;
//
  TLCone_X1->setText(QApplication::translate("CreateBoundaryAn", "X centre 1", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_X1->setValue(_BoundaryAnXcone1);
  TLCone_Y1->setText(QApplication::translate("CreateBoundaryAn", "Y centre 1", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_Y1->setValue(_BoundaryAnYcone1);
  TLCone_Z1->setText(QApplication::translate("CreateBoundaryAn", "Z centre 1", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_Z1->setValue(_BoundaryAnZcone1);
//
  TLCone_V1->setText(QApplication::translate("CreateBoundaryAn", "Radius 1", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_V1->setSingleStep(_Rayon/10.);
  SpinBox_Cone_V1->setMaximum(100000.*_DMax);
  SpinBox_Cone_V1->setValue(_BoundaryAnRayon1);
//
  TLCone_X2->setText(QApplication::translate("CreateBoundaryAn", "X centre 2", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_X2->setValue(_BoundaryAnXcone2);
  TLCone_Y2->setText(QApplication::translate("CreateBoundaryAn", "Y centre 2", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_Y2->setValue(_BoundaryAnYcone2);
  TLCone_Z2->setText(QApplication::translate("CreateBoundaryAn", "Z centre 2", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_Z2->setValue(_BoundaryAnZcone2);
//
  TLCone_V2->setVisible(1);
  SpinBox_Cone_V2->setVisible(1);
  TLCone_V2->setText(QApplication::translate("CreateBoundaryAn", "Radius 2", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_V2->setValue(_BoundaryAnRayon2);
//
//   MESSAGE("Fin de SetConeR")
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::SetConeA()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetConeA")
// Stockage et conversion des valeurs si elles ont change
  if ((_BoundaryAnXcone1 != SpinBox_Cone_X1->value())  or
      (_BoundaryAnYcone1 != SpinBox_Cone_Y1->value())  or
      (_BoundaryAnZcone1 != SpinBox_Cone_Z1->value())  or
      (_BoundaryAnRayon1 != SpinBox_Cone_V1->value())  or
      (_BoundaryAnXcone2 != SpinBox_Cone_X2->value())  or
      (_BoundaryAnYcone2 != SpinBox_Cone_Y2->value())  or
      (_BoundaryAnZcone2 != SpinBox_Cone_Z2->value())  or
      (_BoundaryAnRayon2 != SpinBox_Cone_V2->value()) )
  {
    MESSAGE("Stockage et conversion")
    _BoundaryAnXcone1 = SpinBox_Cone_X1->value() ;
    _BoundaryAnYcone1 = SpinBox_Cone_Y1->value() ;
    _BoundaryAnZcone1 = SpinBox_Cone_Z1->value() ;
    _BoundaryAnRayon1 = SpinBox_Cone_V1->value() ;
    _BoundaryAnXcone2 = SpinBox_Cone_X2->value() ;
    _BoundaryAnYcone2 = SpinBox_Cone_Y2->value() ;
    _BoundaryAnZcone2 = SpinBox_Cone_Z2->value() ;
    _BoundaryAnRayon2 = SpinBox_Cone_V2->value() ;
    convertRayonAngle(1) ;
  }
//
  _Type=3;
//
  TLCone_X1->setText(QApplication::translate("CreateBoundaryAn", "X axis", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_X1->setValue(_BoundaryAnXaxisCone);
  TLCone_Y1->setText(QApplication::translate("CreateBoundaryAn", "Y axis", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_Y1->setValue(_BoundaryAnYaxisCone);
  TLCone_Z1->setText(QApplication::translate("CreateBoundaryAn", "Z axis", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_Z1->setValue(_BoundaryAnZaxisCone);
//
  TLCone_X2->setText(QApplication::translate("CreateBoundaryAn", "X centre", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_X2->setValue(_BoundaryAnXorigCone);
  TLCone_Y2->setText(QApplication::translate("CreateBoundaryAn", "Y centre", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_Y2->setValue(_BoundaryAnYorigCone);
  TLCone_Z2->setText(QApplication::translate("CreateBoundaryAn", "Z centre", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_Z2->setValue(_BoundaryAnZorigCone);
//
  TLCone_V1->setText(QApplication::translate("CreateBoundaryAn", "Angle", 0, QApplication::UnicodeUTF8));
  SpinBox_Cone_V1->setValue(_BoundaryAngle);
  SpinBox_Cone_V1->setSingleStep(1.);
  SpinBox_Cone_V1->setMaximum(90.);
//
  TLCone_V2->setVisible(0);
  SpinBox_Cone_V2->setVisible(0);
//   MESSAGE("Fin de SetConeA")
}


// ------------------------------------------------------------------------
void MonCreateBoundaryAn::SetCone()
// ------------------------------------------------------------------------
{
  MESSAGE("Debut de SetCone")
  gBCylindre->setVisible(0);
  gBSphere->setVisible(0);
  gBCone->setVisible(1);
//
  adjustSize();
  if ( RB_Def_radius->isChecked() )
  {
    SetConeR();
  }
  else
  {
    SetConeA();
  }
//   MESSAGE("Fin de SetCone")
}
// ------------------------------------------------------------------------
void MonCreateBoundaryAn::convertRayonAngle(int option)
// ------------------------------------------------------------------------
// Conversion entre les deux formulations du cone :
// par deux rayons ou avec un axe et un angle.
// Voir sfcoi1 de HOMARD
{
  MESSAGE("Debut de convertRayonAngle, option = "<<option)
//
//         o
//         !    .
//         !        .
//       RA!            .
//         !                o
//         !              RB!   .
//         !                !       .
//         A----------------B----------O
//
//   Thales : RA/RB = AO/BO  ==> BO = AB*RB/(RA-RB)
//   Angle  : tg(alpha) = RA/AO
//
  double daux ;
// De rayon vers angle :
  if ( option == 1 )
  {
    double xa, ya, za, ra ;
    double xb, yb, zb, rb ;
// Positionnement de A vers B, avec RA>RB
    if ( _BoundaryAnRayon1 > _BoundaryAnRayon2 )
    {
      xa = _BoundaryAnXcone1 ;
      ya = _BoundaryAnYcone1 ;
      za = _BoundaryAnZcone1 ;
      ra = _BoundaryAnRayon1 ;
      xb = _BoundaryAnXcone2 ;
      yb = _BoundaryAnYcone2 ;
      zb = _BoundaryAnZcone2 ;
      rb = _BoundaryAnRayon2 ;
    }
    else
    {
      xa = _BoundaryAnXcone2 ;
      ya = _BoundaryAnYcone2 ;
      za = _BoundaryAnZcone2 ;
      ra = _BoundaryAnRayon2 ;
      xb = _BoundaryAnXcone1 ;
      yb = _BoundaryAnYcone1 ;
      zb = _BoundaryAnZcone1 ;
      rb = _BoundaryAnRayon1 ;
    }
// Axe : relie les deux centres, de A vers B.  L'axe est normalise
    _BoundaryAnXaxisCone = xb - xa ;
    _BoundaryAnYaxisCone = yb - ya ;
    _BoundaryAnZaxisCone = zb - za ;
    daux = sqrt ( _BoundaryAnXaxisCone*_BoundaryAnXaxisCone + _BoundaryAnYaxisCone*_BoundaryAnYaxisCone + _BoundaryAnZaxisCone*_BoundaryAnZaxisCone ) ;
    _BoundaryAnXaxisCone = _BoundaryAnXaxisCone/daux ;
    _BoundaryAnYaxisCone = _BoundaryAnYaxisCone/daux ;
    _BoundaryAnZaxisCone = _BoundaryAnZaxisCone/daux ;
// Origine
    daux = daux * rb / (ra-rb) ;
    _BoundaryAnXorigCone = xb + daux*_BoundaryAnXaxisCone ;
    _BoundaryAnYorigCone = yb + daux*_BoundaryAnYaxisCone ;
    _BoundaryAnZorigCone = zb + daux*_BoundaryAnZaxisCone ;
// Angle en degre
    daux = ra / sqrt((_BoundaryAnXorigCone-xa)*(_BoundaryAnXorigCone-xa) + (_BoundaryAnYorigCone-ya)*(_BoundaryAnYorigCone-ya) + (_BoundaryAnZorigCone-za)*(_BoundaryAnZorigCone-za) ) ;
    _BoundaryAngle = atan(daux)*180./PI ;
  }
// D'angle vers rayon :
  else
  {
    double xax, yax, zax ;
// L'axe est normalise
    daux = sqrt ( _BoundaryAnXaxisCone*_BoundaryAnXaxisCone + _BoundaryAnYaxisCone*_BoundaryAnYaxisCone + _BoundaryAnZaxisCone*_BoundaryAnZaxisCone ) ;
    xax = _BoundaryAnXaxisCone/daux ;
    yax = _BoundaryAnYaxisCone/daux ;
    zax = _BoundaryAnZaxisCone/daux ;
// Centre 1 : l'origine
    _BoundaryAnXcone1 = _BoundaryAnXorigCone ;
    _BoundaryAnYcone1 = _BoundaryAnYorigCone ;
    _BoundaryAnZcone1 = _BoundaryAnZorigCone ;
// Rayon 1 : nul
    _BoundaryAnRayon1 = 0. ;
// Centre 2 : l'origine decalee d'une longueur arbitraire le long de l'axe
    _BoundaryAnXcone2 = _BoundaryAnXorigCone + _DMax*xax ;
    _BoundaryAnYcone2 = _BoundaryAnYorigCone + _DMax*yax ;
    _BoundaryAnZcone2 = _BoundaryAnZorigCone + _DMax*zax ;
// Rayon 2 : a calculer
    _BoundaryAnRayon2 = _DMax*tan(_BoundaryAngle*PI/180.) ;
  }
//   MESSAGE("Fin de convertRayonAngle")
}


