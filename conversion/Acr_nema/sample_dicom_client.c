/* ----------------------------- MNI Header -----------------------------------
@NAME       : sample_dicom_client.c
@DESCRIPTION: Sample program to send dicom images to a remote server
@GLOBALS    : 
@CREATED    : May 6, 1997 (Peter Neelin)
@MODIFIED   : $Log: sample_dicom_client.c,v $
@MODIFIED   : Revision 1.1  1997-09-08 21:52:55  neelin
@MODIFIED   : Initial revision
@MODIFIED   :
 * Revision 5.0  1997/08/21  13:25:30  neelin
 * Release of minc version 0.5
 *
 * Revision 1.5  1997/07/11  17:35:58  neelin
 * Changed around send and receive routines for data once again.
 *
 * Revision 1.4  1997/07/11  13:55:41  neelin
 * Fixed handling of message ids.
 *
 * Revision 1.3  1997/07/11  13:22:16  neelin
 * Separated receive_reply from send_group_list.
 *
 * Revision 1.2  1997/07/10  17:39:51  neelin
 * Modified to use new dicom_client_routines.
 *
 * Revision 1.1  1997/05/13  23:53:40  neelin
 * Initial revision
 *
@COPYRIGHT  :
              Copyright 1997 Peter Neelin, McConnell Brain Imaging Centre, 
              Montreal Neurological Institute, McGill University.
              Permission to use, copy, modify, and distribute this
              software and its documentation for any purpose and without
              fee is hereby granted, provided that the above copyright
              notice appear in all copies.  The author and McGill University
              make no representations about the suitability of this
              software for any purpose.  It is provided "as is" without
              express or implied warranty.
---------------------------------------------------------------------------- */

#ifndef lint
static char rcsid[]="$Header: /private-cvsroot/minc/conversion/Acr_nema/sample_dicom_client.c,v 1.1 1997-09-08 21:52:55 neelin Exp $";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <acr_nema.h>

#ifndef public
#  define public
#endif
#ifndef private
#  define private static
#endif

/* Dicom definitions */
#define ACR_MR_IMAGE_STORAGE_UID       "1.2.840.10008.5.1.4.1.1.4"
#define ACR_IMPLICIT_VR_LITTLE_END_UID "1.2.840.10008.1.2"

/* Function prototypes */
public int send_file(Acr_File *afpin, Acr_File *afpout, char *filename);


/* Main program */

int main(int argc, char *argv[])
{
   char *pname;
   char *host;
   char *port;
   char *AEtitle;
   char **file_list;
   int ifile, num_files;
   Acr_File *afpin, *afpout;

   /* Check arguments */
   pname = argv[0];
   if (argc < 5) {
      (void) fprintf(stderr, "Usage: %s host port AEtitle files ...\n", pname);
      return EXIT_FAILURE;
   }
   host = argv[1];
   port = argv[2];
   AEtitle = argv[3];
   file_list = &argv[4];
   num_files = argc - 4;

   /* Make dicom connection */
   if (!acr_open_dicom_connection(host, port, AEtitle, "test",
                                  ACR_MR_IMAGE_STORAGE_UID,
                                  ACR_IMPLICIT_VR_LITTLE_END_UID,
                                  &afpin, &afpout)) {
      return EXIT_FAILURE;
   }

   /* Loop over the input files, sending them one at a time */
   for (ifile = 0; ifile < num_files; ifile++) {
      (void) printf("Sending file %s\n", file_list[ifile]);
      if (!send_file(afpin, afpout, file_list[ifile])) {
         break;
      }
   }

   /* Release the association */
   acr_close_dicom_connection(afpin, afpout);

   return EXIT_SUCCESS;
}

/* ----------------------------- MNI Header -----------------------------------
@NAME       : send_file
@INPUT      : afpin - input stream
              afpout - output stream
              filename - name of file to send
@OUTPUT     : (none)
@RETURNS    : TRUE if send went smoothly.
@DESCRIPTION: Routine to read in an ACR-NEMA format file and send it over
              a dicom connection.
@METHOD     : 
@GLOBALS    : 
@CALLS      : 
@CREATED    : May 9, 1997 (Peter Neelin)
@MODIFIED   : 
---------------------------------------------------------------------------- */
public int send_file(Acr_File *afpin, Acr_File *afpout, char *filename)
{
   FILE *fp;
   Acr_File *file_afp;
   Acr_Group group;
   Acr_Status status;
   int result;

   /* Open input file */
   fp = fopen(filename, "r");
   if (fp == NULL) {
      (void) fprintf(stderr, "Error opening file %s\n", filename);
      return FALSE;
   }

   /* Connect to input stream */
   file_afp = acr_file_initialize(fp, 0, acr_stdio_read);
   (void) acr_test_byte_order(file_afp);

   /* Read in group list up to group */
   status =  acr_input_group_list(file_afp, &group, 0);
   if ((status != ACR_OK) && (status != ACR_END_OF_INPUT)) {
      (void) fprintf(stderr, "Error reading file \"%s\"", filename);
      acr_dicom_error(status, "");
      return FALSE;
   }

   /* Free the afp */
   acr_file_free(file_afp);

   /* Send the group list */
   result = acr_send_group_list(afpin, afpout, group, 
                                ACR_MR_IMAGE_STORAGE_UID);

   /* Delete the group list */
   acr_delete_group_list(group);

   return result;
}
