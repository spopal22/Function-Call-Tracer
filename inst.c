#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

void print_trace_record(const char* prefix, void *this_fn, void *call_site) { // Define function to print trace record
    printf("[%s] this_fn: %p, call_site: %p // ", prefix, this_fn, call_site);
} //Prints trace record in specified format

void __cyg_profile_func_enter(void *this_fn, void *call_site) {
    print_trace_record("enter", this_fn, call_site);
    printf("start of function\n");
} //Prints enter trace record and shows start of the function

void __cyg_profile_func_exit(void *this_fn, void *call_site) {
    print_trace_record("exit", this_fn, call_site);
    printf("end of function\n");
} //Function gets called when exiting, prints an exit trace record and shows end of the function
