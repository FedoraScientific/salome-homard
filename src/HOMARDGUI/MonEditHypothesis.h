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

#ifndef MON_EDITHYPOTHESIS_H
#define MON_EDITHYPOTHESIS_H

#include <SALOMEconfig.h>
#include <SalomeApp_Module.h>

#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)
#include CORBA_CLIENT_HEADER(HOMARD_Gen)

#include <MonCreateHypothesis.h>

class MonEditHypothesis : public MonCreateHypothesis
{
    Q_OBJECT
public:
    MonEditHypothesis( MonCreateIteration* parent, bool modal,
                       HOMARD::HOMARD_Gen_var myHomardGen,
                       QString caseName, QString HypothesisName, QString aFieldFile );
    virtual ~MonEditHypothesis();

protected :
    virtual void InitValEdit();
    virtual void InitAdaptUniforme();
    virtual void InitAdaptZone();
    virtual void InitAdaptChamps();
    virtual void InitGroupes();
    virtual void InitFieldInterp();
    virtual void SetFiltrage();
    virtual bool PushOnApply();

public slots:

};

#endif