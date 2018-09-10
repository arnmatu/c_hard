#undef NDEBUG
#ifndef __minunit_h
#define __minunit_h

#include <stdio.h>
#include <dbg.h>
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

#define mu_assert(test,message) if(!(test)) {\
    log_err(message); return message; }
