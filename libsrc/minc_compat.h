/* Functions for enabling/disabling error messages from the library.
 */
extern int MI2typelen(nc_type);

extern int MI2varname(int fd, int varid, char *varnm);

extern int MI2varid(int fd, const char *varnm);

extern int MI2attinq(int fd, int varid, const char *attnm, nc_type *type_ptr,
		     int *length_ptr);

extern int MI2attname(int fd, int varid, int attid, char *name);

extern int MI2inquire(int fd, int *ndims_ptr, int *nvars_ptr, int *natts_ptr,
		      int *unlimdim_ptr);

extern int MI2varinq(int fd, int varid, char *varnm_ptr, nc_type *type_ptr,
		     int *ndims_ptr, int *dims_ptr, int *natts_ptr);

extern int MI2dimid(int fd, const char *dimnm);

extern int MI2diminq(int fd, int dimid, char *dimnm_ptr, long *len_ptr);

extern int MI2dimdef(int fd, const char *dimnm, long length);

extern int MI2attget(int fd, int varid, const char *attnm, void *value);

extern int MI2attput(int fd, int varid, const char *attnm, nc_type val_typ, 
		     int val_len, void *val_ptr);

extern int MI2endef(int fd);

extern int MI2vardef(int fd, const char *varnm, nc_type vartype, int ndims,
		     const int *dimids);

extern int MI2varget(int fd, int varid, const long *start_ptr, 
		     const long *count_ptr, void *val_ptr);

extern int MI2varput(int fd, int varid, const long *start_ptr,
		     const long *count_ptr, const void *val_ptr);

extern int MI2varput1(int fd, int varid, const long *mindex_ptr,
		      const void *val_ptr);

extern int MI2attdel(int fd, int varid, const char *attnm);

extern int MI2dimrename(int fd, int dimid, const char *new_name);

extern int MI2varputg(int fd, int varid, const long *startp, 
		      const long *countp, const long *stridep, 
		      const long *imapp, const void *valp);

extern int MI2attcopy(int infd, int invarid, const char *name, int outfd, 
		      int outvarid);

#ifndef _MI2_FORCE_NETCDF_
#define nctypelen MI2typelen
#define ncvarname MI2varname
#define ncvarid MI2varid
#define ncdimid MI2dimid
#define ncvarinq MI2varinq
#define ncdiminq MI2diminq
#define ncdimdef MI2dimdef
#define ncattdel MI2attdel
#define ncvardef MI2vardef
#define ncvarput1 MI2varput1
#define ncvarput MI2varput
#define ncvarget MI2varget
#define ncattinq MI2attinq
#define ncvarputg MI2varputg
#define nccreate micreate
#define ncopen miopen
#define ncclose miclose
#define ncattput MI2attput
#define ncinquire MI2inquire
#define ncattname MI2attname
#define ncdimrename MI2dimrename
#define ncattcopy MI2attcopy
#define ncendef MI2endef
#define ncattget MI2attget

#ifndef NC_NOFILL
#define NC_NOFILL 0x100
#endif
#define ncsetfill(x,y) MI_NOERROR
#define ncredef(x) MI_NOERROR
#define ncsync(x) MI_NOERROR
#endif /* _MI2_FORCE_NETCDF_ not defined */
