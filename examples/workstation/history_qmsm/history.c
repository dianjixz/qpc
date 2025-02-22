/*$file${.::history.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: history.qm
* File:  ${.::history.c}
*
* This code has been generated by QM 5.2.3 <www.state-machine.com/qm>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* SPDX-License-Identifier: GPL-3.0-or-later
*
* This generated code is open source software: you can redistribute it under
* the terms of the GNU General Public License as published by the Free
* Software Foundation.
*
* This code is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* NOTE:
* Alternatively, this generated code may be distributed under the terms
* of Quantum Leaps commercial licenses, which expressly supersede the GNU
* General Public License and are specifically designed for licensees
* interested in retaining the proprietary status of their code.
*
* Contact information:
* <www.state-machine.com/licensing>
* <info@state-machine.com>
*/
/*$endhead${.::history.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#include "qpc.h"
#include "history.h"

#include "safe_std.h" /* portable "safe" <stdio.h>/<string.h> facilities */
#include <stdlib.h>

//Q_DEFINE_THIS_FILE

/*$declare${SMs::ToastOven} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${SMs::ToastOven} ........................................................*/
typedef struct {
/* protected: */
    QMsm super;

/* private state histories */
    QMState const *hist_doorClosed;
    QMState const *hist_heating;
} ToastOven;

/* protected: */
static QState ToastOven_initial(ToastOven * const me, void const * const par);
static QState ToastOven_doorClosed  (ToastOven * const me, QEvt const * const e);
static QState ToastOven_doorClosed_e(ToastOven * const me);
static QState ToastOven_doorClosed_x(ToastOven * const me);
static QState ToastOven_doorClosed_i(ToastOven * const me);
static QMState const ToastOven_doorClosed_s = {
    QM_STATE_NULL, /* superstate (top) */
    Q_STATE_CAST(&ToastOven_doorClosed),
    Q_ACTION_CAST(&ToastOven_doorClosed_e),
    Q_ACTION_CAST(&ToastOven_doorClosed_x),
    Q_ACTION_CAST(&ToastOven_doorClosed_i)
};
static QState ToastOven_heating  (ToastOven * const me, QEvt const * const e);
static QState ToastOven_heating_e(ToastOven * const me);
static QState ToastOven_heating_x(ToastOven * const me);
static QState ToastOven_heating_i(ToastOven * const me);
static QMState const ToastOven_heating_s = {
    &ToastOven_doorClosed_s, /* superstate */
    Q_STATE_CAST(&ToastOven_heating),
    Q_ACTION_CAST(&ToastOven_heating_e),
    Q_ACTION_CAST(&ToastOven_heating_x),
    Q_ACTION_CAST(&ToastOven_heating_i)
};
static QState ToastOven_toasting  (ToastOven * const me, QEvt const * const e);
static QState ToastOven_toasting_e(ToastOven * const me);
static QMState const ToastOven_toasting_s = {
    &ToastOven_heating_s, /* superstate */
    Q_STATE_CAST(&ToastOven_toasting),
    Q_ACTION_CAST(&ToastOven_toasting_e),
    Q_ACTION_NULL, /* no exit action */
    Q_ACTION_NULL  /* no initial tran. */
};
static QState ToastOven_baking  (ToastOven * const me, QEvt const * const e);
static QState ToastOven_baking_e(ToastOven * const me);
static QMState const ToastOven_baking_s = {
    &ToastOven_heating_s, /* superstate */
    Q_STATE_CAST(&ToastOven_baking),
    Q_ACTION_CAST(&ToastOven_baking_e),
    Q_ACTION_NULL, /* no exit action */
    Q_ACTION_NULL  /* no initial tran. */
};
static QState ToastOven_off  (ToastOven * const me, QEvt const * const e);
static QState ToastOven_off_e(ToastOven * const me);
static QMState const ToastOven_off_s = {
    &ToastOven_doorClosed_s, /* superstate */
    Q_STATE_CAST(&ToastOven_off),
    Q_ACTION_CAST(&ToastOven_off_e),
    Q_ACTION_NULL, /* no exit action */
    Q_ACTION_NULL  /* no initial tran. */
};
static QState ToastOven_doorOpen  (ToastOven * const me, QEvt const * const e);
static QState ToastOven_doorOpen_e(ToastOven * const me);
static QState ToastOven_doorOpen_x(ToastOven * const me);
static QMState const ToastOven_doorOpen_s = {
    QM_STATE_NULL, /* superstate (top) */
    Q_STATE_CAST(&ToastOven_doorOpen),
    Q_ACTION_CAST(&ToastOven_doorOpen_e),
    Q_ACTION_CAST(&ToastOven_doorOpen_x),
    Q_ACTION_NULL  /* no initial tran. */
};
static QState ToastOven_final  (ToastOven * const me, QEvt const * const e);
static QState ToastOven_final_e(ToastOven * const me);
static QMState const ToastOven_final_s = {
    QM_STATE_NULL, /* superstate (top) */
    Q_STATE_CAST(&ToastOven_final),
    Q_ACTION_CAST(&ToastOven_final_e),
    Q_ACTION_NULL, /* no exit action */
    Q_ACTION_NULL  /* no initial tran. */
};
/*$enddecl${SMs::ToastOven} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

static ToastOven l_oven; /* the only instance of the ToastOven class */

/* global-scope definitions -----------------------------------------*/
QHsm * const the_oven = &l_oven.super.super; /* the opaque pointer */

/*$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/* Check for the minimum required QP version */
#if (QP_VERSION < 690U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 6.9.0 or higher required
#endif
/*$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*$define${SMs::ToastOven_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${SMs::ToastOven_ctor} ...................................................*/
void ToastOven_ctor(void) {
    ToastOven *me = &l_oven;
    QMsm_ctor(&me->super, Q_STATE_CAST(&ToastOven_initial));
}
/*$enddef${SMs::ToastOven_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*$define${SMs::ToastOven} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${SMs::ToastOven} ........................................................*/

/*${SMs::ToastOven::SM} ....................................................*/
static QState ToastOven_initial(ToastOven * const me, void const * const par) {
    static struct {
        QMState const *target;
        QActionHandler act[3];
    } const tatbl_ = { /* tran-action table */
        &ToastOven_doorClosed_s, /* target state */
        {
            Q_ACTION_CAST(&ToastOven_doorClosed_e), /* entry */
            Q_ACTION_CAST(&ToastOven_doorClosed_i), /* initial tran. */
            Q_ACTION_NULL /* zero terminator */
        }
    };
    /*${SMs::ToastOven::SM::initial} */
    (void)par; /* unused parameter */
    /* state history attributes */
    me->hist_doorClosed = &ToastOven_off_s;
    me->hist_heating = &ToastOven_baking_s;
    return QM_TRAN_INIT(&tatbl_);
}

/*${SMs::ToastOven::SM::doorClosed} ........................................*/
/*${SMs::ToastOven::SM::doorClosed} */
static QState ToastOven_doorClosed_e(ToastOven * const me) {
    PRINTF_S("%s;", "door-Closed");
    (void)me; /* unused parameter */
    return QM_ENTRY(&ToastOven_doorClosed_s);
}
/*${SMs::ToastOven::SM::doorClosed} */
static QState ToastOven_doorClosed_x(ToastOven * const me) {
    /* save shallow history */
    me->hist_doorClosed =
        QMsm_childStateObj(Q_HSM_UPCAST(me), &ToastOven_doorClosed_s);
    return QM_EXIT(&ToastOven_doorClosed_s);
}
/*${SMs::ToastOven::SM::doorClosed::initial} */
static QState ToastOven_doorClosed_i(ToastOven * const me) {
    static struct {
        QMState const *target;
        QActionHandler act[2];
    } const tatbl_ = { /* tran-action table */
        &ToastOven_off_s, /* target state */
        {
            Q_ACTION_CAST(&ToastOven_off_e), /* entry */
            Q_ACTION_NULL /* zero terminator */
        }
    };
    /*${SMs::ToastOven::SM::doorClosed::initial} */
    return QM_TRAN_INIT(&tatbl_);
}
/*${SMs::ToastOven::SM::doorClosed} */
static QState ToastOven_doorClosed(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::doorClosed::TERMINATE} */
        case TERMINATE_SIG: {
            static struct {
                QMState const *target;
                QActionHandler act[3];
            } const tatbl_ = { /* tran-action table */
                &ToastOven_final_s, /* target state */
                {
                    Q_ACTION_CAST(&ToastOven_doorClosed_x), /* exit */
                    Q_ACTION_CAST(&ToastOven_final_e), /* entry */
                    Q_ACTION_NULL /* zero terminator */
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::OPEN} */
        case OPEN_SIG: {
            static struct {
                QMState const *target;
                QActionHandler act[3];
            } const tatbl_ = { /* tran-action table */
                &ToastOven_doorOpen_s, /* target state */
                {
                    Q_ACTION_CAST(&ToastOven_doorClosed_x), /* exit */
                    Q_ACTION_CAST(&ToastOven_doorOpen_e), /* entry */
                    Q_ACTION_NULL /* zero terminator */
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::TOAST} */
        case TOAST_SIG: {
            static struct {
                QMState const *target;
                QActionHandler act[3];
            } const tatbl_ = { /* tran-action table */
                &ToastOven_toasting_s, /* target state */
                {
                    Q_ACTION_CAST(&ToastOven_heating_e), /* entry */
                    Q_ACTION_CAST(&ToastOven_toasting_e), /* entry */
                    Q_ACTION_NULL /* zero terminator */
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::BAKE} */
        case BAKE_SIG: {
            static struct {
                QMState const *target;
                QActionHandler act[3];
            } const tatbl_ = { /* tran-action table */
                &ToastOven_baking_s, /* target state */
                {
                    Q_ACTION_CAST(&ToastOven_heating_e), /* entry */
                    Q_ACTION_CAST(&ToastOven_baking_e), /* entry */
                    Q_ACTION_NULL /* zero terminator */
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::OFF} */
        case OFF_SIG: {
            static struct {
                QMState const *target;
                QActionHandler act[2];
            } const tatbl_ = { /* tran-action table */
                &ToastOven_off_s, /* target state */
                {
                    Q_ACTION_CAST(&ToastOven_off_e), /* entry */
                    Q_ACTION_NULL /* zero terminator */
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}

/*${SMs::ToastOven::SM::doorClosed::heating} ...............................*/
/*${SMs::ToastOven::SM::doorClosed::heating} */
static QState ToastOven_heating_e(ToastOven * const me) {
    PRINTF_S("%s;", "heater-On");
    (void)me; /* unused parameter */
    return QM_ENTRY(&ToastOven_heating_s);
}
/*${SMs::ToastOven::SM::doorClosed::heating} */
static QState ToastOven_heating_x(ToastOven * const me) {
    PRINTF_S("%s;", "heater-Off");
    /* save deep history */
    me->hist_heating = QMsm_stateObj(Q_HSM_UPCAST(me));
    return QM_EXIT(&ToastOven_heating_s);
}
/*${SMs::ToastOven::SM::doorClosed::heating::initial} */
static QState ToastOven_heating_i(ToastOven * const me) {
    static struct {
        QMState const *target;
        QActionHandler act[2];
    } const tatbl_ = { /* tran-action table */
        &ToastOven_toasting_s, /* target state */
        {
            Q_ACTION_CAST(&ToastOven_toasting_e), /* entry */
            Q_ACTION_NULL /* zero terminator */
        }
    };
    /*${SMs::ToastOven::SM::doorClosed::heating::initial} */
    return QM_TRAN_INIT(&tatbl_);
}
/*${SMs::ToastOven::SM::doorClosed::heating} */
static QState ToastOven_heating(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; /* unused parameter */
    return status_;
}

/*${SMs::ToastOven::SM::doorClosed::heating::toasting} .....................*/
/*${SMs::ToastOven::SM::doorClosed::heating::toasting} */
static QState ToastOven_toasting_e(ToastOven * const me) {
    PRINTF_S("%s;", "toasting");
    (void)me; /* unused parameter */
    return QM_ENTRY(&ToastOven_toasting_s);
}
/*${SMs::ToastOven::SM::doorClosed::heating::toasting} */
static QState ToastOven_toasting(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; /* unused parameter */
    return status_;
}

/*${SMs::ToastOven::SM::doorClosed::heating::baking} .......................*/
/*${SMs::ToastOven::SM::doorClosed::heating::baking} */
static QState ToastOven_baking_e(ToastOven * const me) {
    PRINTF_S("%s;", "baking");
    (void)me; /* unused parameter */
    return QM_ENTRY(&ToastOven_baking_s);
}
/*${SMs::ToastOven::SM::doorClosed::heating::baking} */
static QState ToastOven_baking(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; /* unused parameter */
    return status_;
}

/*${SMs::ToastOven::SM::doorClosed::off} ...................................*/
/*${SMs::ToastOven::SM::doorClosed::off} */
static QState ToastOven_off_e(ToastOven * const me) {
    PRINTF_S("%s;", "toaster-Off");
    (void)me; /* unused parameter */
    return QM_ENTRY(&ToastOven_off_s);
}
/*${SMs::ToastOven::SM::doorClosed::off} */
static QState ToastOven_off(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; /* unused parameter */
    return status_;
}

/*${SMs::ToastOven::SM::doorOpen} ..........................................*/
/*${SMs::ToastOven::SM::doorOpen} */
static QState ToastOven_doorOpen_e(ToastOven * const me) {
    PRINTF_S("%s;", "door-Open,lamp-On");
    (void)me; /* unused parameter */
    return QM_ENTRY(&ToastOven_doorOpen_s);
}
/*${SMs::ToastOven::SM::doorOpen} */
static QState ToastOven_doorOpen_x(ToastOven * const me) {
    PRINTF_S("%s;", "lamp-Off");
    (void)me; /* unused parameter */
    return QM_EXIT(&ToastOven_doorOpen_s);
}
/*${SMs::ToastOven::SM::doorOpen} */
static QState ToastOven_doorOpen(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::doorOpen::CLOSE} */
        case CLOSE_SIG: {
            static struct {
                QMState const *target;
                QActionHandler act[4];
            } const tatbl_ = { /* tran-action table */
                &ToastOven_heating_s, /* target state */
                {
                    Q_ACTION_CAST(&ToastOven_doorOpen_x), /* exit */
                    Q_ACTION_CAST(&ToastOven_doorClosed_e), /* entry */
                    Q_ACTION_CAST(&ToastOven_heating_e), /* entry */
                    Q_ACTION_NULL /* zero terminator */
                }
            };
            status_ = QM_TRAN_HIST(me->hist_heating, &tatbl_);
            break;
        }
        /*${SMs::ToastOven::SM::doorOpen::TERMINATE} */
        case TERMINATE_SIG: {
            static struct {
                QMState const *target;
                QActionHandler act[3];
            } const tatbl_ = { /* tran-action table */
                &ToastOven_final_s, /* target state */
                {
                    Q_ACTION_CAST(&ToastOven_doorOpen_x), /* exit */
                    Q_ACTION_CAST(&ToastOven_final_e), /* entry */
                    Q_ACTION_NULL /* zero terminator */
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        /*${SMs::ToastOven::SM::doorOpen::OFF} */
        case OFF_SIG: {
            static struct {
                QMState const *target;
                QActionHandler act[3];
            } const tatbl_ = { /* tran-action table */
                &ToastOven_doorClosed_s, /* target state */
                {
                    Q_ACTION_CAST(&ToastOven_doorOpen_x), /* exit */
                    Q_ACTION_CAST(&ToastOven_doorClosed_e), /* entry */
                    Q_ACTION_NULL /* zero terminator */
                }
            };
            status_ = QM_TRAN_HIST(me->hist_doorClosed, &tatbl_);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}

/*${SMs::ToastOven::SM::final} .............................................*/
/*${SMs::ToastOven::SM::final} */
static QState ToastOven_final_e(ToastOven * const me) {
    PRINTF_S("\n%s\n", "Bye! Bye!");
    QF_onCleanup();
    exit(0);
    (void)me; /* unused parameter */
    return QM_ENTRY(&ToastOven_final_s);
}
/*${SMs::ToastOven::SM::final} */
static QState ToastOven_final(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; /* unused parameter */
    return status_;
}
/*$enddef${SMs::ToastOven} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
