/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2020-12-17
 * Language: C Source
 */

/********************************** INCLUDES **********************************/

/* Used for fread and fwrite */
#include <stdio.h>

/* Used for alloca */
#include <alloca.h>

/********************************* PROTOYPES **********************************/

/* The prototypes of your functions go here. */

/************************************ MAIN ************************************/

/* Prints the GPLv3 License to a file called LICENSE and exits. */
int main(int argc, const char **argv) {
  /* The path to the stored GPLv3 license.*/
  const char *gplv3_path = "/etc/roadelou_gplv3/GPLv3_LICENSE";

  /* First, we open the LICENSE file. */
  FILE *gplv3_file = fopen(gplv3_path, "rb");
  /* Checking if the file could be opened. */
  if (gplv3_file == NULL) {
    fprintf(stderr, "The file %s could not be opened.\n", gplv3_path);
    return 1;
  }

  /* Seeking the end of the license file. */
  int status = fseek(gplv3_file, 0L, SEEK_END);
  /* Checking if we could seek the end of the file. */
  if (status == -1) {
    fprintf(stderr,
            "Could not seek the end of %s, this can happend if it is not a "
            "regular file.\n",
            gplv3_path);
    return 1;
  }

  /* Reading the position of the stream to get the size of the file. */
  long gplv3_size = ftell(gplv3_file);
  /* Checking if we could get the size of the file. */
  if (gplv3_size == -1) {
    fprintf(stderr,
            "Could not tell the size of %s, this can happend if it is not a "
            "regular file.\n",
            gplv3_path);
    return 1;
  }

  /* Rewinding the file. */
  rewind(gplv3_file);

  /* Allocating memory to store the content of the file. */
  void *gplv3_buffer = alloca(gplv3_size);

  /* Reading from the source file. */
  size_t read_bytes = fread(gplv3_buffer, 1, gplv3_size, gplv3_file);
  /* Checking the return code. */
  if (read_bytes != gplv3_size) {
    fprintf(stderr, "Could not read from file %s, it might be unavailable.\n",
            gplv3_path);
    return 1;
  }
  /* Closing the source file, we no longer need it. */
  fclose(gplv3_file);

  /* The name of the file where we want to put the GPLv3 License. */
  const char *license_path = "LICENSE";

  /* Opening the target LICENSE file. */
  FILE *license_file = fopen(license_path, "wb");
  /* Checking the return code. */
  if (license_file == NULL) {
    fprintf(stderr,
            "Could not open %s file, it might be in use by another program.\n",
            license_path);
    return 1;
  }

  /* Writing the content of the GPLv3 to the License file. */
  size_t written_bytes = fwrite(gplv3_buffer, 1, gplv3_size, license_file);
  /* Checking the return code. */
  if (written_bytes != gplv3_size) {
    fprintf(stderr, "Could not write to %s, it might not be a regular file.\n",
            license_path);
    return 1;
  }

  /* Closing and flushing the License file. */
  fclose(license_file);

  /* Else everything was successfull, we return 0 and exit. */
  return 0;

  /*
  Note
  ====

  That is a lot of line for "cat /etc/roadelou_gplv3/GPLv3_LICENSE"...
  */
}

/********************************* FUNCTIONS **********************************/

/* The functions for your code go here. */

/************************************ EOF *************************************/
