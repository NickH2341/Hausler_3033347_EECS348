# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY ec_lab_test.c .
# Compile the C program
RUN gcc -o ec_lab_test ec_lab_test.c
# Set the command to run when the container starts
CMD ["./ec_lab_test"]