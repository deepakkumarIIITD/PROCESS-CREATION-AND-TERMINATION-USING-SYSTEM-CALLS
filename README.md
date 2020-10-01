# PROCESS-CREATION-AND-TERMINATION-USING-SYSTEM-CALLS

using process creation system call, fork(). You need to
write a program that spawns a child process, using the fork() system call. The
child process reads a CSV file, presented with the assignment, that has (fake)
student IDs and grades of various assignments. This child process computes the
average score of each student for section ‘A’, and thereafter prints the details of
these students (of section ‘A’, i.e.). The parent process does the same operation,
on the same CSV file but for students of section ‘B’.
The parent process must wait for the child process to terminate, by using
the system call waitpid(). The child process must call the exit() system call
once its execution ends.

You would require to refer to the manpages for various system calls men-
tioned.
