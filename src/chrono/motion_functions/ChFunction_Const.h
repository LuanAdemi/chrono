// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Alessandro Tasora, Radu Serban
// =============================================================================

#ifndef CHFUNCT_CONST_H
#define CHFUNCT_CONST_H

#include "chrono/motion_functions/ChFunction_Base.h"

namespace chrono {

#define FUNCT_CONST 0

/// Constant function:  y = C

class ChApi ChFunction_Const : public ChFunction {
    CH_RTTI(ChFunction_Const, ChFunction);

  private:
    double C;

  public:
    ChFunction_Const() { C = 0; }
    ChFunction_Const(double y_constant) { C = y_constant; }
    ChFunction_Const(const ChFunction_Const& other) { C = other.C; }
    virtual ~ChFunction_Const() {}

    /// "Virtual" copy constructor (covariant return type).
    virtual ChFunction_Const* Clone() const override { return new ChFunction_Const(*this); }

    /// Returns the y value of the function, at position x.
    virtual int Get_Type() const override { return (FUNCT_CONST); }

    virtual double Get_y(double x) const override { return C; }
    virtual double Get_y_dx(double x) const override { return 0; }
    virtual double Get_y_dxdx(double x) const override { return 0; }

    /// Set the constant C for the function, y=C.
    void Set_yconst(double y_constant) { C = y_constant; }
    /// Get the constant C for the function, y=C.
    double Get_yconst() { return C; }

    /// Method to allow serialization of transient data to archives.
    virtual void ArchiveOUT(ChArchiveOut& marchive) override {
        // version number
        marchive.VersionWrite(1);
        // serialize parent class
        ChFunction::ArchiveOUT(marchive);
        // serialize all member data:
        marchive << CHNVP(C);
    }

    /// Method to allow deserialization of transient data from archives.
    virtual void ArchiveIN(ChArchiveIn& marchive) override {
        // version number
        int version = marchive.VersionRead();
        // deserialize parent class
        ChFunction::ArchiveIN(marchive);
        // stream in all member data:
        marchive >> CHNVP(C);
    }
};

}  // end namespace chrono

#endif
