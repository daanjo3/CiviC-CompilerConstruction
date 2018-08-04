
/**
 * @file traverse_tables.c
 *
 * This file defines the function tables for traversal.
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: traverse_tables.c.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#include "traverse_tables.h"
#include "traverse_helper.h"
#include "print.h"
#include "copy_node.h"
#include "free_node.h"
#include "check.h"
#include "transform_for.h"
#include "var_init_trans_global.h"
#include "make_st.h"
#include "print_st.h"
#include "typecheck_inference.h"
#include "typecheck_match.h"
#include "transform_bool_junction.h"
#include "transform_bool_cast.h"
#include "gen_byte_code.h"


travtables_t travtables = {
  /* TR_undefined */
  {&TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror,
   &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror,
   &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror,
   &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror,
   &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror, &TRAVerror}

  /* TR_prt */
  , {&TRAVerror, &PRTprogram, &PRTdeclarations, &PRTfundefdec, &PRTfunbody,
     &PRTvardec, &PRTlocalfundefs, &PRTglobaldec, &PRTglobaldef, &PRTparam,
     &PRTvar, &PRTstatements, &PRTassign, &PRTfuncall, &PRTif, &PRTwhile,
     &PRTdowhile, &PRTfor, &PRTreturn, &PRTexprs, &PRTbinop, &PRTmonop,
     &PRTcondexpr, &PRTcast, &PRTnum, &PRTfloat, &PRTbool, &PRTsymboltable,
     &PRTsymboltableentry, &PRTerror}

  /* TR_copy */
  , {&TRAVerror, &COPYprogram, &COPYdeclarations, &COPYfundefdec,
     &COPYfunbody, &COPYvardec, &COPYlocalfundefs, &COPYglobaldec,
     &COPYglobaldef, &COPYparam, &COPYvar, &COPYstatements, &COPYassign,
     &COPYfuncall, &COPYif, &COPYwhile, &COPYdowhile, &COPYfor, &COPYreturn,
     &COPYexprs, &COPYbinop, &COPYmonop, &COPYcondexpr, &COPYcast, &COPYnum,
     &COPYfloat, &COPYbool, &COPYsymboltable, &COPYsymboltableentry,
     &COPYerror}

  /* TR_free */
  , {&TRAVerror, &FREEprogram, &FREEdeclarations, &FREEfundefdec,
     &FREEfunbody, &FREEvardec, &FREElocalfundefs, &FREEglobaldec,
     &FREEglobaldef, &FREEparam, &FREEvar, &FREEstatements, &FREEassign,
     &FREEfuncall, &FREEif, &FREEwhile, &FREEdowhile, &FREEfor, &FREEreturn,
     &FREEexprs, &FREEbinop, &FREEmonop, &FREEcondexpr, &FREEcast, &FREEnum,
     &FREEfloat, &FREEbool, &FREEsymboltable, &FREEsymboltableentry,
     &FREEerror}

  /* TR_chk */
  , {&TRAVerror, &CHKprogram, &CHKdeclarations, &CHKfundefdec, &CHKfunbody,
     &CHKvardec, &CHKlocalfundefs, &CHKglobaldec, &CHKglobaldef, &CHKparam,
     &CHKvar, &CHKstatements, &CHKassign, &CHKfuncall, &CHKif, &CHKwhile,
     &CHKdowhile, &CHKfor, &CHKreturn, &CHKexprs, &CHKbinop, &CHKmonop,
     &CHKcondexpr, &CHKcast, &CHKnum, &CHKfloat, &CHKbool, &CHKsymboltable,
     &CHKsymboltableentry, &CHKerror}

  /* TR_tf */
  , {&TRAVerror, &TRAVsons, &TRAVsons, &TFfundefdec, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TFvar, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TFfor, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons}

  /* TR_tg */
  , {&TRAVerror, &TGprogram, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TGglobaldef, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons}

  /* TR_ms */
  , {&TRAVerror, &MSprogram, &TRAVsons, &MSfundefdec, &TRAVsons, &MSvardec,
     &TRAVsons, &MSglobaldec, &MSglobaldef, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &MSfor, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons}

  /* TR_ps */
  , {&TRAVerror, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &PSsymboltable, &PSsymboltableentry,
     &TRAVsons}

  /* TR_tci */
  , {&TRAVerror, &TCIprogram, &TRAVsons, &TCIfundefdec, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TCIvar, &TRAVsons,
     &TRAVsons, &TCIfuncall, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TCIbinop, &TCImonop, &TRAVsons, &TRAVsons,
     &TCInum, &TCIfloat, &TCIbool, &TRAVsons, &TRAVsons, &TRAVsons}

  /* TR_tcm */
  , {&TRAVerror, &TCMprogram, &TRAVsons, &TCMfundefdec, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TCMglobaldef, &TRAVsons, &TRAVsons, &TRAVsons,
     &TCMassign, &TCMfuncall, &TCMif, &TCMwhile, &TCMdowhile, &TCMfor,
     &TCMreturn, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons}

  /* TR_tbj */
  , {&TRAVerror, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TBJbinop, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons}

  /* TR_tbc */
  , {&TRAVerror, &TBCprogram, &TRAVsons, &TBCfundefdec, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TBCcast,
     &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons, &TRAVsons}

  /* TR_gbc */
  , {&TRAVerror, &GBCprogram, &GBCdeclarations, &GBCfundefdec, &GBCfunbody,
     &GBCvardec, &GBClocalfundefs, &GBCglobaldec, &GBCglobaldef, &GBCparam,
     &GBCvar, &GBCstatements, &GBCassign, &GBCfuncall, &GBCif, &GBCwhile,
     &GBCdowhile, &GBCfor, &GBCreturn, &GBCexprs, &GBCbinop, &GBCmonop,
     &TRAVsons, &GBCcast, &GBCnum, &GBCfloat, &GBCbool, &TRAVsons, &TRAVsons,
     &TRAVsons}
};

preposttable_t pretable = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL
};

preposttable_t posttable = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL
};

const char *travnames[14] = {
  "unknown", "prt", "copy", "free", "chk", "tf", "tg", "ms", "ps", "tci",
    "tcm", "tbj", "tbc", "gbc"
};
