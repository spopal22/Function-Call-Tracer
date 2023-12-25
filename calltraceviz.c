#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    char *trace_filename;

    //Checks to see if a filename is provided
    if (argc > 1) {
        trace_filename = argv[1];
    } else {
        //If theres none provided, it finds a .calltrace file in the current directory
        trace_filename = ".calltrace";
        if (access(trace_filename, F_OK) == -1) {
            fprintf(stderr, "No .calltrace file in current directory\n");
            exit(EXIT_FAILURE);
        }
    }

    int fd = open(trace_filename, O_RDONLY);  //OPens the call trace file for reading
    
    if (fd == -1) {
        perror("Could not open call trace file");
        exit(EXIT_FAILURE);
    }

    struct record {
        void *this_fn;
        void *call_site;
        clock_t start_time;
        clock_t end_time;
    } call_record; //Reads and prints the call trace records

    while (read(fd, &call_record, sizeof(call_record)) > 0) {
        printf("Function Call: this_fn=%p, call_site=%p, start_time=%lu, end_time=%lu\n",
               call_record.this_fn, call_record.call_site, call_record.start_time, call_record.end_time);
    } //Prints out the specifics of the function call trace records

    close(fd); //Closes the file after its been read

    return 0;
}