//  HOMARD HOMARD : implementaion of HOMARD idl descriptions
//
// Copyright (C) 2011-2012  CEA/DEN, EDF R&D
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
//  File   : HOMARD_Zone.cxx
//  Author : Paul RASCLE, EDF
//  Module : HOMARD

#include "HOMARD_Zone.hxx"
#include "utilities.h"

//=============================================================================
/*!
 *  default constructor:
 */
//=============================================================================
HOMARD_Zone::HOMARD_Zone():
  _Name( "" ),_Type( 2 ),
  _Xmin( 0 ), _Xmax( 0 ), _Ymin( 0 ), _Ymax( 0 ), _Zmin( 0 ), _Zmax( 0 ),
  _Xcentre( 0 ), _Ycentre( 0 ), _Zcentre( 0 ), _Rayon( 0 ),
  _Xaxe( 0 ), _Yaxe( 0 ), _Zaxe( 0 ), _Haut( 0 ),
  _Xincr( 0 ), _Yincr( 0 ), _Zincr( 0 )
{
  MESSAGE("HOMARD_Zone") ;
}

//=============================================================================
HOMARD_Zone::~HOMARD_Zone()
{
  MESSAGE("~HOMARD_Zone") ;
}

//=============================================================================
void HOMARD_Zone::SetName( const char* Name )
{
  _Name = std::string( Name ) ;
}

//=============================================================================
std::string HOMARD_Zone::GetName() const
{
  return _Name;
}

//=============================================================================
std::string HOMARD_Zone::GetDumpPython() const
{
//   MESSAGE("GetDumpPython avec _Type " << _Type) ;
//   MESSAGE("GetDumpPython avec _Name " << _Name) ;
  std::ostringstream aScript;
  aScript << "\n# Creation of the ";
  if ( _Type >= 11 and _Type <= 13 ) { aScript << "rectangle " ; }
  else if ( _Type == 2 ) { aScript << "box " ;}
  else if ( _Type >= 31 and _Type <= 33 ) { aScript << "disk " ;}
  else if ( _Type == 4 ) { aScript << "sphere " ; }
  else if ( _Type == 5 ) { aScript << "cylinder " ; }
  else if ( _Type >= 61 and _Type <= 63 ) { aScript << "disk with hole " ;}
  else if ( _Type == 7 ) { aScript << "pipe " ; }
  aScript << _Name << "\n" ;
//
  aScript << "\t" << _Name << " = homard.CreateZone" ;
//
  switch (_Type)
  {
    case 11:
    { aScript << "Box2D( \"" << _Name << "\", " << _Xmin << ", " << _Xmax << ", " << _Ymin << ", " << _Ymax << ", 1 )\n";
      break ;
    }
    case 12:
    { aScript << "Box2D( \"" << _Name << "\", " << _Ymin << ", " << _Ymax << ", " << _Zmin << ", " << _Zmax << ", 2 )\n";
      break ;
    }
    case 13:
    { aScript << "Box2D( \"" << _Name << "\", " << _Zmin << ", " << _Zmax << ", " << _Xmin << ", " << _Xmax << ", 3 )\n";
      break ;
    }
    case 2:
    { aScript << "Box( \""  << _Name << "\", " << _Xmin << ", " << _Xmax << ", " << _Ymin << ", " << _Ymax << ", " << _Zmin << ", " << _Zmax << ")\n";
      break ;
    }

    case 4:
    { aScript << "Sphere( \"" << _Name << "\", " << _Xcentre << ", " << _Ycentre << ", " << _Zcentre << ", " << _Rayon << ")\n";
      break ;
    }

    case 31:
    { aScript << "Disk( \"" << _Name << "\", " << _Xcentre << ", " << _Ycentre << ", " << _Rayon << ", 1 )\n";
      break ;
    }
    case 32:
    { aScript << "Disk( \"" << _Name << "\", " << _Ycentre << ", " << _Zcentre << ", " << _Rayon << ", 2 )\n";
      break ;
    }
    case 33:
    { aScript << "Disk( \"" << _Name << "\", " << _Zcentre << ", " << _Xcentre << ", " << _Rayon << ", 3 )\n";
      break ;
    }
    case 5:
    { aScript << "Cylinder( \"" << _Name << "\", " << _Xcentre << ", " << _Ycentre << ", " << _Zcentre << ", " << _Xaxe << ", " << _Yaxe << ", " << _Zaxe << ", " << _Rayon << ", " << _Haut << ")\n";
      break ;
    }

    case 61:
    { aScript << "DiskWithHole( \"" << _Name << "\", " << _Xcentre << ", " << _Ycentre << ", " << _Rayon << ", " << _Rayonint << ", 1 )\n";
      break ;
    }
    case 62:
    { aScript << "DiskWithHole( \"" << _Name << "\", " << _Ycentre << ", " << _Zcentre << ", " << _Rayon << ", " << _Rayonint << ", 2 )\n";
      break ;
    }
    case 63:
    { aScript << "DiskWithHole( \"" << _Name << "\", " << _Zcentre << ", " << _Xcentre << ", " << _Rayon << ", " << _Rayonint << ", 3 )\n";
      break ;
    }
    case 7:
    { aScript << "Pipe( \"" << _Name << "\", " << _Xcentre << ", " << _Ycentre << ", " << _Zcentre << ", " << _Xaxe << ", " << _Yaxe << ", " << _Zaxe << ", " << _Rayon << ", " << _Haut << ", " << _Rayonint << ")\n";
      break ;
    }
  }

  return aScript.str() ;
}

//=============================================================================
void HOMARD_Zone::SetType( int Type )
{
  _Type = Type;
}

//=============================================================================
int HOMARD_Zone::GetType() const
{
  return _Type;
}

//======================================================================
void HOMARD_Zone::SetLimit( double X0, double X1, double X2 )
{
  _Xincr = X0; _Yincr = X1; _Zincr = X2;
}
//=======================================================================================
void HOMARD_Zone::SetBox( double X0, double X1, double X2, double X3, double X4, double X5 )
{
  _Xmin = X0; _Xmax = X1;
  _Ymin = X2; _Ymax = X3;
  _Zmin = X4; _Zmax = X5;
}

//======================================================================
void HOMARD_Zone::SetSphere( double X0, double X1, double X2, double X3 )
{
  _Xcentre = X0;
  _Ycentre = X1;
  _Zcentre = X2;
  _Rayon = X3;
}

//=======================================================================================
void HOMARD_Zone::SetCylinder( double X0, double X1, double X2,
                               double X3, double X4, double X5, double X6, double X7 )
{
  _Xcentre = X0;
  _Ycentre = X1;
  _Zcentre = X2;
  _Xaxe = X3;
  _Yaxe = X4;
  _Zaxe = X5;
  _Rayon = X6;
  _Haut = X7;
}
//=======================================================================================
void HOMARD_Zone::SetPipe( double X0, double X1, double X2,
                           double X3, double X4, double X5, double X6, double X7, double X8 )
{
  _Xcentre = X0;
  _Ycentre = X1;
  _Zcentre = X2;
  _Xaxe = X3;
  _Yaxe = X4;
  _Zaxe = X5;
  _Rayon = X6;
  _Haut = X7;
  _Rayonint = X8;
}

//=======================================================================================
std::vector<double> HOMARD_Zone::GetLimit() const
{
  std::vector<double> mesLimit;
  mesLimit.push_back( _Xincr ) ;
  mesLimit.push_back( _Yincr ) ;
  mesLimit.push_back( _Zincr ) ;
  return mesLimit;
}

//=======================================================================================
std::vector<double> HOMARD_Zone::GetCoords() const
{
  std::vector<double> mesCoor;
//
  switch (_Type)
  {
//  Rectangle ou parallelepipede
    case 11:
    { }
    case 12:
    { }
    case 13:
    { }
    case 2:
    {
      mesCoor.push_back( _Xmin ) ;
      mesCoor.push_back( _Xmax ) ;
      mesCoor.push_back( _Ymin ) ;
      mesCoor.push_back( _Ymax ) ;
      mesCoor.push_back( _Zmin ) ;
      mesCoor.push_back( _Zmax ) ;
      break ;
    }
//  Sphere
    case 4:
    {
      mesCoor.push_back( _Xcentre ) ;
      mesCoor.push_back( _Ycentre ) ;
      mesCoor.push_back( _Zcentre ) ;
      mesCoor.push_back( _Rayon ) ;
      break ;
    }
//  Disque ou cylindre
    case 31:
    { }
    case 32:
    { }
    case 33:
    { }
    case 5:
    {
      mesCoor.push_back( _Xcentre ) ;
      mesCoor.push_back( _Ycentre ) ;
      mesCoor.push_back( _Zcentre ) ;
      mesCoor.push_back( _Xaxe ) ;
      mesCoor.push_back( _Yaxe ) ;
      mesCoor.push_back( _Zaxe ) ;
      mesCoor.push_back( _Rayon ) ;
      mesCoor.push_back( _Haut ) ;
      break ;
    }
//  Disque avec trou ou tuyau
    case 61:
    { }
    case 62:
    { }
    case 63:
    { }
    case 7:
    {
      mesCoor.push_back( _Xcentre ) ;
      mesCoor.push_back( _Ycentre ) ;
      mesCoor.push_back( _Zcentre ) ;
      mesCoor.push_back( _Xaxe ) ;
      mesCoor.push_back( _Yaxe ) ;
      mesCoor.push_back( _Zaxe ) ;
      mesCoor.push_back( _Rayon ) ;
      mesCoor.push_back( _Haut ) ;
      mesCoor.push_back( _Rayonint ) ;
      break ;
    }
    ASSERT ( _Type == -1 ) ;
  }
  return mesCoor;
}

//=============================================================================
void HOMARD_Zone::AddHypo( const char* NomHypo )
{
  _ListHypo.push_back( std::string( NomHypo ) ) ;
}

//=============================================================================
void HOMARD_Zone::SupprHypo( const char* NomHypo )
{
  std::list<std::string>::iterator it = find( _ListHypo.begin(), _ListHypo.end(), NomHypo ) ;
  if ( it != _ListHypo.end() )
  {
    MESSAGE ("Dans SupprHypo pour " << NomHypo) ;
    _ListHypo.erase( it ) ;
  }
}

//=============================================================================
const std::list<std::string>& HOMARD_Zone::GetHypo() const
{
  return _ListHypo;
}

//=============================================================================
void HOMARD_Zone::SupprHypos()
{
  _ListHypo.clear() ;
}
