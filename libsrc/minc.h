#ifndef MINC_HEADER_FILE
#define MINC_HEADER_FILE

/* ----------------------------- MNI Header -----------------------------------
@NAME       : minc.h
@DESCRIPTION: Header file for minc (Medical Image NetCDF) file format 
              standard.
@METHOD     : Includes name definitions for NetCDF dimensions, attributes
              and variables for the following :
                 NetCDF standard attributes
                 MI general variable attributes
                 MI dimensions and associated variables
                 MI dimension variable attributes
                 MI root variable
                 MI image variable
                 MI patient variable
                 MI study variable
                 MI acquisition variable
@CREATED    : July 24, 1992. (Peter Neelin, Montreal Neurological Institute)
@MODIFIED   : 
@RCSID      : $Header: /private-cvsroot/minc/libsrc/minc.h,v 1.15 1992-12-01 16:30:55 neelin Exp $ MINC (MNI)
---------------------------------------------------------------------------- */

#ifndef MINC_PRIVATE_HEADER_FILE
#ifndef lint
static char minc_h_rcsid[] = "$Header: /private-cvsroot/minc/libsrc/minc.h,v 1.15 1992-12-01 16:30:55 neelin Exp $ MINC (MNI)";
#endif
#endif

#include <netcdf.h>

/* Some useful constants */
#define MI_EMPTY_STRING ""
/* Error flags */
#define MI_ERROR (-1)
#define MI_NOERROR 0
/* Maximum length of standard attributes */
#define MI_MAX_ATTSTR_LEN  64
/* Number of spatial dimensions */
#define MI_NUM_SPACE_DIMS 3
/* Maximum number of image dimensions for image conversion */
#define MI_MAX_IMGDIMS MAX_VAR_DIMS

/* NetCDF standard attributes */
#define MIunits       "units"
#define MIlong_name   "long_name"
#define MIvalid_range "valid_range"
#define MIvalid_max   "valid_max"
#define MIvalid_min   "valid_min"
#define MI_FillValue  "_FillValue"
#define MItitle       "title"
#define MIhistory     "history"

/* General variable attributes */
#define MIvartype  "vartype"
#define MIvarid    "varid"
#define MIsigntype "signtype"
#define MIparent   "parent"
#define MIchildren "children"
#define MIcomments "comments"
#define MIversion  "version"

/* General attribute constants */
/*    Prefix for identifying a variable attribute pointer */
#define MI_VARATT_POINTER_PREFIX "--->"
/*    Separator for elements of MIchildren */
#define MI_CHILD_SEPARATOR "\n"
/*    MIvartype values */
#define MI_GROUP     "group________"
#define MI_DIMENSION "dimension____"
#define MI_DIM_WIDTH "dim-width____"
#define MI_VARATT    "var_attribute"
/*    MIvarid value */
#define MI_STDVAR "MINC standard variable"
/*    MIsigntype values */
#define MI_SIGNED   "signed__"
#define MI_UNSIGNED "unsigned"
/*    MIversion value */
#define MI_VERSION_1_0 "MINC Version    1.0"
#define MI_CURRENT_VERSION MI_VERSION_1_0
/* Generally useful values for boolean attributes */
#define MI_TRUE  "true_"
#define MI_FALSE "false"

/* Dimension names and names of associated variables */
#define MIxspace           "xspace"
#define MIyspace           "yspace"
#define MIzspace           "zspace"
#define MItime             "time"
#define MItfrequency       "tfrequency"
#define MIxfrequency       "xfrequency"
#define MIyfrequency       "yfrequency"
#define MIzfrequency       "zfrequency"
#define MIvector_dimension "vector_dimension"
#define MIxspace_width     "xspace-width"
#define MIyspace_width     "yspace-width"
#define MIzspace_width     "zspace-width"
#define MItime_width       "time-width"
#define MItfrequency_width "tfrequency-width"
#define MIxfrequency_width "xfrequency-width"
#define MIyfrequency_width "yfrequency-width"
#define MIzfrequency_width "zfrequency-width"

/* Dimension variable attribute names */
/* For dimension variables (MIspacing is also for dimension width vars) */
#define MIspacing           "spacing"
#define MIstep              "step"
#define MIstart             "start"
#define MIspacetype         "spacetype"
#define MIalignment         "alignment"
#define MIdirection_cosines "direction_cosines"
/* For dimension width variables */
#define MIwidth             "width"
#define MIfiltertype        "filtertype"

/* Dimension attribute constants */
/*    MIgridtype values */
#define MI_REGULAR   "regular__"
#define MI_IRREGULAR "irregular"
/*    MIspacetype values */
#define MI_NATIVE    "native____"
#define MI_TALAIRACH "talairach_"
#define MI_CALLOSAL  "callosal__"
/*    MIalignment values */
#define MI_START  "start_"
#define MI_CENTRE "centre"
#define MI_END    "end___"
#define MI_CENTER MI_CENTRE
/*    MIfiltertype values */
#define MI_SQUARE     "square____"
#define MI_GAUSSIAN   "gaussian__"
#define MI_TRIANGULAR "triangular"

/* The root variable */
#define MIrootvariable "rootvariable"

/* The image variable and its attributes */
#define MIimage    "image"
#define MIimagemax "image-max"
#define MIimagemin "image-min"
#define MIcomplete "complete"

/* The patient variable and its attributes */
#define MIpatient        "patient"
#define MIfull_name      "full_name"
#define MIother_names    "other_names"
#define MIidentification "identification"
#define MIother_ids      "other_ids"
#define MIbirthdate      "birthdate"
#define MIsex            "sex"
#define MIage            "age"
#define MIweight         "weight"
#define MIsize           "size"
#define MIaddress        "address"
#define MIinsurance_id   "insurance_id"

/* Patient attribute constants */
#define MI_MALE   "male__"
#define MI_FEMALE "female"
#define MI_OTHER  "other_"

/* The study variable and its attributes */
#define MIstudy               "study"
#define MIstart_time          "start_time"
#define MIstart_year          "start_year"
#define MIstart_month         "start_month"
#define MIstart_day           "start_day"
#define MIstart_hour          "start_hour"
#define MIstart_minute        "start_minute"
#define MIstart_seconds       "start_seconds"
#define MImodality            "modality"
#define MImanufacturer        "manufacturer"
#define MIdevice_model        "device_model"
#define MIinstitution         "institution"
#define MIdepartment          "department"
#define MIstation_id          "station_id"
#define MIreferring_physician "referring_physician"
#define MIattending_physician "attending_physician"
#define MIradiologist         "radiologist"
#define MIoperator            "operator"
#define MIadmitting_diagnosis "admitting_diagnosis"
#define MIprocedure           "procedure"

/* Study attribute constants */
#define MI_PET   "PET__"
#define MI_SPECT "SPECT"
#define MI_GAMMA "GAMMA"
#define MI_MRI   "MRI__"
#define MI_MRS   "MRS__"
#define MI_MRA   "MRA__"
#define MI_CT    "CT___"
#define MI_DSA   "DSA__"
#define MI_DR    "DR___"

/* The acquisition variable and its attributes */
#define MIacquisition           "acquisition"
#define MIprotocol              "protocol"
#define MIscanning_sequence     "scanning_sequence"
#define MIrepetition_time       "repetition_time"
#define MIecho_time             "echo_time"
#define MIinversion_time        "inversion_time"
#define MInum_averages          "num_averages"
#define MIimaging_frequency     "imaging_frequency"
#define MIimaged_nucleus        "imaged_nucleus"
#define MIradionuclide          "radionuclide"
#define MIcontrast_agent        "contrast_agent"
#define MIradionuclide_halflife "radionuclide_halflife"
#define MItracer                "tracer"
#define MIinjection_time        "injection_time"
#define MIinjection_year        "injection_year"
#define MIinjection_month       "injection_month"
#define MIinjection_day         "injection_day"
#define MIinjection_hour        "injection_hour"
#define MIinjection_minute      "injection_minute"
#define MIinjection_seconds     "injection_seconds"
#define MIinjection_length      "injection_length"
#define MIinjection_dose        "injection_dose"
#define MIdose_units            "dose_units"
#define MIinjection_volume      "injection_volume"
#define MIinjection_route       "injection_route"

/* Constants for image conversion variable (icv) properties */
/* Maximum number of icv's allowed */
#define MI_MAX_NUM_ICV MAX_NC_OPEN
/* Default max and min for normalization */
#define MI_DEFAULT_MAX 1.0
#define MI_DEFAULT_MIN 0.0
/* For converting data type */
#define MI_ICV_TYPE             1
#define MI_ICV_SIGN             2
#define MI_ICV_DO_RANGE         3
#define MI_ICV_VALID_MAX        4
#define MI_ICV_VALID_MIN        5
/* For doing normalization */
#define MI_ICV_DO_NORM          6
#define MI_ICV_USER_NORM        7
#define MI_ICV_IMAGE_MAX        8
#define MI_ICV_IMAGE_MIN        9
/* Values actually used in normalization - read-only */
#define MI_ICV_NORM_MAX        10
#define MI_ICV_NORM_MIN        11
/* For doing dimension conversions */
#define MI_ICV_DO_DIM_CONV     12
/* For converting vector fields to scalar */
#define MI_ICV_DO_SCALAR       13
/* For flipping axis direction */
#define MI_ICV_XDIM_DIR        14
#define MI_ICV_YDIM_DIR        15
#define MI_ICV_ZDIM_DIR        16
/* For changing size of first two dimensions (excluding MIvector_dimension) */
#define MI_ICV_ADIM_SIZE       17
#define MI_ICV_BDIM_SIZE       18
#define MI_ICV_KEEP_ASPECT     19
/* The pixel size and location of first two dimensions (these are readonly) */
#define MI_ICV_ADIM_STEP       20
#define MI_ICV_BDIM_STEP       21
#define MI_ICV_ADIM_START      22
#define MI_ICV_BDIM_START      23
/* Number of image dimensions for dimension conversion */
#define MI_ICV_NUM_IMGDIMS     24
/* Image dimension properties. For each dimension, add the dimension 
   number (counting from fastest to slowest). */
#define MI_ICV_DIM_SIZE        1000
#define MI_ICV_DIM_STEP        1100
#define MI_ICV_DIM_START       1200

/* Constants that can be used as values for the above properties. */
/* Possible values for MI_ICV_?DIM_DIR */
#define MI_ICV_POSITIVE         1
#define MI_ICV_NEGATIVE       (-1)
#define MI_ICV_ANYDIR           0
/* Possible value for MI_ICV_?DIM_SIZE */
#define MI_ICV_ANYSIZE        (-1)

/* Error codes.
   Note that they must not conflict with NetCDF error codes since
   they are stored in the same global variable. */
#define MI_ERR_NONNUMERIC       1331  /* Non-numeric type */
#define MI_ERR_NONCHAR          1332  /* Non-character type */
#define MI_ERR_NONSCALAR        1333  /* Non-scalar attribute */
#define MI_ERR_BADOP            1334  /* Bad operation for MI_varaccess */
#define MI_ERR_NOTPOINTER       1335  /* Attribute is not a pointer */
#define MI_ERR_BAD_STDVAR       1336  /* Not a standard variable */
#define MI_ERR_BADSUFFIX        1337  /* Bad dimension width suffix */
#define MI_ERR_NOICV            1338  /* Out of icv slots */
#define MI_ERR_BADICV           1339  /* Illegal icv identifier */
#define MI_ERR_BADPROP          1340  /* Unknown icv property */
#define MI_ERR_ICVATTACHED      1341  /* Tried to modify attached icv */
#define MI_ERR_TOOFEWDIMS       1342  /* Too few dimensions to be an image */
#define MI_ERR_ICVNOTATTACHED   1343  /* Tried to access an unattached icv */
#define MI_ERR_DIMSIZE          1344  /* Dimensions differ in size */
#define MI_ERR_ICV_INVCOORDS    1345  /* Invalid icv coordinates */
#define MI_ERR_WRONGNDIMS       1346  /* Too many dimensions for a dim var */

/* MINC public functions */
/* Define public constant */
#ifndef public
#define public
#endif

/* From netcdf_convenience.c */
public int miattget(int cdfid, int varid, char *name, nc_type datatype,
                    int max_length, void *value, int *att_length);
public int miattget1(int cdfid, int varid, char *name, nc_type datatype,
                    void *value);
public char *miattgetstr(int cdfid, int varid, char *name, 
                         int maxlen, char *value);
public int miattputint(int cdfid, int varid, char *name, int value);
public int miattputdbl(int cdfid, int varid, char *name, double value);
public int miattputstr(int cdfid, int varid, char *name, char *value);
public int mivarget(int cdfid, int varid, long start[], long count[],
                    nc_type datatype, char *sign, void *values);
public int mivarget1(int cdfid, int varid, long mindex[],
                     nc_type datatype, char *sign, void *value);
public int mivarput(int cdfid, int varid, long start[], long count[],
                    nc_type datatype, char *sign, void *values);
public int mivarput1(int cdfid, int varid, long mindex[],
                     nc_type datatype, char *sign, void *value);
public long *miset_coords(int nvals, long value, long coords[]);
public long *mitranslate_coords(int cdfid, 
                                int invar,  long incoords[],
                                int outvar, long outcoords[]);
public int micopy_all_atts(int incdfid, int invarid, 
                           int outcdfid, int outvarid);
public int micopy_var_def(int incdfid, int invarid, int outcdfid);
public int micopy_var_values(int incdfid, int invarid, 
                             int outcdfid, int outvarid);
public int micopy_all_var_defs(int incdfid, int outcdfid, int nexclude,
                               int excluded_vars[]);
public int micopy_all_var_values(int incdfid, int outcdfid, int nexclude,
                                 int excluded_vars[]);

/* From minc_convenience.c */
public int miattput_pointer(int cdfid, int varid, char *name, int ptrvarid);
public int miattget_pointer(int cdfid, int varid, char *name);
public int miadd_child(int cdfid, int parent_varid, int child_varid);
public int micreate_std_variable(int cdfid, char *name, nc_type datatype, 
                                 int ndims, int dim[]);
public int micreate_group_variable(int cdfid, char *name);

/* From image_conversion.c */
public int miicv_create();
public int miicv_free(int icvid);
public int miicv_setdbl(int icvid, int icv_property, double value);
public int miicv_setint(int icvid, int icv_property, int value);
public int miicv_set(int icvid, int icv_property, void *value);
public int miicv_inq(int icvid, int icv_property, void *value);
public int miicv_ndattach(int icvid, int cdfid, int varid);
public int miicv_detach(int icvid);
public int miicv_get(int icvid, long start[], long count[], void *values);
public int miicv_put(int icvid, long start[], long count[], void *values);

/* From dim_conversion.c */
public int miicv_attach(int icvid, int cdfid, int varid);


/* End ifndef MINC_HEADER_FILE */
#endif
