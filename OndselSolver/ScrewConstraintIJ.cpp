/***************************************************************************
 *   Copyright (c) 2023 Ondsel, Inc.                                       *
 *                                                                         *
 *   This file is part of OndselSolver.                                    *
 *                                                                         *
 *   See LICENSE file for details about copyright.                         *
 ***************************************************************************/
 
#include "corecrt_math_defines.h"

#include "ScrewConstraintIJ.h"
#include "ScrewConstraintIqcJqc.h"

using namespace MbD;

MbD::ScrewConstraintIJ::ScrewConstraintIJ(EndFrmsptr frmi, EndFrmsptr frmj) : ConstraintIJ(frmi, frmj)
{
}

std::shared_ptr<ScrewConstraintIJ> MbD::ScrewConstraintIJ::With(EndFrmsptr frmi, EndFrmsptr frmj)
{
	return std::make_shared<ScrewConstraintIqcJqc>(frmi, frmj);
}

void MbD::ScrewConstraintIJ::calcPostDynCorrectorIteration()
{
	auto z = zIeJeIe->value();
	auto thez = thezIeJe->value();
	aG = (2.0 * OS_M_PI * z) - (pitch * thez) - aConstant;
}

void MbD::ScrewConstraintIJ::init_zthez()
{
	assert(false);
}

void MbD::ScrewConstraintIJ::initzIeJeIe()
{
	assert(false);
}

void MbD::ScrewConstraintIJ::initthezIeJe()
{
	assert(false);
}

void MbD::ScrewConstraintIJ::initialize()
{
	ConstraintIJ::initialize();
	this->init_zthez();
}

void MbD::ScrewConstraintIJ::initializeGlobally()
{
	zIeJeIe->initializeGlobally();
	thezIeJe->initializeGlobally();
}

void MbD::ScrewConstraintIJ::initializeLocally()
{
	zIeJeIe->initializeLocally();
	thezIeJe->initializeLocally();
}

void MbD::ScrewConstraintIJ::postInput()
{
	zIeJeIe->postInput();
	thezIeJe->postInput();
	aConstant = (2.0 * OS_M_PI * zIeJeIe->value()) - (thezIeJe->value() * pitch);
	ConstraintIJ::postInput();
}

void MbD::ScrewConstraintIJ::postPosICIteration()
{
	zIeJeIe->postPosICIteration();
	thezIeJe->postPosICIteration();
	ConstraintIJ::postPosICIteration();
}

void MbD::ScrewConstraintIJ::preAccIC()
{
	zIeJeIe->preAccIC();
	thezIeJe->preAccIC();
	ConstraintIJ::preAccIC();
}

void MbD::ScrewConstraintIJ::prePosIC()
{
	zIeJeIe->prePosIC();
	thezIeJe->prePosIC();
	ConstraintIJ::prePosIC();
}

void MbD::ScrewConstraintIJ::preVelIC()
{
	zIeJeIe->preVelIC();
	thezIeJe->preVelIC();
	ConstraintIJ::preVelIC();
}

void MbD::ScrewConstraintIJ::simUpdateAll()
{
	zIeJeIe->simUpdateAll();
	thezIeJe->simUpdateAll();
	ConstraintIJ::simUpdateAll();
}
