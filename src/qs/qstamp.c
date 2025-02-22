/*$file${src::qs::qstamp.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: qpc.qm
* File:  ${src::qs::qstamp.c}
*
* This code has been generated by QM 5.2.3 <www.state-machine.com/qm>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This code is covered by the following QP license:
* License #    : LicenseRef-QL-dual
* Issued to    : Any user of the QP/C real-time embedded framework
* Framework(s) : qpc
* Support ends : 2023-12-31
* License scope:
*
* Copyright (C) 2005 Quantum Leaps, LLC <state-machine.com>.
*
* SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-QL-commercial
*
* This software is dual-licensed under the terms of the open source GNU
* General Public License version 3 (or any later version), or alternatively,
* under the terms of one of the closed source Quantum Leaps commercial
* licenses.
*
* The terms of the open source GNU General Public License version 3
* can be found at: <www.gnu.org/licenses/gpl-3.0>
*
* The terms of the closed source Quantum Leaps commercial licenses
* can be found at: <www.state-machine.com/licensing>
*
* Redistributions in source code must retain this top-level comment block.
* Plagiarizing this software to sidestep the license obligations is illegal.
*
* Contact information:
* <www.state-machine.com/licensing>
* <info@state-machine.com>
*/
/*$endhead${src::qs::qstamp.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*! @file
* @brief Application build time-stamp
* @details
* This module needs to be re-compiled in every new software build. To achive
* this, it is recommended to delete the object file (qstamp.o, or qstamp.obj)
* in the build directory before each build. (Most development tools allow
* you to specify a pre-build command, which is the ideal place to delete
* the qstamp object file.)
*/

#include "qstamp.h"

/*! the calendar date of the last translation of the form: "Mmm dd yyyy" */
char const Q_BUILD_DATE[12] = __DATE__;

/*! the time of the last translation of the form: "hh:mm:ss" */
char const Q_BUILD_TIME[9] = __TIME__;
